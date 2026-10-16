// Ekspresi campuran int dan double: siapa yang menang?
// Tiga cara menghitung rata-rata dua nilai, hanya satu yang benar.
#include <iostream>

using namespace std;

int main() {
    int uts = 75;
    int uas = 80;

    double rerata_1 = (uts + uas) / 2;                        // int / int, baru disimpan ke double
    double rerata_2 = (uts + uas) / 2.0;                      // int / double: pecahan selamat
    double rerata_3 = static_cast<double>(uts + uas) / 2;     // ubah dulu ke double, baru dibagi

    cout << "rerata_1 = " << rerata_1 << "\n";
    cout << "rerata_2 = " << rerata_2 << "\n";
    cout << "rerata_3 = " << rerata_3 << "\n";

    int bulat = 3;
    double pecahan = 0.5;
    cout << "bulat + pecahan = " << bulat + pecahan << " (int bertemu double: hasilnya double)\n";
    cout << "bulat / 2 + pecahan = " << bulat / 2 + pecahan << " (pembagian int dikerjakan dulu)\n";
    return 0;
}
