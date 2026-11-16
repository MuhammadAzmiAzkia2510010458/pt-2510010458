// Pass by value: fungsi menerima SALINAN, perubahan di dalam fungsi tidak sampai ke pemanggil.
// Pass by reference (tanda &): fungsi menerima variabel pemanggil ITU SENDIRI, perubahannya tersimpan.
#include <iostream>

using namespace std;

void tambahSatuSalinan(int x);
void tambahSatuAsli(int& x);
void tukar(int& a, int& b);

int main() {
    int umur = 19;

    tambahSatuSalinan(umur);
    cout << "Setelah tambahSatuSalinan : " << umur << "\n";

    tambahSatuAsli(umur);
    cout << "Setelah tambahSatuAsli    : " << umur << "\n";

    int p = 3;
    int q = 8;
    tukar(p, q);
    cout << "Setelah tukar             : p = " << p << ", q = " << q << "\n";
    return 0;
}

void tambahSatuSalinan(int x) {
    x = x + 1;                  // yang bertambah hanya salinan bernama x
    cout << "  di dalam salinan  : " << x << "\n";
}

void tambahSatuAsli(int& x) {
    x = x + 1;                  // x adalah nama lain untuk umur milik main
    cout << "  di dalam referensi: " << x << "\n";
}

void tukar(int& a, int& b) {
    int sementara = a;
    a = b;
    b = sementara;
}
