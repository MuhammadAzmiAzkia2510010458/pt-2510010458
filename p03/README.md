# P03 Ekspresi dan Operator: Menghitung Nilai Akhir

Folder kode Pertemuan 3 Pemrograman Terstruktur. Buka folder ini di Visual Studio Code
(File, Open Folder) supaya pengaturan di `.vscode` ikut terpakai.

## Isi

| Berkas | Kegunaan |
|---|---|
| `operator.cpp` | Lima operator aritmetika pada int dan double; pembagian bilangan bulat dan bedanya dengan Python |
| `prioritas.cpp` | Prioritas dan asosiativitas operator, operator gabungan `+=` dan `++`. Tebak dulu, baru jalankan |
| `campuran.cpp` | Ekspresi campuran int dan double: tiga cara menghitung rata-rata, hanya satu yang benar |
| `sinilai_v02_awal.cpp` | Starter SiNilai v0.2: bagian input dari v0.1 sudah jadi, lengkapi perhitungan nilai akhir |
| `contoh_masukan.txt` | Masukan uji yang sama dengan Pertemuan 2: `./sinilai_v02 < contoh_masukan.txt` |
| `.vscode/`, `.gitignore` | Sama dengan pertemuan sebelumnya |
| `_kunci/` | Kunci SiNilai v0.2, hanya untuk dosen |

## Keluaran SiNilai v0.2 yang diharapkan (bagian akhir)

```cpp
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

```

```
--- Kartu Nilai Mahasiswa ---
Nama        : Siti Aminah
NPM         : 2024010101
Nilai akhir : 83.975
Rerata polos: 85.875
```

Nilai akhir = 100 x 0,10 + 85,5 x 0,45 + 78 x 0,25 + 80 x 0,20 = 10 + 38,475 + 19,5 + 16 = 83,975.

## Yang dikumpulkan mahasiswa

Folder `p03` di repository `pt-NPM` berisi `sinilai_v02.cpp` dan  `README.md`. Lihat Modul Pertemuan 3 bagian E.

## Deklarasi AI

Tidak ada
