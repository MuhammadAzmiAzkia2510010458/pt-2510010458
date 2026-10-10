#include <iostream>
using namespace std;
 
int main() {
    int tahun = 0;
    cout << "Tahun: ";
    cin >> tahun;
 
    bool habis_4 = tahun % 4 == 0;
    bool habis_100 = tahun % 100 == 0;
    bool habis_400 = tahun % 400 == 0;
 
    bool kabisat = (habis_4 && !habis_100) || habis_400;
 
    if (kabisat) {
        cout << tahun << " adalah tahun kabisat\n";
    } else {
        cout << tahun << " bukan tahun kabisat\n";
    }
    return 0;
}