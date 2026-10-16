
#include <iostream>
using namespace std;

int main() {
    double nilai = 0;
    double tertinggi = 0;
    int banyak = 0;

    cout << "Masukkan nilai (angka negatif untuk berhenti) \n";
    cout << "Nilai: ";
    cin >> nilai;

    while (nilai >= 0) {
        if (banyak == 0 || nilai > tertinggi) {
            tertinggi = nilai;
        }

        banyak++;

        cout << "Nilai: ";
        cin >> nilai;
    }

    if (banyak > 0) {
        cout << "Nilai tertinggi: " << tertinggi << "\n";
    } else {
        cout << "Tidak ada nilai yang dimasukkan.\n";
    }

    return 0;
}
