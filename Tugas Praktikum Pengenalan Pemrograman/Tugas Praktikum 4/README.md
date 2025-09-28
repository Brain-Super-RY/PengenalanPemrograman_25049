# 🏪 Warung Digi - Update Sistem Kasir & Analisis Pelanggan V3 (C++)

**Warung Digi** adalah program simulasi kasir canggih berbasis **C++** yang dirancang tidak hanya untuk mengelola transaksi, tetapi juga untuk melakukan analisis perbandingan data belanja pelanggan secara langsung.

Program ini memungkinkan pengguna untuk:

  * Melihat daftar barang lengkap dengan stok dan harga.
  * Melakukan pembelian dengan mencari barang via **nomor atau nama**.
  * Menghitung **total belanja, PPN (11%)**, dan berbagai **skema diskon berlapis** secara otomatis.
  * Mencetak **struk belanja profesional** yang terperinci.
  * **Membandingkan total belanja dua pelanggan** terakhir menggunakan semua operator relasi.
  * Menganalisis dan **mengkategorikan pelanggan** berdasarkan total transaksinya.

Program ini secara efektif mendemonstrasikan penggunaan fundamental C++, seperti:

  * **Variabel dan Tipe Data** (string, int, double, bool)
  * **Struktur Data** (Array)
  * **Operator** (Aritmatika, Relasi)
  * **Percabangan** (if-else if-else)
  * **Perulangan** (while, for)
  * **Input/Output** standar (cin, cout, getline)

-----

## ⚡ Fitur Unggulan

1.  **Manajemen Inventaris Real-time**

      * Terdapat **15 jenis barang** yang siap dijual.
      * Stok barang akan otomatis berkurang dan diperbarui secara *real-time* setelah setiap transaksi berhasil.

2.  **Skema Diskon Berlapis & Pajak**

      * **Diskon Event 5%**: Diberikan otomatis untuk seluruh total belanja.
      * **Diskon Belanja Bertingkat**:
          * Tambahan **10%** jika total belanja \> Rp 100.000.
          * Tambahan **25%** jika total belanja \> Rp 1.000.000.
      * **Diskon Spesial Barang**: Diskon **10%** untuk satu jenis barang jika total pembeliannya (subtotal) \> Rp 550.000.
      * **Diskon Member 5%**: Keuntungan tambahan bagi pelanggan yang memiliki kartu member.
      * **PPN 11%**: Pajak ditambahkan secara otomatis pada total akhir setelah semua diskon diterapkan.

3.  **Analisis & Perbandingan Pelanggan**

      * Fitur unik untuk membandingkan total belanja dari **dua pelanggan terakhir**.
      * Menampilkan hasil perbandingan dari **semua 6 operator relasi** (`==`, `!=`, `>`, `<`, `>=`, `<=`).
      * Memberikan **kesimpulan** pelanggan mana yang berbelanja lebih banyak beserta selisihnya.
      * **Mengelompokkan pelanggan** ke dalam kategori (*VIP, Premium, Regular, New Customer*).
      * Membandingkan akumulasi belanja dengan **target penjualan harian** warung.

-----

## 🛠️ Teknologi yang Digunakan

  * **Bahasa Pemrograman**: C++
  * **Library Standar**:
      * `<iostream>` → Untuk menangani proses Input/Output.
      * `<string>` → Untuk menggunakan tipe data string dan manipulasinya.

-----

## 🚀 Cara Menjalankan

1.  Pastikan Anda sudah menginstall C++ compiler seperti **g++** (MinGW di Windows) atau menggunakan IDE (misalnya Visual Studio Code, Code::Blocks).
2.  Simpan kode program sebagai `warung_digi.cpp`.
3.  Buka terminal atau command prompt, lalu navigasi ke folder tempat file disimpan.
4.  Kompilasi program dengan perintah:
    ```bash
    g++ warung_digi.cpp -o warung_digi
    ```
5.  Jalankan program yang sudah dikompilasi:
    ```bash
    ./warung_digi
    ```
6.  Program siap digunakan melalui menu interaktif yang tampil.

-----

## 📜 Alur Program

1.  **Menu Utama**

      * `1. Lihat Daftar Barang`: Menampilkan semua produk, stok, dan harga.
      * `2. Beli Barang`: Memulai sesi belanja.
      * `3. Cetak Struk & Bayar`: Menyelesaikan transaksi dan mencetak struk.
      * `4. Bandingkan Belanja 2 Pelanggan`: Masuk ke menu analisis.
      * `0. Keluar`: Menghentikan program.

2.  **Proses Belanja**

      * Pengguna memilih barang berdasarkan nomor atau mengetik nama barang.
      * Memasukkan jumlah yang ingin dibeli.
      * Sistem akan memvalidasi ketersediaan stok.
      * Jika berhasil, barang ditambahkan ke keranjang dan stok diperbarui.

3.  **Pembayaran & Struk**

      * Program akan menghitung total, semua diskon yang berlaku, dan PPN.
      * Pengguna memasukkan nominal uang pembayaran.
      * Struk detail akan tercetak di layar beserta uang kembalian.
      * Data transaksi pelanggan akan disimpan untuk fitur perbandingan.

4.  **Analisis Pelanggan**

      * Menu ini akan menampilkan data dua pelanggan terakhir.
      * Menampilkan hasil perbandingan belanja dan kategori masing-masing pelanggan.

-----

## 📊 Contoh Output Analisis Pelanggan

```
===== PERBANDINGAN BELANJA DUA PELANGGAN =====
============= WARUNG DIGI =============

===== RINGKASAN DATA =====
Pelanggan 1: Budi = Rp 255750.5
Pelanggan 2: Ani = Rp 150200.0

===== HASIL PERBANDINGAN =====
Belanja sama (==): TIDAK (0)
Belanja berbeda (!=): YA (1)
Budi > Ani: YA (1)
Budi < Ani: TIDAK (0)
Budi >= Ani: YA (1)
Budi <= Ani: TIDAK (0)

===== KESIMPULAN =====
Budi belanja LEBIH BANYAK
Selisih: Rp 105550.5

===== KATEGORI PELANGGAN =====
Budi: Premium Customer
Ani: Regular Customer

Tekan ENTER untuk kembali...
```