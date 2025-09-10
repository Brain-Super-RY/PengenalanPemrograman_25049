#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // === Deklarasi dan Inisialisasi 5 Barang menggunakan Array ===
    string kodeBarang[5] = {"IDM-001", "TBK-002", "SQN-003", "CGL-004", "ULT-005"};
    string namaBarang[5] = {"Indomie Goreng", "Teh Botol Kotak", "Silverqueen 62g", "Chitato Sapi Panggang", "Susu UHT Ultra Milk"};
    int jumlah[5] = {50, 72, 35, 40, 60};
    double harga[5] = {3000.00, 3500.00, 12500.00, 11000.00, 5500.00};
    string tanggalKadaluarsa[5] = {"17-08-2026", "20-01-2026", "10-11-2025", "25-05-2026", "05-03-2026"};

    int pilihanBarang;

    // Loop utama program
    do {
        // === Tampilkan Daftar Barang (Menu Pilihan) ===
        cout << "\n===== SELAMAT DATANG DI WARUNG DIGI =====" << endl;
        cout << "Silakan pilih barang untuk melihat detail lengkap:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << namaBarang[i] << endl;
        }
        cout << "--------------------------------------------" << endl;
        cout << "0. Keluar dari program" << endl;
        cout << "============================================" << endl;
        
        cout << "Masukkan pilihan Anda (1-5 atau 0): ";
        cin >> pilihanBarang;

        // Cek jika pilihan valid (antara 1 dan 5)
        if (pilihanBarang >= 1 && pilihanBarang <= 5) {
            // Konversi pilihan (1-5) menjadi indeks array (0-4)
            int index = pilihanBarang - 1;

            // === Langsung Tampilkan Semua Data Barang yang Dipilih ===
            cout << "\n---------- DETAIL LENGKAP ----------" << endl;
            cout << "Nama Barang        : " << namaBarang[index] << endl;
            cout << "Kode Barang        : " << kodeBarang[index] << endl;
            cout << "Jumlah Stok        : " << jumlah[index] << " pcs" << endl;
            cout << fixed << setprecision(2); // Atur format harga
            cout << "Harga Satuan       : Rp " << harga[index] << endl;
            cout << "Tanggal Kadaluarsa : " << tanggalKadaluarsa[index] << endl;
            cout << "------------------------------------" << endl;

        } else if (pilihanBarang == 0) {
            // Jika pilihan 0, program akan berhenti setelah loop ini selesai
            continue; 
        } else {
            // Jika pilihan tidak valid
            cout << "\nPilihan tidak valid! Silakan masukkan angka antara 1-5 atau 0." << endl;
        }
        
        // Memberi jeda agar pengguna bisa membaca output sebelum menu muncul lagi
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.ignore(); // Mengabaikan input newline sebelumnya
        cin.get();    // Menunggu pengguna menekan Enter

    } while (pilihanBarang != 0);

    cout << "\nTerima kasih telah menggunakan program ini. Sampai jumpa!" << endl;

    return 0;
}