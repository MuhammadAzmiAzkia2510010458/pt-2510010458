// Lima operator aritmetika, dicoba pada bilangan bulat dan pecahan.
// Perhatikan baris pembagian: hasilnya bergantung pada tipe yang dibagi, bukan pada nilainya.
#include <iostream>

using namespace std;

int main() {
    int a = 7;
    int b = 2;
    double x = 7;
    double y = 2;

    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "a / b = " << a / b << "   (int dibagi int: pecahan dibuang)\n";
    cout << "a % b = " << a % b << "   (sisa bagi, hanya untuk int)\n";
    cout << "x / y = " << x / y << " (double dibagi double)\n";
    cout << "a / 2.0 = " << a / 2.0 << " (int dibagi double: hasilnya double)\n";
    cout << "-7 / 2 = " << -7 / 2 << "  (C++ memotong ke arah nol; Python membulatkan ke bawah, -4)\n";
    return 0;
}
