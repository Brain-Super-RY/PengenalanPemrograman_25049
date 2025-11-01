#include <iostream>
#include <string>
using namespace std;

struct Pasien
{
    string nama;
    string jenisPenyakit;
    string alamat;
    long long biayaPerawatan;
};

string formatRupiah(long long angka) {
    string hasil = "";
    string angkaStr = to_string(angka);
    int panjang = angkaStr.length();
    int hitung = 0;
    
    for (int i = panjang - 1; i >= 0; i--) {
        if (hitung == 3) {
            hasil = "." + hasil;
            hitung = 0;
        }
        hasil = angkaStr[i] + hasil;
        hitung++;
    }
    
    return "Rp " + hasil;
}

int main()
{
    int jumlahPasien;

    cout << "========================================" << endl;
    cout << "  SISTEM DATA PASIEN RUMAH SAKIT" << endl;
    cout << "========================================" << endl;

    cout << "Masukkan jumlah pasien: ";
    cin >> jumlahPasien;
    cin.ignore();
    cout << "----------------------------------------" << endl;

    Pasien dataPasien[jumlahPasien];

    for (int i = 0; i < jumlahPasien; i++)
    {
        cout << "Masukkan data untuk pasien ke-" << (i + 1) << ":\n";

        cout << "Nama Pasien        : ";
        getline(cin, dataPasien[i].nama);

        cout << "Jenis Penyakit     : ";
        getline(cin, dataPasien[i].jenisPenyakit);

        cout << "Alamat             : ";
        getline(cin, dataPasien[i].alamat);

        cout << "Biaya Perawatan    : Rp ";
        cin >> dataPasien[i].biayaPerawatan;
        cin.ignore();
        cout << "----------------------------------------" << endl;
    }

    cout << "========================================" << endl;
    cout << "        DAFTAR SELURUH PASIEN" << endl;
    cout << "========================================" << endl;

    long long totalBiaya = 0;

    for (int i = 0; i < jumlahPasien; i++)
    {
        cout << "\nPasien ke-" << (i + 1) << endl;
        cout << "Nama               : " << dataPasien[i].nama << endl;
        cout << "Jenis Penyakit     : " << dataPasien[i].jenisPenyakit << endl;
        cout << "Alamat             : " << dataPasien[i].alamat << endl;
        cout << "Biaya Perawatan    : " << formatRupiah(dataPasien[i].biayaPerawatan) << endl;
        cout << "----------------------------------------" << endl;

        totalBiaya += dataPasien[i].biayaPerawatan;
    }

    cout << "========================================" << endl;
    cout << "Total Biaya Seluruh Pasien : " << formatRupiah(totalBiaya) << endl;
    cout << "========================================" << endl;

    return 0;
}