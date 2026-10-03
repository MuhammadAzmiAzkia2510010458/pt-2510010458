// SiNilai v0.1: data satu mahasiswa.
// Program membaca nama, NPM, dan empat komponen nilai, lalu menampilkannya sebagai kartu.
// Lengkapi bagian TODO. Versi ini belum menghitung apa-apa; itu tugas Pertemuan 3.
#include <iostream>
#include <string>

using namespace std;

int main() {
    // TODO 1: deklarasikan variabel untuk nama dan NPM.
    //         Nama bisa lebih dari satu kata. NPM adalah deretan angka yang tidak pernah
    //         dihitung, dan bisa diawali 0, jadi pikirkan tipe yang tepat.
    string nama;
    string npm = "2510010458";
    // TODO 2: deklarasikan empat variabel nilai: kehadiran, mingguan, uts, uas.
    //         Nilai bisa berisi pecahan seperti 85.5.
    int kehadiran = 100;
    double mingguan = 85.5;
    double nilai_uts = 80;
    double nilai_uas = 85.5;

    cout << "=== SiNilai v0.1 ===\n";
    cout << "Nama           : ";
    getline(cin, nama);
    // TODO 3: baca nama. Ingat, nama bisa mengandung spasi.

    cout << "NPM            : " << npm << "\n";
    // TODO 4: baca NPM.

    // TODO 5: baca keempat komponen nilai, satu per satu, dengan prompt seperti di atas.
    cout << "Kehadiran      : " << kehadiran << "\n";
    cout << "Nilai Mingguan : " << mingguan << "\n";
    cout << "Nilai UTS      : " << nilai_uts << "\n";
    cout << "Nilai UAS      : " << nilai_uas << "\n";

    cout << "\n--- Kartu Data Mahasiswa ---\n";
    // TODO 6: tampilkan semua data yang tadi dibaca, satu baris per data, rata seperti prompt.
    cout << "Nama           : " << nama << "\n";
    cout << "NPM            : " << npm << "\n";
    cout << "Kehadiran      : " << kehadiran << "\n";
    cout << "Nilai Mingguan : " << mingguan << "\n";
    cout << "Nilai UTS      : " << nilai_uts << "\n";
    cout << "Nilai UAS      : " << nilai_uas << "\n";
    return 0;
}
