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

void isJenisTransaksiValid(char *jenisTransaksi){
    /* Deskripsi Program */
    while (1){
        if (strcmp(jenisTransaksi, "Pemasukan") == 0 || strcmp(jenisTransaksi, "pemasukan") == 0 ||
            strcmp(jenisTransaksi, "Pengeluaran") == 0 || strcmp(jenisTransaksi, "pengeluaran") == 0){
            break; //jenis valid
        } else {
            printf("Jenis transaksi tidak valid. Masukkan ulang (Pemasukan/Pengeluaran): ");
            scanf(" %[^\n]", jenisTransaksi);
        }
    }
}

void isNominalTransaksiValid(int *nominalTransaksi){
    /* Deskripsi Program */
    while (1){
        if (*nominalTransaksi > 0){
            break; //nominal valid
        } else {
            printf("Nominal transaksi harus lebih dari 0. Masukkan ulang: ");
            scanf("%d", nominalTransaksi);
        }
    }
}

void isTanggalTransaksiValid(char *tanggalTransaksi){
    /* Deskripsi Program */
    while (1){
        if (strlen(tanggalTransaksi) > 0){
            break; //tanggal valid
        } else {
            printf("Tanggal transaksi tidak boleh kosong. Masukkan ulang (DD/MM/YYYY): ");
            scanf(" %[^\n]", tanggalTransaksi);
        }
    }
}

void isPosAnggaranTransaksiValid(char *posAnggaran, PosAnggaran dataPos[], int jumlahPos){
    /* Deklarasi Variabel */
    int i;
    int posValid = 0;

    /* Deskripsi Program */
    while (1){
        for (i = 0; i < jumlahPos; i++){
            if (strcmp(posAnggaran, dataPos[i].namaPos) == 0){
                posValid = 1;
                break;
            }
        }
        if (posValid){
            break; //pos anggaran valid
        } else {
            printf("Pos anggaran tidak valid. Masukkan ulang: ");
            scanf(" %[^\n]", posAnggaran);
        }
    }
}

void tambahTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos){
    /* Deklarasi Variabel*/
    Transaksi transaksiBaru;
    int valid;

    /* Deskripsi Program */
    transaksiBaru.nominal = 0; //inisialisasi nominal
    printf("Menambahkan Transaksi Baru:\n");
    // Input data transaksi baru dari pengguna
    do
    {
        printf("Masukkan tanggal transaksi (DD/MM/YYYY): ");
        scanf("%s", transaksiBaru.tanggal);
    } while (isTanggalTransaksiValid(transaksiBaru.tanggal), 0);
    do
    {
        printf("Masukkan pos anggaran: ");
        scanf(" %[^\n]", transaksiBaru.pos);
    } while(isPosAnggaranTransaksiValid(transaksiBaru.pos, dataPos, jumlahPos), 0);
    
    do
    {
        printf("Masukkan jenis transaksi (Pemasukan/Pengeluaran): ");
        scanf(" %[^\n]", transaksiBaru.jenis);
    } while (isJenisTransaksiValid(transaksiBaru.jenis), 0);
    do
    {
        printf("Masukkan nominal transaksi: ");
        scanf("%d", &transaksiBaru.nominal);
    } while (isNominalTransaksiValid(&transaksiBaru.nominal), 0);
    printf("Masukkan deskripsi transaksi: ");
    scanf(" %[^\n]", transaksiBaru.deskripsi);

    generateId(*jumlahTransaksi + 1, transaksiBaru.id); //menghasilkan ID unik untuk transaksi baru
    // valid = validasiTransaksi(transaksiBaru, dataPos, jumlahPos); //memvalidasi data transaksi baru
    //Jika data valid, tambahkan ke file dan array
    if (1){ //ubah kembali ke valid jika fungsi validasi diaktifkan 
        appendDataTransaksi(transaksiBaru);
        dataTransaksi[*jumlahTransaksi] = transaksiBaru;
        (*jumlahTransaksi)++;
    }
}