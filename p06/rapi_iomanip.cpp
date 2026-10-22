// Merapikan keluaran dengan <iomanip>: setw (lebar kolom), left/right (rata kiri/kanan),
// fixed dan setprecision (jumlah angka di belakang koma). Semuanya berlaku untuk cout.
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama = "Siti Aminah";
    double nilai_akhir = 83.975;
    double rerata = 67.075;

    cout << "Tanpa pengaturan:\n";
    cout << nilai_akhir << " " << rerata << " " << 2.0 / 3 << "\n\n";

    cout << "Dua angka di belakang koma (fixed + setprecision):\n";
    cout << fixed << setprecision(2);
    cout << nilai_akhir << " " << rerata << " " << 2.0 / 3 << "\n\n";

    cout << "Kolom selebar 20 dan 8 (setw hanya berlaku untuk satu keluaran berikutnya):\n";
    cout << left << setw(20) << "Nama" << right << setw(8) << "Nilai" << "\n";
    cout << left << setw(20) << nama << right << setw(8) << nilai_akhir << "\n";
    cout << left << setw(20) << "Budi Santoso" << right << setw(8) << 67.75 << "\n";
    return 0;
}
