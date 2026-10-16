#include <iostream>
using namespace std;

int main (){
    int nilai1;
    int nilai2;
    cout << "Masukkan Nilai pertama = ";
    cin >> nilai1;
    cout << "Masukkan Nila kedua = ";
    cin >> nilai2;

    cout << "Hasil Pembagian = " << nilai1 / nilai2 << "\n";
    cout << "Sisa Pembagian = " << nilai1 % nilai2;

    return 0;
}