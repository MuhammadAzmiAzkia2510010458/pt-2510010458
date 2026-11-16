// Pelunasan utang Pertemuan 7: empat salinan pembacaan aman menjadi SATU fungsi yang dipanggil empat kali.
// bacaKomponen menerima label sebagai parameter dan mengembalikan angka yang sudah sah.
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

double bacaKomponen(string label);
string bacaNama();

int main() {
    string nama = bacaNama();
    double kehadiran = bacaKomponen("Kehadiran");
    double mingguan = bacaKomponen("Mingguan ");
    double uts = bacaKomponen("UTS      ");
    double uas = bacaKomponen("UAS      ");

    cout << "\nTersimpan: " << nama << " " << kehadiran << " " << mingguan << " " << uts << " " << uas << "\n";
    return 0;
}

// Meminta angka 0 sampai 100 sampai sah. Huruf dan angka di luar rentang ditolak.
double bacaKomponen(string label) {
    double nilai = 0;
    cout << label << " : ";
    cin >> nilai;
    while (cin.fail() || nilai < 0 || nilai > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus angka 0 sampai 100. " << label << " : ";
        cin >> nilai;
    }
    return nilai;
}

// Meminta nama sampai sah (tidak kosong, tanpa angka), lalu merapikannya menjadi Huruf Besar Di Awal Kata.
string bacaNama() {
    string nama;
    bool sah = false;
    do {
        cout << "Nama      : ";
        getline(cin, nama);
        int panjang = nama.length();
        bool ada_huruf = false;
        bool ada_angka = false;
        for (int k = 0; k < panjang; k++) {
            if (nama[k] != ' ') {
                ada_huruf = true;
            }
            if (isdigit(nama[k])) {
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

    int panjang = nama.length();
    bool awal_kata = true;
    for (int k = 0; k < panjang; k++) {
        if (nama[k] == ' ') {
            awal_kata = true;
        } else if (awal_kata) {
            nama[k] = toupper(nama[k]);
            awal_kata = false;
        } else {
            nama[k] = tolower(nama[k]);
        }
    }
    return nama;
}
