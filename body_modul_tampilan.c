void tampilMenu() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                 APLIKASI KEUANGAN MAHASISWA                 |\n");
    printf(" +=============================================================+\n");
    printf("  1. Tambah Pos Anggaran\n");
    printf("  2. Tambah Transaksi\n");
    printf("  3. Lihat Laporan Keuangan\n");
    printf("  0. Kembali ke Menu Utama\n");
    printf("_______________________________________________________________\n");
}

void tampilSubMenuPos() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                        SUB MENU POS                         |\n");
    printf(" +=============================================================+\n");
    printf("  1. Tambah Pos Anggaran\n");
    printf("  2. Tampilkan Daftar Pos\n");
    printf("  0. Kembali ke Menu Utama\n");
    printf("_______________________________________________________________\n");

}

void tampilSubMenuTransaksi() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                    SUB MENU TRANSAKSI                       |\n");
    printf(" +=============================================================+\n");
    printf("  1. Tambah Transaksi\n");
    printf("  2. Tampilkan Daftar Transaksi\n");
    printf("  0. Kembali ke Menu Utama\n");
    printf("_______________________________________________________________\n");
}

void tampilSubMenuDaftarTransaksi(){
    /* Deskripsi Program */
    printf(" +=============================================================+\n");
    printf(" |                    MENU DAFTAR TRANSAKSI                    |\n");
    printf(" +=============================================================+\n");
    printf("1. Semua\n");
    printf("2. Pemasukan\n");
    printf("3. Pengeluaran\n");
    printf("0. Kembali ke Menu Transaksi\n");
    printf("_______________________________________________________________\n");
}

void tampilDaftarTransaksi(Transaksi dataTransaksi[], int jumlahTransaksi, char* filter){
    /* Deklarasi Variabel */
    int index;
    
    /* Deskripsi Program */
    printf("\n=== DAFTAR TRANSAKSI (%s) ===\n", filter);
    if (jumlahTransaksi == 0) {
        printf("Belum ada data transaksi.\n");
        return;
    }
    printf("ID\tTanggal\t\tPos Anggaran\tJenis\t\tNominal\t\tDeskripsi\n");
    printf("-----------------------------------------------------------------------------------------\n");
    // menampilkan transaksi sesuai filter
    for(index = 0; index < jumlahTransaksi; index++) {
        
        // Cek kondisi filter
        if (
            // 1. Jika filter adalah "semua" atau "Semua"
            (strcmp(filter, "semua") == 0 || strcmp(filter, "Semua") == 0) ||

            // 2. Logika PEMASUKAN (Input user Pemasukan/pemasukan DAN Data Pemasukan/pemasukan)
            (
                (strcmp(filter, "pemasukan") == 0 || strcmp(filter, "Pemasukan") == 0) && 
                (strcmp(dataTransaksi[index].jenis, "Pemasukan") == 0 || strcmp(dataTransaksi[index].jenis, "pemasukan") == 0)
            ) ||

            // 3. Logika PENGELUARAN (Input user Pengeluaran/pengeluaran DAN Data Pengeluaran/pengeluaran)
            (
                (strcmp(filter, "pengeluaran") == 0 || strcmp(filter, "Pengeluaran") == 0) && 
                (strcmp(dataTransaksi[index].jenis, "Pengeluaran") == 0 || strcmp(dataTransaksi[index].jenis, "pengeluaran") == 0)
            )
        ) {
            // Menampilkan data transaksi jika salah satu kondisi di atas terpenuhi
            printf("%s\t%s\t%s\t\t%s\t%d\t\t%s\n", 
                dataTransaksi[index].id, 
                dataTransaksi[index].tanggal, 
                dataTransaksi[index].pos, 
                dataTransaksi[index].jenis, 
                dataTransaksi[index].nominal, 
                dataTransaksi[index].deskripsi);
        }
    }
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
        printf("|%-5d|%-10s|%-25s|%15d\n",
               i + 1,
               dataPos[i].id,
               dataPos[i].namaPos,
               dataPos[i].batasNominal);
    }
}



void tampilRingkasanKeuangan(int totalPemasukan, int totalPengeluaran, int saldoAkhir, float rataRata, int jumlahPemasukan, int jumlahPengeluaran) {
    printf("Total Pemasukan  (%d Transaksi)     : Rp %d\n", jumlahPemasukan, totalPemasukan);
    printf("Total Pengeluaran (%d Transaksi)    : Rp %d\n", jumlahPengeluaran, totalPengeluaran);
    printf("Saldo Akhir                         : Rp %d\n", saldoAkhir);
    printf("Rata-rata Pengeluaran               : Rp %.3f\n\n", rataRata);
}

void tampilTabelPosAnggaran(PosAnggaran dataPos[], int jumlahPos, int jumlahTransaksiPerPos[]) {
    printf("POS ANGGARAN\n\n");
    printf("%-15s | %-12s | %-14s | %-12s | %-17s | %-10s\n",
            "Pos", "Batas (Rp)", "Realisasi (Rp)", "Sisa (Rp)", "Jumlah Transaksi", "Status");
    printf("----------------------------------------------------------------------\n");
    
    for (int i = 0; i < jumlahPos; i++) {
        int sisa = dataPos[i].batasNominal - dataPos[i].totalTerpakai;
        char status[10];
        
        if (dataPos[i].totalTerpakai > dataPos[i].batasNominal) {
            strcpy(status, "Melebihi");
        } else {
            strcpy(status, "Aman");
        }
        
        printf("%-15s | %-12d | %-14d | %-12d | %-17d | %-10s\n",
            dataPos[i].namaPos,
            dataPos[i].batasNominal,
            dataPos[i].totalTerpakai,
            sisa,
            jumlahTransaksiPerPos[i],
            status);
    }
    
    printf("----------------------------------------------------------------------\n\n");
}

void kondisiKeuangan(int saldoAkhir) {
    printf("Kondisi Keuangan : ");
    if (saldoAkhir < 0)
        printf("Defisit (Pengeluaran lebih besar dari total pemasukan)\n");
    else if (saldoAkhir == 0)
        printf("Seimbang (Tanpa sisa uang)\n");
    else
        printf("Surplus (Masih memiliki sisa uang)\n");
}

void kesimpulanKeuangan(PosAnggaran dataPos[], int totalPemasukan, int totalPengeluaran) {
    float persentase = ((float)(totalPemasukan - totalPengeluaran) / totalPemasukan) * 100;

    printf("\nKesimpulan       : ");

    if (persentase > 25) {
        printf("Anda termasuk mahasiswa hemat dan produktif.\n");
        printf("                   Pengeluaran masih jauh di bawah batas anggaran.\n");    
    }
    else if (persentase > 0) {  
        printf("Keuangan Anda seimbang,\n");
        printf("                   tetap waspada terhadap pengeluaran tidak perlu.\n"); 
    }
    else if (persentase > -10) { 
        printf("Anda mulai boros, \n");
        printf("                   perhatikan pengeluaran harian.\n"); 
    }
    else {  
        printf("Kondisi keuangan kurang sehat.\n");
        printf("                   Kurangi pengeluaran dan cari tambahan pemasukan.\n"); 
    }
}

void tampilLaporanKeuangan(Transaksi dataTransaksi[], int jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos) {
    
    // Hitung semua data menggunakan fungsi modular
    int totalPemasukan = hitungTotalPemasukan(dataTransaksi, jumlahTransaksi);
    int totalPengeluaran = hitungTotalPengeluaran(dataTransaksi, jumlahTransaksi);
    int saldoAkhir = hitungSaldoAkhir(totalPemasukan, totalPengeluaran);
    float rataRataPengeluaran = avgPengeluaran(totalPengeluaran, dataTransaksi, jumlahTransaksi);
    
    int jumlahPemasukan = hitungJumlahTransaksi("Pemasukan", dataTransaksi, jumlahTransaksi);
    int jumlahPengeluaran = hitungJumlahTransaksi("Pengeluaran", dataTransaksi, jumlahTransaksi);
    
    // Hitung realisasi per pos
    int jumlahTransaksiPerPos[50] = {0};
    hitungRealisasi(dataTransaksi, jumlahTransaksi, dataPos, jumlahPos, jumlahTransaksiPerPos);
    
    // Tampilkan laporan
    printf("\n");
    printf("=============== LAPORAN KEUANGAN BULAN NOVEMBER 2025 ================\n\n");
    
    // Ringkasan Keuangan
    tampilRingkasanKeuangan(totalPemasukan, totalPengeluaran, saldoAkhir, rataRataPengeluaran, jumlahPemasukan, jumlahPengeluaran);
    
    printf("----------------------------------------------------------------------\n\n");
    
    // Tabel Pos Anggaran
    tampilTabelPosAnggaran(dataPos, jumlahPos, jumlahTransaksiPerPos);
    
    // Kondisi dan Kesimpulan
    kondisiKeuangan(saldoAkhir);
    kesimpulanKeuangan(dataPos, totalPemasukan, totalPengeluaran);
    
    printf("\n======================================================================\n");
}

