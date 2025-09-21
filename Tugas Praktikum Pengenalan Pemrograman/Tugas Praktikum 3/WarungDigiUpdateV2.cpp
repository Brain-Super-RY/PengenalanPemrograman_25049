#include <iostream>  
#include <string>    
using namespace std;

/*
  ---------------------------------------------
  Utility kecil: fungsi-fungsi yang membantu UI
  ---------------------------------------------
  Fungsi-fungsi ini digabung agar bagian main tetap bersih dan mudah dibaca.
*/

// clearScreen(): bersihkan terminal agar menu tidak "dobel" saat discroll.
// - Menggunakan perintah system("cls") pada Windows dan system("clear") pada Unix/Linux/Mac.
// - Perlu diingat: pemanggilan system() bukan cara paling "aman", tapi praktis untuk praktik/demonstrasi.
void clearScreen() {
#ifdef _WIN32
    system("cls");   // Windows
#else
    system("clear"); // Linux / macOS
#endif
}

// pauseAndWait(): menunggu user tekan ENTER sebelum kembali ke menu.
// - Kita menggunakan cin.ignore(1000, '\n') untuk menghabiskan newline
//   yang mungkin tersisa di buffer, lalu cin.get() menunggu ENTER.
// - Catatan: angka 1000 di sini sifatnya "cukup besar" untuk praktik; bukan solusi paling robust.
void pauseAndWait() {
    cout << "\nTekan ENTER untuk kembali ke menu...";
    cin.ignore(1000, '\n'); // buang newline / sisa input bila ada
    cin.get();              // tunggu ENTER
}

// toLowerSimple(): konversi sederhana dari string ke lowercase (hanya untuk A-Z ASCII)
// - Berguna untuk pencarian nama barang case-insensitive tanpa include <cctype>.
// - Kelemahan: hanya bekerja benar untuk huruf ASCII A-Z; karakter non-ASCII tidak ditangani.
string toLowerSimple(const string &s) {
    string out = s;
    for (size_t i = 0; i < out.length(); ++i) {
        char c = out[i];
        if (c >= 'A' && c <= 'Z') out[i] = c + 32; // 'A'(65) -> 'a'(97)
    }
    return out;
}

// findItemByName(): cari index barang berdasarkan nama (case-insensitive)
// - Mengembalikan index (0..n-1) jika ditemukan, atau -1 jika tidak.
int findItemByName(const string names[], int n, const string &query) {
    string q = toLowerSimple(query);
    for (int i = 0; i < n; ++i) {
        if (toLowerSimple(names[i]) == q) return i;
    }
    return -1;
}

/*
  -----------------------
  MAIN PROGRAM
  -----------------------
  Struktur program:
  - Inisialisasi data (nama, stok, harga)
  - Loop menu utama (lihat, beli, cetak struk, keluar)
  - Fitur utama: menambah ke keranjang, update stok realtime, hitung diskon/pajak, bayar
*/

int main() {
    // JUMLAH_BARANG konstanta untuk ukuran array; memudahkan bila ingin ubah jumlah barang
    const int JUMLAH_BARANG = 15;

    // Array nama barang (tipe string)
    // Contoh: "Indomie Goreng", dsb.
    string namaBarang[JUMLAH_BARANG] = {
        "Indomie Goreng",
        "Teh Botol Kotak",
        "Silverqueen 62g",
        "Chitato Sapi Panggang",
        "Susu UHT Ultra Milk",
        "Beras Premium 5kg",
        "Aqua Botol 600ml",
        "Kopi Kapal Api Sachet",
        "Energen Cereal",
        "Oreo Coklat",
        "Roma Malkist",
        "Tango Wafer",
        "Mie Sedap Soto",
        "Good Day Cappuccino",
        "Yakult 5pcs"
    };

    // Array stok tiap barang (int)
    int stok[JUMLAH_BARANG] = {
        120, 90, 60, 75, 110,
        80, 150, 200, 95, 140,
        130, 125, 100, 95, 85
    };

    // Array harga tiap barang (double agar ada pecahan)
    // Kita menggunakan double; untuk aplikasi nyata sebaiknya menyimpan currency dalam integer (mis. sen)
    double harga[JUMLAH_BARANG] = {
        3800.50, 4200.00, 16500.00, 13200.00, 7000.00,
        70000.00, 5200.00, 2200.00, 2700.00, 8500.00,
        7800.00, 9400.00, 3400.00, 3800.00, 9500.00
    };

    // Keranjang: jumlah yang dibeli per item selama sesi (inisialisasi 0)
    int keranjang[JUMLAH_BARANG] = {0};

    // pilihanMenu: kontrol menu, -1 default
    int pilihanMenu = -1;

    // Loop utama program: tampilkan menu sampai user pilih 0 (keluar)
    do {
        clearScreen(); // bersihkan layar tiap kali tampil menu

        // Tampilan menu utama
        cout << "===== WARUNG DIGI =====" << endl;
        cout << "1. Lihat Daftar Barang" << endl;
        cout << "2. Beli Barang" << endl;
        cout << "3. Cetak Struk & Bayar" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";

        // Baca input menu (menggunakan >> karena input satu angka sederhana)
        cin >> pilihanMenu;
        // Setelah >> ada newline tersisa; buang supaya getline di bagian lain aman
        cin.ignore(1000, '\n');

        // ----- MENU 1: Lihat Daftar Barang ---------------------------------
        if (pilihanMenu == 1) {
            clearScreen();
            cout << "=== DAFTAR BARANG WARUNG DIGI ===" << endl;
            cout << "No  Nama Barang               Stok   Harga" << endl;
            cout << "----------------------------------------------" << endl;

            // Loop ke semua barang, cetak nomor, nama, stok, dan harga
            // Perhatikan padding manual: kita gunakan perhitungan panjang string untuk alignment sederhana
            for (int i = 0; i < JUMLAH_BARANG; ++i) {
                cout << (i+1) << ". " << namaBarang[i];
                int pad = 22 - (int)namaBarang[i].length(); // 22 = kolom "nama" lebar asumsi
                if (pad < 1) pad = 1;
                for (int s = 0; s < pad; ++s) cout << ' ';
                cout << stok[i] << "    Rp " << harga[i] << endl;
            }
            cout << "----------------------------------------------" << endl;

            // Pause agar user bisa membaca daftar sebelum kembali ke menu
            pauseAndWait();
        }

        // ----- MENU 2: Beli Barang -----------------------------------------
        else if (pilihanMenu == 2) {
            clearScreen();
            cout << "=== BELI BARANG ===" << endl;
            cout << "Masukkan nomor atau nama barang: ";

            // Baca seluruh baris: memungkinkan input nama yang mengandung spasi
            string input;
            getline(cin, input);

            // Trim sederhana: hapus spasi/tabs di kiri dan kanan
            while (!input.empty() && (input.front() == ' ' || input.front() == '\t')) input.erase(0,1);
            while (!input.empty() && (input.back() == ' ' || input.back() == '\t')) input.pop_back();

            int index = -1;                // index barang yang dipilih
            bool inputIsNumber = true;     // flag bila user memasukkan nomor

            // Jika input kosong -> batalkan pembelian
            if (input.empty()) {
                cout << "Input kosong. Batal." << endl;
                pauseAndWait();
                continue;
            }

            // Periksa apakah seluruh karakter adalah digit (nomor)
            for (size_t i = 0; i < input.size(); ++i) {
                if (!(input[i] >= '0' && input[i] <= '9')) { inputIsNumber = false; break; }
            }

            // Jika nomor: ubah manual ke int (menghindari stoi agar aman tanpa try/catch)
            if (inputIsNumber) {
                int nomor = 0;
                for (size_t i = 0; i < input.size(); ++i) {
                    nomor = nomor * 10 + (input[i] - '0'); // operator aritmatika +, * dan operator assignment
                }
                if (nomor >= 1 && nomor <= JUMLAH_BARANG) index = nomor - 1;
                else index = -1;
            }
            // Jika bukan nomor: cari berdasarkan nama, case-insensitive
            else {
                index = findItemByName(namaBarang, JUMLAH_BARANG, input);
            }

            // Jika tidak ditemukan -> beri pesan dan kembali ke menu
            if (index == -1) {
                cout << "Barang tidak ditemukan." << endl;
                pauseAndWait();
                continue;
            }

            // Tampilkan detail pilihan dan minta jumlah
            cout << "Anda memilih: " << namaBarang[index]
                 << " | Stok: " << stok[index]
                 << " | Harga: Rp " << harga[index] << endl;
            cout << "Masukkan jumlah beli: ";

            int jumlahBeli;
            cin >> jumlahBeli;           // baca jumlah (diasumsikan integer)
            cin.ignore(1000, '\n');      // buang newline

            // Validasi: jumlah > 0 dan tidak melebihi stok
            if (jumlahBeli <= 0 || jumlahBeli > stok[index]) {
                cout << "Jumlah tidak valid atau stok tidak mencukupi." << endl;
                pauseAndWait();
                continue;
            }

            // Tambah ke keranjang dan kurangi stok (update realtime)
            // Operator assignment (+=, -=) dipakai di sini
            keranjang[index] += jumlahBeli;
            stok[index] -= jumlahBeli;

            cout << "Ditambahkan ke keranjang: " << jumlahBeli << " x " << namaBarang[index] << endl;
            pauseAndWait();
        }

        // ----- MENU 3: Cetak Struk & Bayar --------------------------------
        else if (pilihanMenu == 3) {
            clearScreen();

            // Variabel perhitungan
            double totalBelanja = 0.0; // akumulasi subtotal semua item
            double totalDiskon  = 0.0; // akumulasi diskon dari semua sumber

            // Header struk ringkas
            cout << "===== STRUK BELANJA WARUNG DIGI =====" << endl;
            cout << "No  Nama Barang           Qty   Harga    Subtotal" << endl;
            cout << "--------------------------------------------------" << endl;

            // Loop untuk kalkulasi subtotal tiap item dan cetak baris di struk
            for (int i = 0; i < JUMLAH_BARANG; i++) {
                if (keranjang[i] > 0) {
                    double subtotal = harga[i] * keranjang[i]; // operator * dan assignment
                    totalBelanja += subtotal;                  // operator +=

                    // Cetak baris item dengan padding manual
                    cout << (i+1) << ". " << namaBarang[i];
                    int pad = 22 - (int)namaBarang[i].length();
                    if (pad < 1) pad = 1;
                    for (int s = 0; s < pad; ++s) cout << ' ';
                    cout << keranjang[i] << "   Rp " << harga[i] << "   Rp " << subtotal << endl;

                    // Diskon per-item: jika subtotal item > 550.000 => diskon 10% untuk item ini
                    // Operator relasi (>) dipakai untuk pengecekan
                    if (subtotal > 550000) totalDiskon += subtotal * 0.10;
                }
            }

            // Jika keranjang kosong -> kembali ke menu
            if (totalBelanja == 0.0) {
                cout << "(Keranjang kosong)" << endl;
                pauseAndWait();
                continue;
            }

            // Diskon global / bertingkat:
            // - Event 5% untuk semua transaksi (selalu berlaku)
            // - Tambahan 10% jika totalBelanja > 100.000
            // - Tambahan 25% jika totalBelanja > 1.000.000
            totalDiskon += totalBelanja * 0.05;
            if (totalBelanja > 100000)  totalDiskon += totalBelanja * 0.10;
            if (totalBelanja > 1000000) totalDiskon += totalBelanja * 0.25;

            // Pilih apakah memiliki kartu member -> diskon tambahan 5%
            int isMember;
            cout << "Apakah punya kartu member? (1=Ya,0=Tidak): ";
            cin >> isMember;
            if (isMember == 1) totalDiskon += totalBelanja * 0.05;

            // Safety: pastikan diskon tidak melebihi totalBelanja
            if (totalDiskon > totalBelanja) totalDiskon = totalBelanja;

            // Hitung PPN (11%) berdasarkan (totalBelanja - totalDiskon)
            double ppn = (totalBelanja - totalDiskon) * 0.11;
            if (ppn < 0.0) ppn = 0.0; // jaga-jaga

            // Total bayar setelah diskon dan pajak
            double totalBayar = totalBelanja - totalDiskon + ppn;
            if (totalBayar < 0.0) totalBayar = 0.0; // safety

            // Tampilkan ringkasan biaya
            cout << "--------------------------------------------------" << endl;
            cout << "Total Belanja : Rp " << totalBelanja << endl;
            cout << "Total Diskon  : Rp " << totalDiskon << endl;
            cout << "PPN (11%)     : Rp " << ppn << endl;
            cout << "TOTAL BAYAR   : Rp " << totalBayar << endl;

            // Proses pembayaran: minta uang bayar sampai cukup
            double uangBayar;
            do {
                cout << "Masukkan uang bayar: Rp ";
                cin >> uangBayar;
                if (uangBayar < totalBayar) cout << "Uang tidak cukup!" << endl;
            } while (uangBayar < totalBayar);

            // Hitung kembalian
            cout << "Kembalian: Rp " << (uangBayar - totalBayar) << endl;
            cout << "===== TERIMA KASIH =====" << endl;

            // Kosongkan keranjang untuk transaksi berikutnya (reset)
            for (int i = 0; i < JUMLAH_BARANG; i++) keranjang[i] = 0;

            // Jeda supaya user sempat baca struk
            pauseAndWait();
        }

        // ----- MENU 0: Keluar ----------------------------------------------
        else if (pilihanMenu == 0) {
            clearScreen();
            cout << "Terima kasih sudah berbelanja!" << endl;
        }

        // ----- Input menu tidak valid --------------------------------------
        else {
            cout << "Menu tidak valid." << endl;
            pauseAndWait();
        }

    } while (pilihanMenu != 0); // loop sampai user pilih 0

    return 0;
}