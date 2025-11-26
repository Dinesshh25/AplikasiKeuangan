void tampilMenu() {
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