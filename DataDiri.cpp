#include <iostream>
#include <string> // Perlu ditambahkan untuk menggunakan tipe data string dan getline

using namespace std;

int main() {
    // --- Variabel untuk menyimpan data ---
    string namaLengkap;
    string nim;
    string jurusan;
    int tahunLahir;
    int usia;

    // --- Judul Program ---
    cout << "========================================" << endl;
    cout << "===   PROGRAM INPUT DATA DIRI        ===" << endl;
    cout << "========================================" << endl << endl;

    // --- Proses Input Data dari Pengguna ---

    // 1. Menggunakan getline() untuk membaca nama lengkap (termasuk spasi)
    cout << "Masukkan Nama Lengkap Anda : ";
    getline(cin, namaLengkap);

    cout << "Masukkan NIM Anda          : ";
    cin >> nim;

    cout << "Masukkan Jurusan Anda      : ";
    // 2. Membersihkan "sisa input" sebelum menggunakan getline() lagi
    cin.ignore(); 
    getline(cin, jurusan);

    cout << "Masukkan Tahun Lahir Anda  : ";
    cin >> tahunLahir;

    // --- Proses Kalkulasi ---
    // 3. Menghitung usia berdasarkan tahun sekarang (2025)
    usia = 2025 - tahunLahir;

    // --- Proses Output / Tampilan Hasil ---
    cout << "\n\n--- KARTU TANDA MAHASISWA (KTM) ---" << endl;
    cout << "-------------------------------------" << endl;
    // 4. Menggunakan '\t' (tab) agar tampilan rapi
    cout << "Nama\t\t: " << namaLengkap << endl;
    cout << "NIM\t\t: " << nim << endl;
    cout << "Jurusan\t\t: " << jurusan << endl;
    cout << "Tahun Lahir\t: " << tahunLahir << endl;
    cout << "Usia\t\t: " << usia << " tahun" << endl;
    cout << "-------------------------------------" << endl;

    return 0;
}
