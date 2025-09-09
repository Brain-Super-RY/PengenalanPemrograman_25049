# 🏪 Program Warung Digi (C++)

Ini adalah program C++ sederhana yang berfungsi untuk menampilkan daftar barang warung beserta detail lengkapnya (kode, nama, jumlah stok, harga, dan tanggal kadaluarsa). Program ini dibuat sebagai latihan dasar untuk memahami konsep **array, input, output, perulangan, dan validasi input** dalam C++.

## ✨ Fitur

- **Menu Daftar Barang**: Menampilkan pilihan 5 barang yang tersedia.
- **Detail Barang Lengkap**: Menampilkan nama, kode barang, stok, harga satuan, dan tanggal kadaluarsa.
- **Validasi Input**: Menangani input salah agar pengguna tidak keluar dari program secara tidak sengaja.
- **Looping Menu**: Program terus berjalan hingga pengguna memilih opsi keluar.

## ⚙️ Teknologi yang Digunakan

- **Bahasa**: C++
- **Library**: `<iostream>`, `<string>`, `<iomanip>`

## 🚀 Cara Kompilasi dan Menjalankan

Anda memerlukan compiler C++ seperti **G++** (tersedia di MinGW untuk Windows atau build-essentials di Linux).

1. **Simpan Kode**  
   Simpan kode program di atas dalam sebuah file, misalnya `WarungDigi.cpp`.

2. **Buka Terminal atau Command Prompt**  
   Arahkan ke folder tempat Anda menyimpan file `WarungDigi.cpp`.

3. **Kompilasi Program**  
   Jalankan perintah berikut untuk mengkompilasi kode:
   ```bash
   g++ WarungDigi.cpp -o WarungDigi

4.  **Jalankan Program**
    Setelah kompilasi berhasil, jalankan program dengan perintah:
    -   Di Windows:
        ```bash
        .\WarungDigi.exe
        ```
    -   Di Linux / macOS:
        ```bash
        ./WarungDigi
        ```

## 📝 Contoh Penggunaan

Berikut adalah contoh output saat program dijalankan:

```
===== SELAMAT DATANG DI WARUNG DIGI =====
Silakan pilih barang untuk melihat detail lengkap:
1. Indomie Goreng
2. Teh Botol Kotak
3. Silverqueen 62g
4. Chitato Sapi Panggang
5. Susu UHT Ultra Milk
--------------------------------------------
0. Keluar dari program
============================================
Masukkan pilihan Anda (1-5 atau 0): 2

---------- DETAIL LENGKAP ----------
Nama Barang        : Teh Botol Kotak
Kode Barang        : TBK-002
Jumlah Stok        : 72 pcs
Harga Satuan       : Rp 3500.00
Tanggal Kadaluarsa : 20-01-2026
------------------------------------
```