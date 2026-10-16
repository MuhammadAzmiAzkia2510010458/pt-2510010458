// Membaca input dari pengguna dengan cin.
// Coba jalankan dengan nama satu kata, lalu dengan nama dua kata. Amati bedanya.
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama;
    int angkatan = 0;
    double nilai = 0;

    cout << "Nama     : ";
    cin >> nama;
    cout << "Angkatan : ";
    cin >> angkatan;
    cout << "Nilai    : ";
    cin >> nilai;

    cout << "\nHalo, " << nama << " angkatan " << angkatan
              << ". Nilaimu " << nilai << ".\n";
    return 0;
}
