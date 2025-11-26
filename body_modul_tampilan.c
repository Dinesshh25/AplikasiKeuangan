void tampilMenu() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                 APLIKASI KEUANGAN MAHASISWA                 |\n");
    printf(" +=============================================================+\n");
    printf("  1. Tambah Pos Anggaran\n");
    printf("  2. Tambah Transaksi\n");
    printf("  3. Lihat Laporan Keuangan\n");
    printf("  0. Kembali ke Menu Utama\n");
    printf("_________________________________________\n");
}

void tampilSubMenuPos() {
    printf("\n");
    printf(" +=============================================================+\n");
    printf(" |                        SUB MENU POS                         |\n");
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
        printf("|%-5d|%-10s|%-25s|%15d\n",
               i + 1,
               dataPos[i].id,
               dataPos[i].namaPos,
               dataPos[i].batasNominal);
    }
}


void tampilLaporanKeuangan(Transaksi dataTransaksi[], int jumlahTransaksi, 
                           PosAnggaran dataPos[], int jumlahPos) {
    
    int totalPemasukan = 0;
    int totalPengeluaran = 0;
    int saldoAkhir = 0;
    float rataRataPengeluaran = 0;
    int jumlahTransaksiPengeluaran = 0;
    
    // Hitung total pemasukan dan pengeluaran dari transaksi
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (strcmp(dataTransaksi[i].jenis, "Pemasukan") == 0) {
            totalPemasukan += dataTransaksi[i].nominal;
        } else if (strcmp(dataTransaksi[i].jenis, "Pengeluaran") == 0) {
            totalPengeluaran += dataTransaksi[i].nominal;
            jumlahTransaksiPengeluaran++;
        }
    }
    
    // Hitung saldo akhir
    saldoAkhir = totalPemasukan - totalPengeluaran;
    
    // Hitung rata-rata pengeluaran
    if (jumlahTransaksiPengeluaran > 0) {
        rataRataPengeluaran = (float)totalPengeluaran / jumlahTransaksiPengeluaran;
    }
    
    // Update realisasi dan jumlah transaksi per pos
    for (int i = 0; i < jumlahPos; i++) {
        dataPos[i].totalTerpakai = 0; // Reset dulu
    }
    
    // Hitung realisasi per pos dari transaksi
    int jumlahTransaksiPerPos[50] = {0}; // Counter transaksi per pos
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (strcmp(dataTransaksi[i].jenis, "Pengeluaran") == 0) {
            for (int j = 0; j < jumlahPos; j++) {
                if (strcmp(dataTransaksi[i].pos, dataPos[j].id) == 0) {
                    dataPos[j].totalTerpakai += dataTransaksi[i].nominal;
                    jumlahTransaksiPerPos[j]++;
                    break;
                }
            }
        }
    }
    
    // Tampilkan laporan
    printf("\n");
    printf("=============== LAPORAN KEUANGAN BULAN NOVEMBER 2025 ================\n\n");
    
    // Ringkasan Keuangan
    printf("Total Pemasukan  (%d Transaksi)     : Rp %d\n", 
           jumlahTransaksi - jumlahTransaksiPengeluaran, totalPemasukan);
    printf("Total Pengeluaran (%d Transaksi)    : Rp %d\n", 
           jumlahTransaksiPengeluaran, totalPengeluaran);
    printf("Saldo Akhir                         : Rp %d\n", saldoAkhir);
    printf("Rata-rata Pengeluaran               : Rp %.3f\n\n", rataRataPengeluaran);
    
    printf("----------------------------------------------------------------------\n\n");
    
    // Tabel Pos Anggaran
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
    
    // Kondisi Keuangan
    printf("Kondisi Keuangan : ");
    if (saldoAkhir < 0) {
        printf("Defisit (Pengeluaran lebih besar dari total pemasukan)\n");
    } else if (saldoAkhir == 0) {
        printf("Seimbang (Tanpa sisa uang)\n");
    } else {
        printf("Surplus (Masih memiliki sisa uang)\n");
    }
    
    printf("\nKesimpulan       : ");
    
    // Cek apakah ada pos yang melebihi batas
    int adaMelebihi = 0;
    for (int i = 0; i < jumlahPos; i++) {
        if (dataPos[i].totalTerpakai > dataPos[i].batasNominal) {
            adaMelebihi = 1;
            break;
        }
    }
    
    if (adaMelebihi) {
        printf("Anda termasuk mahasiswa hemat dan produktif.\n");
        printf("                   Pengeluaran masih jauh di bawah batas anggaran.\n");
    } else {
        printf("Anda termasuk mahasiswa hemat dan produktif.\n");
        printf("                   Pengeluaran masih jauh di bawah batas anggaran.\n");
    }
    
    if (saldoAkhir > 0) {
        printf("                   Kondisi keuangan bulan ini sangat sehat.\n");
    } else if (saldoAkhir < 0) {
        printf("                   Kondisi keuangan bulan ini defisit.\n");
    }
    
    printf("\n======================================================================\n");
}