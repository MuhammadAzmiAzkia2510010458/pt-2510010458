// SiNilai v0.2: menghitung nilai akhir satu mahasiswa.
// Dibangun di atas v0.1: bagian membaca data sudah jadi, tinggal menghitung dan menampilkan.
// Formula: nilai akhir = kehadiran x 10% + mingguan x 45% + UTS x 25% + UAS x 20%.
#include <iostream>
#include <string>

using namespace std;

int main() {
    // TODO 1: deklarasikan empat konstanta bobot dari konstanta.cpp Pertemuan 2
    //         (BOBOT_KEHADIRAN, BOBOT_MINGGUAN, BOBOT_UTS, BOBOT_UAS).

    string nama;
    string npm;
    double kehadiran = 0;
    double mingguan = 0;
    double uts = 0;
    double uas = 0;

    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    cout << "=== SiNilai v0.2 ===\n";
    cout << "Nama      : ";
    getline(cin, nama);
    cout << "NPM       : ";
    cin >> npm;
    cout << "Kehadiran : ";
    cin >> kehadiran;
    cout << "Mingguan  : ";
    cin >> mingguan;
    cout << "UTS       : ";
    cin >> uts;
    cout << "UAS       : ";
    cin >> uas;

    // TODO 2: hitung nilai akhir dengan formula di atas. Simpan ke variabel double nilai_akhir.
    double nilai_akhir = kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN + uts * BOBOT_UTS + uas * BOBOT_UAS;
    // TODO 3: hitung juga rata-rata sederhana keempat komponen (tanpa bobot), simpan ke rerata_polos.
    double rerata_polos = (kehadiran + mingguan + uts + uas) / 4.0;
    //         Hati-hati: pembaginya jangan bilangan bulat.

    cout << "\n--- Kartu Nilai Mahasiswa ---\n";
    cout << "Nama        : " << nama << "\n";
    cout << "NPM         : " << npm << "\n";
    cout << "Nilai Akhir : " << nilai_akhir << "\n";
    cout << "Rerata polos: " << rerata_polos << "\n";
    // TODO 4: tampilkan nilai_akhir dan rerata_polos, sejajar dengan baris di atas.

    return 0;
}
