// Meminta nama sampai sah: tidak kosong, bukan hanya spasi, dan tidak mengandung angka.
// do-while (tanya dulu, periksa kemudian) dibungkus dengan pemeriksaan huruf per huruf.
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama;
    bool sah = false;

    do {
        cout << "Nama: ";
        getline(cin, nama);

        int panjang = nama.length();
        bool ada_huruf = false;
        bool ada_angka = false;
        for (int i = 0; i < panjang; i++) {
            if (nama[i] != ' ') {
                ada_huruf = true;
            }
            if (isdigit(nama[i])) {
                ada_angka = true;
            }
        }

        if (!ada_huruf) {
            cout << "Nama tidak boleh kosong.\n";
        } else if (ada_angka) {
            cout << "Nama tidak boleh mengandung angka.\n";
        } else {
            sah = true;
        }
    } while (!sah);

    cout << "Nama tersimpan: " << nama << "\n";
    return 0;
}
