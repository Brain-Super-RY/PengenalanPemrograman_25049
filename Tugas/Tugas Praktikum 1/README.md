# Program Data Diri Mahasiswa (C++)

Ini adalah program C++ sederhana yang berfungsi untuk mengumpulkan data diri mahasiswa dan menampilkannya dalam format Kartu Tanda Mahasiswa (KTM) digital. Program ini dibuat sebagai latihan dasar untuk memahami konsep input, output, variabel, dan penanganan string dasar dalam C++.

## ✨ Fitur

- **Input Data Lengkap**: Menerima input Nama Lengkap (termasuk spasi), NIM, Jurusan, dan Tahun Lahir.
- **Kalkulasi Usia Otomatis**: Secara otomatis menghitung usia mahasiswa berdasarkan tahun lahir yang diinput.
- **Tampilan Terformat**: Menampilkan hasil output dalam format KTM yang rapi dan mudah dibaca menggunakan karakter tab (`\t`).
- **Penanganan Input Lanjutan**: Menggunakan `getline()` untuk membaca string dengan spasi dan `cin.ignore()` untuk mengatasi masalah umum antara `cin` dan `getline`.

## ⚙️ Teknologi yang Digunakan

- **Bahasa**: C++

## 🚀 Cara Kompilasi dan Menjalankan

Anda memerlukan C++ compiler seperti G++ (biasanya sudah termasuk dalam MinGW di Windows atau build-essentials di Linux).

1.  **Simpan Kode**
    Simpan kode program di atas dalam sebuah file, misalnya `DataDiri.cpp`.

2.  **Buka Terminal atau Command Prompt**
    Navigasikan ke direktori tempat Anda menyimpan file `DataDiri.cpp`.

3.  **Kompilasi Program**
    Jalankan perintah berikut untuk mengkompilasi kode:
    ```bash
    g++ DataDiri.cpp -o DataDiri
    ```

4.  **Jalankan Program**
    Setelah kompilasi berhasil, jalankan program dengan perintah:
    -   Di Windows:
        ```bash
        .\DataDiri.exe
        ```
    -   Di Linux / macOS:
        ```bash
        ./DataDiri
        ```

## 📝 Contoh Penggunaan

Berikut adalah contoh output saat program dijalankan:

```
========================================
===   PROGRAM INPUT DATA DIRI        ===
========================================

Masukkan Nama Lengkap Anda : Rizky Yoga Salasa
Masukkan NIM Anda          : 25049
Masukkan Jurusan Anda      : Teknik Informatika
Masukkan Tahun Lahir Anda  : 2007


--- KARTU TANDA MAHASISWA (KTM) ---
-------------------------------------
Nama            : Rizky Yoga Salasa
NIM             : 25049
Jurusan         : Teknik Informatika
Tahun Lahir     : 2007
Usia            : 18 tahun
-------------------------------------
```
