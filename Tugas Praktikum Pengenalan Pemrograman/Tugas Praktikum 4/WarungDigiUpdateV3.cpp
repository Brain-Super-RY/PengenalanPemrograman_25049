#include <iostream>
#include <string>
using namespace std;

int main() {
    const int JUMLAH_BARANG = 15;
    
    // Data barang
    string namaBarang[JUMLAH_BARANG] = {
        "Indomie Goreng", "Teh Botol Kotak", "Silverqueen 62g", 
        "Chitato Sapi Panggang", "Susu UHT Ultra Milk", "Beras Premium 5kg",
        "Aqua Botol 600ml", "Kopi Kapal Api Sachet", "Energen Cereal",
        "Oreo Coklat", "Roma Malkist", "Tango Wafer", 
        "Mie Sedap Soto", "Good Day Cappuccino", "Yakult 5pcs"
    };
    
    int stok[JUMLAH_BARANG] = {
        120, 90, 60, 75, 110, 80, 150, 200, 95, 140, 130, 125, 100, 95, 85
    };
    
    double harga[JUMLAH_BARANG] = {
        3800.50, 4200.00, 16500.00, 13200.00, 7000.00, 70000.00,
        5200.00, 2200.00, 2700.00, 8500.00, 7800.00, 9400.00,
        3400.00, 3800.00, 9500.00
    };
    
    int keranjang[JUMLAH_BARANG] = {0}; // semua diinisialisasi 0
    
    // Variabel untuk history transaksi
    string namaPelanggan1 = "";
    string namaPelanggan2 = "";
    double totalPelanggan1 = 0.0;
    double totalPelanggan2 = 0.0;
    int pelangganKe = 1; // counter pelanggan
    
    int pilihan = -1;
    
    while (pilihan != 0) {
        // Clear screen sederhana
        system("cls"); // Windows
        
        cout << "===== WARUNG DIGI =====" << endl;
        cout << "1. Lihat Daftar Barang" << endl;
        cout << "2. Beli Barang" << endl;
        cout << "3. Cetak Struk & Bayar" << endl;
        cout << "4. Bandingkan Belanja 2 Pelanggan" << endl; // Menu baru
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            // Menu 1: Lihat Barang
            system("cls");
            cout << "=== DAFTAR BARANG WARUNG DIGI ===" << endl;
            cout << "No  Nama Barang               Stok   Harga" << endl;
            cout << "----------------------------------------------" << endl;
            
            for (int i = 0; i < JUMLAH_BARANG; i++) {
                cout << (i+1) << ". " << namaBarang[i];
                // Padding sederhana
                int spasi = 25 - namaBarang[i].length();
                for (int j = 0; j < spasi; j++) cout << " ";
                cout << stok[i] << "    Rp " << harga[i] << endl;
            }
            
            cout << "\nTekan ENTER untuk kembali...";
            cin.ignore();
            cin.get();
        }
        
        else if (pilihan == 2) {
            // Menu 2: Beli Barang
            system("cls");
            cout << "=== BELI BARANG ===" << endl;
            cout << "Masukkan nomor (1-15) atau nama barang: ";
            
            string input;
            cin.ignore();
            getline(cin, input);
            
            int index = -1;
            
            // Cek apakah input berupa angka
            bool isNumber = true;
            for (int i = 0; i < input.length(); i++) {
                if (input[i] < '0' || input[i] > '9') {
                    isNumber = false;
                    break;
                }
            }
            
            if (isNumber && !input.empty()) {
                // Konversi string ke int manual
                int nomor = 0;
                for (int i = 0; i < input.length(); i++) {
                    nomor = nomor * 10 + (input[i] - '0');
                }
                if (nomor >= 1 && nomor <= JUMLAH_BARANG) {
                    index = nomor - 1;
                }
            } else {
                // Pencarian berdasarkan nama
                for (int i = 0; i < JUMLAH_BARANG; i++) {
                    if (namaBarang[i] == input) {
                        index = i;
                        break;
                    }
                }
            }
            
            if (index == -1) {
                cout << "Barang tidak ditemukan!" << endl;
            } else {
                cout << "Barang: " << namaBarang[index] << endl;
                cout << "Stok: " << stok[index] << endl;
                cout << "Harga: Rp " << harga[index] << endl;
                cout << "Jumlah beli: ";
                
                int jumlah;
                cin >> jumlah;
                
                if (jumlah > 0 && jumlah <= stok[index]) {
                    keranjang[index] += jumlah;
                    stok[index] -= jumlah;
                    cout << "Berhasil ditambahkan ke keranjang!" << endl;
                } else {
                    cout << "Jumlah tidak valid atau stok habis!" << endl;
                }
            }
            
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            cin.get();
        }
        
        else if (pilihan == 3) {
            // Menu 3: Struk & Bayar
            system("cls");
            
            // Input nama pelanggan 
            string namaPelanggan;
            cout << "Nama pelanggan: ";
            cin.ignore();
            getline(cin, namaPelanggan);
            
            double totalBelanja = 0.0;
            bool adaBarang = false;
            
            cout << "\n===== STRUK BELANJA WARUNG DIGI =====" << endl;
            cout << "Pelanggan: " << namaPelanggan << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "Nama Barang               Qty   Harga    Subtotal" << endl;
            cout << "--------------------------------------------------" << endl;
            
            // Tampilkan item yang dibeli
            for (int i = 0; i < JUMLAH_BARANG; i++) {
                if (keranjang[i] > 0) {
                    adaBarang = true;
                    double subtotal = harga[i] * keranjang[i];
                    totalBelanja += subtotal;
                    
                    cout << namaBarang[i];
                    int spasi = 25 - namaBarang[i].length();
                    for (int j = 0; j < spasi; j++) cout << " ";
                    cout << keranjang[i] << "   Rp " << harga[i] 
                         << "   Rp " << subtotal << endl;
                }
            }
            
            if (!adaBarang) {
                cout << "(Keranjang kosong)" << endl;
                cout << "Tekan ENTER untuk kembali...";
                cin.get();
                continue;
            }
            
            // Hitung diskon
            double totalDiskon = 0.0;
            
            // Diskon per item (jika subtotal > 550rb)
            for (int i = 0; i < JUMLAH_BARANG; i++) {
                if (keranjang[i] > 0) {
                    double subtotal = harga[i] * keranjang[i];
                    if (subtotal > 550000) {
                        totalDiskon += subtotal * 0.10;
                    }
                }
            }
            
            // Diskon global
            totalDiskon += totalBelanja * 0.05; // Event 5%
            if (totalBelanja > 100000) totalDiskon += totalBelanja * 0.10;
            if (totalBelanja > 1000000) totalDiskon += totalBelanja * 0.25;
            
            // Member discount
            cout << "Punya kartu member? (1=Ya, 0=Tidak): ";
            int member;
            cin >> member;
            if (member == 1) {
                totalDiskon += totalBelanja * 0.05;
            }
            
            // Safety check
            if (totalDiskon > totalBelanja) totalDiskon = totalBelanja;
            
            // PPN 11%
            double ppn = (totalBelanja - totalDiskon) * 0.11;
            double totalBayar = totalBelanja - totalDiskon + ppn;
            
            cout << "--------------------------------------------------" << endl;
            cout << "Total Belanja : Rp " << totalBelanja << endl;
            cout << "Total Diskon  : Rp " << totalDiskon << endl;
            cout << "PPN (11%)     : Rp " << ppn << endl;
            cout << "TOTAL BAYAR   : Rp " << totalBayar << endl;
            
            // Simpan data pelanggan untuk perbandingan
            if (pelangganKe == 1) {
                namaPelanggan1 = namaPelanggan;
                totalPelanggan1 = totalBayar;
                pelangganKe = 2;
                cout << "\n[Data pelanggan 1 tersimpan untuk perbandingan]" << endl;
            } else if (pelangganKe == 2) {
                namaPelanggan2 = namaPelanggan;
                totalPelanggan2 = totalBayar;
                pelangganKe = 1;
                cout << "\n[Data pelanggan 2 tersimpan untuk perbandingan]" << endl;
            }
            
            // Pembayaran
            double uangBayar;
            do {
                cout << "Masukkan uang bayar: Rp ";
                cin >> uangBayar;
                if (uangBayar < totalBayar) {
                    cout << "Uang tidak cukup!" << endl;
                }
            } while (uangBayar < totalBayar);
            
            cout << "Kembalian: Rp " << (uangBayar - totalBayar) << endl;
            cout << "===== TERIMA KASIH =====" << endl;
            
            // Reset keranjang
            for (int i = 0; i < JUMLAH_BARANG; i++) {
                keranjang[i] = 0;
            }
            
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            cin.get();
        }
        
        else if (pilihan == 4) {
            // Menu 4: Perbandingan Belanja 2 Pelanggan
            system("cls");
            cout << "===== PERBANDINGAN BELANJA DUA PELANGGAN =====" << endl;
            cout << "============= WARUNG DIGI =============" << endl << endl;
            
            // Cek apakah sudah ada data pelanggan
            if (namaPelanggan1 == "" && namaPelanggan2 == "") {
                cout << "Belum ada data pelanggan!" << endl;
                cout << "Silakan lakukan transaksi terlebih dahulu (menu 3)." << endl;
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
            else if (namaPelanggan2 == "") {
                cout << "Hanya ada 1 data pelanggan (" << namaPelanggan1 << ")" << endl;
                cout << "Input data pelanggan kedua:" << endl;
                cout << "Nama pelanggan: ";
                cin.ignore();
                getline(cin, namaPelanggan2);
                cout << "Total belanja: Rp ";
                cin >> totalPelanggan2;
            }
            
            // Tampilkan ringkasan
            cout << "\n===== RINGKASAN DATA =====" << endl;
            cout << "Pelanggan 1: " << namaPelanggan1 << " = Rp " << totalPelanggan1 << endl;
            cout << "Pelanggan 2: " << namaPelanggan2 << " = Rp " << totalPelanggan2 << endl;
            
            // Implementasi semua operator relasi (==, !=, >, <, >=, <=)
            cout << "\n===== HASIL PERBANDINGAN (OPERATOR RELASI) =====" << endl;
            
            // Operator == (sama dengan)
            bool samaBelanja = (totalPelanggan1 == totalPelanggan2);
            cout << "Belanja sama (==): " << (samaBelanja ? "YA" : "TIDAK");
            cout << " (" << samaBelanja << ")" << endl;
            
            // Operator != (tidak sama dengan)
            bool berbedaBelanja = (totalPelanggan1 != totalPelanggan2);
            cout << "Belanja berbeda (!=): " << (berbedaBelanja ? "YA" : "TIDAK");
            cout << " (" << berbedaBelanja << ")" << endl;
            
            // Operator > (lebih besar)
            bool lebihBesar = (totalPelanggan1 > totalPelanggan2);
            cout << namaPelanggan1 << " > " << namaPelanggan2 << ": ";
            cout << (lebihBesar ? "YA" : "TIDAK") << " (" << lebihBesar << ")" << endl;
            
            // Operator < (lebih kecil)
            bool lebihKecil = (totalPelanggan1 < totalPelanggan2);
            cout << namaPelanggan1 << " < " << namaPelanggan2 << ": ";
            cout << (lebihKecil ? "YA" : "TIDAK") << " (" << lebihKecil << ")" << endl;
            
            // Operator >= (lebih besar atau sama dengan)
            bool lebihBesarSama = (totalPelanggan1 >= totalPelanggan2);
            cout << namaPelanggan1 << " >= " << namaPelanggan2 << ": ";
            cout << (lebihBesarSama ? "YA" : "TIDAK") << " (" << lebihBesarSama << ")" << endl;
            
            // Operator <= (lebih kecil atau sama dengan)
            bool lebihKecilSama = (totalPelanggan1 <= totalPelanggan2);
            cout << namaPelanggan1 << " <= " << namaPelanggan2 << ": ";
            cout << (lebihKecilSama ? "YA" : "TIDAK") << " (" << lebihKecilSama << ")" << endl;
            
            // Kesimpulan dengan if-else dan operator aritmatika
            cout << "\n===== KESIMPULAN =====" << endl;
            if (totalPelanggan1 > totalPelanggan2) {
                cout << namaPelanggan1 << " belanja LEBIH BANYAK" << endl;
                double selisih = totalPelanggan1 - totalPelanggan2;
                cout << "Selisih: Rp " << selisih << endl;
            }
            else if (totalPelanggan1 < totalPelanggan2) {
                cout << namaPelanggan2 << " belanja LEBIH BANYAK" << endl;
                double selisih = totalPelanggan2 - totalPelanggan1;
                cout << "Selisih: Rp " << selisih << endl;
            }
            else {
                cout << "Kedua pelanggan belanja SAMA BANYAK!" << endl;
            }
            
            // Kategori pelanggan
            cout << "\n===== KATEGORI PELANGGAN =====" << endl;
            
            // Pelanggan 1
            cout << namaPelanggan1 << ": ";
            if (totalPelanggan1 >= 500000) {
                cout << "VIP Customer";
            }
            else if (totalPelanggan1 >= 200000) {
                cout << "Premium Customer";
            }
            else if (totalPelanggan1 >= 50000) {
                cout << "Regular Customer";
            }
            else {
                cout << "New Customer";
            }
            cout << endl;
            
            // Pelanggan 2
            cout << namaPelanggan2 << ": ";
            if (totalPelanggan2 >= 500000) {
                cout << "VIP Customer";
            }
            else if (totalPelanggan2 >= 200000) {
                cout << "Premium Customer";
            }
            else if (totalPelanggan2 >= 50000) {
                cout << "Regular Customer";
            }
            else {
                cout << "New Customer";
            }
            cout << endl;
            
            // Target warung
            double targetHarian = 300000.0;
            double totalDuaPelanggan = totalPelanggan1 + totalPelanggan2;
            
            cout << "\n===== PERBANDINGAN DENGAN TARGET =====" << endl;
            cout << "Target harian: Rp " << targetHarian << endl;
            cout << "Total 2 pelanggan: Rp " << totalDuaPelanggan << endl;
            
            bool capaiTarget = (totalDuaPelanggan >= targetHarian);
            cout << "Capai target: " << (capaiTarget ? "YA" : "TIDAK");
            cout << " (" << capaiTarget << ")" << endl;
            
            if (!capaiTarget) {
                double kurang = targetHarian - totalDuaPelanggan;
                cout << "Kekurangan: Rp " << kurang << endl;
            } else {
                double lebih = totalDuaPelanggan - targetHarian;
                cout << "Kelebihan: Rp " << lebih << endl;
            }
            
            cout << "\nTekan ENTER untuk kembali...";
            cin.ignore();
            cin.get();
        }
        
        else if (pilihan == 0) {
            system("cls");
            cout << "===== TERIMA KASIH =====" << endl;
            cout << "Warung Digi - Belanja Hemat Setiap Hari!" << endl;
        }
        
        else {
            cout << "Menu tidak valid!" << endl;
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}