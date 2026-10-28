// Merapikan nama menjadi Huruf Besar Di Awal Kata: huruf pertama tiap kata dibesarkan, sisanya dikecilkan.
// Kuncinya satu bendera bool: apakah huruf yang sedang dilihat berada di awal kata?
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama;
    cout << "Nama (bebas huruf besar kecil): ";
    getline(cin, nama);

    int panjang = nama.length();
    bool awal_kata = true;
    for (int i = 0; i < panjang; i++) {
        if (nama[i] == ' ') {
            awal_kata = true;
        } else if (awal_kata) {
            nama[i] = toupper(nama[i]);
            awal_kata = false;
        } else {
            nama[i] = tolower(nama[i]);
        }
    }

    cout << "Hasil: " << nama << "\n";
    return 0;
}
