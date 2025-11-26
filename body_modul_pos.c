/* ========================================
   FILE: pos_anggaran.c
   Implementasi fungsi modul pos anggaran
   (Dengan load dari file dan ID otomatis)
   ======================================== */

#include <stdio.h>
#include <string.h>
// Fungsi helper untuk menyimpan data ke file
void simpanDataPosKeFile(PosAnggaran dataPos[], int jumlahPos) {
    FILE *file = fopen("pos_anggaran.txt", "w");
    if (file == NULL) {
        printf("[!] ERROR: Gagal menyimpan data ke file!\n");
        return;
    }
    
    // Tulis header
    fprintf(file, "ID|Pos|Batas Nominal (Rp)\n");
    
    // Tulis semua data
    for (int i = 0; i < jumlahPos; i++) {
        fprintf(file, "%s|%s|%d\n", 
                dataPos[i].id,
                dataPos[i].namaPos, 
                dataPos[i].batasNominal);
    }
    
    fclose(file);
}

// Fungsi helper untuk generate ID baru (format string)
void generateIDPos(char idBaru[], PosAnggaran dataPos[], int jumlahPos) {
    if (jumlahPos == 0) {
        strcpy(idBaru, "P001"); // ID pertama
        return;
    }
    
    // Cari nomor ID terbesar
    int maxNum = 0;
    for (int i = 0; i < jumlahPos; i++) {
        // Ambil angka dari ID (misal: "P001" -> 1)
        int num = atoi(&dataPos[i].id[1]); // Skip karakter 'P'
        if (num > maxNum) {
            maxNum = num;
        }
    }
    
    // Generate ID baru dengan format P001, P002, dst
    sprintf(idBaru, "P%03d", maxNum + 1);
}

void loadDataPos(PosAnggaran dataPos[], int *jumlahPos) {
    FILE *file = fopen("pos_anggaran.txt", "r");
    
    if (file == NULL) {
        // File belum ada, mulai dengan data kosong
        *jumlahPos = 0;
        printf("[i] File 'pos_anggaran.txt' belum ada. Memulai dengan data kosong.\n");
        return;
    }
    
    char buffer[200];
    *jumlahPos = 0;
    
    // Skip header (baris pertama)
    fgets(buffer, sizeof(buffer), file);
    
    // Baca data per baris
    while (fgets(buffer, sizeof(buffer), file) != NULL && *jumlahPos < 50) {
        PosAnggaran pos;
        char *token;
        
        // Parse ID
        token = strtok(buffer, "|");
        if (token != NULL) {
            strcpy(pos.id, token);
        }
        
        // Parse Nama Pos
        token = strtok(NULL, "|");
        if (token != NULL) {
            strcpy(pos.namaPos, token);
        }
        
        // Parse Batas Nominal
        token = strtok(NULL, "|");
        if (token != NULL) {
            pos.batasNominal = atoi(token);
        }
        
        pos.totalTerpakai = 0; // Default 0 saat load
        
        dataPos[*jumlahPos] = pos;
        (*jumlahPos)++;
    }
    
    fclose(file);
    printf("[✓] Berhasil memuat %d pos anggaran dari file.\n", *jumlahPos);
}

void appendDataPos(PosAnggaran dataPos[], int *jumlahPos) {
    PosAnggaran posBaru;
    int valid;
    
    printf("\n=== TAMBAH POS ANGGARAN ===\n");
    
    // Generate ID otomatis (dalam bentuk string)
    generateIDPos(posBaru.id, dataPos, *jumlahPos);
    printf("ID Pos (otomatis): %s\n", posBaru.id);
    
    // Input dan validasi nama pos
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
    
    // Tambahkan ke array
    dataPos[*jumlahPos] = posBaru;
    (*jumlahPos)++;
    
    printf("\n[✓] Pos anggaran berhasil ditambahkan!\n");
    
    // Simpan ke file
    simpanDataPosKeFile(dataPos, *jumlahPos);
    printf("[✓] Data tersimpan ke file 'pos_anggaran.txt'\n");
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