// Procedure generateIDPos untuk generate ID baru (format string)
void generateIDPos(char idBaru[], PosAnggaran dataPos[], int jumlahPos) {
    if (jumlahPos == 0) {
        strcpy(idBaru, "P001"); // ID pertama
        return;
    }
    
    // Cari nomor ID terbesar
    int maxNum = 0;
    for (int i = 0; i < jumlahPos; i++) {
        // Ambil angka dari ID (misal: "P001" -> 1)
        int num = atoi(&dataPos[i].id[1]); // Skip karakter 'P'
        if (num > maxNum) {
            maxNum = num;
        }
    }
    
    // Generate ID baru dengan format P001, P002, dst
    sprintf(idBaru, "P%03d", maxNum + 1);
}

// Procedure ubahKapital untuk membuat seluruh huruf nama pos menjadi huruf besar
void ubahKapital(char *s) {
    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] = s[0] - 32;  // ubah huruf kecil ke besar
    }
}

// Procedure lowerCase untuk membandingkan antar huruf
void lowerCase(const char *src, char *dest) {
    while (*src) {
        if (*src >= 'A' && *src <= 'Z') {
            *dest = *src + 32;
        } else {
            *dest = *src;
        }
        src++;
        dest++;
    }
    *dest = '\0';
}

// Procedure simpanDataPosKeFile untuk menyimpan data ke file
void simpanDataPosKeFile(PosAnggaran dataPos[], int jumlahPos) {
    FILE *file = fopen("pos_anggaran.txt", "w");
    if (file == NULL) {
        printf("[!] ERROR: Gagal menyimpan data ke file!\n");
        return;
    }
    
    // Tulis header
    fprintf(file, "ID|Pos|Batas Nominal (Rp)\n");
    
    // Tulis semua data
    for (int i = 0; i < jumlahPos; i++) {
        fprintf(file, "%s|%s|%d\n", 
                dataPos[i].id,
                dataPos[i].namaPos, 
                dataPos[i].batasNominal);
    }
    
    fclose(file);
}

// Fungsi validasiNamaPos untuk memberikan peringatan input nama yang tidak sesuai
int validasiNamaPos(PosAnggaran dataPos[], int jumlahPos, char nama[]) {
    // 1. Cek kosong
    if (nama[0] == '\0') {
        printf("Nama pos tidak boleh kosong!\n");
        return 0;
    }

    // 2. Buat versi lowercase untuk pengecekan duplikasi
    char namaLower[100];
    lowerCase(nama, namaLower);

    for (int i = 0; i < jumlahPos; i++) {
        char existingLower[100];
        lowerCase(dataPos[i].namaPos, existingLower);

        if (strcmp(existingLower, namaLower) == 0) {
            printf("Nama pos '%s' sudah ada! Gunakan nama lain.\n", nama);
            return 0;
        }
    }

    // 3. Jika valid → ubah huruf pertama kapital untuk penyimpanan
    ubahKapital(nama);

    return 1;
}


// Fungsi validasiNamaPos untuk memberikan peringatan input nomina yang dibawah 0
int validasiNominal(long long nominal) {
    if (nominal <= 0 || nominal > 10000000000) {
        printf("Batas nominal harus bilangan positif (>0) dan tidak boleh lebih dari 10 juta!\n");
        return 0;
    }
    return 1;
}

// Procedure appendDataPos untuk menambahkan data baru ke pos_anggaran.txt 
void appendDataPos(PosAnggaran dataPos[], int *jumlahPos) {
    PosAnggaran posBaru;

    printf("\n=== TAMBAH POS ANGGARAN ===\n");

    // Generate ID otomatis
    generateIDPos(posBaru.id, dataPos, *jumlahPos);
    printf("ID Pos (otomatis): %s\n", posBaru.id);

    // Input nama pos + validasi
    do {
        printf("Masukkan Nama Pos: ");
        fflush(stdin);
        fgets(posBaru.namaPos, sizeof(posBaru.namaPos), stdin);
        posBaru.namaPos[strcspn(posBaru.namaPos, "\n")] = '\0';
    } while (!validasiNamaPos(dataPos, *jumlahPos, posBaru.namaPos));
    
    // Input nominal + validasi
    do {
        printf("Masukkan Batas Nominal (Rp): ");
        scanf("%lld", &posBaru.batasNominal);
    } while (!validasiNominal(posBaru.batasNominal));

    // Set awal pemakaian
    posBaru.totalTerpakai = 0;

    // Simpan ke array
    dataPos[*jumlahPos] = posBaru;
    (*jumlahPos)++;

    printf("\n Pos anggaran berhasil ditambahkan!\n");

    simpanDataPosKeFile(dataPos, *jumlahPos);
    printf(" Data tersimpan ke file 'pos_anggaran.txt'\n");
}

// Procedure loadDataPos untuk memproses data yang ada di pos_anggaran.txt untuk dimtampilkan
void loadDataPos(PosAnggaran dataPos[], int *jumlahPos) {
    FILE *file = fopen("pos_anggaran.txt", "r");
    
    if (file == NULL) {
        // File belum ada, mulai dengan data kosong
        *jumlahPos = 0;
        printf("[i] File 'pos_anggaran.txt' belum ada. Memulai dengan data kosong.\n");
        return;
    }
    
    char buffer[200];
    *jumlahPos = 0;
    
    // Skip header (baris pertama)
    fgets(buffer, sizeof(buffer), file);
    
    // Baca data per baris
    while (fgets(buffer, sizeof(buffer), file) != NULL && *jumlahPos < 50) {
        PosAnggaran pos;
        char *token;
        
        // Parse ID
        token = strtok(buffer, "|");
        if (token != NULL) {
            strcpy(pos.id, token);
        }
        
        // Parse Nama Pos
        token = strtok(NULL, "|");
        if (token != NULL) {
            strcpy(pos.namaPos, token);
        }
        
        // Parse Batas Nominal
        token = strtok(NULL, "|");
        if (token != NULL) {
            pos.batasNominal = atoi(token);
        }
        
        pos.totalTerpakai = 0; // Default 0 saat load
        
        dataPos[*jumlahPos] = pos;
        (*jumlahPos)++;
    }
    
    fclose(file);
}
