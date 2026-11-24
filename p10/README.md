# P10 Larik Satu Dimensi sebagai Parameter Fungsi

- **Nama:** Muhammad Azmi Azkia
- **NPM:** 2510010458
- **Program Studi:** Teknik Informatika
- **Mata Kuliah:** Pemrograman Terstruktur
- **Pertemuan:** 10

Folder kode Pertemuan 10 Pemrograman Terstruktur. Larik memakai daya tampung tetap (`const int MAKS`)
dan jumlah isi yang dihitung terpisah; `std::vector` sengaja tidak dipakai karena diserahkan ke PBO.

## Isi

| Berkas | Kegunaan |
|---|---|
| `larik_dasar.cpp` | Deklarasi, inisialisasi `{...}` dan `{}`, indeks 0 sampai `JUMLAH - 1`, membaca dan mencetak dengan perulangan |
| `batas_indeks.cpp` | Indeks di luar batas lolos compile dan menghasilkan sampah; penjaga batas ditulis sendiri |
| `larik_fungsi.cpp` | Larik sebagai parameter: `rerata`, `indeksTerbesar`, `cariNama` (`const`, hanya membaca) dan `naikkanSemua` (mengubah larik pemanggil) |
| `urutkan.cpp` | Selection sort menurun pada dua larik sejajar dengan `indeksTertinggi` dan `tukar` dari Pertemuan 9; jejak tiap putaran |
| `sinilai_v08_awal.cpp` | Starter SiNilai v0.8: main, prototipe, semua fungsi v0.7, dan `tukar` sudah jadi; enam fungsi berparameter larik TODO |
| `contoh_masukan.txt` | Sama dengan Pertemuan 7 dan 9 (sengaja berantakan) |
| `.vscode/`, `.gitignore` | Sama dengan pertemuan sebelumnya |

## Fungsi baru SiNilai v0.8

| Fungsi | Parameter larik | Mengembalikan | Status di starter |
|---|---|---|---|
| `rerataKelas(const double nilai_akhir[], int jumlah)` | hanya membaca | `double` | TODO 1 |
| `hitungLulus(const double nilai_akhir[], int jumlah)` | hanya membaca | `int` | TODO 2 |
| `indeksTertinggi(const double nilai_akhir[], int mulai, int jumlah)` | hanya membaca | `int` indeks | TODO 3 |
| `urutkanMenurun(string nama[], string npm[], double nilai_akhir[], string huruf[], int jumlah)` | mengubah empat larik sejajar | `void` | TODO 4 |
| `cetakPeringkat(const string nama[], const string npm[], const double nilai_akhir[], const string huruf[], int jumlah)` | hanya membaca | `void` | TODO 5 |
| `hitungSebaran(const string huruf[], int jumlah, int& a, ..., int& e)` | hanya membaca; lima referensi | `void` | TODO 6 |

Perbedaan keluaran dengan v0.7 pada `contoh_masukan.txt` hanya tiga: baris judul, prompt jumlah yang kini
menyebut batas 1 sampai 50, dan blok baru `=== Peringkat Kelas ===` (terurut menurun) sebelum Laporan Kelas.

## Kode dan Hasil uji Sinilai v0.5 (sinilai_v07.cpp)
```cpp
// SiNilai v0.8: semua mahasiswa disimpan dalam larik, lalu diolah lewat fungsi berparameter larik.
// Semua fungsi v0.7 dipakai apa adanya (bacaJumlah hanya ditambah batas atas MAKS). Fungsi main,
// prototipe, dan tukarAngka/tukarTeks sudah jadi. Enam TODO adalah fungsi baru yang menerima larik.
// Sampai semua TODO selesai, baseline kelas memberi warning unused parameter; itu wajar.
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int MAKS = 50;                            // daya tampung larik
const double BOBOT_KEHADIRAN = 0.10;
const double BOBOT_MINGGUAN = 0.45;
const double BOBOT_UTS = 0.25;
const double BOBOT_UAS = 0.20;

// Fungsi-fungsi v0.7, dipakai apa adanya (bacaJumlah hanya ditambah batas atas MAKS)
int bacaJumlah();
string bacaNama();
double bacaKomponen(string label);
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas);
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas);
string hurufMutu(double nilai_akhir);
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus);
void perbaruiPenghitung(char awal, int& a, int& b, int& c, int& d, int& e);
void cetakSebaran(int a, int b, int c, int d, int e);

// Fungsi baru v0.8: menerima larik
double rerataKelas(const double nilai_akhir[], int jumlah);
int hitungLulus(const double nilai_akhir[], int jumlah);
int indeksTertinggi(const double nilai_akhir[], int mulai, int jumlah);
void tukarAngka(double& a, double& b);
void tukarTeks(string& a, string& b);
void urutkanMenurun(string nama[], string npm[], double nilai_akhir[], string huruf[], int jumlah);
void cetakPeringkat(const string nama[], const string npm[], const double nilai_akhir[], const string huruf[], int jumlah);
void hitungSebaran(const string huruf[], int jumlah, int& a, int& b, int& c, int& d, int& e);

int main() {
    cout << "=== SiNilai v0.8 ===\n";
    int jumlah_mahasiswa = bacaJumlah();
    cout << fixed << setprecision(2);

    string nama[MAKS];                          // empat larik sejajar: kotak ke-i
    string npm[MAKS];                           // di semua larik milik mahasiswa yang sama
    double nilai_akhir[MAKS] = {};
    string huruf[MAKS];

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i + 1 << " dari " << jumlah_mahasiswa << " ---\n";
        bacaData(nama[i], npm[i], kehadiran, mingguan, uts, uas);
        nilai_akhir[i] = hitungNilaiAkhir(kehadiran, mingguan, uts, uas);
        huruf[i] = hurufMutu(nilai_akhir[i]);
        cetakBaris(nama[i], nilai_akhir[i], huruf[i], nilai_akhir[i] >= 60);
    }

    urutkanMenurun(nama, npm, nilai_akhir, huruf, jumlah_mahasiswa);
    cetakPeringkat(nama, npm, nilai_akhir, huruf, jumlah_mahasiswa);

    int jumlah_lulus = hitungLulus(nilai_akhir, jumlah_mahasiswa);
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;
    hitungSebaran(huruf, jumlah_mahasiswa, jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << rerataKelas(nilai_akhir, jumlah_mahasiswa) << "\n";
    cout << "Tertinggi        : " << nama[0] << " (" << nilai_akhir[0] << ")\n";  // sudah terurut
    cetakSebaran(jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);
    return 0;
}

// ---------- Fungsi v0.7 ----------

// Meminta jumlah mahasiswa 1 sampai MAKS sampai sah, lalu membuang sisa baris.
int bacaJumlah() {
    int jumlah = 0;
    cout << "Jumlah mahasiswa (1 sampai " << MAKS << "): ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1 || jumlah > MAKS) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat 1 sampai " << MAKS << ". Coba lagi: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');
    return jumlah;
}

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

double bacaKomponen(string label) {
    double nilai = 0;
    cout << label << ": ";
    cin >> nilai;
    while (cin.fail() || nilai < 0 || nilai > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus angka 0 sampai 100. " << label << ": ";
        cin >> nilai;
    }
    return nilai;
}

void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas) {
    nama = bacaNama();
    cout << "NPM       : ";
    getline(cin, npm);
    kehadiran = bacaKomponen("Kehadiran ");
    mingguan = bacaKomponen("Mingguan  ");
    uts = bacaKomponen("UTS       ");
    uas = bacaKomponen("UAS       ");
    cin.ignore(1000, '\n');
}

double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas) {
    return kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN + uts * BOBOT_UTS + uas * BOBOT_UAS;
}

string hurufMutu(double nilai_akhir) {
    if (nilai_akhir >= 80) {
        return "A";
    } else if (nilai_akhir >= 75) {
        return "B+";
    } else if (nilai_akhir >= 70) {
        return "B";
    } else if (nilai_akhir >= 65) {
        return "C+";
    } else if (nilai_akhir >= 60) {
        return "C";
    } else if (nilai_akhir >= 40) {
        return "D";
    }
    return "E";
}

void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus) {
    cout << "  " << left << setw(20) << nama << right << setw(7) << nilai_akhir
         << "  " << left << setw(3) << huruf;
    if (lulus) {
        cout << "Lulus\n";
    } else {
        cout << "Belum lulus\n";
    }
}

void perbaruiPenghitung(char awal, int& a, int& b, int& c, int& d, int& e) {
    switch (awal) {
        case 'A':
            a++;
            break;
        case 'B':
            b++;
            break;
        case 'C':
            c++;
            break;
        case 'D':
            d++;
            break;
        default:
            e++;
    }
}

void cetakSebaran(int a, int b, int c, int d, int e) {
    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        if (huruf == 'A') {
            banyak = a;
        } else if (huruf == 'B') {
            banyak = b;
        } else if (huruf == 'C') {
            banyak = c;
        } else if (huruf == 'D') {
            banyak = d;
        } else {
            banyak = e;
        }
        cout << huruf << " | ";
        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }
        cout << " " << banyak << "\n";
    }
}

// ---------- Fungsi baru v0.8 ----------

// TODO 1: jumlahkan nilai_akhir[0] sampai nilai_akhir[jumlah - 1], kembalikan rata-ratanya.
double rerataKelas(const double nilai_akhir[], int jumlah) {
    double total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += nilai_akhir[i];
    }
    return total / jumlah;
}

// TODO 2: hitung berapa kotak yang nilainya >= 60.
int hitungLulus(const double nilai_akhir[], int jumlah) {
    int lulus = 0;
    for (int i = 0; i < jumlah; i++) {
        if (nilai_akhir[i] >= 60) {
            lulus++;
        }
    }
    return lulus;
}

// TODO 3: kembalikan indeks nilai tertinggi di antara kotak mulai sampai jumlah - 1
// (pola indeksTertinggi di urutkan.cpp). Nilai sama: pilih yang lebih dulu, seperti v0.7.
int indeksTertinggi(const double nilai_akhir[], int mulai, int jumlah) {
    int tertinggi = mulai;
    for (int i = mulai + 1; i < jumlah; i++) {
        if (nilai_akhir[i] > nilai_akhir[tertinggi]) {
            tertinggi = i;
        }
    }
    return tertinggi;
}

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

// TODO 4: selection sort menurun (pola urutkanMenurun di urutkan.cpp). Ingat: ada EMPAT larik
// sejajar yang harus ditukar bersama (nilai_akhir dengan tukarAngka; nama, npm, huruf dengan
// tukarTeks).
void urutkanMenurun(string nama[], string npm[], double nilai_akhir[], string huruf[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {      // kotak terakhir otomatis benar
        int t = indeksTertinggi(nilai_akhir, i, jumlah);
        if (t != i) {
            tukarAngka(nilai_akhir[i], nilai_akhir[t]);
            tukarTeks(nama[i], nama[t]);        // nama ikut pindah bersama nilainya
            tukarTeks(npm[i], npm[t]); 
            tukarTeks(huruf[i], huruf[t]); 
        }
        cout << "  putaran " << i + 1 << ": ";
        for (int k = 0; k < jumlah; k++) {
            cout << nama[k] << " ";
        }
        cout << "\n";
    }
}

// TODO 5: cetak judul "=== Peringkat Kelas ===" (didahului baris kosong), lalu satu baris per
// mahasiswa: nomor urut rata kanan lebar 2, titik, NPM, nama rata kiri lebar 20, nilai rata kanan
// lebar 7, huruf.
void cetakPeringkat(const string nama[], const string npm[], const double nilai_akhir[], const string huruf[], int jumlah) {
    cout << "\n=== Peringkat Kelas ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << right << setw(2) << i + 1 << ". "
             << npm[i] << " "
             << left << setw(20) << nama[i]
             << right << setw(7) << nilai_akhir[i]
             << " " << huruf[i] << "\n";
    }
}

// TODO 6: untuk setiap kotak, panggil perbaruiPenghitung(huruf[i][0], a, b, c, d, e)
// supaya lima penghitung milik main bertambah.
void hitungSebaran(const string huruf[], int jumlah, int& a, int& b, int& c, int& d, int& e) {
    for (int i = 0; i < jumlah; i++) {
         perbaruiPenghitung(huruf[i][0], a, b, c, d, e);
    }
}
```

Hasil :
```text
=== SiNilai v0.8 ===
Jumlah mahasiswa (1 sampai 50): 6

--- Mahasiswa ke-1 dari 6 ---
Nama      : siti AMINAH
NPM       : 2024010101
Kehadiran : 100
Mingguan  : 85.5
UTS       : 78
UAS       : 80
  Siti Aminah           83.97  A  Lulus

--- Mahasiswa ke-2 dari 6 ---
Nama      : BUDI SANTOSO
NPM       : 2024010102
Kehadiran : 80
Mingguan  : 70
UTS       : 65
UAS       : 60
  Budi Santoso          67.75  C+ Lulus

--- Mahasiswa ke-3 dari 6 ---
Nama      : r2d2
Nama tidak boleh mengandung angka.
Nama      : rina wati
NPM       : 2024010103
Kehadiran : 60
Mingguan  : 50
UTS       : 40
UAS       : 55
  Rina Wati             49.50  D  Belum lulus

--- Mahasiswa ke-4 dari 6 ---
Nama      : dewi lestari
NPM       : 2024010104
Kehadiran : 90
Mingguan  : abc
Harus angka 0 sampai 100. Mingguan  : 90
UTS       : 90
UAS       : 90
  Dewi Lestari          90.00  A  Lulus

--- Mahasiswa ke-5 dari 6 ---
Nama      : eko PRASETYO
NPM       : 2024010105
Kehadiran : 75
Mingguan  : 72
UTS       : 120
Harus angka 0 sampai 100. UTS       : 70
UAS       : 68
  Eko Prasetyo          71.00  B  Lulus

--- Mahasiswa ke-6 dari 6 ---
Nama      : fajar nugroho
NPM       : 2024010106
Kehadiran : 30
Mingguan  : 20
UTS       : 35
UAS       : 25
  Fajar Nugroho         25.75  E  Belum lulus
  putaran 1: Dewi Lestari Budi Santoso Rina Wati Siti Aminah Eko Prasetyo Fajar Nugroho 
  putaran 2: Dewi Lestari Siti Aminah Rina Wati Budi Santoso Eko Prasetyo Fajar Nugroho 
  putaran 3: Dewi Lestari Siti Aminah Eko Prasetyo Budi Santoso Rina Wati Fajar Nugroho 
  putaran 4: Dewi Lestari Siti Aminah Eko Prasetyo Budi Santoso Rina Wati Fajar Nugroho 
  putaran 5: Dewi Lestari Siti Aminah Eko Prasetyo Budi Santoso Rina Wati Fajar Nugroho 

=== Peringkat Kelas ===
 1. 2024010104 Dewi Lestari          90.00 A
 2. 2024010101 Siti Aminah           83.97 A
 3. 2024010105 Eko Prasetyo          71.00 B
 4. 2024010102 Budi Santoso          67.75 C+
 5. 2024010103 Rina Wati             49.50 D
 6. 2024010106 Fajar Nugroho         25.75 E

=== Laporan Kelas ===
Jumlah mahasiswa : 6
Lulus            : 4
Belum lulus      : 2
Rata-rata kelas  : 64.66
Tertinggi        : Dewi Lestari (90.00)

Sebaran huruf mutu:
A | ## 2
B | # 1
C | # 1
D | # 1
E | # 1
```

## Yang dikumpulkan mahasiswa

Folder `p10` di repository `pt-NPM` berisi `sinilai_v08.cpp`. Lihat Modul Pertemuan 10 bagian E.

## Deklarasi AI

Tidak menggunakan AI, semua nya mengikuti instruksi dari modul