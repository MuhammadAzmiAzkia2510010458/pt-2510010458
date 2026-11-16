// Fungsi: sepotong program yang diberi nama, menerima masukan lewat parameter, dan (boleh) mengembalikan hasil.
// Prototipe (deklarasi) di atas main memberi tahu compiler bentuk fungsinya; definisinya (isi) ditulis setelah main.
#include <iostream>

using namespace std;

// Prototipe: nama, tipe kembalian, dan tipe parameter. Diakhiri titik koma.
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas);
void cetakGaris(int panjang);

int main() {
    cetakGaris(30);
    cout << "Siti  : " << hitungNilaiAkhir(100, 85.5, 78, 80) << "\n";
    cout << "Budi  : " << hitungNilaiAkhir(80, 70, 65, 60) << "\n";

    double nilai_rina = hitungNilaiAkhir(60, 50, 40, 55);
    cout << "Rina  : " << nilai_rina << "\n";
    cetakGaris(30);
    return 0;
}

// Definisi: isi fungsi. Nama parameter di sini adalah variabel lokal milik fungsi ini.
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas) {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;
    double hasil = kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN
                 + uts * BOBOT_UTS + uas * BOBOT_UAS;
    return hasil;     // nilai ini dikirim kembali ke pemanggil
}

// void: fungsi yang mengerjakan sesuatu tanpa mengembalikan nilai.
void cetakGaris(int panjang) {
    for (int i = 1; i <= panjang; i++) {
        cout << "-";
    }
    cout << "\n";
}
