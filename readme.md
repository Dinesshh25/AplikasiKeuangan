# Aplikasi Keuangan Mahasiswa  

Aplikasi ini adalah proyek **C modular** untuk mata kuliah *Dasar-Dasar Pemrograman*, berdasarkan kasus “Aplikasi Keuangan Mahasiswa”.  
Program berfungsi sebagai pelacak keuangan pribadi dengan fitur pencatatan pos anggaran, transaksi, penyimpanan data, dan analisis keuangan.

-----------------------

### Struktur File Program
Proyek terdiri dari enam file utama, masing-masing memiliki tanggung jawab tersendiri.
1. main.c (Controller / Program Utama)
    Mengatur alur utama program, ada header modul, memanggil body modul, pilhMenu.
    Berisi:
    - Deklarasi array data pos dan transaksi
    - Loop menu utama menggunakan do-while
2. body_modul_tampilan.c 
    Berisi seluruh modul untuk menampilkan.
    Berisi:
    - tampilMenu()
    - tampilSubMenuTransaksi()
    - tampilLaporanKeuangan()
    - tampilLaporanPos()
    - tampilRekapitulasi()
    - tampilDaftarTransaksi()
3. body_modul_pos.c
    Berisi seluruh modul untuk pos.
    Berisi:
    - pilihMenu()
    - kelolaTambahPos()
    - kelolaTambahTransaksi()
    - validasiPosDuplikat()
    - validasiTransaksi()
    - generateId()
4. body_modul_transaksi.c
    Berisi seluruh modul untuk transaksi.
    Berisi:
    - hitungTotalPemasukan()
    - hitungTotalPengeluaran()
    - hitungSaldoAkhir()
    - hitungRealisasi()
    - kondisiKeuangan()
    - kesimpulanKeuangan()
    - avgPengeluaran()
    - hitungJumlahTransaksi()
5. body_modul_laporan.c
    Berisi seluruh modul untuk laporan keuangan.
    Berisi:
    - loadDataPos()
    - appendDataPos()
    - loadDataTransaksi()
    - appendDataTransaksi()

-------------------------
