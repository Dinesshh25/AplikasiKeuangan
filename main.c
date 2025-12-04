#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*
    Struktur Data Aplikasi Keuangan Mahasiswa
    PosAnggaran: Menyimpan informasi tentang pos anggaran seperti nama pos dan batas nominal.
    Transaksi: Menyimpan informasi tentang transaksi keuangan termasuk pemasukan dan pengeluaran seperti ID, tanggal, pos anggaran, nominal, jenis, dan deskripsi.
*/
typedef struct {
    char id[10];
    char namaPos[50];
    long long batasNominal;
    int totalTerpakai;
} PosAnggaran;

typedef struct {
    char id[10];
    char tanggal[11];
    char pos[50];
    char jenis[20];
    int nominal;
    char deskripsi[100];
} Transaksi;


/*
    Include Body Modul
*/
#include "body_modul_pos.c"
#include "body_modul_transaksi.c"
#include "body_modul_laporan.c"
#include "body_modul_tampilan.c"



/* 
   HEADER MODUL APLIKASI KEUANGAN
 */

/* ========================================
   MODUL TAMPILAN
   ======================================== */

void tampilMenu();
/* Procedure bertujuan untuk menampilkan menu utama aplikasi keuangan mahasiswa ke layar
   I.S. : Program dijalankan
   F.S. : Menu utama aplikasi keuangan mahasiswa ditampilkan ke layar
          (1. tambah pos, 2. tambah transaksi, 3. laporan, 0. keluar)
*/

int pilihMenu();
/* Function bertujuan untuk menerima input pilihan menu dari pengguna
   Input  : Pilihan menu dari pengguna (integer)
   Output : Pilihan menu yang dipilih pengguna
*/

void tampilSubMenuTransaksi();
/*
    Procedure bertujuan untuk menampilkan submenu transaksi aplikasi keuangan mahasiswa ke layar.
    I. S. : Menu utama ditampilkan, dan pengguna memilih menu transaksi
    F. S. : Submenu transaksi aplikasi keuangan mahasiswa ditampilkan ke layar.
            (1. tambah pemasukan, 2. tambah pengeluaran, 3. lihat daftar transaksi, 0. kembali)  
*/

void tampilSubMenuPos();
/* Procedure bertujuan untuk menampilkan submenu pos anggaran ke layar
   I.S. : Menu utama ditampilkan dan pengguna memilih menu pos anggaran
   F.S. : Submenu pos anggaran ditampilkan ke layar
          (1. Tambah Pos Anggaran, 2. Tampilkan Daftar Pos, 0. Kembali)
*/

/* ========================================
   MODUL TRANSAKSI
   ======================================== */

void tampilSubMenuPos();
/* Procedure bertujuan untuk menampilkan submenu pos anggaran ke layar
   I.S. : Menu utama ditampilkan dan pengguna memilih menu pos anggaran
   F.S. : Submenu pos anggaran ditampilkan ke layar
          (1. Tambah Pos Anggaran, 2. Tampilkan Daftar Pos, 0. Kembali)
*/

/* ========================================
   MODUL TRANSAKSI
   ======================================== */

void loadDataTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi);
/*
    Procedure bertujuan untuk memuat data transaksi dari file data_transaksi ke dalam array dataTransaksi.
    I. S. : dataTransaksi kosong, jumlahTransaksi = 0.
    F. S. : dataTransaksi terisi, jumlahTransaksi diperbarui.
*/

void appendDataTransaksi(Transaksi transaksiBaru);
/*
    Procedure bertujuan untuk menambahkan data transaksi baru ke dalam file data_transaksi.
    I. S. : Data transaksi baru telah divalidasi dan siap untuk disimpan, file data_transaksi memiliki N baris.
    F. S. : Data transaksi baru ditambahkan ke dalam file data_transaksi sebagai baris ke N+1.
*/

void tambahTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos);
/*
    Procedure bertujuan untuk menambahkan data transaksi ke dalam array dataTransaksi.
    I. S. : Pengguna memilih untuk menambah transaksi
    F. S. : dataTransaksi dan jumlahTransaksi bertambah 1 jika data valid dan data ditambahkan ke dalam file data_transaksi.
*/

int isJenisTransaksiValid(char *jenisTransaksi);
/*
    Function bertujuan untuk memvalidasi jenis transaksi yang dimasukkan oleh pengguna.
    Input : jenisTransaksi (string yang berisi jenis transaksi yang dimasukkan oleh pengguna)
    Output : Mengembalikan 1 jika jenis transaksi valid (Pemasukan/Pengeluaran), atau 0 jika tidak valid.
*/

int isNominalTransaksiValid(int *nominalTransaksi);
/*
    Function bertujuan untuk memvalidasi nominal transaksi yang dimasukkan oleh pengguna.
    Input : nominalTransaksi (pointer ke integer yang berisi nominal transaksi yang dimasukkan oleh pengguna)
    Output : Mengembalikan 1 jika nominal transaksi valid (lebih besar dari 0), atau 0 jika tidak valid.
*/

int isTanggalTransaksiValid(char *tanggalTransaksi);
/*
    Function bertujuan untuk memvalidasi tanggal transaksi yang dimasukkan oleh pengguna.
    Input : tanggalTransaksi (string yang berisi tanggal transaksi yang dimasukkan oleh pengguna)
    Output : Mengembalikan 1 jika tanggal transaksi valid (tidak kosong), atau 0 jika tidak valid.
*/

int isPosAnggaranTransaksiValid(char *posAnggaran, PosAnggaran dataPos[], int jumlahPos);
/*
    Function bertujuan untuk memvalidasi pos anggaran transaksi yang dimasukkan oleh pengguna.
    Input : posAnggaran (string yang berisi pos anggaran yang dimasukkan oleh pengguna), dataPos (array data pos anggaran), jumlahPos (jumlah pos anggaran yang ada)
    Output : Mengembalikan 1 jika pos anggaran valid (ada di dataPos), atau 0 jika tidak valid.
*/


void generateId(int jumlahTransaksi, char *bufferId);
/*
    Procedure bertujuan untuk menghasilkan ID unik untuk setiap transaksi berdasarkan jumlah transaksi yang ada.
    Input : jumlahTransaksi (jumlah transaksi yang ada)
    Output : bufferId (ID unik yang dihasilkan disimpan dalam bufferId)
*/


void tampilSubMenuDaftarTransaksi();
/*
    Procedure bertujuan untuk menampilkan submenu daftar transaksi aplikasi keuangan mahasiswa ke layar.
    I. S. : Submenu transaksi ditampilkan, dan pengguna memilih untuk melihat daftar transaksi
    F. S. : Submenu daftar transaksi aplikasi keuangan mahasiswa ditampilkan ke layar.
            (1. semua, 2. pemasukan, 3. pengeluaran, 0. kembali)  
*/

void tampilDaftarTransaksi(Transaksi dataTransaksi[], int jumlahTransaksi, char filter[]);
/*
    Procedure bertujuan untuk menampilkan daftar transaksi ke layar dengan opsi filter.
    I. S. : Data transaksi sudah ada, filter diberikan ("semua", "pemasukan", atau "pengeluaran")
    F. S. : Daftar transaksi ditampilkan ke layar sesuai dengan filter yang diberikan.
            Jika filter "semua", tampilkan semua transaksi.
            Jika filter "pemasukan", tampilkan hanya transaksi pemasukan.
            Jika filter "pengeluaran", tampilkan hanya transaksi pengeluaran.
*/

void tampilLaporanKeuangan(Transaksi dataTransaksi[], int jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos);
/*
    Procedure bertujuan untuk menampilkan laporan keuangan lengkap mulai dari rekapitulasi, pos anggaran, hingga kesimpulan kondisi keuangan.
    I. S. : Data transaksi dan pos sudah ada, pengguna memilih menu laporan keuangan di menu utama.
    F. S. : Laporan keuangan ditampilkan ke layar, termasuk total pemasukan, total pengeluaran, saldo akhir, rata-rata pengeluaran, data pos anggaran, status keuangan, dan kondisi keuangan.
*/

void tampilLaporanPos(PosAnggaran dataPos[], int jumlahPos, Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Procedure bertujuan untuk menampilkan tabel laporan pos anggaran beserta realisasi pengeluaran pada tampilan laporan keuangan.
    I. S. : Data pos anggaran dan data transaksi sudah ada, pengguna memilih untuk melihat laporan keuangan di menu utama.
    F. S. : Laporan pos anggaran ditampilkan ke layar, termasuk nama pos, batas nominal, realisasi, sisa anggaran, jumlah transaksi, dan status.
*/

void tampilRekapitulasi(int totalPemasukan, int totalPengeluaran, int saldoAkhir, int avgPengeluaran);
/*
    Procedure bertujuan untuk menampilkan rekapitulasi keuangan termasuk total pemasukan, total pengeluaran, saldo akhir, dan rata-rata pengeluaran pada bagian atas tampilan laporan keuangan.
    I. S. : Data rekapitulasi sudah dihitung, pengguna memilih untuk melihat laporan keuangan di menu utama.
    F. S. : Rekapitulasi keuangan ditampilkan ke layar termasuk jumlah transaksi pemasukan dan pengeluaran. 
*/

void appendDataTransaksi(Transaksi transaksiBaru);
/* Procedure bertujuan untuk menambahkan data transaksi baru ke dalam file
   I.S. : Data transaksi baru telah divalidasi dan siap disimpan, file memiliki N baris
   F.S. : Data transaksi baru ditambahkan ke file sebagai baris ke N+1
*/

void tambahTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos);
/* Procedure bertujuan untuk menambahkan data transaksi ke dalam array
   I.S. : Pengguna memilih untuk menambah transaksi
   F.S. : Jika data valid, transaksi ditambahkan ke array dan file, jumlahTransaksi bertambah 1
          Jika data tidak valid, transaksi tidak ditambahkan dan pesan error ditampilkan
*/

void generateId(int jumlahTransaksi, char *bufferId);
/* Procedure bertujuan untuk menghasilkan ID unik untuk transaksi baru
   I.S. : Jumlah transaksi saat ini diketahui
   F.S. : ID unik dengan format TXXX dihasilkan dan disimpan ke bufferId
*/

int validasiTransaksi(Transaksi transaksiBaru, PosAnggaran dataPos[], int jumlahPos);
/* Function bertujuan untuk memvalidasi data transaksi yang akan ditambahkan
   Input  : transaksiBaru (data transaksi baru), dataPos (array pos anggaran), jumlahPos (jumlah pos)
   Output : 1 jika data valid (jenis Pemasukan/Pengeluaran, nominal > 0, tanggal tidak kosong, 
            ID pos valid untuk pengeluaran), 0 jika tidak valid dengan pesan error
*/

/* ========================================
   MODUL POS ANGGARAN
   ======================================== */

void loadDataPos(PosAnggaran dataPos[], int *jumlahPos);
/* Procedure bertujuan untuk memuat data pos anggaran dari file ke dalam array
   I.S. : Array dataPos kosong, jumlahPos = 0
   F.S. : Jika file pos_anggaran.txt ada, data dimuat ke array dan jumlahPos diperbarui
          Jika file tidak ada, dimulai dengan data kosong
*/


int validasiPosAnggaran(PosAnggaran dataPos[], int jumlahPos, char namaPos[], int nominal);
/* Function bertujuan untuk memvalidasi apakah pengeluaran melebihi batas anggaran
   I. S. : Data pos anggaran sudah ada, kategori dan nominal pengeluaran diketahui
   F. S. : Return 1 jika melebihi batas, return 0 jika masih dalam batas
           Menampilkan peringatan jika melebihi batas 
*/

void generateId(int jumlahTransaksi, char *bufferId);
/* Procedure bertujuan untuk menghasilkan ID unik untuk transaksi baru
   I.S. : Jumlah transaksi saat ini diketahui
   F.S. : ID unik dengan format TXXX dihasilkan dan disimpan ke bufferId
*/

int validasiTransaksi(Transaksi transaksiBaru, PosAnggaran dataPos[], int jumlahPos);
/* Function bertujuan untuk memvalidasi data transaksi yang akan ditambahkan
   Input  : transaksiBaru (data transaksi baru), dataPos (array pos anggaran), jumlahPos (jumlah pos)
   Output : 1 jika data valid (jenis Pemasukan/Pengeluaran, nominal > 0, tanggal tidak kosong, 
            ID pos valid untuk pengeluaran), 0 jika tidak valid dengan pesan error
*/

/* ========================================
   MODUL POS ANGGARAN
   ======================================== */

void loadDataPos(PosAnggaran dataPos[], int *jumlahPos);
/* Procedure bertujuan untuk memuat data pos anggaran dari file ke dalam array
   I.S. : Array dataPos kosong, jumlahPos = 0
   F.S. : Jika file pos_anggaran.txt ada, data dimuat ke array dan jumlahPos diperbarui
          Jika file tidak ada, dimulai dengan data kosong
*/

void appendDataPos(PosAnggaran dataPos[], int *jumlahPos);
/* Procedure bertujuan untuk menambahkan pos anggaran baru
   I.S. : Array pos anggaran sudah dideklarasikan
   F.S. : Jika data valid, pos anggaran baru ditambahkan ke array dan file, jumlahPos bertambah 1
          Data otomatis disimpan ke file pos_anggaran.txt
*/

void tampilDaftarPos(PosAnggaran dataPos[], int jumlahPos);
/* Procedure bertujuan untuk menampilkan daftar semua pos anggaran ke layar
   I. S. : Data pos anggaran sudah ada
   F. S. : Daftar pos anggaran ditampilkan ke layar dengan informasi:
           - ID
           - Nama Pos
           - Batas Nominal (Rp)
*/ 

void generateIDPos(char idBaru[], PosAnggaran dataPos[], int jumlahPos);
/* Procedure bertujuan untuk menghasilkan ID unik untuk pos anggaran baru
   I.S. : Jumlah pos anggaran saat ini diketahui
   F.S. : ID unik dengan format P001, P002, dst dihasilkan dan disimpan ke idBaru
*/

int validasiNamaPos(PosAnggaran dataPos[], int jumlahPos, char nama[]);
/* Function bertujuan untuk memvalidasi nama pos anggaran agar tidak duplikat
   Input  : dataPos (array pos anggaran), jumlahPos (jumlah pos), nama (nama pos yang akan divalidasi)
   Output : 1 jika nama sudah ada (duplikat), 0 jika nama belum ada
*/

int validasiNominal(long long nominal);
/* Function bertujuan untuk memvalidasi batas nominal agar bilangan positif
   Input  : nominal (nilai yang akan divalidasi)
   Output : 1 jika valid (nominal > 0), 0 jika tidak valid (nominal <= 0)
*/

/* ========================================
   MODUL LAPORAN KEUANGAN
   ======================================== */

void tampilLaporanKeuangan(Transaksi dataTransaksi[], int jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos);
/* Procedure bertujuan untuk menampilkan laporan keuangan lengkap
   I.S. : Data transaksi dan pos anggaran sudah ada
   F.S. : Laporan keuangan ditampilkan ke layar dengan informasi:
          - Total Pemasukan
          - Total Pengeluaran
          - Saldo Akhir
          - Rata-rata Pengeluaran
          - Tabel Pos Anggaran (Batas, Realisasi, Sisa, Jumlah Transaksi, Status)
          - Kondisi Keuangan (Defisit/Seimbang/Surplus)
          - Kesimpulan
*/
int hitungJumlahTransaksi(char kriteria[], Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung jumlah transaksi (berapa kali transaksi) berdasarkan nama pos atau jenis pemasukan/pengeluaran.
    Input : kriteria (nama pos anggaran atau jenis transaksi), dataTransaksi (array data transaksi), jumlahTransaksi (jumlah transaksi yang ada)
    Output : Mengembalikan jumlah transaksi yang sesuai dengan nama pos atau jenisnya.1
*/

int hitungTotalPemasukan(Transaksi dataTransaksi[], int jumlahTransaksi);
/* Function bertujuan untuk menghitung total pemasukan dari semua transaksi
   Input  : dataTransaksi (array transaksi), jumlahTransaksi (jumlah transaksi)
   Output : Total nominal dari semua transaksi bertipe "Pemasukan"
*/

int hitungTotalPengeluaran(Transaksi dataTransaksi[], int jumlahTransaksi);
/* Function bertujuan untuk menghitung total pengeluaran dari semua transaksi
   Input  : dataTransaksi (array transaksi), jumlahTransaksi (jumlah transaksi)
   Output : Total nominal dari semua transaksi bertipe "Pengeluaran"
*/

int hitungSaldoAkhir(int totalPemasukan, int totalPengeluaran);
/* Function bertujuan untuk menghitung saldo akhir
   Input  : totalPemasukan (total pemasukan), totalPengeluaran (total pengeluaran)
   Output : Saldo akhir (totalPemasukan - totalPengeluaran)
*/

float avgPengeluaran(int totalPengeluaran, Transaksi dataTransaksi[], int jumlahTransaksi);
/* Function bertujuan untuk menghitung rata-rata pengeluaran per transaksi
   Input  : totalPengeluaran (total pengeluaran), dataTransaksi (array transaksi), 
            jumlahTransaksi (jumlah transaksi)
   Output : Rata-rata pengeluaran per transaksi pengeluaran
*/

int hitungJumlahTransaksi(char kriteria[], Transaksi dataTransaksi[], int jumlahTransaksi);
/* Function bertujuan untuk menghitung jumlah transaksi berdasarkan jenis
   Input  : kriteria (jenis transaksi: "Pemasukan"/"Pengeluaran"), 
            dataTransaksi (array transaksi), jumlahTransaksi (jumlah transaksi)
   Output : Jumlah transaksi yang sesuai dengan kriteria
*/

void hitungRealisasi(Transaksi dataTransaksi[], int jumlahTransaksi, PosAnggaran dataPos[], int jumlahPos, int jumlahTransaksiPerPos[]);
/* Procedure bertujuan untuk menghitung realisasi pengeluaran per pos anggaran
   I.S. : Data transaksi dan pos anggaran sudah ada
   F.S. : totalTerpakai dan jumlahTransaksiPerPos diperbarui untuk setiap pos
*/

void tampilRingkasanKeuangan(int totalPemasukan, int totalPengeluaran, int saldoAkhir, float rataRata, int jumlahPemasukan, int jumlahPengeluaran);
/* Procedure bertujuan untuk menampilkan ringkasan keuangan ke layar
   I.S. : Semua data perhitungan sudah selesai dihitung
   F.S. : Ringkasan keuangan ditampilkan ke layar (total pemasukan, pengeluaran, saldo, rata-rata)
*/

void tampilTabelPosAnggaran(PosAnggaran dataPos[], int jumlahPos, int jumlahTransaksiPerPos[]);
/* Procedure bertujuan untuk menampilkan tabel pos anggaran ke layar
   I.S. : Data pos anggaran dan jumlah transaksi per pos sudah dihitung
   F.S. : Tabel pos anggaran ditampilkan ke layar dengan informasi:
          Pos, Batas, Realisasi, Sisa, Jumlah Transaksi, Status
*/

void kondisiKeuangan(int saldoAkhir);
/* Procedure bertujuan untuk menampilkan kondisi keuangan ke layar
   I.S. : Saldo akhir sudah dihitung
   F.S. : Kondisi keuangan ditampilkan (Defisit/Seimbang/Surplus)
*/

void kesimpulanKeuangan(PosAnggaran dataPos[], int totalPemasukan, int totalPengeluaran);
/* Procedure bertujuan untuk menampilkan kesimpulan keuangan ke layar
   I.S. : Data pos anggaran dan saldo akhir sudah diketahui
   F.S. : Kesimpulan keuangan ditampilkan ke layar berdasarkan analisis kondisi
*/


int main() {
    /* Deklarasi Variabel */
    Transaksi dataTransaksi[100];
    PosAnggaran dataPos[50];
    int jumlahTransaksi = 0;
    int jumlahPos = 0;
    int pilihanMenu;
    int pilihanSubMenu; // Tambahan untuk sub menu
    char filter[10];

    /* Deskripsi Program */
    printf("Selamat datang di Aplikasi Keuangan\n");

    loadDataTransaksi(dataTransaksi, &jumlahTransaksi); //memuat data transaksi dari file
    loadDataPos(dataPos, &jumlahPos); //memuat data pos anggaran dari file

    //looping menu utama
    do
    {
        tampilMenu(); //menampilkan menu utama
        pilihanMenu = pilihMenu(); //memilih menu utama

        //menjalankan menu utama, memutuskan fungsi berdasarkan pilihan menu
        switch (pilihanMenu){
            case 1:
                do {
                    tampilSubMenuPos(); // Tampilkan sub menu pos
                    printf("Masukkan pilihan: ");
                    scanf("%d", &pilihanSubMenu);
                    
                    switch(pilihanSubMenu) {
                        case 1:
                            appendDataPos(dataPos, &jumlahPos);
                            getch();
                            break;
                        case 2:
                            tampilDaftarPos(dataPos,jumlahPos);
                            printf("Tekan sembarang tombol untuk kembali ke menu pos...");
                            getch();
                            break;
                        case 0:
                            printf("\nKembali ke menu utama...\n");
                            break;
                        default:
                            printf("Pilihan tidak valid. Silakan coba lagi.\n");
                            break;
                    }
                } while(pilihanSubMenu != 0); // Loop sampai pilih 0 (kembali)
                break;
                
            case 2:
                do {
                    tampilSubMenuTransaksi();
                    printf("Masukkan pilihan: ");
                    scanf("%d", &pilihanSubMenu);

                    switch (pilihanSubMenu){
                    case 1:
                        tambahTransaksi(dataTransaksi,&jumlahTransaksi,dataPos, jumlahPos);    
                        printf("Tekan sembarang tombol untuk kembali ke menu transaksi...");
                        getch();
                        break;
                    case 2:
                        tampilSubMenuDaftarTransaksi();
                        printf("Masukkan pilihan (contoh: semua, pemasukan, pengeluaran): ");
                        scanf("%s", filter);
                        tampilDaftarTransaksi(dataTransaksi,jumlahTransaksi,filter);
                        printf("Tekan sembarang tombol untuk kembali ke menu transaksi...");
                        getch();
                        break;
                    case 0:
                        printf("\nKembali ke menu utama...\n");
                        break;
                    default:
                        printf("Pilihan tidak valid. Silakan coba lagi.\n");
                        break;
                    }
                } while (pilihanSubMenu != 0);
                
                break;
                
            case 3:
                tampilLaporanKeuangan(dataTransaksi,jumlahTransaksi,dataPos,jumlahPos);
                printf("Tekan sembarang tombol untuk kembali ke menu utama...");
                getch();
                break;
                
            case 0:
                printf("Terima kasih telah menggunakan Aplikasi Keuangan. Sampai jumpa!\n"); //keluar dari aplikasi
                break;
                
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n"); //menangani pilihan tidak valid
                break;
        }
    } while (pilihanMenu != 0); //mengulangi sampai pengguna memilih untuk keluar
    
    return 0;
}

// Implementasi Modul pilihMenu (body modul pilihMenu)
int pilihMenu(){
    /* Deklarasi Variabel */
    int pilihanMenu;

    /* Deskripsi Program */
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihanMenu);
    return pilihanMenu;
}