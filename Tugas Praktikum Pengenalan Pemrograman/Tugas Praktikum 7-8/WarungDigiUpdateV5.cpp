#include <iostream>  // Untuk input dan output
#include <string>    // Untuk menggunakan tipe data string
using namespace std; // Agar tidak perlu menulis std:: setiap kali

// Fungsi utama
int main()
{
    const int JUMLAH_BARANG = 15; // Jumlah jenis barang di warung

    // Data nama barang
    string namaBarang[JUMLAH_BARANG] = {
        "Indomie Goreng", "Teh Botol Kotak", "Silverqueen 62g",
        "Chitato Sapi Panggang", "Susu UHT Ultra Milk", "Beras Premium 5kg",
        "Aqua Botol 600ml", "Kopi Kapal Api Sachet", "Energen Cereal",
        "Oreo Coklat", "Roma Malkist", "Tango Wafer",
        "Mie Sedap Soto", "Good Day Cappuccino", "Yakult 5pcs"};
    // Stok barang
    int stok[JUMLAH_BARANG] = {
        120, 90, 60, 75, 110, 80, 150, 200, 95, 140, 130, 125, 100, 95, 85};
    // Harga barang
    double harga[JUMLAH_BARANG] = {
        3800.50, 4200.00, 16500.00, 13200.00, 7000.00, 70000.00,
        5200.00, 2200.00, 2700.00, 8500.00, 7800.00, 9400.00,
        3400.00, 3800.00, 9500.00};
    // Keranjang belanja
    int keranjang[JUMLAH_BARANG] = {0};

    // Variabel untuk history transaksi
    string namaPelanggan1 = "";
    string namaPelanggan2 = "";
    double totalPelanggan1 = 0.0;
    double totalPelanggan2 = 0.0;
    int pelangganKe = 1;

    int pilihan;

    // Menu utama dalam loop
    do
    {
        system("cls"); // Bersihkan layar (untuk Windows, gunakan "clear" untuk Linux/Mac)
        // Tampilkan menu
        cout << "===== WARUNG DIGI =====" << endl;
        cout << "1. Tambah Stok" << endl;                    // Menu Tambah Stok
        cout << "2. Kurangi Stok" << endl;                   // Menu Kurangi Stok
        cout << "3. Lihat Stok" << endl;                     // Menu Lihat Stok
        cout << "4. Keluar" << endl;                         // Menu Keluar
        cout << "5. Lihat Daftar Barang" << endl;            // Menu Lihat Daftar Barang
        cout << "6. Beli Barang" << endl;                    // Menu Beli Barang
        cout << "7. Cetak Struk & Bayar" << endl;            // Menu Cetak Struk & Bayar
        cout << "8. Bandingkan Belanja 2 Pelanggan" << endl; // Menu Bandingkan Belanja 2 Pelanggan
        cout << "Pilih menu: ";                              // Input pilihan menu
        cin >> pilihan;                                      // Baca pilihan menu

        // Proses pilihan menu
        switch (pilihan)
        {
        case 1:
        { // Tambah Stok
            system("cls");
            cout << "=== TAMBAH STOK BARANG ===" << endl; // Judul menu
            cout << "Daftar Barang:" << endl;             // Tampilkan daftar barang

            for (int i = 0; i < JUMLAH_BARANG; i++)
            {                                                                                     // Loop untuk menampilkan semua barang
                cout << (i + 1) << ". " << namaBarang[i] << " (Stok: " << stok[i] << ")" << endl; // Tampilkan nomor, nama, dan stok barang
            }

            int nomorBarang, jumlahTambah;           // Variabel untuk nomor barang dan jumlah tambah
            cout << "\nPilih nomor barang (1-15): "; // Input nomor barang
            cin >> nomorBarang;                      // Baca nomor barang

            if (nomorBarang >= 1 && nomorBarang <= JUMLAH_BARANG)
            {                                                     // Validasi nomor barang
                int index = nomorBarang - 1;                      // Hitung indeks array
                cout << "Barang: " << namaBarang[index] << endl;  // Tampilkan nama barang
                cout << "Stok saat ini: " << stok[index] << endl; // Tampilkan stok saat ini
                cout << "Jumlah tambah stok: ";                   // Input jumlah tambah stok
                cin >> jumlahTambah;                              // Baca jumlah tambah

                if (jumlahTambah > 0)
                { // Validasi jumlah tambah
                    stok[index] += jumlahTambah;
                    cout << "Stok berhasil ditambahkan!" << endl; // Tambah stok
                    cout << "Stok baru: " << stok[index] << endl; // Tampilkan stok baru
                }
                else
                {
                    cout << "Jumlah tidak valid!" << endl; // Pesan error jika jumlah tidak valid
                }
            }
            else
            {
                cout << "Nomor barang tidak valid!" << endl; // Pesan error jika nomor barang tidak valid
            }

            cout << "\nTekan ENTER untuk kembali..."; // Tunggu input ENTER
            cin.ignore();                             // Bersihkan buffer
            cin.get();
            break; // Kembali ke menu utama
        }

        case 2:
        { // Kurangi Stok
            system("cls");
            cout << "=== KURANGI STOK BARANG ===" << endl; // Judul menu
            cout << "Daftar Barang:" << endl;              // Tampilkan daftar barang

            for (int i = 0; i < JUMLAH_BARANG; i++)
            {                                                                                     // Loop untuk menampilkan semua barang
                cout << (i + 1) << ". " << namaBarang[i] << " (Stok: " << stok[i] << ")" << endl; // Tampilkan nomor, nama, dan stok barang
            }

            int nomorBarang, jumlahKurang;           // Variabel untuk nomor barang dan jumlah pengurangan
            cout << "\nPilih nomor barang (1-15): "; // Input nomor barang
            cin >> nomorBarang;                      // Baca nomor barang

            if (nomorBarang >= 1 && nomorBarang <= JUMLAH_BARANG)
            {                                                     // Validasi nomor barang
                int index = nomorBarang - 1;                      // Hitung indeks array
                cout << "Barang: " << namaBarang[index] << endl;  // Tampilkan nama barang
                cout << "Stok saat ini: " << stok[index] << endl; // Tampilkan stok saat ini
                cout << "Jumlah kurangi stok: ";                  // Input jumlah stok yang ingin dikurangi
                cin >> jumlahKurang;                              // Baca jumlah pengurangan

                if (jumlahKurang > 0 && jumlahKurang <= stok[index])
                {                                                 // Validasi jumlah (harus positif dan <= stok)
                    stok[index] -= jumlahKurang;                  // Kurangi stok
                    cout << "Stok berhasil dikurangi!" << endl;   // Tampilkan pesan sukses
                    cout << "Stok baru: " << stok[index] << endl; // Tampilkan stok terbaru
                }
                else
                {
                    cout << "Jumlah tidak valid atau melebihi stok!" << endl; // Pesan error jika input tidak valid
                }
            }
            else
            {
                cout << "Nomor barang tidak valid!" << endl; // Pesan error jika nomor barang di luar jangkauan
            }

            cout << "\nTekan ENTER untuk kembali..."; // Tunggu user menekan ENTER
            cin.ignore();                             // Bersihkan buffer input
            cin.get();                                // Tunggu input ENTER
            break;                                    // Kembali ke menu utama
        }

        case 3:
        { // Lihat Stok
            system("cls");
            cout << "=== STOK BARANG WARUNG DIGI ===" << endl;          // Judul menu
            cout << "No  Nama Barang               Stok" << endl;       // Header tabel
            cout << "----------------------------------------" << endl; // Garis pembatas

            for (int i = 0; i < JUMLAH_BARANG; i++)
            {                                             // Loop untuk menampilkan semua barang
                cout << (i + 1) << ". " << namaBarang[i]; // Tampilkan nomor dan nama barang
                int spasi = 25 - namaBarang[i].length();  // Hitung jarak antar kolom
                for (int j = 0; j < spasi; j++)
                    cout << " ";         // Tambahkan spasi agar rata
                cout << stok[i] << endl; // Tampilkan stok barang
            }

            cout << "\nTekan ENTER untuk kembali..."; // Tunggu input ENTER
            cin.ignore();
            cin.get();
            break;
        }

        case 4:
        { // Keluar
            system("cls");
            cout << "===== TERIMA KASIH =====" << endl;                 // Pesan perpisahan
            cout << "Warung Digi - Belanja Hemat Setiap Hari!" << endl; // Slogan toko
            break;
        }

        case 5:
        { // Lihat Daftar Barang
            system("cls");
            cout << "=== DAFTAR BARANG WARUNG DIGI ===" << endl;              // Judul menu
            cout << "No  Nama Barang               Stok   Harga" << endl;     // Header tabel
            cout << "----------------------------------------------" << endl; // Garis pembatas

            for (int i = 0; i < JUMLAH_BARANG; i++)
            {                                             // Loop untuk menampilkan daftar barang
                cout << (i + 1) << ". " << namaBarang[i]; // Tampilkan nomor dan nama barang
                int spasi = 35 - namaBarang[i].length();  // Hitung spasi agar kolom rapi
                for (int j = 0; j < spasi; j++)
                    cout << " ";                                  // Tambahkan spasi
                cout << stok[i] << "    Rp " << harga[i] << endl; // Tampilkan stok dan harga
            }

            cout << "\nTekan ENTER untuk kembali..."; // Tunggu ENTER
            cin.ignore();
            cin.get();
            break;
        }

        case 6:
        { // Beli Barang
            system("cls");
            cout << "=== BELI BARANG ===" << endl;              // Judul menu
            cout << "Masukkan nomor (1-15) atau nama barang: "; // Petunjuk input

            string input;        // Variabel untuk menampung input pengguna
            cin.ignore();        // Bersihkan buffer
            getline(cin, input); // Baca input sebagai string (bisa angka/nama)

            int index = -1; // Inisialisasi indeks barang (-1 artinya belum ditemukan)

            // Cek apakah input berupa angka
            bool isNumber = true; // Asumsi awal input adalah angka
            for (int i = 0; i < input.length(); i++)
            { // Loop untuk mengecek tiap karakter
                if (input[i] < '0' || input[i] > '9')
                { // Jika ada huruf, maka bukan angka
                    isNumber = false;
                    break;
                }
            }

            if (isNumber && !input.empty())
            { // Jika input angka dan tidak kosong
                int nomor = 0;
                for (int i = 0; i < input.length(); i++)
                { // Konversi string angka menjadi integer
                    nomor = nomor * 10 + (input[i] - '0');
                }
                if (nomor >= 1 && nomor <= JUMLAH_BARANG)
                {                      // Validasi rentang nomor
                    index = nomor - 1; // Hitung indeks array
                }
            }
            else
            { // Jika input berupa teks/nama barang
                for (int i = 0; i < JUMLAH_BARANG; i++)
                {
                    if (namaBarang[i] == input)
                    {              // Bandingkan nama barang
                        index = i; // Simpan indeks jika cocok
                        break;
                    }
                }
            }

            if (index == -1)
            { // Jika barang tidak ditemukan
                cout << "Barang tidak ditemukan!" << endl;
            }
            else
            {
                cout << "Barang: " << namaBarang[index] << endl; // Tampilkan nama barang
                cout << "Stok: " << stok[index] << endl;         // Tampilkan stok barang
                cout << "Harga: Rp " << harga[index] << endl;    // Tampilkan harga barang
                cout << "Jumlah beli: ";                         // Input jumlah pembelian

                int jumlah; // Variabel jumlah pembelian
                cin >> jumlah;

                if (jumlah > 0 && jumlah <= stok[index])
                {                                                         // Validasi jumlah pembelian
                    keranjang[index] += jumlah;                           // Tambahkan ke keranjang
                    stok[index] -= jumlah;                                // Kurangi stok
                    cout << "Berhasil ditambahkan ke keranjang!" << endl; // Pesan sukses
                }
                else
                {
                    cout << "Jumlah tidak valid atau stok habis!" << endl; // Pesan error
                }
            }

            cout << "Tekan ENTER untuk kembali..."; // Tunggu user tekan ENTER
            cin.ignore();
            cin.get();
            break;
        }

        case 7:
        { // Cetak Struk & Bayar
            system("cls");
            string namaPelanggan; // Variabel untuk menyimpan nama pelanggan
            cout << "Nama pelanggan: ";
            cin.ignore();
            getline(cin, namaPelanggan); // Input nama pelanggan

            double totalBelanja = 0.0; // Total belanja keseluruhan
            bool adaBarang = false;    // Penanda apakah keranjang berisi barang

            cout << "\n===== STRUK BELANJA WARUNG DIGI =====" << endl; // Header struk
            cout << "Pelanggan: " << namaPelanggan << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "Nama Barang               Qty   Harga    Subtotal" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < JUMLAH_BARANG; i++)
            { // Loop menampilkan barang yang dibeli
                if (keranjang[i] > 0)
                { // Hanya tampilkan barang yang dibeli
                    adaBarang = true;
                    double subtotal = harga[i] * keranjang[i]; // Hitung subtotal per barang
                    totalBelanja += subtotal;                  // Tambahkan ke total belanja

                    cout << namaBarang[i];
                    int spasi = 25 - namaBarang[i].length(); // Rata kolom nama
                    for (int j = 0; j < spasi; j++)
                        cout << " ";
                    cout << keranjang[i] << "   Rp " << harga[i]
                         << "   Rp " << subtotal << endl;
                }
            }

            if (!adaBarang)
            { // Jika keranjang kosong
                cout << "(Keranjang kosong)" << endl;
                cout << "Tekan ENTER untuk kembali...";
                cin.get();
                break;
            }

            // Hitung diskon berdasarkan total belanja
            double totalDiskon = 0.0;
            string pesanDiskon = "";

            if (totalBelanja >= 100000)
            {
                totalDiskon = totalBelanja * 0.10; // Diskon 10%
                pesanDiskon = "Mendapat Diskon 10%";
            }
            else if (totalBelanja >= 50000)
            {
                totalDiskon = totalBelanja * 0.05; // Diskon 5%
                pesanDiskon = "Mendapat Diskon 5%";
            }
            else
            {
                pesanDiskon = "Tidak ada diskon";
            }

            cout << "\nTotal Belanja : Rp " << totalBelanja << endl;
            cout << "Keterangan    : " << pesanDiskon << endl;
            if (totalDiskon > 0)
            {
                cout << "Total Diskon  : Rp " << totalDiskon << endl;
            }

            cout << "Punya kartu member? (1=Ya, 0=Tidak): "; // Diskon tambahan jika member
            int member;
            cin >> member;
            if (member == 1)
            {
                totalDiskon += totalBelanja * 0.05; // Diskon tambahan 5%
            }

            if (totalDiskon > totalBelanja)
                totalDiskon = totalBelanja; // Pastikan diskon tidak melebihi total

            double ppn = (totalBelanja - totalDiskon) * 0.11;     // Hitung pajak (11%)
            double totalBayar = totalBelanja - totalDiskon + ppn; // Hitung total bayar akhir

            cout << "--------------------------------------------------" << endl;
            cout << "Total Belanja : Rp " << totalBelanja << endl;
            cout << "Total Diskon  : Rp " << totalDiskon << endl;
            cout << "PPN (11%)     : Rp " << ppn << endl;
            cout << "TOTAL BAYAR   : Rp " << totalBayar << endl;

            // Simpan data pelanggan untuk perbandingan
            if (pelangganKe == 1)
            {
                namaPelanggan1 = namaPelanggan;
                totalPelanggan1 = totalBayar;
                pelangganKe = 2;
                cout << "\n[Data pelanggan 1 tersimpan untuk perbandingan]" << endl;
            }
            else
            {
                namaPelanggan2 = namaPelanggan;
                totalPelanggan2 = totalBayar;
                pelangganKe = 1;
                cout << "\n[Data pelanggan 2 tersimpan untuk perbandingan]" << endl;
            }

            double uangBayar; // Variabel untuk jumlah uang pembayaran
            do
            {
                cout << "Masukkan uang bayar: Rp ";
                cin >> uangBayar;
                if (uangBayar < totalBayar)
                {
                    cout << "Uang tidak cukup!" << endl; // Validasi uang bayar
                }
            } while (uangBayar < totalBayar);

            cout << "Kembalian: Rp " << (uangBayar - totalBayar) << endl; // Hitung dan tampilkan kembalian
            cout << "===== TERIMA KASIH =====" << endl;

            for (int i = 0; i < JUMLAH_BARANG; i++)
            {
                keranjang[i] = 0; // Kosongkan keranjang setelah pembayaran
            }

            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            cin.get();
            break;
        }

        case 8:
        { // Bandingkan Belanja 2 Pelanggan
            system("cls");
            cout << "===== PERBANDINGAN BELANJA DUA PELANGGAN =====" << endl; // Judul menu
            cout << "============= WARUNG DIGI =============" << endl
                 << endl;

            if (namaPelanggan1 == "" && namaPelanggan2 == "")
            { // Jika belum ada data pelanggan
                cout << "Belum ada data pelanggan!" << endl;
                cout << "Silakan lakukan transaksi terlebih dahulu (menu 7)." << endl;
                cout << "\nAtau input manual:" << endl;

                cout << "=== DATA PELANGGAN PERTAMA ===" << endl;
                cout << "Nama pelanggan: ";
                cin.ignore();
                getline(cin, namaPelanggan1);
                cout << "Total belanja: Rp ";
                cin >> totalPelanggan1;

                cout << "\n=== DATA PELANGGAN KEDUA ===" << endl;
                cout << "Nama pelanggan: ";
                cin.ignore();
                getline(cin, namaPelanggan2);
                cout << "Total belanja: Rp ";
                cin >> totalPelanggan2;
            }
            else if (namaPelanggan2 == "")
            { // Jika baru ada 1 data pelanggan
                cout << "Hanya ada 1 data pelanggan (" << namaPelanggan1 << ")" << endl;
                cout << "Input data pelanggan kedua:" << endl;
                cout << "Nama pelanggan: ";
                cin.ignore();
                getline(cin, namaPelanggan2);
                cout << "Total belanja: Rp ";
                cin >> totalPelanggan2;
            }

            cout << "\n===== RINGKASAN DATA =====" << endl; // Tampilkan data pelanggan
            cout << "Pelanggan 1: " << namaPelanggan1 << " = Rp " << totalPelanggan1 << endl;
            cout << "Pelanggan 2: " << namaPelanggan2 << " = Rp " << totalPelanggan2 << endl;

            cout << "\n===== HASIL PERBANDINGAN =====" << endl; // Perbandingan nilai total belanja

            bool samaBelanja = (totalPelanggan1 == totalPelanggan2);
            cout << "Belanja sama (==): " << (samaBelanja ? "YA" : "TIDAK");
            cout << " (" << samaBelanja << ")" << endl;

            bool berbedaBelanja = (totalPelanggan1 != totalPelanggan2);
            cout << "Belanja berbeda (!=): " << (berbedaBelanja ? "YA" : "TIDAK");
            cout << " (" << berbedaBelanja << ")" << endl;

            bool lebihBesar = (totalPelanggan1 > totalPelanggan2);
            cout << namaPelanggan1 << " > " << namaPelanggan2 << ": ";
            cout << (lebihBesar ? "YA" : "TIDAK") << " (" << lebihBesar << ")" << endl;

            bool lebihKecil = (totalPelanggan1 < totalPelanggan2);
            cout << namaPelanggan1 << " < " << namaPelanggan2 << ": ";
            cout << (lebihKecil ? "YA" : "TIDAK") << " (" << lebihKecil << ")" << endl;

            bool lebihBesarSama = (totalPelanggan1 >= totalPelanggan2);
            cout << namaPelanggan1 << " >= " << namaPelanggan2 << ": ";
            cout << (lebihBesarSama ? "YA" : "TIDAK") << " (" << lebihBesarSama << ")" << endl;

            bool lebihKecilSama = (totalPelanggan1 <= totalPelanggan2);
            cout << namaPelanggan1 << " <= " << namaPelanggan2 << ": ";
            cout << (lebihKecilSama ? "YA" : "TIDAK") << " (" << lebihKecilSama << ")" << endl;

            cout << "\n===== KESIMPULAN =====" << endl; // Tentukan siapa yang lebih banyak belanja
            if (totalPelanggan1 > totalPelanggan2)
            {
                cout << namaPelanggan1 << " belanja LEBIH BANYAK" << endl;
                double selisih = totalPelanggan1 - totalPelanggan2;
                cout << "Selisih: Rp " << selisih << endl;
            }
            else if (totalPelanggan1 < totalPelanggan2)
            {
                cout << namaPelanggan2 << " belanja LEBIH BANYAK" << endl;
                double selisih = totalPelanggan2 - totalPelanggan1;
                cout << "Selisih: Rp " << selisih << endl;
            }
            else
            {
                cout << "Kedua pelanggan belanja SAMA BANYAK!" << endl;
            }

            cout << "\n===== KATEGORI PELANGGAN =====" << endl; // Klasifikasi pelanggan berdasarkan total belanja
            cout << namaPelanggan1 << ": ";
            if (totalPelanggan1 >= 500000)
            {
                cout << "VIP Customer";
            }
            else if (totalPelanggan1 >= 200000)
            {
                cout << "Premium Customer";
            }
            else if (totalPelanggan1 >= 50000)
            {
                cout << "Regular Customer";
            }
            else
            {
                cout << "New Customer";
            }
            cout << endl;

            cout << namaPelanggan2 << ": ";
            if (totalPelanggan2 >= 500000)
            {
                cout << "VIP Customer";
            }
            else if (totalPelanggan2 >= 200000)
            {
                cout << "Premium Customer";
            }
            else if (totalPelanggan2 >= 50000)
            {
                cout << "Regular Customer";
            }
            else
            {
                cout << "New Customer";
            }
            cout << endl;

            double targetHarian = 300000.0; // Target total dua pelanggan per hari
            double totalDuaPelanggan = totalPelanggan1 + totalPelanggan2;

            cout << "\n===== PERBANDINGAN DENGAN TARGET =====" << endl;
            cout << "Target harian: Rp " << targetHarian << endl;
            cout << "Total 2 pelanggan: Rp " << totalDuaPelanggan << endl;

            bool capaiTarget = (totalDuaPelanggan >= targetHarian);
            cout << "Capai target: " << (capaiTarget ? "YA" : "TIDAK");
            cout << " (" << capaiTarget << ")" << endl;

            if (!capaiTarget)
            {
                double kurang = targetHarian - totalDuaPelanggan;
                cout << "Kekurangan: Rp " << kurang << endl; // Selisih jika belum capai target
            }
            else
            {
                double lebih = totalDuaPelanggan - targetHarian;
                cout << "Kelebihan: Rp " << lebih << endl; // Selisih jika melebihi target
            }

            cout << "\nTekan ENTER untuk kembali..."; // Tunggu user tekan ENTER
            cin.ignore();
            cin.get();
            break;
        }

        default:                                    // Menu tidak valid
            cout << "Menu tidak valid!" << endl;    // Pesan error
            cout << "Tekan ENTER untuk kembali..."; // Tunggu input ENTER
            cin.ignore();                           // Bersihkan buffer
            cin.get();                              // Tunggu ENTER
            break;                                  // Kembali ke menu utama
        }

    } while (pilihan != 4); // Ulangi sampai pilih menu Keluar (4)

    return 0; // Akhiri program
}