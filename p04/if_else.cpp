// if-else dua cabang: tepat satu dari dua blok yang dijalankan, tidak pernah keduanya.
#include <iostream>

using namespace std;

int main() {
    double nilai_akhir = 0;
    cout << "Nilai akhir: ";
    cin >> nilai_akhir;

    if (nilai_akhir >= 60) {
        cout << "Lulus\n";
    } else {
        cout << "Belum lulus\n";
    }
    return 0;
}
