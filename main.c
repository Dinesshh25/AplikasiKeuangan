#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Struktur Data Aplikasi Keuangan Mahasiswa
    PosAnggaran: Menyimpan informasi tentang pos anggaran seperti nama pos dan batas nominal.
    Transaksi: Menyimpan informasi tentang transaksi keuangan termasuk pemasukan dan pengeluaran seperti ID, tanggal, pos anggaran, nominal, jenis, dan deskripsi.
*/
typedef struct {
    char namaPos[50];
    int batasNominal;
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
    Header Modul
*/
void tampilMenu();
/*
    Procedure bertujuan untuk menampilkan menu utama aplikasi keuangan mahasiswa ke layar.
    I. S. : Program dijalankan
    F. S. : Menu utama aplikasi keuangan mahasiswa ditampilkan ke layar.
            (1. tambah pos, 2. tambah transaksi, 3. laporan, 0. keluar)  
*/

int pilihMenu();
/*
    Function bertujuan untuk menerima input pilihan menu dari pengguna.
    Input : Pilihan menu dari pengguna
    Output : Mengembalikan pilihan menu sebagai integer
*/

void tampilSubMenuTransaksi();
/*
    Procedure bertujuan untuk menampilkan submenu transaksi aplikasi keuangan mahasiswa ke layar.
    I. S. : Menu utama ditampilkan, dan pengguna memilih menu transaksi
    F. S. : Submenu transaksi aplikasi keuangan mahasiswa ditampilkan ke layar.
            (1. tambah pemasukan, 2. tambah pengeluaran, 3. lihat daftar transaksi, 0. kembali)  
*/

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

int validasiTransaksi(Transaksi transaksiBaru, PosAnggaran dataPos[], int jumlahPos);
/*
    Function bertujuan untuk memvalidasi data transaksi yang akan ditambahkan.
    Input : Data transaksi baru (transaksiBaru), data pos anggaran (dataPos), jumlah pos anggaran (jumlahPos)
    Output : Mengembalikan 1 dan data ditambahkan ke dalam file data_transaksi jika data valid (hanya pemasukan/pengeluaran, nominal > 0, tanggal tidak kosong, pos anggaran berasal dari dataPos)
            Mengembalikan 0 dan menampilkan pesan kesalahan jika tidak valid.
*/

void generateId(int jumlahTransaksi, char *bufferId);
/*
    Procedure bertujuan untuk menghasilkan ID unik untuk setiap transaksi berdasarkan jumlah transaksi yang ada.
    Input : jumlahTransaksi (jumlah transaksi yang ada)
    Output : bufferId (ID unik yang dihasilkan disimpan dalam bufferId)
*/

int hitungJumlahTransaksi(char kriteria[], Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung jumlah transaksi (berapa kali transaksi) berdasarkan nama pos atau jenis pemasukan/pengeluaran.
    Input : kriteria (nama pos anggaran atau jenis transaksi), dataTransaksi (array data transaksi), jumlahTransaksi (jumlah transaksi yang ada)
    Output : Mengembalikan jumlah transaksi yang sesuai dengan nama pos atau jenisnya.
*/

int hitungTotalPemasukan(Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung total pemasukan dari semua transaksi yang ada.
    Input : Data transaksi sudah ada
    Output : Mengembalikan total pemasukan dari semua transaksi.
*/

int hitungTotalPengeluaran(Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung total pengeluaran dari semua transaksi yang ada.
    Input : Data transaksi sudah ada
    Output : Mengembalikan total pengeluaran dari semua transaksi.
*/

int hitungSaldoAKhir(int totalPemasukan, int totalPengeluaran);
/*
    Function bertujuan untuk menghitung saldo akhir berdasarkan total pemasukan dan total pengeluaran.
    Input : totalPemasukan, totalPengeluaran
    Output : Mengembalikan saldo akhir (totalPemasukan - totalPengeluaran).
*/

int avgPengeluaran(int totalPengeluaran, Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung rata-rata pengeluaran dari semua transaksi pengeluaran yang ada.
    Input : totalPengeluaran, dataTransaksi (array data transaksi), jumlahTransaksi (jumlah transaksi yang ada)
    Output : Mengembalikan rata-rata pengeluaran.
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



int main() {
    /* Deklarasi Variabel */
    Transaksi dataTransaksi[100];
    PosAnggaran dataPos[50];
    int jumlahTransaksi = 0;
    int jumlahPos = 0;
    int pilihanMenu;

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
                tambahPos(dataPos, &jumlahPos); //menambah pos anggaran
                break;
            case 2:
                tambahTransaksi(dataTransaksi, &jumlahTransaksi, dataPos, jumlahPos); //menambah transaksi
                break;
            case 3:
                tampilLaporanKeuangan(dataTransaksi, jumlahTransaksi, dataPos, jumlahPos); //menampilkan laporan keuangan
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
    printf("Masukkan pilihan (1/2/3/0): ");
    scanf("%d", &pilihanMenu);
    return pilihanMenu;
}