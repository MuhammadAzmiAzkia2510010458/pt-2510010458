// Larik (array): satu nama untuk sederet data sejenis. Setiap kotak dipilih dengan indeks,
// dan indeks dihitung dari 0: kotak pertama nilai[0], kotak terakhir nilai[JUMLAH - 1].
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int JUMLAH = 5;                       // ukuran larik harus konstanta
    string nama[JUMLAH] = {"Siti", "Budi", "Rina", "Dewi", "Eko"};
    double nilai[JUMLAH] = {83.975, 67.75, 49.5, 90, 71};
    int hadir[JUMLAH] = {};                     // {} berarti semua kotak diisi 0

    cout << "Kotak pertama : " << nama[0] << " " << nilai[0] << "\n";
    cout << "Kotak terakhir: " << nama[JUMLAH - 1] << " " << nilai[JUMLAH - 1] << "\n";

    nilai[2] = 55;                              // mengubah isi satu kotak
    cout << "Setelah diubah: " << nama[2] << " " << nilai[2] << "\n\n";

    for (int i = 0; i < JUMLAH; i++) {          // mulai 0, berhenti sebelum JUMLAH
        cout << "Kehadiran " << nama[i] << " (dari 16): ";
        cin >> hadir[i];                        // membaca langsung ke kotak ke-i
    }

    double total = 0;
    cout << "\nIndeks  Nama     Nilai  Hadir\n";
    for (int i = 0; i < JUMLAH; i++) {
        cout << setw(6) << i << "  " << left << setw(6) << nama[i]
             << right << setw(7) << nilai[i] << setw(7) << hadir[i] << "\n";
        total += nilai[i];
    }
    cout << "Rata-rata nilai: " << total / JUMLAH << "\n";
    return 0;
}
