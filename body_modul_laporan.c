int hitungTotalPemasukan(Transaksi dataTransaksi[], int jumlahTransaksi){
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (strcmp(dataTransaksi[i].jenis, "Pemasukan") == 0) {
            total += dataTransaksi[i].nominal;
        }
    }
    return total;
}

int hitungTotalPengeluaran(Transaksi dataTransaksi[], int jumlahTransaksi){
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (strcmp(dataTransaksi[i].jenis, "Pengeluaran") == 0) {
            total += dataTransaksi[i].nominal;
        }
    }
    return total;
}

int hitungSaldoAkhir(int totalPemasukan, int totalPengeluaran){
    return totalPemasukan - totalPengeluaran;
}

int avgPengeluaran(int totalPengeluaran, Transaksi dataTransaksi[], int jumlahTransaksi){

}

// int hitungJumlahTransaksi(char kriteria[],Transaksi dataTransaksi[], int jumlahTransaksi){
//     int jumlah = 0;
//     for (int i = 0; i < jumlahTransaksi; i++) {
//         if (strcmp(dataTransaksi[i].jenis, "Pengeluaran") == 0) {
//             jumlah++;
//         }
//     }
//     return jumlah;
// }

// void hitungRealisasi(Transaksi dataTransaksi[], int jumlahTransaksi,PosAnggaran dataPos[], int jumlahPos,int jumlahTransaksiPerPos[]) {
//     // Reset realisasi
//     for (int i = 0; i < jumlahPos; i++) {
//         dataPos[i].totalTerpakai = 0;
//         jumlahTransaksiPerPos[i] = 0;
//     }

//     // Hitung per pos
//     for (int i = 0; i < jumlahTransaksi; i++) {
//         if (strcmp(dataTransaksi[i].jenis, "Pengeluaran") == 0) {
//             for (int j = 0; j < jumlahPos; j++) {
//                 if (strcmp(dataTransaksi[i].pos, dataPos[j].namaPos) == 0) {
//                     dataPos[j].totalTerpakai += dataTransaksi[i].nominal;
//                     jumlahTransaksiPerPos[j]++;
//                     break;
//                 }
//             }
//         }
//     }
// }

// void kondisiKeuangan(int saldoAkhir) {
//     printf("Kondisi Keuangan : ");
//     if (saldoAkhir < 0)
//         printf("Defisit (Pengeluaran lebih besar dari pemasukan)\n");
//     else if (saldoAkhir == 0)
//         printf("Seimbang (Tidak ada sisa uang)\n");
//     else
//         printf("Surplus (Masih memiliki sisa uang)\n");
// }

// void kesimpulanKeuangan(PosAnggaran dataPos[], int jumlahPos, int saldoAkhir) {
//     int adaMelebihi = 0;

//     for (int i = 0; i < jumlahPos; i++) {
//         if (dataPos[i].totalTerpakai > dataPos[i].batasNominal) {
//             adaMelebihi = 1;
//             break;
//         }
//     }

//     printf("\nKesimpulan : ");

//     if (adaMelebihi) {
//         printf("Beberapa pos anggaran melebihi batas yang ditentukan.\n");
//     } else {
//         printf("Semua pos anggaran masih dalam batas aman.\n");
//     }

//     if (saldoAkhir > 0) {
//         printf("               Keuangan berada dalam kondisi sangat sehat.\n");
//     } else if (saldoAkhir < 0) {
//         printf("               Keuangan mengalami defisit.\n");
//     }
// }



// yg belum ada: kondisiKeuangan(), kesimpulanKeuangan(), hitungRealisasi(), hitungJumlahTransaksi()