#include <iostream>
using namespace std;

void garis() {
    cout << "======================================================" << endl;
}

void hitungLuasPersegi() {
    double sisi, luas;
    cout << "Masukkan panjang sisi persegi: ";
    cin >> sisi;
    luas = sisi * sisi;
    cout << "Luas Persegi: " << luas << " Cm " << endl;
}

void hitungLuasLingkaran() {
    const float phi = 3.14;
    double radius, luas;
    cout << "Masukkan jari-jari lingkaran: ";
    cin >> radius;
    luas = phi * radius * radius;
    cout << "Luas Lingkaran: " << luas << " Cm " << endl;
}

void hitungLuasSegitiga() {
    double alas, tinggi, luas;
    cout << "Masukkan alas segitiga: ";
    cin >> alas;
    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggi;
    luas = 0.5 * alas * tinggi;
    cout << "Luas Segitiga: " << luas << " Cm " << endl;
}


int main() {
    int pilihan;
    do {
        garis();
        cout << "           MENU PROGRAM HITUNG LUAS BANGUN " << endl;
        garis();
        cout << "Pilih bangun datar yang ingin dihitung luasnya: " << endl;
        cout << "1. Hitung Luas Persegi" << endl;
        cout << "2. Hitung Luas Lingkaran" << endl;
        cout << "3. Hitung Luas Segitiga" << endl;
        cout << "4. Keluar" << endl;
        garis();
        cout << "Masukkan pilihan Anda (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                hitungLuasPersegi();
                break;
            case 2:
                hitungLuasLingkaran();
                break;
            case 3:
                hitungLuasSegitiga();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);
    
    return 0;
}