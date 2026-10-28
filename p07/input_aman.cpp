// Membaca angka dengan aman. Kalau pengguna mengetik huruf, cin gagal (cin.fail() bernilai true),
// variabelnya diisi 0, dan huruf itu tetap tertinggal di antrean sehingga cin gagal lagi selamanya.
// Obatnya tiga langkah: cin.clear() memulihkan cin, cin.ignore(1000, '\n') membuang sisa baris,
// lalu minta lagi. Inilah penyembuh perulangan tanpa henti dari Pertemuan 5.
#include <iostream>

using namespace std;

int main() {
    double nilai = 0;
    cout << "Nilai (0-100): ";
    cin >> nilai;

    while (cin.fail() || nilai < 0 || nilai > 100) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Itu bukan angka. ";
        } else {
            cout << "Harus 0 sampai 100. ";
        }
        cout << "Coba lagi: ";
        cin >> nilai;
    }

    cout << "Tersimpan: " << nilai << "\n";
    return 0;
}
