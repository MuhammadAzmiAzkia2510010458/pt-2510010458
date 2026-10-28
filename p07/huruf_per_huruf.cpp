// Menelusuri string huruf per huruf dengan perulangan for: posisi 0 sampai length() - 1.
// Setiap nama[i] bertipe char, jadi bisa dibandingkan dengan 'a' dan diubah dengan toupper.
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama;
    cout << "Nama lengkap: ";
    getline(cin, nama);

    int panjang = nama.length();
    int spasi = 0;
    int vokal = 0;
    string terbalik;
    string kapital;

    for (int i = 0; i < panjang; i++) {
        char c = nama[i];
        if (c == ' ') {
            spasi++;
        }
        char kecil = tolower(c);
        if (kecil == 'a' || kecil == 'i' || kecil == 'u' || kecil == 'e' || kecil == 'o') {
            vokal++;
        }
        terbalik = c + terbalik;
        kapital = kapital + static_cast<char>(toupper(c));
    }

    cout << "Panjang       : " << panjang << "\n";
    cout << "Banyak kata   : " << spasi + 1 << "\n";
    cout << "Banyak vokal  : " << vokal << "\n";
    cout << "Huruf kapital : " << kapital << "\n";
    cout << "Dibalik       : " << terbalik << "\n";
    return 0;
}
