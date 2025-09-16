---

# 🏪 Warung Digi – Sistem Kasir Warung Sederhana

## 📖 Deskripsi

Warung Digi adalah program berbasis **C++** yang mensimulasikan sistem kasir di sebuah warung/minimarket sederhana.
Dibuat untuk keperluan **tugas praktikum 3** (materi operator, array, perulangan, percabangan), program ini dirancang agar:

* Memiliki data barang dengan stok dan harga.
* Bisa menampilkan struk belanja profesional.
* Menerapkan sistem diskon dan pajak sesuai kondisi nyata.
* Mendukung beberapa metode pembayaran.
* Data barang (stok & harga) bisa diupdate secara realtime.

Program ini menggunakan library **wajib**:

* `<iostream>` untuk input & output.
* `<string>` untuk manipulasi teks.

---

## ⚡ Fitur Utama

### 🎁 Manajemen Barang

* Menyediakan **15 barang** dengan harga yang bervariasi dan dapat berubah ubah.
* Setiap barang punya **stok yang bervariasi dan berubah ubah**.
* Stok dan harga bisa diupdate dari menu admin.

### 🛒 Sistem Belanja

* Pengguna bisa memilih barang berdasarkan **nomor** atau **nama barang**.
* Setiap pembelian akan otomatis mengurangi stok barang.
* Struk belanja ditampilkan setelah transaksi selesai.

### 💸 Diskon & Pajak

Diskon dihitung otomatis sesuai kondisi:

1. **Diskon Event**: 5% untuk semua barang.
2. **Diskon Tambahan**: 10% jika total belanja > Rp100.000.
3. **Diskon Barang**: 50% untuk barang dengan subtotal > Rp550.000.
4. **Diskon Besar**: 25% jika total belanja > Rp1.000.000.
5. **Diskon Member**: 5% tambahan jika menggunakan kartu member.
6. **Pajak (PPN 11%)**: otomatis ditambahkan ke total bayar sesuai peraturan pajak di Indonesia.

### 💳 Metode Pembayaran

Program mendukung berbagai opsi:

* Tunai 💵
* E-Wallet 📱
* Kartu ATM 💳
* Kartu Member 🎫
* Transfer Bank 🏦

### 📊 Struk Profesional

* Menampilkan nama barang, jumlah, harga satuan, subtotal, total diskon, PPN, dan total bayar.

### 🔧 Menu Admin

Selain belanja, tersedia juga menu:

* **Update Stok Barang**
* **Update Harga Barang**
  Sehingga data barang benar-benar dinamis.

---

## 🛠️ Operator yang Digunakan

Program ini mengimplementasikan berbagai operator sesuai materi praktikum 3:

* **Aritmatika**: `+`, `-`, `*`, `/` → menghitung total, diskon, pajak.
* **Relasi/Perbandingan**: `>`, `<`, `>=`, `<=`, `==` → pengecekan kondisi diskon.
* **Logika**: `&&`, `||` → validasi input dan kombinasi syarat diskon.
* **Bitwise (opsional contoh)**: digunakan untuk menandai flag diskon (misalnya `diskonAktif |= 1`).
* **Assignment & shorthand**: `=`, `+=`, `-=` → update stok & harga.

---

## 🚀 Cara Menjalankan

### 1. Compile Program

Gunakan compiler g++ (Linux/Mac/Windows via MinGW/WSL):

```bash
g++ warung_digi.cpp -o warung_digi
```

### 2. Jalankan Program

```bash
./warung_digi
```

### 3. Menu Utama

* `1` → Lihat daftar barang
* `2` → Beli barang
* `3` → Cetak struk belanja
* `4` → Update stok barang
* `5` → Update harga barang
* `0` → Keluar

---

## 📊 Contoh Output Struk

```
=================== STRUK BELANJA WARUNG DIGI ===================
Nama Barang               Jumlah   Harga        Subtotal
-----------------------------------------------------------------
Indomie Goreng            5        Rp 3500.50   Rp 17502.50
Beras Premium 5kg         2        Rp 65000.00  Rp 130000.00
Aqua Botol 600ml          10       Rp 5000.00   Rp 50000.00
-----------------------------------------------------------------
Total Belanja   : Rp 197502.50
Diskon Event    : Rp 9875.12
Diskon 10%      : Rp 19750.25
Diskon Member   : Rp 9875.12
Total Diskon    : Rp 394... 
Setelah Diskon  : Rp 158002.01
PPN 11%         : Rp 17380.22
TOTAL BAYAR     : Rp 175382.23
=================================================================

Pilih metode pembayaran:
1. Tunai
2. E-Wallet
3. Kartu ATM
4. Kartu Member
5. Transfer Bank

Pilihan: 2
Pembayaran melalui E-Wallet berhasil ✅
```

---

## 👨‍💻 Catatan Developer


* Fungsi tambahan seperti `toLowerManual`, `isDigitManual`, dan `cetakHarga` dibuat agar tidak bergantung pada library eksternal.
* Semua data barang disimpan dalam array sehingga mudah diubah.
* Sistem diskon & pajak dapat diubah sesuai kebutuhan praktikum atau simulasi bisnis.
* Karena output tabel berbasis spasi, tampilan bisa sedikit berbeda antar terminal/device, namun tetap bisa dibaca rapi.

---