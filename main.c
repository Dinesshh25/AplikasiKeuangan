//pemanggilan body modul
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "body_modul_pos.c"
#include "body_modul_transaksi.c"
#include "body_modul_laporan.c"
#include "body_modul_tampilan.c"

/*
    Strukture Data Aplikasi Keuangan Mahasiswa
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
    Header Modul
*/
void tampilMenu();
/*
    Procedure bertujuan untuk menampilkan menu utama aplikasi keuangan mahasiswa ke layar.
    I. S. : Program dijalankan
    F. S. : Menu utama aplikasi keuangan mahasiswa ditampilkan ke layar.
            (1. tambah pos, 2. tambah transaksi, 3. laporan, 0. keluar)  
*/

void pilihMenu();
/*
    Procedure bertujuan untuk memproses pilihan (meminta dan membaca) menu yang dipilih oleh pengguna.
    I. S. : Menu utama ditampilkan
    F. S. : Proses sesuai dengan pilihan menu yang dipilih oleh pengguna dijalankan.
*/

void tampilSubMenuTransaksi();
/*
    Procedure bertujuan untuk menampilkan submenu transaksi aplikasi keuangan mahasiswa ke layar.
    I. S. : Menu utama ditampilkan, dan pengguna memilih menu transaksi
    F. S. : Submenu transaksi aplikasi keuangan mahasiswa ditampilkan ke layar.
            (1. tambah pemasukan, 2. tambah pengeluaran, 0. kembali)  
*/

void loadDataTransaksi(Transaksi dataTransaksi[], int *jumlahTransaksi);
/*
    Procedure bertujuan untuk memuat data transaksi dari file data_transaksi ke dalam array dataTransaksi.
    I. S. : dataTransaksi kosong, jumlahTransaksi = 0.
    F. S. : dataTransaksi terisi, jumlahTransaksi diperbarui.
*/

void appendDataTransaksi(Transaksi txBaru);
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

int validasiTransaksi(Transaksi txBaru, PosAnggaran dataPos[], int jumlahPos);
/*
    Function bertujuan untuk memvalidasi data transaksi yang akan ditambahkan.
    I. S. : Data transaksi baru telah diinput oleh pengguna
    F. S. : Mengembalikan 1 dan data ditambahkan ke dalam file data_transaksi jika data valid (hanya pemasukan/pengeluaran, nominal > 0, tanggal tidak kosong, pos anggaran berasal dari dataPos)
            Mengembalikan 0 dan menampilkan pesan kesalahan jika tidak valid.
*/

int generateId(int jumlahTransaksi);
/*
    Function bertujuan untuk menghasilkan ID unik untuk transaksi baru berdasarkan jumlah transaksi yang sudah ada.
    I. S. : Jumlah transaksi sudah diketahui
    F. S. : Mengembalikan ID unik dalam format "TXXX" di mana XXX adalah nomor urut transaksi dengan padding nol di depan.
*/

int hitungJumlahTransaksi(char namaPos[], Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung jumlah transaksi (berapa kali transaksi).
    I. S. : Data transaksi sudah ada
    F. S. : Mengembalikan jumlah transaksi.
*/

void tampilDaftarTransaksi(Transaksi dataTransaksi[], int jumlahTransaksi, char filter[]);
/*
    Procedure bertujuan untuk menampilkan daftar transaksi ke layar dengan opsi filter.
    I. S. : Data transaksi sudah ada
    F. S. : Daftar transaksi ditampilkan ke layar sesuai dengan filter yang diberikan.
            Jika filter "semua", tampilkan semua transaksi.
            Jika filter "pemasukan", tampilkan hanya transaksi pemasukan.
            Jika filter "pengeluaran", tampilkan hanya transaksi pengeluaran.
*/

int hitungTotalPemasukan(Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung total pemasukan dari semua transaksi yang ada.
    I. S. : Data transaksi sudah ada
    F. S. : Mengembalikan total pemasukan dari semua transaksi.
*/

int hitungTotalPengeluaran(Transaksi dataTransaksi[], int jumlahTransaksi);
/*
    Function bertujuan untuk menghitung total pengeluaran dari semua transaksi yang ada.
    I. S. : Data transaksi sudah ada
    F. S. : Mengembalikan total pengeluaran dari semua transaksi.
*/




float main() {
    //Deklarasi Variabel

    //Deskripsi Program
    printf("Selamat datang di Aplikasi Keuangan\n");
    return 0;
}

//pilihmenu