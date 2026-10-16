// Pola akumulator: satu variabel penampung yang dimulai dari 0 lalu ditambah sedikit demi sedikit
// di setiap putaran. Hampir semua laporan (total, rata-rata, jumlah lulus) memakai pola ini.
#include <iostream>

using namespace std;

int main() {
    int jumlah = 0;
    cout << "Berapa nilai yang akan dimasukkan? ";
    cin >> jumlah;

    double total = 0;
    for (int i = 1; i <= jumlah; i++) {
        double nilai = 0;
        cout << "Nilai ke-" << i << ": ";
        cin >> nilai;
        total += nilai;
    }

    cout << "Total     : " << total << "\n";
    cout << "Rata-rata : " << total / jumlah << "\n";
    return 0;
}
