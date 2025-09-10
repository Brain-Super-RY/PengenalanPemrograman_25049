#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // === Data Awal Warung Digi ===
    string namaBarang[5] = {
        "Indomie Goreng",
        "Teh Botol Kotak",
        "Silverqueen 62g",
        "Chitato Sapi Panggang",
        "Susu UHT Ultra Milk"
    };
    
    int jumlah[5] = {50, 72, 35, 40, 60};
    double harga[5] = {3000.00, 3500.00, 12500.00, 11000.00, 5500.00};

    int pilihan;

    // Tampilkan data awal
    cout << "===== DATA AWAL WARUNG DIGI =====" << endl;
    cout << left << setw(25) << "Nama Barang"
         << setw(10) << "Jumlah"
         << setw(10) << "Harga" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        cout << left << setw(25) << namaBarang[i]
             << setw(10) << jumlah[i]
             << "Rp " << fixed << setprecision(2) << harga[i] << endl;
    }

    cout << "=============================================\n" << endl;

    // Menu interaktif
    do {
        cout << "===== MENU WARUNG DIGI =====" << endl;
        cout << "1. Lihat detail barang" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int pilihBarang;
            cout << "\nDaftar Barang:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << namaBarang[i] << endl;
            }
            cout << "Pilih barang (1-5): ";
            cin >> pilihBarang;

            if (pilihBarang >= 1 && pilihBarang <= 5) {
                int index = pilihBarang - 1;
                cout << "\n--- DETAIL BARANG ---" << endl;
                cout << "Nama Barang : " << namaBarang[index] << endl;
                cout << "Jumlah      : " << jumlah[index] << " pcs" << endl;
                cout << "Harga       : Rp " << fixed << setprecision(2) << harga[index] << endl;
                cout << "----------------------\n" << endl;
            } else {
                cout << "Pilihan tidak valid!\n" << endl;
            }
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid!\n" << endl;
        }

    } while (pilihan != 0);

    cout << "Terima kasih telah menggunakan Warung Digi!" << endl;

    return 0;
}
