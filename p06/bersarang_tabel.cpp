// Perulangan bersarang: satu perulangan di dalam perulangan lain.
// Perulangan luar memilih baris, perulangan dalam mengisi kolom pada baris itu.
// setw dari <iomanip> membuat setiap angka menempati lebar yang sama sehingga kolomnya lurus.
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cout << "Tabel perkalian sampai: ";
    cin >> n;

    for (int baris = 1; baris <= n; baris++) {
        for (int kolom = 1; kolom <= n; kolom++) {
            cout << setw(4) << baris * kolom;
        }
        cout << "\n";
    }
    return 0;
}
