# 📦 Program Input dan Output Data Barang (C++)

## 📝 Deskripsi

Program ini digunakan untuk **menginput dan menampilkan data barang** menggunakan **array dua dimensi** di bahasa pemrograman C++.
Setiap barang memiliki tiga atribut utama:

* Nama Barang
* Stok
* Harga

Data yang dimasukkan oleh pengguna akan disimpan dalam array, lalu ditampilkan dalam bentuk tabel di terminal.

---

## ⚙️ Fitur Program

* Input jumlah barang secara dinamis.
* Input data (nama, stok, harga) menggunakan `getline()` agar bisa menangani spasi.
* Penyimpanan data dalam array dua dimensi.
* Output data dalam format tabel yang rapi.

---

## 💻 Bahasa dan Tools

* **Bahasa:** C++
* **Compiler:** g++ atau setara
* **Lingkungan:** Terminal / Command Prompt / IDE seperti Code::Blocks, Visual Studio Code, atau Dev-C++

---

## 🧩 Cara Menjalankan Program

1. **Kompilasi program:**

   ```bash
   g++ data_barang.cpp -o data_barang
   ```

2. **Jalankan program:**

   ```bash
   ./data_barang
   ```

3. **Masukkan jumlah barang** yang ingin diinput.

4. **Isi data barang** (nama, stok, harga).

5. **Lihat hasil output** berupa tabel data barang.

---

## 🧠 Contoh Output

```
Masukkan jumlah barang: 2

Barang ke-1
Nama Barang : Pulpen
Stok        : 10
Harga       : 2000

Barang ke-2
Nama Barang : Buku
Stok        : 5
Harga       : 6000


Nama Barang    Stok    Harga
----------------------------------
Pulpen         10      2000
Buku           5       6000
```

---

## 🧩 Struktur Data yang Digunakan

Program menggunakan array dua dimensi bertipe `string`:

```cpp
string data[barang][3];
```

* `data[i][0]` → Nama Barang
* `data[i][1]` → Stok
* `data[i][2]` → Harga

---