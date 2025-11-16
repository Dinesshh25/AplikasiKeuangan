# Aplikasi Keuangan Mahasiswa  

Aplikasi ini adalah proyek **C modular** untuk mata kuliah *Dasar-Dasar Pemrograman*, berdasarkan kasus “Aplikasi Keuangan Mahasiswa”.  
Program berfungsi sebagai pelacak keuangan pribadi dengan fitur pencatatan pos anggaran, transaksi, penyimpanan data, dan analisis keuangan.

-----------------------

### Struktur File Program
Proyek terdiri dari enam file utama, masing-masing memiliki tanggung jawab tersendiri.
1. modul.h (Header / Kamus Program)
    Berfungsi sebagai pusat definisi dan prototipe fungsi.
    Berisi:
    - #include library standar (stdio.h, string.h, dll.)
    - Definisi struct PosAnggaran dan struct Transaksi
    - Prototipe dari seluruh fungsi dan prosedur dalam proyek
2. main.c (Controller / Program Utama)
    Mengatur alur utama program dan memanggil fungsi dari modul lain.
    Berisi:
    - #include "modul.h"
    - Deklarasi array data pos dan transaksi
    - Pemanggilan loadDataPos() dan loadDataTransaksi()
    - Loop menu utama menggunakan do-while
    - Struktur switch-case untuk memanggil modul logika
3. modul_tampilan.c (View)
    Berisi seluruh prosedur untuk menampilkan data ke layar.
    Berisi:
    - tampilMenu()
    - tampilSubMenuTransaksi()
    - tampilLaporanKeuangan()
    - tampilLaporanPos()
    - tampilRekapitulasi()
    - tampilDaftarTransaksi()
4. modul_logika.c (Logic & Validation)
    Mengatur alur kerja, validasi input, dan fungsi pendukung lainnya.
    Berisi:
    - pilihMenu()
    - kelolaTambahPos()
    - kelolaTambahTransaksi()
    - validasiPosDuplikat()
    - validasiTransaksi()
    - generateId()
5. modul_kalkulasi.c (Calculation)
    Berisi fungsi perhitungan murni tanpa melakukan input/output.
    Berisi:
    - hitungTotalPemasukan()
    - hitungTotalPengeluaran()
    - hitungSaldoAkhir()
    - hitungRealisasi()
    - kondisiKeuangan()
    - kesimpulanKeuangan()
    - avgPengeluaran()
    - hitungJumlahTransaksi()
6. modul_file.c (File I/O)
    Mengatur penyimpanan dan pembacaan data dari file .txt.
    Berisi:
    - loadDataPos()
    - appendDataPos()
    - loadDataTransaksi()
    - appendDataTransaksi()

-------------------------