void loadDataTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi){
    /* Deklarasi Variabel*/
    int index = 0;

    /* Deskripsi Program */
    FILE *filetransaksi = fopen("data_transaksi.txt", "r"); //membuka file data_transaksi.txt
    //Cek jika file tidak ada
    if (filetransaksi == NULL)
    {
        *jumlahTransaksi = 0;
        return;
    }

    //Membaca data transaksi dari file 
    while (fscanf(filetransaksi, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^\n]\n",
        dataTransaksi[index].id,
        dataTransaksi[index].tanggal,
        dataTransaksi[index].pos,
        dataTransaksi[index].jenis,
        &dataTransaksi[index].nominal,
        dataTransaksi[index].deskripsi
    ) != EOF)
    {
        index++;
    }

    *jumlahTransaksi = index; //memperbarui jumlah transaksi
    fclose(filetransaksi); //menutup file
}

void appendDataTransaksi(Transaksi transaksiBaru){ 
    /* Deskripsi Program */
    FILE *filetransaksi = fopen("data_transaksi.txt", "a"); //membuka file data_transaksi.txt untuk penambahan data

    //Menambahkan data transaksi baru ke file
    fprintf(filetransaksi, "%s|%s|%s|%s|%d|%s\n",
        transaksiBaru.id,
        transaksiBaru.tanggal,
        transaksiBaru.pos,
        transaksiBaru.jenis,
        transaksiBaru.nominal,
        transaksiBaru.deskripsi
    );

    fclose(filetransaksi); //menutup file
}

void generateId(int jumlahTransaksi, char *bufferId){
    /* Deskripsi Program */
    sprintf(bufferId, "T%03d", jumlahTransaksi + 1); //menghasilkan ID unik dengan format TXXX
}

int isJenisTransaksiValid(char *jenisTransaksi){
    /* Deskripsi Program */
    // Cek validitas (Pemasukan/Pengeluaran, huruf besar/kecil)
    if (strcmp(jenisTransaksi, "Pemasukan") == 0 || strcmp(jenisTransaksi, "pemasukan") == 0 ||
        strcmp(jenisTransaksi, "Pengeluaran") == 0 || strcmp(jenisTransaksi, "pengeluaran") == 0){
        return 1; // Valid
    } else {
        printf("Jenis transaksi tidak valid. Harus 'Pemasukan' atau 'Pengeluaran'.\n");
        return 0; // Invalid
    }
}

int isNominalTransaksiValid(int *nominalTransaksi){
    /* Deskripsi Program */
    if (*nominalTransaksi > 0){
        return 1; // Valid
    } else {
        printf("Nominal transaksi harus lebih dari 0.\n");
        return 0; // Invalid
    }
}

int isTanggalTransaksiValid(char *tanggalTransaksi){
    /* Deskripsi Program */
    if (strlen(tanggalTransaksi) > 0){
        return 1; // Valid
    } else {
        printf("Tanggal transaksi tidak boleh kosong.\n");
        return 0; // Invalid
    }
}

int isPosAnggaranTransaksiValid(char *posAnggaran, PosAnggaran dataPos[], int jumlahPos){
    /* Deskripsi Program*/
    int i;
    // Loop cari nama pos di array
    for (i = 0; i < jumlahPos; i++){
        if (strcmp(posAnggaran, dataPos[i].namaPos) == 0){
            return 1; // Ketemu & Valid
        }
    }
    
    printf("Pos anggaran '%s' tidak ditemukan. Cek daftar pos.\n", posAnggaran);
    return 0; // Invalid
}

void tambahTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos){
    Transaksi transaksiBaru;
    
    printf("\n--- Menambahkan Transaksi Baru ---\n");

    // Input Tanggal (Loop sampai Valid)
    do {
        printf("Masukkan tanggal (DD/MM/YYYY): ");
        scanf(" %[^\n]", transaksiBaru.tanggal);
    } while (!isTanggalTransaksiValid(transaksiBaru.tanggal));

    // Input Jenis (Loop sampai Valid)
    do {
        printf("Masukkan jenis transaksi (Pemasukan/Pengeluaran): ");
        scanf(" %[^\n]", transaksiBaru.jenis);
    } while (!isJenisTransaksiValid(transaksiBaru.jenis));

    // Cek apakah user menginput "Pemasukan" (Huruf besar/kecil)
    int isMasuk = (strcmp(transaksiBaru.jenis, "Pemasukan") == 0 || strcmp(transaksiBaru.jenis, "pemasukan") == 0);

    if (isMasuk) {
        // Jika pemasukan, isi otomatis
        strcpy(transaksiBaru.pos, "Pemasukan"); 
        printf(">> Pos Anggaran otomatis diatur ke: 'Pemasukan'\n");
    } else {
        // Jika pengeluaran, user isi Pos Anggaran yang valid
        do {
            printf("Masukkan pos anggaran: ");
            scanf(" %[^\n]", transaksiBaru.pos);
        } while (!isPosAnggaranTransaksiValid(transaksiBaru.pos, dataPos, jumlahPos));
    }

    // Input Nominal (Loop sampai Valid)
    do {
        printf("Masukkan nominal transaksi: ");
        scanf("%d", &transaksiBaru.nominal);
    } while (!isNominalTransaksiValid(&transaksiBaru.nominal)); 

    printf("Masukkan deskripsi transaksi: ");
    scanf(" %[^\n]", transaksiBaru.deskripsi);

    generateId(*jumlahTransaksi, transaksiBaru.id);
    
    appendDataTransaksi(transaksiBaru);
    dataTransaksi[*jumlahTransaksi] = transaksiBaru;
    (*jumlahTransaksi)++;
    
    printf("\nTransaksi Berhasil Disimpan!\n");
}