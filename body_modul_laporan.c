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

int hitungJumlahTransaksi(char kriteria[], Transaksi dataTransaksi[], int jumlahTransaksi){
    int jumlah = 0;
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (strcmp(dataTransaksi[i].jenis, kriteria) == 0) {
            jumlah++;
        }
    }
    return jumlah;
}

float avgPengeluaran(int totalPengeluaran, Transaksi dataTransaksi[], int jumlahTransaksi){
    int jumlahPengeluaran = hitungJumlahTransaksi("Pengeluaran", dataTransaksi, jumlahTransaksi);
    
    if (jumlahPengeluaran > 0) {
        return (float)totalPengeluaran / jumlahPengeluaran;
    }
    return 0;
}


void hitungRealisasi(Transaksi dataTransaksi[], int jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos, int jumlahTransaksiPerPos[]) {
    // Reset realisasi
    for (int i = 0; i < jumlahPos; i++) {
        dataPos[i].totalTerpakai = 0;
        jumlahTransaksiPerPos[i] = 0;
    }

    // Hitung per pos berdasarkan ID pos
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (strcmp(dataTransaksi[i].jenis, "Pengeluaran") == 0) {
            for (int j = 0; j < jumlahPos; j++) {
                // Bandingkan ID pos di transaksi dengan ID pos di dataPos
                if (strcmp(dataTransaksi[i].pos, dataPos[j].namaPos) == 0) {
                    dataPos[j].totalTerpakai += dataTransaksi[i].nominal;
                    jumlahTransaksiPerPos[j]++;
                    break;
                }
            }
        }
    }
}