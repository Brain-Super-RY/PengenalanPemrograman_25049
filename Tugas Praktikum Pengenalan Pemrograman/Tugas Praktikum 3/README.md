# 🏪 Program Warung Digi (C++)

**Warung Digi** adalah program simulasi kasir sederhana berbasis **C++** yang dibuat untuk tugas praktikum pemrograman.

Program ini memungkinkan pengguna untuk:

* Melihat daftar barang beserta stok dan harga.
* Membeli barang dan otomatis mengurangi stok.
* Menghitung **total belanja, diskon event, diskon tambahan, diskon besar, diskon member, dan PPN (11%)**.
* Menampilkan **struk belanja profesional** seperti minimarket.
* Mendukung berbagai **metode pembayaran** (tunai,  kartu member).
* Menampilkan **stok barang terbaru secara realtime** setelah pembelian.

Program ini juga sekaligus mendemonstrasikan penggunaan:

* **Variabel dan tipe data**
* **Operator (aritmatika, relasi, logika, dll.)**
* **Percabangan (if/else, switch-case)**
* **Perulangan (while, do-while, for)**
* **Input/Output standar (cin, cout)**

---

## ⚡ Fitur Utama

1. **Daftar Barang**

   * Terdapat **15 barang** dengan stok bervariasi.

2. **Diskon dan Pajak**

   * Diskon event otomatis **5% untuk semua barang**.
   * Diskon tambahan:

     * **10%** jika total belanja > Rp 100.000
     * **10% per barang** jika subtotal barang > Rp 550.000
     * **25% tambahan** jika total belanja > Rp 1.000.000
     * **5% tambahan** untuk pemilik kartu member.
   * PPN (Pajak Pertambahan Nilai) **11%** otomatis ditambahkan sesuai peraturan Indonesia.

3. **Keranjang Belanja**

   * Barang yang dibeli akan tersimpan di keranjang.
   * Stok barang otomatis berkurang.

4. **Struk Belanja**

   * Menampilkan detail: nama barang, jumlah, harga satuan, subtotal.
   * Menghitung total belanja, diskon, pajak, total bayar, uang diterima, dan kembalian.
   * Setelah struk tampil, program memberi **jeda sebentar** agar pengguna bisa membacanya sebelum kembali ke menu.

5. **Metode Pembayaran**

   * **Tunai** 💵
   * **Kartu Member** 🎫
   * Setiap metode menampilkan notifikasi otomatis sesuai pilihan pengguna.

6. **Update Data Barang**

   * Data berubah realtime selama program berjalan.

---

## 🛠️ Teknologi yang Digunakan

* **Bahasa Pemrograman**: C++
* **Library Wajib**:

  * `<iostream>` → Input/Output standar
  * `<string>` → Manipulasi teks

---

## 🚀 Cara Menjalankan

1. Pastikan sudah terinstall **g++** (GNU Compiler) atau IDE C++ (misalnya Code::Blocks, Dev C++, Visual Studio Code).
2. Simpan file sebagai `warung_digi.cpp`.
3. Kompilasi program:

   ```bash
   g++ warung_digi.cpp -o warung_digi
   ```
4. Jalankan program:

   ```bash
   ./warung_digi
   ```
5. Ikuti menu interaktif yang tersedia.

---

## 📜 Alur Program

1. **Menu Utama**

   * Lihat daftar barang
   * Beli barang
   * Cetak struk belanja
   * Keluar

2. **Proses Belanja**

   * Pilih barang.
   * Masukkan jumlah beli.
   * Sistem cek stok.
   * Barang masuk ke keranjang.

3. **Struk Belanja**

   * Hitung total, diskon, pajak.
   * Pilih metode pembayaran.
   * Input uang bayar.
   * Tampilkan kembalian.
   * Cetak struk profesional.
   * **Program memberi jeda sejenak agar struk bisa dibaca.**
   * Setelah itu, **program kembali ke menu utama dengan stok terbaru.**

---

## 📊 Contoh Output Struk

```
======================================
       STRUK BELANJA WARUNG DIGI      
======================================
Nama Barang         Qty     Subtotal
--------------------------------------
Indomie Goreng      3       Rp 10501.50
Silverqueen 62g     2       Rp 31000.00
Beras Premium 5kg   1       Rp 65000.00
--------------------------------------
Total Belanja           Rp 106501.50
Total Diskon            Rp 14500.15
PPN 11%                 Rp 10100.15
TOTAL BAYAR             Rp 102101.50

Metode Pembayaran: Tunai
Uang Diterima           Rp 110000.00
Kembalian               Rp 7898.50
======================================
         TERIMA KASIH :)              
======================================

(Struk akan ditampilkan beberapa detik sebelum kembali ke menu utama)
```

---
