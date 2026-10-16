// while: mengulang selama syaratnya benar; jumlah putaran tidak diketahui sejak awal.
// Pengguna memasukkan nilai satu per satu, dan angka negatif menjadi tanda berhenti (sentinel).
#include <iostream>

using namespace std;

int main() {
    double total = 0;
    int banyak = 0;
    double nilai = 0;

    cout << "Masukkan nilai satu per satu, angka negatif untuk berhenti.\n";
    cout << "Nilai: ";
    cin >> nilai;
    while (nilai >= 0) {
        total += nilai;
        banyak++;
        cout << "Nilai: ";
        cin >> nilai;
    }

    cout << "Banyak nilai : " << banyak << "\n";
    if (banyak > 0) {
        cout << "Rata-rata    : " << total / banyak << "\n";
    } else {
        cout << "Tidak ada nilai yang dimasukkan.\n";
    }
    return 0;
}
