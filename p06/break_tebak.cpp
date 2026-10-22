// break: keluar dari perulangan lebih awal, sebelum syaratnya sempat salah.
// Pemain punya paling banyak 5 kesempatan menebak; begitu benar, tidak perlu menunggu kesempatan habis.
#include <iostream>

using namespace std;

int main() {
    const int RAHASIA = 7;
    const int MAKS_PERCOBAAN = 5;
    int tebakan = 0;
    bool benar = false;

    for (int percobaan = 1; percobaan <= MAKS_PERCOBAAN; percobaan++) {
        cout << "Tebakan ke-" << percobaan << " (1-10): ";
        cin >> tebakan;
        if (tebakan == RAHASIA) {
            benar = true;
            break;
        }
        if (tebakan < RAHASIA) {
            cout << "Terlalu kecil.\n";
        } else {
            cout << "Terlalu besar.\n";
        }
    }

    if (benar) {
        cout << "Benar! Angkanya " << RAHASIA << ".\n";
    } else {
        cout << "Kesempatan habis. Angkanya " << RAHASIA << ".\n";
    }
    return 0;
}
