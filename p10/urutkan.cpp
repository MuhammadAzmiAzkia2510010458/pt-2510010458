// Mengurutkan larik dari yang terbesar (selection sort): untuk setiap posisi i dari kiri,
// cari indeks terbesar di sisa larik (mulai i), lalu tukar isinya dengan kotak i.
// Dua larik sejajar (nama dan nilai) harus ditukar bersama supaya nama tidak terpisah dari nilainya.
// Inilah jawaban pertanyaan refleksi Pertemuan 6: tanpa larik, daftar tidak bisa dicetak ulang terurut.
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int indeksTertinggi(const double nilai[], int mulai, int jumlah);
void tukarAngka(double& a, double& b);
void tukarTeks(string& a, string& b);
void urutkanMenurun(string nama[], double nilai[], int jumlah);
void cetakSemua(const string nama[], const double nilai[], int jumlah);

int main() {
    const int JUMLAH = 5;
    string nama[JUMLAH] = {"Siti", "Budi", "Rina", "Dewi", "Eko"};
    double nilai[JUMLAH] = {83.975, 67.75, 49.5, 90, 71};
    cout << fixed << setprecision(2);

    cout << "Sebelum diurutkan:\n";
    cetakSemua(nama, nilai, JUMLAH);

    urutkanMenurun(nama, nilai, JUMLAH);

    cout << "\nSetelah diurutkan:\n";
    cetakSemua(nama, nilai, JUMLAH);
    return 0;
}

// Sama dengan indeksTerbesar di larik_fungsi.cpp,
// tetapi pencarian dimulai dari kotak mulai.
int indeksTertinggi(const double nilai[], int mulai, int jumlah) {
    int tertinggi = mulai;
    for (int i = mulai + 1; i < jumlah; i++) {
        if (nilai[i] > nilai[tertinggi]) {
            tertinggi = i;
        }
    }
    return tertinggi;
}

// tukar dari Pertemuan 9; isi kotak larik adalah variabel biasa,
// jadi bisa dikirim sebagai referensi.
void tukarAngka(double& a, double& b) {
    double sementara = a;
    a = b;
    b = sementara;
}

void tukarTeks(string& a, string& b) {
    string sementara = a;
    a = b;
    b = sementara;
}

void urutkanMenurun(string nama[], double nilai[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {      // kotak terakhir otomatis benar
        int t = indeksTertinggi(nilai, i, jumlah);
        if (t != i) {
            tukarAngka(nilai[i], nilai[t]);
            tukarTeks(nama[i], nama[t]);        // nama ikut pindah bersama nilainya
        }
        cout << "  putaran " << i + 1 << ": ";
        for (int k = 0; k < jumlah; k++) {
            cout << nama[k] << " ";
        }
        cout << "\n";
    }
}

void cetakSemua(const string nama[], const double nilai[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "  [" << i << "] " << left << setw(6) << nama[i]
             << right << setw(7) << nilai[i] << "\n";
    }
}
