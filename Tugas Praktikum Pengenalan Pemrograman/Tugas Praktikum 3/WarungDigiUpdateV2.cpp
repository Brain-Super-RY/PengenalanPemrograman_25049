#include <iostream>
#include <string>
using namespace std;

// ================================================================
// Fungsi bantu: konversi string jadi huruf kecil
// ================================================================
string toLowerManual(string teks) {
    string hasil = teks;
    for (int i = 0; i < hasil.length(); i++) {
        if (hasil[i] >= 'A' && hasil[i] <= 'Z') {
            hasil[i] = hasil[i] + 32; // ASCII konversi A-Z ke a-z
        }
    }
    return hasil;
}

// ================================================================
// Fungsi bantu: cek apakah string berupa angka
// ================================================================
bool isDigitManual(string teks) {
    if (teks.length() == 0) return false;
    for (int i = 0; i < teks.length(); i++) {
        if (teks[i] < '0' || teks[i] > '9') return false;
    }
    return true;
}

// ================================================================
// Fungsi bantu untuk cetak harga double dengan 2 digit pecahan
// ================================================================
void cetakHarga(double nilai) {
    int rupiah = (int) nilai;                   // bagian ribuan
    int sen = (int)((nilai - rupiah) * 100);    // bagian pecahan
    if (sen < 0) sen = -sen;
    cout << "Rp " << rupiah << ",";
    if (sen < 10) cout << "0";
    cout << sen;
}

// ================================================================
// Fungsi cari barang berdasarkan nama
// ================================================================
int cariBarang(string input, string namaBarang[], int n) {
    string cari = toLowerManual(input);
    for (int i = 0; i < n; i++) {
        if (toLowerManual(namaBarang[i]) == cari) return i;
    }
    return -1;
}

// ================================================================
// Fungsi STRUK BELANJA FINAL
// ================================================================
void cetakStrukFinal(string namaBarang[], int keranjang[], double harga[], int n, bool isMember) {
    double total = 0;
    cout << "\n=================== STRUK BELANJA WARUNG DIGI ===================" << endl;
    cout << "Nama Barang               Jumlah   Harga        Subtotal" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        if (keranjang[i] > 0) {
            double subtotal = keranjang[i] * harga[i];

            // Diskon 50% untuk masing-masing barang jika subtotal > 550k
            if (subtotal > 550000) {
                subtotal *= 0.5;
            }
            total += subtotal;

            // Cetak baris struk
            cout << namaBarang[i];
            int len = namaBarang[i].length();
            for (int j = 0; j < 25 - len; j++) cout << " ";

            cout << keranjang[i];
            if (keranjang[i] < 10) cout << "       ";
            else if (keranjang[i] < 100) cout << "      ";
            else cout << "     ";

            cetakHarga(harga[i]);
            cout << "    ";
            cetakHarga(subtotal);
            cout << endl;
        }
    }

    // ================= Hitung Diskon =================
    double diskonEvent = total * 0.05;                              // Diskon event 5%
    double diskonTambahan = (total > 100000) ? total * 0.10 : 0;    // Diskon tambahan 10% jika total > 100k
    double diskonExtra = (total > 1000000) ? total * 0.25 : 0;      // Diskon ekstra 25% jika total > 1jt
    double diskonMember = (isMember) ? total * 0.05 : 0;            // Diskon member 5% jika punya kartu member

    double totalDiskon = diskonEvent + diskonTambahan + diskonExtra + diskonMember;
    double setelahDiskon = total - totalDiskon;

    // Pajak PPN 11%
    double pajakPPN = setelahDiskon * 0.11;         
    double bayar = setelahDiskon + pajakPPN;

    // ================= Cetak Ringkasan =================
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Total Belanja : "; cetakHarga(total); cout << endl;
    cout << "Diskon Event  : "; cetakHarga(diskonEvent); cout << endl;
    cout << "Diskon 10%    : "; cetakHarga(diskonTambahan); cout << endl;
    cout << "Diskon 25%    : "; cetakHarga(diskonExtra); cout << endl;
    if (isMember) {
        cout << "Diskon Member : "; cetakHarga(diskonMember); cout << endl;
    }
    cout << "Total Diskon  : "; cetakHarga(totalDiskon); cout << endl;
    cout << "Setelah Diskon: "; cetakHarga(setelahDiskon); cout << endl;
    cout << "PPN 11%       : "; cetakHarga(pajakPPN); cout << endl;
    cout << "TOTAL BAYAR   : "; cetakHarga(bayar); cout << endl;
    cout << "=================================================================\n" << endl;

    // ================= Pilihan Metode Pembayaran =================
    cout << "Pilih metode pembayaran:\n";       // Pilihan metode pembayaran
    cout << "1. Tunai\n";                       // Pilihan metode pembayaran tunai
    cout << "2. E-Wallet\n";                    // Pilihan metode pembayaran e-wallet
    cout << "3. Kartu ATM\n";                   // Pilihan metode pembayaran kartu ATM
    cout << "4. Kartu Member\n";                // Pilihan metode pembayaran kartu member
    cout << "5. Transfer Bank\n";               // Pilihan metode pembayaran transfer bank
    cout << "Pilihan: ";                        
    int metode;
    cin >> metode;

    switch(metode) {
        case 1: cout << "Pembayaran dilakukan secara TUNAI.\n"; break;
        case 2: cout << "Pembayaran melalui E-Wallet berhasil.\n"; break;
        case 3: cout << "Pembayaran via Kartu ATM diproses.\n"; break;
        case 4: cout << "Pembayaran menggunakan Kartu Member.\n"; break;
        case 5: cout << "Transfer Bank berhasil diterima.\n"; break;
        default: cout << "Metode pembayaran tidak valid!\n"; break;
    }
}

// ================================================================
// MAIN PROGRAM
// ================================================================
int main() {
    // === DATA AWAL WARUNG DIGI ===
    string namaBarang[15] = {
        "Indomie Goreng", "Teh Botol Kotak", "Silverqueen 62g",
        "Chitato Sapi Panggang", "Susu UHT Ultra Milk",
        "Beras 5kg", "Minyak Goreng 1L", "Gula Pasir 1kg",
        "Kopi Kapal Api 165g", "Aqua Botol 600ml",
        "Sprite Kaleng 330ml", "Roti Tawar",
        "Telur Ayam 1kg", "Sabun Lifebuoy", "Shampoo Sunsilk 170ml"
    };

    int jumlah[15] = {
        35, 25, 30, 15, 30,
        500, 40, 45, 55, 20,
        70, 65, 55, 70, 60
    };

    double harga[15] = {
        3500.50, 4000.00, 15000.75, 12500.25, 6000.00,
        65000.00, 20000.50, 17000.00, 18000.25, 5000.00,
        7000.00, 12000.75, 28000.00, 8000.25, 25000.00
    };

    int keranjang[15] = {0}; 
    int pilihan;
    bool isMember = false;

    do {
        cout << "\n========= MENU WARUNG DIGI =========" << endl;
        cout << "1. Lihat detail barang" << endl;
        cout << "2. Beli barang" << endl;
        cout << "3. Cetak struk belanja" << endl;
        cout << "4. Update stok barang" << endl;
        cout << "5. Update harga barang" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\nDaftar Barang:" << endl;
            for (int i = 0; i < 15; i++) {
                cout << i + 1 << ". " << namaBarang[i]
                     << " (Stok: " << jumlah[i] << ", Harga: ";
                cetakHarga(harga[i]); cout << ")" << endl;
            }

        } else if (pilihan == 2) {
            string input;
            cout << "\nKetik nomor barang atau nama barang: ";
            cin.ignore();
            getline(cin, input);

            int index = -1;
            if (isDigitManual(input)) {
                index = stoi(input) - 1;
            } else {
                index = cariBarang(input, namaBarang, 15);
            }

            if (index >= 0 && index < 15) {
                int qty;
                cout << "Masukkan jumlah yang ingin dibeli: ";
                cin >> qty;

                if (qty > 0 && qty <= jumlah[index]) {
                    keranjang[index] += qty;
                    jumlah[index] -= qty;
                    cout << "Barang berhasil ditambahkan ke keranjang!" << endl;
                } else {
                    cout << "Jumlah tidak valid atau stok tidak mencukupi!" << endl;
                }
            } else {
                cout << "Barang tidak ditemukan!" << endl;
            }

        } else if (pilihan == 3) {
            cout << "Apakah Anda punya kartu member? (y/n): ";
            char jawab;
            cin >> jawab;
            if (jawab == 'y' || jawab == 'Y') isMember = true;
            cetakStrukFinal(namaBarang, keranjang, harga, 15, isMember);

            cout << "\n=== Data Barang Terupdate Setelah Transaksi ===" << endl;
            for (int i = 0; i < 15; i++) {
                cout << i + 1 << ". " << namaBarang[i]
                     << " (Stok: " << jumlah[i] << ", Harga: ";
                cetakHarga(harga[i]); cout << ")" << endl;
            }

        } else if (pilihan == 4) {
            int idx, stokBaru;
            cout << "\nMasukkan nomor barang untuk update stok: ";
            cin >> idx;
            if (idx >= 1 && idx <= 15) {
                cout << "Stok baru untuk " << namaBarang[idx-1] << ": ";
                cin >> stokBaru;
                jumlah[idx-1] = stokBaru;
                cout << "Stok berhasil diupdate!\n";
            } else {
                cout << "Nomor barang tidak valid!\n";
            }

        } else if (pilihan == 5) {
            int idx;
            double hargaBaru;
            cout << "\nMasukkan nomor barang untuk update harga: ";
            cin >> idx;
            if (idx >= 1 && idx <= 15) {
                cout << "Harga baru untuk " << namaBarang[idx-1] << ": ";
                cin >> hargaBaru;
                harga[idx-1] = hargaBaru;
                cout << "Harga berhasil diupdate!\n";
            } else {
                cout << "Nomor barang tidak valid!\n";
            }

        }

    } while (pilihan != 0);

    cout << "\nTerima kasih telah berbelanja di Warung Digi!" << endl;
    return 0;
}