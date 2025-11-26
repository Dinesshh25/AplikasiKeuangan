void tampilMenu(){
    /* Deskripsi Program */
    printf("\n=== Aplikasi Keuangan Mahasiswa ===\n");
    printf("Menu Utama:\n");
    printf("1. Pos Anggaran\n");
    printf("2. Transaksi\n");
    printf("3. Laporan Keuangan\n");
    printf("0. Keluar\n");
    printf("=====================================\n");
}

void tampilSubMenuTransaksi(){
    /* Deskripsi Program */
    printf("\n--- Transaksi Keuangan ---\n");
    printf("1. Tambah Pemasukan\n");
    printf("2. Tambah Pengeluaran\n");
    printf("3. Lihat Daftar Transaksi\n");
    printf("0. Kembali ke Menu Utama\n");
    printf("-------------------------\n");
}

void tampilSubMenuDaftarTransaksi(){
    /* Deskripsi Program */
    printf("\n--- Daftar Transaksi ---\n");
    printf("1. Semua\n");
    printf("2. Pemasukan\n");
    printf("3. Pengeluaran\n");
    printf("0. Kembali ke Menu Transaksi\n");
    printf("-------------------------\n");
}

void tampilDaftarTransaksi(Transaksi dataTransaksi[], int jumlahTransaksi, char* filter){
    /* Deklarasi Variabel */
    int index;
    
    /* Deskripsi Program */
    printf("\n--- Daftar Transaksi (%s) ---\n", filter);
    printf("ID\tTanggal\t\tPos Anggaran\tJenis\t\tNominal\tDeskripsi\n");
    printf("--------------------------------------------------------------------------\n");
    // menampilkan transaksi sesuai filter
    for(index = 0; index < jumlahTransaksi; index++) {
        // cek filter dan tampilkan transaksi yang sesuai
        if(strcmp(filter, "semua") == 0 ||
            (strcmp(filter, "pemasukan") == 0 && (strcmp(dataTransaksi[index].jenis, "Pemasukan") == 0 || strcmp(dataTransaksi[index].jenis, "pemasukan") == 0)) ||
            (strcmp(filter, "pengeluaran") == 0 && (strcmp(dataTransaksi[index].jenis, "Pengeluaran") == 0 || strcmp(dataTransaksi[index].jenis, "pengeluaran") == 0))) {
            // menampilkan data transaksi
            printf("%s\t%s\t%s\t%s\t%d\t%s\n", 
                dataTransaksi[index].id, 
                dataTransaksi[index].tanggal, 
                dataTransaksi[index].pos, 
                dataTransaksi[index].jenis, 
                dataTransaksi[index].nominal, 
                dataTransaksi[index].deskripsi);
        }
    }
}

void tampilRekapitulasi(int totalPemasukan, int totalPengeluaran, int saldoAkhir, int avgPengeluaran){
    /* Deskripsi Program */
    printf("Total Pemasukan   : %d\n", totalPemasukan);
    printf("Total Pengeluaran : %d\n", totalPengeluaran);
    printf("Saldo Akhir       : %d\n", saldoAkhir);
    printf("Rata-rata Pengeluaran : %d\n", avgPengeluaran);
}

void tampilLaporanPos(PosAnggaran dataPos[], int jumlahPos, Transaksi dataTransaksi[], int jumlahTransaksi){

}

void tampilLaporanKeuangan(Transaksi dataTransaksi[], int jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos){

}void tampilMenu() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                 APLIKASI KEUANGAN MAHASISWA                 |\n");
    printf(" +=============================================================+\n");
    printf("  1. Tambah Pos Anggaran\n");
    printf("  2. Tambah Transaksi\n");
    printf("  3. Tambah Transaksi\n");
    printf("  0. Kembali ke Menu Utama\n");
    printf("_________________________________________\n");
}

void tampilSubMenuPos() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                          SUB MENU POS                       |\n");
    printf(" +=============================================================+\n");
    printf("  1. Tambah Pos Anggaran\n");
    printf("  2. Tampilkan Daftar Pos\n");
    printf("  0. Kembali ke Menu Utama\n");
    printf("__________________________________________\n");

}

void tampilSubMenuTransaksi() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                    SUB MENU TRANSAKSI                       |\n");
    printf(" +=============================================================+\n");
    printf("  1. Tambah Transaksi\n");
    printf("  2. Tampilkan Daftar Transaksi\n");
    printf("  0. Kembali ke Menu Utama\n");
    printf("__________________________________________\n");
}

void tampilDaftarPos(PosAnggaran dataPos[], int jumlahPos) {
    printf("\n=== DAFTAR POS ANGGARAN ===\n");

    if (jumlahPos == 0) {
        printf("Belum ada data pos anggaran.\n");
        return;
    }

    // Header
    printf("\n%-5s %-10s %-25s %15s\n",
           "|No", "|ID", "|Pos", "|Batas Nominal (Rp)");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahPos; i++) {
        printf("|%-5d |%-10s |%-25s |%15d\n",
               i + 1,
               dataPos[i].id,
               dataPos[i].namaPos,
               dataPos[i].batasNominal);
    }
}


void tampilLaporan(){
    printf("Halo");
};