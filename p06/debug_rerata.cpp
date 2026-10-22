// Latihan debugger: program ini membangun bersih tetapi rata-ratanya salah.
// Jangan dibaca sampai ketemu; jalankan dengan debugger, pasang breakpoint di baris total += nilai,
// pantau i, nilai, dan total, lalu temukan sendiri di putaran ke berapa sesuatu tidak beres.
// Masukan uji: 3 nilai, yaitu 80, 70, 90. Rata-rata yang benar 80.
#include <iostream>

using namespace std;

int main() {
    int jumlah = 0;
    cout << "Berapa nilai? ";
    cin >> jumlah;

    double total = 0;
    for (int i = 1; i < jumlah; i++) {
        double nilai = 0;
        cout << "Nilai ke-" << i << ": ";
        cin >> nilai;
        total += nilai;
    }

    cout << "Rata-rata: " << total / jumlah << "\n";
    return 0;
}
