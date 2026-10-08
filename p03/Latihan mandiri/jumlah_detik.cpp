#include <iostream>
using namespace std;

int main() {
  int jumlah_detik; 
    cout << "Masukkan jumlah detik = ";
    cin >> jumlah_detik;
    cout << jumlah_detik / 3600 << " jam, ";
    cout << (jumlah_detik % 3600) / 60 << " menit, ";
    cout << jumlah_detik % 60 << " detik";
  return 0;
}

