#include <iostream>
#include <string>
using namespace std;

int main() {
    // ==========================================
    // 1. DATA BARANG WARUNG
    // ==========================================
    const int JUMLAH_BARANG = 15; // jumlah total barang di warung

    // Nama barang (tipe data string)
    string namaBarang[JUMLAH_BARANG] = {
        "Indomie Goreng", "Teh Botol Kotak", "Silverqueen 62g",
        "Chitato Sapi Panggang", "Susu UHT Ultra Milk", "Beras Premium 5kg",
        "Aqua Botol 600ml", "Kopi Kapal Api Sachet", "Energen Cereal",
        "Oreo Coklat", "Roma Malkist", "Tango Wafer",
        "Mie Sedap Soto", "Good Day Cappuccino", "Yakult 5pcs"
    };

    // Stok tiap barang (tipe data integer)
    int stok[JUMLAH_BARANG] = {
        100, 80, 60, 70, 90, 120, 150, 200,
        110, 140, 130, 125, 100, 95, 85
    };

    // Harga tiap barang (tipe data double supaya ada pecahan koma)
    double harga[JUMLAH_BARANG] = {
        3500.50, 4000.00, 15500.00, 12500.00, 6500.00,
        65000.00, 5000.00, 2000.00, 2500.00, 8000.00,
        7500.00, 9000.00, 3200.00, 3500.00, 9000.00
    };

    // Keranjang belanja (menyimpan jumlah barang yang dibeli user)
    int keranjang[JUMLAH_BARANG] = {0};

    // Variabel umum untuk menu dan perhitungan
    int pilihanMenu, pilihBarang, jumlahBeli, isMember;
    double totalBelanja = 0, diskon = 0, ppn = 0, totalBayar = 0;

    // ==========================================
    // 2. MENU UTAMA WARUNG DIGI
    // ==========================================
    do {
        cout << "\n===== WARUNG DIGI =====" << endl;
        cout << "1. Lihat Daftar Barang" << endl;
        cout << "2. Beli Barang" << endl;
        cout << "3. Cetak Struk Belanja" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        // --------------------------------------
        // Menu 1: Menampilkan daftar barang
        // --------------------------------------
        if (pilihanMenu == 1) {
            cout << "\n--- DAFTAR BARANG ---" << endl;
            for (int i = 0; i < JUMLAH_BARANG; i++) {
                cout << i+1 << ". " << namaBarang[i]
                     << " | Stok: " << stok[i]
                     << " | Harga: Rp " << harga[i] << endl;
            }
        } 
        // --------------------------------------
        // Menu 2: Membeli barang (pilih dan masuk ke keranjang)
        // --------------------------------------
        else if (pilihanMenu == 2) {
            cout << "\nPilih barang (1-" << JUMLAH_BARANG << "): ";
            cin >> pilihBarang;

            if (pilihBarang >= 1 && pilihBarang <= JUMLAH_BARANG) {
                int index = pilihBarang - 1; // karena array dimulai dari 0

                cout << "Masukkan jumlah beli: ";
                cin >> jumlahBeli;

                // Validasi jumlah beli
                if (jumlahBeli > 0 && jumlahBeli <= stok[index]) {
                    keranjang[index] += jumlahBeli; // barang masuk keranjang
                    stok[index] -= jumlahBeli;      // stok berkurang
                    cout << "Ditambahkan ke keranjang: " 
                         << jumlahBeli << " " << namaBarang[index] << endl;
                } else {
                    cout << "Jumlah tidak valid atau stok tidak cukup!" << endl;
                }
            } else {
                cout << "Pilihan barang tidak valid!" << endl;
            }
        }
        // --------------------------------------
        // Menu 3: Cetak struk belanja + pembayaran
        // --------------------------------------
        else if (pilihanMenu == 3) {
            totalBelanja = 0;
            diskon = 0;

            cout << "\n======================================" << endl;
            cout << "       STRUK BELANJA WARUNG DIGI      " << endl;
            cout << "======================================" << endl;
            cout << "Nama Barang         Qty     Subtotal" << endl;
            cout << "--------------------------------------" << endl;

            // Loop semua barang untuk menghitung total belanja
            for (int i = 0; i < JUMLAH_BARANG; i++) {
                if (keranjang[i] > 0) {
                    double subtotal = harga[i] * keranjang[i]; // operator *
                    totalBelanja += subtotal;                  // operator +=

                    // Diskon khusus barang (10%) jika subtotal > 550k
                    if (subtotal > 550000) {
                        diskon += subtotal * 0.10;
                    }

                    // Cetak detail barang
                    cout << namaBarang[i] << "\t" << keranjang[i] 
                         << "\tRp " << subtotal << endl;
                }
            }

            // Diskon event 5% untuk semua transaksi
            diskon += totalBelanja * 0.05;

            // Diskon tambahan 10% jika total belanja > 100 ribu
            if (totalBelanja > 100000) {
                diskon += totalBelanja * 0.10;
            }

            // Diskon tambahan 25% jika total belanja > 1 juta
            if (totalBelanja > 1000000) {
                diskon += totalBelanja * 0.25;
            }

            // Diskon member 5% (opsional)
            cout << "\nApakah Anda punya kartu member? (1=Ya, 0=Tidak): ";
            cin >> isMember;
            if (isMember == 1) {
                diskon += totalBelanja * 0.05;
            }

            // Pajak PPN 11% (setelah diskon)
            ppn = (totalBelanja - diskon) * 0.11;

            // Total akhir yang harus dibayar
            totalBayar = totalBelanja - diskon + ppn;

            // Cetak total
            cout << "--------------------------------------" << endl;
            cout << "Total Belanja : Rp " << totalBelanja << endl;
            cout << "Total Diskon  : Rp " << diskon << endl;
            cout << "PPN 11%       : Rp " << ppn << endl;
            cout << "TOTAL BAYAR   : Rp " << totalBayar << endl;

            // ==========================================
            // 3. INPUT PEMBAYARAN DAN KEMBALIAN
            // ==========================================
            double uangBayar = 0;
            do {
                cout << "\nMasukkan jumlah uang bayar: Rp ";
                cin >> uangBayar;

                // Validasi: uang harus cukup
                if (uangBayar < totalBayar) {
                    cout << "Uang tidak cukup, coba lagi!" << endl;
                }
            } while (uangBayar < totalBayar);

            // Hitung kembalian (operator -)
            double kembalian = uangBayar - totalBayar;

            // Cetak detail pembayaran
            cout << "Uang Diterima : Rp " << uangBayar << endl;
            cout << "Kembalian     : Rp " << kembalian << endl;
            cout << "======================================" << endl;

            // Jeda sebelum kembali ke menu (tekan ENTER)
            cout << "\nTekan ENTER untuk kembali ke menu...";
            cin.ignore(); // membersihkan buffer input
            cin.get();    // menunggu user tekan enter
        }
        // --------------------------------------
        // Validasi jika menu tidak ada
        // --------------------------------------
        else if (pilihanMenu != 0) {
            cout << "Menu tidak valid!" << endl;
        }

    } while (pilihanMenu != 0); // perulangan berhenti jika user pilih 0

    // ==========================================
    // 4. AKHIR PROGRAM
    // ==========================================
    cout << "\nTerima kasih sudah berbelanja di Warung Digi!" << endl;

    return 0;
}