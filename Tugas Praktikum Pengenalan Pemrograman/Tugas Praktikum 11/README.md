# **Program Perhitungan Luas Bangun Datar (C++)**

## 📌 Deskripsi Program

Program ini adalah aplikasi sederhana berbasis C++ yang digunakan untuk menghitung luas beberapa bangun datar, yaitu:

* Persegi
* Lingkaran
* Segitiga

Program menggunakan sistem menu sehingga pengguna dapat memilih bangun yang diinginkan, memasukkan nilai (sisi / jari-jari / alas & tinggi), lalu hasil luas akan otomatis ditampilkan di layar.

---

## ✅ Fitur Program

✔ Perhitungan luas persegi
✔ Perhitungan luas lingkaran
✔ Perhitungan luas segitiga
✔ Input menggunakan `cin` dan output menggunakan `cout`
✔ Menu berulang dengan `do-while` sampai user memilih keluar

---

---

## 🧮 Rumus yang Digunakan

| Bangun Datar | Rumus                  |
| ------------ | ---------------------- |
| Persegi      | `sisi × sisi`          |
| Lingkaran    | `π × r × r` (π = 3.14) |
| Segitiga     | `½ × alas × tinggi`    |

---

## ▶ Cara Kerja Program

1. Program menampilkan menu utama
2. Pengguna memilih opsi 1–3 untuk perhitungan atau 4 untuk keluar
3. Program meminta input sesuai bangun yang dipilih
4. Hasil luas ditampilkan
5. Program kembali ke menu sampai pengguna memilih keluar

---

## 📌 Contoh Output

```
======================================================
           MENU PROGRAM HITUNG LUAS BANGUN 
======================================================
1. Hitung Luas Persegi
2. Hitung Luas Lingkaran
3. Hitung Luas Segitiga
4. Keluar
======================================================
Masukkan pilihan Anda (1-4): 1
Masukkan panjang sisi persegi: 6
Luas Persegi: 36 Cm
```

---

## 🛠 Teknologi Yang Digunakan

* Bahasa C++
* Compiler C++ (MinGW, Dev-C++, g++, Visual Studio Code, dsb)

---

## ✅ Cara Menjalankan Program

### **Linux / Mac**

```
g++ main.cpp -o hitung
./hitung
```

### **Windows (MinGW)**

```
g++ main.cpp -o hitung.exe
hitung.exe
```

---
