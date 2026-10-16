// Urutan evaluasi: prioritas (mana yang dikerjakan dulu) dan asosiativitas (dari kiri atau dari kanan).
// Tebak dulu setiap hasilnya sebelum menjalankan program.
#include <iostream>

using namespace std;

int main() {
    cout << "2 + 3 * 4     = " << 2 + 3 * 4 << "\n";
    cout << "(2 + 3) * 4   = " << (2 + 3) * 4 << "\n";
    cout << "10 - 4 - 3    = " << 10 - 4 - 3 << "\n";
    cout << "10 - (4 - 3)  = " << 10 - (4 - 3) << "\n";
    cout << "2 * 3 / 4     = " << 2 * 3 / 4 << "\n";
    cout << "2 / 4 * 3     = " << 2 / 4 * 3 << "\n";
    cout << "17 % 5 * 2    = " << 17 % 5 * 2 << "\n";

    int hitung = 10;
    hitung += 5;     // sama dengan hitung = hitung + 5
    hitung -= 3;     // sama dengan hitung = hitung - 3
    hitung *= 2;     // sama dengan hitung = hitung * 2
    hitung++;        // sama dengan hitung = hitung + 1
    cout << "hitung        = " << hitung << "\n";
    return 0;
}
