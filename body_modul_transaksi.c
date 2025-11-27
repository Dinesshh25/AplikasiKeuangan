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
    sprintf(bufferId, "T%03d", jumlahTransaksi); //menghasilkan ID unik dengan format TXXX
}

int validasiTransaksi(Transaksi transaksiBaru, PosAnggaran dataPos[], int jumlahPos){
    /* Deklarasi Variabel*/
    int i, cekMasuk, cekKeluar;
    int posValid = 0;

    /* Deskripsi Program */
    // Validasi jenis transaksi
    cekMasuk = strcmp(transaksiBaru.jenis, "Pemasukan") == 0 || strcmp(transaksiBaru.jenis, "pemasukan") == 0; //case insensitive
    cekKeluar = strcmp(transaksiBaru.jenis, "Pengeluaran") == 0 || strcmp(transaksiBaru.jenis, "pengeluaran") == 0; //case insensitive
    if (!cekMasuk && !cekKeluar){
        printf("Jenis transaksi tidak valid. Harus 'Pemasukan' atau 'Pengeluaran'.\n");
        return 0;
    }

    // Validasi nominal
    if (transaksiBaru.nominal <= 0){
        printf("Nominal transaksi harus lebih dari 0.\n");
        return 0;
    }

    // Validasi tanggal
    if (strlen(transaksiBaru.tanggal) == 0){
        printf("Tanggal transaksi tidak boleh kosong.\n");
        return 0;
    }

    // Validasi pos anggaran
    if (cekKeluar) {
        for (i = 0; i < jumlahPos; i++){
            if (strcmp(transaksiBaru.pos, dataPos[i].namaPos) == 0){
                posValid = 1;
                break;
            }
        }
        
        if (!posValid){
            printf("Pos anggaran tidak valid...\n");
            return 0;
        }
    }

    return 1; //data valid
}

void tambahTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos){
    /* Deklarasi Variabel*/
    Transaksi transaksiBaru;
    int valid;

    /* Deskripsi Program */
    transaksiBaru.nominal = 0; //inisialisasi nominal
    printf("Menambahkan Transaksi Baru:\n");
    // Input data transaksi baru dari pengguna
    printf("Masukkan tanggal transaksi (DD/MM/YYYY): ");
    scanf("%s", transaksiBaru.tanggal);
    printf("Masukkan pos anggaran: ");
    scanf(" %[^\n]", transaksiBaru.pos);
    printf("Masukkan jenis transaksi (Pemasukan/Pengeluaran): ");
    scanf(" %[^\n]", transaksiBaru.jenis);
    printf("Masukkan nominal transaksi: ");
    scanf("%d", &transaksiBaru.nominal);
    printf("Masukkan deskripsi transaksi: ");
    scanf(" %[^\n]", transaksiBaru.deskripsi);

    generateId(*jumlahTransaksi + 1, transaksiBaru.id); //menghasilkan ID unik untuk transaksi baru
    valid = validasiTransaksi(transaksiBaru, dataPos, jumlahPos); //memvalidasi data transaksi baru
    //Jika data valid, tambahkan ke file dan array
    if (valid){
        appendDataTransaksi(transaksiBaru);
        dataTransaksi[*jumlahTransaksi] = transaksiBaru;
        (*jumlahTransaksi)++;
    }
}