# 🏪 Program Warung Digi (C++)

Program Warung Digi ini dibuat menggunakan C++ untuk menampilkan data awal barang (`namaBarang`, `jumlah`, `harga`) dalam bentuk tabel serta menyediakan menu interaktif agar pengguna dapat melihat detail barang tertentu. Program ini merupakan implementasi dari tugas **proyek mini Warung** dengan variabel penting yang ditentukan.

## ✨ Fitur
- **Data Awal Otomatis**: Menampilkan daftar barang saat program dijalankan.  
- **Menu Interaktif**: User bisa memilih barang untuk melihat detailnya.  
- **Validasi Input**: Menangani input salah agar tidak error.  
- **Looping Menu**: Program berjalan terus sampai user memilih keluar.  

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

## 📝 Contoh Output

### Data Awal

```text
===== DATA AWAL WARUNG DIGI =====
Nama Barang              Jumlah    Harga
---------------------------------------------
Indomie Goreng           50        Rp 3000.00
Teh Botol Kotak          72        Rp 3500.00
Silverqueen 62g          35        Rp 12500.00
Chitato Sapi Panggang    40        Rp 11000.00
Susu UHT Ultra Milk      60        Rp 5500.00
=============================================
```

### Menu Interaktif

```text
===== MENU WARUNG DIGI =====
1. Lihat detail barang
0. Keluar
Pilih menu: 1

Daftar Barang:
1. Indomie Goreng
2. Teh Botol Kotak
3. Silverqueen 62g
4. Chitato Sapi Panggang
5. Susu UHT Ultra Milk
Pilih barang (1-5): 2

--- DETAIL BARANG ---
Nama Barang : Teh Botol Kotak
Jumlah      : 72 pcs
Harga       : Rp 3500.00
----------------------
```
