 #include <iostream>
#include <string>
using namespace std;

int main() {
    int barang;
    cout << "Masukkan jumlah barang: ";
    cin >> barang;
    cin.ignore();

    string data[barang][3];

    for (int i = 0; i < barang; i++) {
        cout << "\nBarang ke-" << i + 1 << endl;
        cout << "Nama Barang : ";
        getline(cin, data[i][0]);
        cout << "Stok        : ";
        getline(cin, data[i][1]);
        cout << "Harga       : ";
        getline(cin, data[i][2]);
    }

    cout << "\n\nNama Barang\tStok\tHarga\n";
    cout << "----------------------------------\n";
    for (int i = 0; i < barang; i++) {
        cout << data[i][0] << "\t\t"
             << data[i][1] << "\t"
             << data[i][2] << endl;
    }

    return 0;
}
