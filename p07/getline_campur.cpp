// Jebakan mencampur cin >> dan getline: tombol Enter setelah angka masih tersisa di antrean masukan,
// dan getline berikutnya memungutnya sebagai baris kosong. Program ini sengaja memperlihatkan jebakannya;
// obatnya satu baris, cin.ignore(1000, '\n'), yang kamu sisipkan sendiri di praktikum.
#include <iostream>
#include <string>

using namespace std;

int main() {
    int umur = 0;
    string nama_pertama;
    string nama_kedua;

    cout << "Umur: ";
    cin >> umur;
    // TODO praktikum: sisipkan cin.ignore(1000, '\n'); di sini, lalu bandingkan hasilnya.

    cout << "Nama: ";
    getline(cin, nama_pertama);        // tanpa ignore: langsung selesai, isinya kosong

    cout << "Nama (sekali lagi): ";
    getline(cin, nama_kedua);          // baru yang ini membaca ketikanmu

    cout << "\nUmur         : " << umur << "\n";
    cout << "Nama pertama : [" << nama_pertama << "] panjang " << nama_pertama.length() << "\n";
    cout << "Nama kedua   : [" << nama_kedua << "] panjang " << nama_kedua.length() << "\n";
    return 0;
}
