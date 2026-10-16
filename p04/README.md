# P04 Percabangan: if, if-else, switch, dan Operator Logika

## Isi

| Berkas | Kegunaan |
|---|---|
| `sinilai_v03_awal.cpp` | SiNilai v0.3 berisi huruf mutu, status, keterangan |

## Kasus uji SiNilai v0.3

```cpp
// SiNilai v0.3: nilai akhir diubah menjadi huruf mutu dan keterangan kelulusan.
// Dibangun di atas v0.2. Tabel konversi mengikuti peraturan akademik (lihat kontrak kuliah):
//   80-100 A | 75-79,9 B+ | 70-74,9 B | 65-69,9 C+ | 60-64,9 C | 40-59,9 D | 0-39,9 E
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    string nama;
    string npm;
    double kehadiran = 0;
    double mingguan = 0;
    double uts = 0;
    double uas = 0;

    cout << "=== SiNilai v0.3 ===\n";
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

    double nilai_akhir = kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN
                       + uts * BOBOT_UTS + uas * BOBOT_UAS;

    // TODO 1: deklarasikan string huruf_mutu, lalu isi dengan if-else bertingkat sesuai tabel di atas.
    //         Mulai dari batas tertinggi (80) turun ke bawah. Pikirkan kasus batas: 79.9, 80, 59.9, 60.
    string huruf_mutu;
    if (nilai_akhir >= 80) {
        huruf_mutu = "A";
    } else if (nilai_akhir >= 75) {
        huruf_mutu = "B+";
    } else if (nilai_akhir >= 70) {
        huruf_mutu = "B";
    } else if (nilai_akhir >= 65) {
        huruf_mutu = "C+";
    } else if (nilai_akhir >= 60) {
        huruf_mutu = "C";
    } else if (nilai_akhir >= 40) {
        huruf_mutu = "D";
    } else {
        huruf_mutu = "E";
    }

    // TODO 2: deklarasikan bool lulus. Aturan SiNilai: lulus bila huruf mutu minimal C
    //         (dengan kata lain, nilai_akhir >= 60).
    bool lulus = nilai_akhir >= 60;

    // TODO 3: deklarasikan string keterangan. Isi dengan switch pada huruf pertama huruf_mutu
    string keterangan;
    switch (huruf_mutu[0]) {
        case 'A':
            keterangan = "Sangat Baik";
            break;
        case 'B':
            keterangan = "Baik";
            break;
        case 'C':
            keterangan = "Cukup";
            break;
        case 'D':
            keterangan = "Kurang";
            break;
        case 'E':
            keterangan = "Sangat Kurang";
            break;
        default:
            cout << "Salah Input";
    }
    //         (huruf_mutu[0] bertipe char): 'A' Sangat baik, 'B' Baik, 'C' Cukup,
    //         'D' Kurang, 'E' Sangat kurang. Ingat break.

    cout << "\n--- Kartu Nilai Mahasiswa ---\n";
    cout << "Nama        : " << nama << "\n";
    cout << "NPM         : " << npm << "\n";
    cout << "Nilai akhir : " << nilai_akhir << "\n";
    // TODO 4: tampilkan Huruf mutu, Keterangan, dan Status (Lulus / Belum lulus) sejajar.
    cout << "Huruf mutu  : " << huruf_mutu << "\n";
    cout << "Keterangan  : " << keterangan << "\n";
    if (lulus) {
        cout << "Status      : Lulus\n";
    } else {
        cout << "Status      : Belum Lulus\n";
    }


    return 0;
}

```

| Empat komponen | Nilai akhir | Huruf | Keterangan | Status |
|---|---|---|---|---|
| contoh_masukan.txt | 83.975 | A | Sangat baik | Lulus |
| 80 x4 | 80 | A | Sangat baik | Lulus |
| 79.9 x4 | 79.9 | B+ | Baik | Lulus |
| 60 x4 | 60 | C | Cukup | Lulus |
| 59.9 x4 | 59.9 | D | Kurang | Belum lulus |
| 30 x4 | 30 | E | Sangat kurang | Belum lulus |

## Yang dikumpulkan mahasiswa

Folder `p04` di repository `pt-NPM` berisi `sinilai_v03.cpp` dan  `README.md`. Lihat Modul Pertemuan 4 bagian E.

## Deklarasi AI
Tuliskan AI yang digunakan, prompt, dan umpan balik AI
Tidak Ada