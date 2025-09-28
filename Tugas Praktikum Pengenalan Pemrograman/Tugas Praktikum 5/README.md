# 🏪  Warung Digi - Update Sistem V4 (C++)

**Warung Digi** Program ini dirancang untuk mendemonstrasikan penggunaan **fungsi** dan **percabangan (if–else)** dalam bahasa C++ dan dapat menghitung total pembayaran setelah menerapkan aturan diskon tertentu.

Program ini memungkinkan pengguna untuk:

* Memasukkan total belanja.
* Mengetahui apakah mendapat **diskon 20%, 10%, 5%, atau 0%**.
* Melihat **total bayar setelah diskon**.

---

## ⚡ Aturan Diskon

* Belanja ≥ Rp 500.000 → **diskon 20%**
* Belanja ≥ Rp 200.000 → **diskon 10%**
* Belanja ≥ Rp 100.000 → **diskon 5%**
* Belanja < Rp 100.000 → **tanpa diskon**

---

## 🛠️ Teknologi yang Digunakan

* **Bahasa Pemrograman**: C++
* **Library Standar**:

  * `<iostream>` → Input/Output
  * (fungsi tambahan menggunakan `double` untuk perhitungan diskon)

---

## 🚀 Cara Menjalankan

1. Pastikan Anda sudah menginstall C++ compiler seperti **g++** (MinGW di Windows) atau menggunakan IDE (misalnya Code::Blocks, Visual Studio Code).
2. Simpan kode program sebagai `diskon.cpp`.
3. Buka terminal atau command prompt, lalu navigasi ke folder tempat file disimpan.
4. Kompilasi program dengan perintah:

   ```bash
   g++ diskon.cpp -o diskon
   ```
5. Jalankan program:

   ```bash
   ./diskon
   ```

---

## 📜 Alur Program

1. Program meminta input berupa total belanja.
2. Program memeriksa nilai input dengan **percabangan if–else**.
3. Diskon ditentukan sesuai aturan yang berlaku.
4. Program menampilkan **total belanja, persentase diskon, dan total bayar**.

---

## 📊 Contoh Output

### Input: 600000

```
=== Program Hitung Diskon ===
Masukkan total belanja: Rp 600000

Total Belanja : Rp 600000
Diskon        : 20%
Total Bayar   : Rp 480000
```

### Input: 150000

```
=== Program Hitung Diskon ===
Masukkan total belanja: Rp 150000

Total Belanja : Rp 150000
Diskon        : 5%
Total Bayar   : Rp 142500
```

### Input: 50000

```
=== Program Hitung Diskon ===
Masukkan total belanja: Rp 50000

Total Belanja : Rp 50000
Diskon        : 0%
Total Bayar   : Rp 50000
```

---