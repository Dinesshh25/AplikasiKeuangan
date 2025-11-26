


void appendDataPos(PosAnggaran dataPos[], int *jumlahPos) {
    PosAnggaran posBaru;
    int valid;
     do {
        valid = 1;
        printf("Masukkan Nama Pos: ");
        fflush(stdin);
        fgets(posBaru.namaPos, sizeof(posBaru.namaPos), stdin);
        posBaru.namaPos[strcspn(posBaru.namaPos, "\n")] = '\0';
        
        // Validasi: Nama tidak boleh sama
        for (int i = 0; i < *jumlahPos; i++) {
            if (strcmp(dataPos[i].namaPos, posBaru.namaPos) == 0) {
                printf("Nama pos '%s' sudah ada! Gunakan nama lain.\n\n", posBaru.namaPos);
                valid = 0;
                break;
            }
        }
    } while (!valid);
    
    // Input dan validasi batas nominal
    do {
        printf("Masukkan Batas Nominal (Rp): ");
        scanf("%d", &posBaru.batasNominal);
        
        // Validasi: Harus bilangan positif
        if (posBaru.batasNominal <= 0) {
            printf("Batas nominal harus bilangan positif (>0)!\n\n");
        }
    } while (posBaru.batasNominal <= 0);
    
    posBaru.totalTerpakai = 0;
    
    dataPos[*jumlahPos] = posBaru;
    (*jumlahPos)++;
    
    printf("\nPos anggaran berhasil ditambahkan!\n");
    
    // Simpan ke file
    FILE *file = fopen("pos_anggaran.txt", "w");
    if (file != NULL) {
        fprintf(file, "Pos|Batas Nominal (Rp)\n");
        for (int i = 0; i < *jumlahPos; i++) {
            fprintf(file, "%s|%d\n", dataPos[i].namaPos, dataPos[i].batasNominal);
        }
        fclose(file);
    }
}

void loadDataPos(PosAnggaran dataPos[], int *jumlahPos) {
    printf("\n=== DAFTAR POS ANGGARAN ===\n");
    
    if (*jumlahPos == 0) {
        printf("Belum ada data pos anggaran.\n");
        return;
    }
    
    printf("\n%-5s %-20s %-20s\n", "No", "Pos", "Batas Nominal (Rp)");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < *jumlahPos; i++) {
        printf("%-5d %-20s %d\n",
               i + 1,
               dataPos[i].namaPos,
               dataPos[i].batasNominal);
    }
}

int validasiPosAnggaran(PosAnggaran dataPos[], int jumlahPos, char namaPos[], int nominal) {
    for (int i = 0; i < jumlahPos; i++) {
        if (strcmp(dataPos[i].namaPos, namaPos) == 0) {
            if (dataPos[i].totalTerpakai + nominal > dataPos[i].batasNominal) {
                printf("\nPERINGATAN: Pengeluaran melebihi batas anggaran '%s'!\n", namaPos);
                return 1; // Melebihi batas
            }
            return 0; // Masih dalam batas
        }
    }
    return 0;
}