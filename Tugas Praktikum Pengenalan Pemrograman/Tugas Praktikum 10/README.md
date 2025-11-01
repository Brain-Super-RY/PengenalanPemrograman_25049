# 🏥 Sistem Data Pasien Rumah Sakit  
![C++](https://img.shields.io/badge/Language-C++-00599C?logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Stable-brightgreen)

> Program berbasis **C++** untuk mengelola data pasien rumah sakit secara sederhana dan efisien.  
> Mendukung input dinamis, perhitungan total biaya, dan format tampilan uang Rupiah 🇮🇩  

---

## 🚀 Fitur Utama

| Fitur | Deskripsi |
|:------|:-----------|
| 🧾 **Data Pasien** | Menyimpan nama, jenis penyakit, alamat, dan biaya perawatan |
| 💰 **Format Rupiah** | Mengubah angka menjadi format uang Indonesia (`Rp 1.000.000`) |
| 🔁 **Input Dinamis** | Jumlah pasien bisa ditentukan oleh pengguna |
| 🧮 **Total Biaya** | Menghitung total seluruh biaya pasien |
| 🖥️ **Output Rapi** | Tampilan data diformat dengan garis pemisah yang jelas |

---

## ⚙️ Cara Kerja Program
1. Pengguna memasukkan jumlah pasien.  
2. Program meminta input data tiap pasien: nama, penyakit, alamat, dan biaya.  
3. Data disimpan dalam array bertipe `struct Pasien`.  
4. Setelah semua data dimasukkan, sistem menampilkan daftar pasien lengkap dengan biaya dalam format Rupiah.  
5. Program menjumlahkan seluruh biaya dan menampilkan total akhir.

---

## 🧩 Struktur Data
```cpp
struct Pasien {
    string nama;
    string jenisPenyakit;
    string alamat;
    long long biayaPerawatan;
};
````

---

## 💡 Fungsi `formatRupiah()`

Fungsi ini digunakan untuk memformat angka menjadi tampilan uang dengan titik setiap tiga digit.

```cpp
formatRupiah(2500000); // Output: Rp 2.500.000
```

---

## 🖼️ Contoh Output

```
========================================
  SISTEM DATA PASIEN RUMAH SAKIT
========================================
Masukkan jumlah pasien: 2
----------------------------------------
Masukkan data untuk pasien ke-1:
Nama Pasien        : Budi Santoso
Jenis Penyakit     : Demam Berdarah
Alamat             : Karawang
Biaya Perawatan    : Rp 1250000
----------------------------------------
Masukkan data untuk pasien ke-2:
Nama Pasien        : Siti Aminah
Jenis Penyakit     : Tifus
Alamat             : Cikampek
Biaya Perawatan    : Rp 1500000
----------------------------------------

========================================
        DAFTAR SELURUH PASIEN
========================================

Pasien ke-1
Nama           : Budi Santoso
Jenis Penyakit : Demam Berdarah
Alamat         : Karawang
Biaya Perawatan: Rp 1.250.000
----------------------------------------

Pasien ke-2
Nama           : Siti Aminah
Jenis Penyakit : Tifus
Alamat         : Cikampek
Biaya Perawatan: Rp 1.500.000
----------------------------------------

========================================
Total Biaya Seluruh Pasien: Rp 2.750.000
========================================
```

---

## 🧠 Konsep Pemrograman yang Digunakan

* 🧱 **Struct** — mengelompokkan beberapa data dalam satu entitas
* 🔁 **Looping** — mengulangi proses input dan output
* 📚 **Array** — menyimpan banyak data pasien dalam satu variabel
* ✂️ **String Handling** — menggunakan `getline()` untuk input teks panjang
* 🧮 **Fungsi Custom** — `formatRupiah()` untuk format uang
* 🧼 **cin.ignore()** — mencegah error input setelah membaca angka

---