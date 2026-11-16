// Lingkup (scope) dan umur variabel: variabel lokal lahir saat fungsinya dipanggil dan mati saat fungsinya selesai.
// Variabel global hidup sepanjang program dan bisa diubah dari mana saja; itulah yang membuatnya sulit dilacak.
#include <iostream>

using namespace std;

int banyak_panggilan = 0;       // GLOBAL: dideklarasikan di luar semua fungsi. Contoh yang TIDAK ditiru.

int kuadrat(int n);
void catat();
void cetakDuaKali();

int main() {
    int n = 5;                  // n milik main
    cout << "kuadrat(" << n << ") = " << kuadrat(n) << "\n";
    cout << "n di main tetap " << n << "\n";

    catat();
    catat();
    cetakDuaKali();
    cout << "banyak_panggilan = " << banyak_panggilan << " (siapa saja yang mengubahnya?)\n";
    return 0;
}

int kuadrat(int n) {            // n yang ini milik kuadrat, berbeda dari n milik main
    n = n * n;
    return n;
}

void catat() {
    int hitung = 0;             // lokal: lahir bernilai 0 setiap kali catat() dipanggil
    hitung++;
    banyak_panggilan++;         // global: terus bertambah
    cout << "catat: hitung = " << hitung << ", banyak_panggilan = " << banyak_panggilan << "\n";
}

void cetakDuaKali() {
    banyak_panggilan += 2;      // fungsi lain diam-diam ikut mengubah global yang sama
    cout << "cetakDuaKali dipanggil\n";
}
