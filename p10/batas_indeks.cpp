// Compiler TIDAK menjaga batas larik. Indeks di luar 0 sampai JUMLAH - 1 tetap lolos compile,
// tetapi membaca kotak milik orang lain: hasilnya sampah, atau program mati tanpa pesan.
// Yang menjaga batas adalah kamu: periksa indeks sebelum dipakai.
#include <iostream>

using namespace std;

int main() {
    const int JUMLAH = 3;
    int nilai[JUMLAH] = {70, 80, 90};

    cout << "nilai[0] = " << nilai[0] << "\n";
    cout << "nilai[2] = " << nilai[2] << "\n";
    cout << "nilai[3] = " << nilai[3] << "   <- di luar batas, isinya sampah\n";
    cout << "nilai[7] = " << nilai[7] << "   <- di luar batas, isinya sampah\n\n";

    int indeks = 0;
    cout << "Indeks yang ingin dilihat (0 sampai " << JUMLAH - 1 << "): ";
    cin >> indeks;
    if (indeks < 0 || indeks >= JUMLAH) {       // penjaga batas: milikmu, bukan compiler
        cout << "Indeks " << indeks << " di luar batas.\n";
    } else {
        cout << "nilai[" << indeks << "] = " << nilai[indeks] << "\n";
    }
    return 0;
}
