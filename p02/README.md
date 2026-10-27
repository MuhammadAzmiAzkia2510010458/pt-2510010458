# P02 Tipe dan Input: Tipe Data, Variabel, Konstanta, dan Input Dasar

Folder kode Pertemuan 2 Pemrograman Terstruktur. Buka folder ini di Visual Studio Code
(File, Open Folder) supaya pengaturan di `.vscode` ikut terpakai.

## Isi

| Berkas | Kegunaan |
|---|---|
| `tipe_dasar.cpp` | Lima tipe yang dipakai sepanjang semester: int, double, char, bool, string. Mulai pertemuan ini semua kode kelas memakai `using namespace std;` |
| `konstanta.cpp` | Konstanta dengan `const`, memakai bobot penilaian mata kuliah ini. Ada satu baris untuk dicoba diubah |
| `input_dasar.cpp` | Membaca input dengan `cin`. Coba dengan nama satu kata lalu dua kata |
| `sinilai_v01_awal.cpp` | Starter SiNilai v0.1: lengkapi TODO sampai kartu data mahasiswa tampil benar |
| `contoh_masukan.txt` | Contoh masukan untuk mencoba SiNilai: `./sinilai_v01 < contoh_masukan.txt` |
| `.vscode/`, `.gitignore` | Sama dengan Pertemuan 1: Git Bash, Code Runner, Ctrl+Shift+B, hasil build tidak di-commit |

## Keluaran SiNilai v0.1 yang diharapkan
```cpp
// SiNilai v0.1: data satu mahasiswa.
// Program membaca nama, NPM, dan empat komponen nilai, lalu menampilkannya sebagai kartu.
// Lengkapi bagian TODO. Versi ini belum menghitung apa-apa; itu tugas Pertemuan 3.
#include <iostream>
#include <string>

using namespace std;

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
    string npm;
    // TODO 2: deklarasikan empat variabel nilai: kehadiran, mingguan, uts, uas.
    //         Nilai bisa berisi pecahan seperti 85.5.
    double kehadiran = 0;
    double mingguan = 0;
    double nilai_uts = 0;
    double nilai_uas = 0;

    cout << "=== SiNilai v0.1 ===\n";
    cout << "Nama           : ";
    getline(cin, nama);
    // TODO 3: baca nama. Ingat, nama bisa mengandung spasi.

    cout << "NPM            : ";
    cin >> npm;
    // TODO 4: baca NPM.

    // TODO 5: baca keempat komponen nilai, satu per satu, dengan prompt seperti di atas.
    cout << "Kehadiran      : ";
    cin >> kehadiran;
    cout << "Nilai Mingguan : ";
    cin >> mingguan;
    cout << "Nilai UTS      : ";
    cin >> nilai_uts;
    cout << "Nilai UAS      : ";
    cin >> nilai_uas;

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


```

```
=== SiNilai v0.1 ===
Nama      : Siti Aminah
NPM       : 2024010101
Kehadiran : 100
Mingguan  : 85.5
UTS       : 78
UAS       : 80

--- Kartu Data Mahasiswa ---
Nama      : Siti Aminah
NPM       : 2024010101
Kehadiran : 100
Mingguan  : 85.5
UTS       : 78
UAS       : 80
```

## Yang dikumpulkan mahasiswa

Folder `p02` di repository `pt-NPM` berisi `sinilai_v01.cpp`, dan  `README.md`. Lihat Modul Pertemuan 2 bagian E.

## Deklarasi AI

Tidak ada
