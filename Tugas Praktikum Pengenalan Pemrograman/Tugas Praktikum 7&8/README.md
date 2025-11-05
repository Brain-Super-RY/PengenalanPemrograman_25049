# 🏪 Warung Digi - Update Sistem V5 (C++)

**Warung Digi** kini hadir dalam versi **V5**, dengan sistem menu interaktif yang sepenuhnya dikendalikan oleh **percabangan `switch–case`** dan **perulangan `do–while`**.
Versi ini merupakan pengembangan besar dari versi sebelumnya dengan logika program yang lebih terstruktur, mudah digunakan, dan memiliki fitur menu tambahan yang lebih lengkap.

---

## ⚙️ Fitur Utama

Program kini memungkinkan pengguna untuk:

* 🔹 **Mengelola stok barang secara real-time** (tambah & kurangi stok).
* 🔹 **Melihat daftar barang** lengkap beserta stok dan harga.
* 🔹 **Melakukan pembelian** berdasarkan *nomor* atau *nama barang*.
* 🔹 **Mencetak struk otomatis** dengan perhitungan diskon & pajak (PPN 11%).
* 🔹 **Menyimpan data dua pelanggan terakhir** untuk dibandingkan.
* 🔹 **Menganalisis total belanja dua pelanggan** dan menentukan kategori pelanggan.
* 🔹 **Menu berulang otomatis** berkat penggunaan `do–while loop`.

---

## 🧠 Pembaruan Logika (Update Highlights)

### 🧩 Struktur Program

* Menu utama kini dijalankan di dalam **loop `do–while`**, agar selalu tampil ulang sampai pengguna memilih keluar.
* Setiap pilihan menu diproses menggunakan **`switch (pilihan)`**, membuat alur program jauh lebih rapi dan modular.

### 🆕 Menu Baru

| No | Nama Menu                      | Fungsi                                                       |
| -- | ------------------------------ | ------------------------------------------------------------ |
| 1  | Tambah Stok                    | Menambah stok barang yang sudah ada                          |
| 2  | Kurangi Stok                   | Mengurangi stok barang dengan validasi                       |
| 3  | Lihat Stok                     | Menampilkan stok seluruh barang                              |
| 4  | Keluar                         | Menutup program                                              |
| 5  | Lihat Daftar Barang            | Menampilkan semua barang lengkap dengan harga                |
| 6  | Beli Barang                    | Menambahkan barang ke keranjang (bisa cari pakai nomor/nama) |
| 7  | Cetak Struk & Bayar            | Menghitung total, diskon, PPN, dan kembalian                 |
| 8  | Bandingkan Belanja 2 Pelanggan | Membandingkan total dua pelanggan terakhir dan kategorinya   |

---

## 🛠️ Teknologi yang Digunakan

* **Bahasa Pemrograman:** C++
* **Library Standar:**

  * `<iostream>` → Input/Output utama
  * `<string>` → Penyimpanan dan manipulasi nama barang/pelanggan

---

## 🚀 Cara Menjalankan

1. Pastikan sudah menginstall compiler C++ seperti **g++** (MinGW) atau IDE seperti **Code::Blocks** / **VS Code**.
2. Simpan kode program dengan nama `warung_digi_v5.cpp`.
3. Buka terminal, arahkan ke folder penyimpanan, lalu kompilasi:

   ```bash
   g++ warung_digi_v5.cpp -o warung_digi_v5
   ```
4. Jalankan program:

   ```bash
   ./warung_digi_v5
   ```
5. Nikmati pengalaman kasir digital dengan menu interaktif Warung Digi 😄

---

## 🧾 Alur Program

1. **Menu Utama (Loop do–while)**
   Menu akan terus tampil ulang hingga pengguna memilih opsi “Keluar (4)”.

2. **Proses Menu (Switch–Case)**
   Setiap pilihan menu memiliki fungsinya masing-masing.
   Contohnya:

   * `case 1:` untuk menambah stok
   * `case 6:` untuk membeli barang
   * `case 8:` untuk analisis dua pelanggan

3. **Transaksi & Pembayaran**

   * Program menghitung total harga, diskon (hingga 15% dengan kartu member), dan PPN 11%.
   * Setelah pembayaran, struk otomatis dicetak lengkap dengan subtotal per barang dan total akhir.

4. **Analisis Pelanggan**

   * Sistem menyimpan dua transaksi terakhir dan menampilkan hasil perbandingan menggunakan semua operator relasi:
     `==`, `!=`, `>`, `<`, `>=`, `<=`.
   * Kategori pelanggan:

     * ≥ Rp 500.000 → **VIP Customer**
     * ≥ Rp 200.000 → **Premium Customer**
     * ≥ Rp 50.000 → **Regular Customer**
     * < Rp 50.000 → **New Customer**

---

## 💡 Contoh Output (Ringkas)

```
===== WARUNG DIGI =====
1. Tambah Stok
2. Kurangi Stok
3. Lihat Stok
4. Keluar
5. Lihat Daftar Barang
6. Beli Barang
7. Cetak Struk & Bayar
8. Bandingkan Belanja 2 Pelanggan
Pilih menu: 7

===== STRUK BELANJA WARUNG DIGI =====
Nama Barang               Qty   Harga    Subtotal
--------------------------------------------------
Indomie Goreng            5     Rp 3800.5   Rp 19002.5
Teh Botol Kotak           3     Rp 4200     Rp 12600
--------------------------------------------------
Total Belanja : Rp 31602.5
Diskon        : Rp 1580.12
PPN (11%)     : Rp 3308.75
TOTAL BAYAR   : Rp 33331.13
```

---

## 🧩 Kesimpulan

Versi V5 ini memperkenalkan:

* Struktur **menu dinamis** menggunakan `switch–case`.
* **Loop utama `do–while`** untuk navigasi tanpa restart program.
* **Menu analisis pelanggan** untuk menilai performa penjualan harian.
* **Antarmuka teks yang lebih informatif dan interaktif.**

---