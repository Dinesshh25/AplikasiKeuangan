int hitungTotalPemasukan(Transaksi dataTransaksi[], int jumlahTransaksi){
    /* Deklarasi Variabel */
    int totalPemasukan = 0;
    int index;

    /* Deskripsi Program */
    // menghitung total pemasukan
    for (index = 0; index < jumlahTransaksi; index++){
        if (strcmp(dataTransaksi[index].jenis, "Pemasukan") == 0 || strcmp(dataTransaksi[index].jenis, "pemasukan") == 0){
            totalPemasukan += dataTransaksi[index].nominal; //menambahkan nominal ke total pemasukan
        }
    }
    return totalPemasukan; //mengembalikan total pemasukan
}

int hitungTotalPengeluaran(Transaksi dataTransaksi[], int jumlahTransaksi){
    /* Deklarasi Variabel */
    int totalPengeluaran = 0;
    int index;

    /* Deskripsi Program */
    // menghitung total pengeluaran
    for (index = 0; index < jumlahTransaksi; index++){
        if (strcmp(dataTransaksi[index].jenis, "Pengeluaran") == 0 || strcmp(dataTransaksi[index].jenis, "pengeluaran") == 0){
            totalPengeluaran += dataTransaksi[index].nominal; //menambahkan nominal ke total pengeluaran
        }
    }
    return totalPengeluaran; //mengembalikan total pengeluaran
}

int hitungSaldoAKhir(int totalPemasukan, int totalPengeluaran){
    /* Deskripsi Program */
    return totalPemasukan - totalPengeluaran; //menghitung dan mengembalikan saldo akhir
}

int avgPengeluaran(int totalPengeluaran, Transaksi dataTransaksi[], int jumlahTransaksi){
    /* Deklarasi Variabel */
    int countPengeluaran = 0;
    int index;

    /* Deskripsi Program */
    // menghitung rata-rata pengeluaran
    for (index = 0; index < jumlahTransaksi; index++){
        if (strcmp(dataTransaksi[index].jenis, "Pengeluaran") == 0 || strcmp(dataTransaksi[index].jenis, "pengeluaran") == 0){
            countPengeluaran++; //menghitung jumlah transaksi pengeluaran
        }
    }   
    return totalPengeluaran / countPengeluaran; //menghitung dan mengembalikan rata-rata pengeluaran
}

// yg belum ada: kondisiKeuangan(), kesimpulanKeuangan(), hitungRealisasi(), hitungJumlahTransaksi()