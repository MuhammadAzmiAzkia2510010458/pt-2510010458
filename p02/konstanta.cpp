// Konstanta: nilai yang tidak boleh berubah selama program berjalan.
// Bobot penilaian mata kuliah ini sendiri dipakai sebagai contoh.
#include <iostream>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    cout << "Bobot kehadiran : " << BOBOT_KEHADIRAN << "\n";
    cout << "Bobot mingguan  : " << BOBOT_MINGGUAN << "\n";
    cout << "Bobot UTS       : " << BOBOT_UTS << "\n";
    cout << "Bobot UAS       : " << BOBOT_UAS << "\n";
    cout << "Jumlah          : "
              << BOBOT_KEHADIRAN + BOBOT_MINGGUAN + BOBOT_UTS + BOBOT_UAS << "\n";

    // Praktikum 2: hapus tanda komentar pada baris di bawah, lalu bangun ulang.
    // BOBOT_UAS = 0.30;
    return 0;
}
