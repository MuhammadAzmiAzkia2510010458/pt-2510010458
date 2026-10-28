# P07 std::string dan Validasi Masukan

- **Nama:** Muhammad Azmi Azkia
- **NPM:** 2510010458
- **Program Studi:** Teknik Informatika
- **Mata Kuliah:** Pemrograman Terstruktur
- **Pertemuan:** 7

Folder kode Pertemuan 7 Pemrograman Terstruktur, pertemuan terakhir sebelum UTS. Program yang punya
keputusan atau perulangan berpasangan dengan flowchart di modul; dua program yang alurnya lurus
(`gabung_banding.cpp`, `getline_campur.cpp`) tidak.

## Isi

| Berkas | Kegunaan |
|---|---|
| `gabung_banding.cpp` | `+`, `==`, `<`, `.length()`, `[posisi]`: dasar-dasar string |
| `huruf_per_huruf.cpp` | for dari 0 sampai `length() - 1`: hitung kata dan vokal, balik, kapital |
| `rapikan_nama.cpp` | Huruf Besar Di Awal Kata dengan bendera `awal_kata`, `toupper`, `tolower` |
| `getline_campur.cpp` | Jebakan Enter yang tersisa setelah `cin >>`; obatnya `cin.ignore(1000, '\n')` disisipkan di praktikum |
| `input_aman.cpp` | Membaca angka dengan aman: `cin.fail()`, `cin.clear()`, `cin.ignore()`; penyembuh perulangan tanpa henti P5 |
| `validasi_nama.cpp` | do-while sampai nama sah: tidak kosong, bukan hanya spasi, tanpa angka |
| `sinilai_v06_awal.cpp` | Starter SiNilai v0.6: v0.5 utuh, lengkapi pembacaan aman dan validasi serta perapian nama |
| `contoh_masukan.txt` | Enam mahasiswa dengan masukan sengaja berantakan: nama kosong, `r2d2`, `abc`, `120` |
| `.vscode/`, `.gitignore` | Sama dengan Pertemuan 6 (termasuk `launch.json` debugger) |

## Kasus uji SiNilai v0.6 (`./sinilai_v06 < contoh_masukan.txt`)

Data mahasiswanya sama dengan Pertemuan 6, tetapi berkasnya berisi jebakan: nama ditulis
`siti AMINAH` dan `BUDI SANTOSO`, ada baris kosong sebelum nama Budi, ada nama `r2d2` sebelum Rina,
ada `abc` untuk nilai mingguan Dewi, dan `120` untuk UTS Eko. Program yang benar menolak semua jebakan
itu, meminta ulang, merapikan nama, dan menghasilkan laporan yang persis sama dengan v0.5:

| Mahasiswa (sudah dirapikan) | Nilai akhir | Huruf | Status |
|---|---|---|---|
| Siti Aminah | 83.97 | A | Lulus |
| Budi Santoso | 67.75 | C+ | Lulus |
| Rina Wati | 49.50 | D | Belum lulus |
| Dewi Lestari | 90.00 | A | Lulus |
| Eko Prasetyo | 71.00 | B | Lulus |
| Fajar Nugroho | 25.75 | E | Belum lulus |

Laporan kelas: 6 mahasiswa, 4 lulus, 2 belum lulus, rata-rata 64.66, tertinggi Dewi Lestari (90.00),
sebaran A 2, B 1, C 1, D 1, E 1.

Starter (`sinilai_v06_awal.cpp`) berjalan benar untuk masukan yang bersih, tetapi menghasilkan
laporan kacau untuk `contoh_masukan.txt`: itulah yang harus kamu perbaiki.

## Kode dan Hasil uji Sinilai v0.5 (sinilai_v05.cpp)
```cpp
// SiNilai v0.6: v0.5 yang tangguh terhadap masukan salah. Dibangun di atas v0.5 (laporan kelas).
// Yang baru: angka dibaca dengan aman (cin.fail, clear, ignore), nama divalidasi dan dirapikan
// huruf per huruf. Perhatikan: pola pembacaan aman ditulis berulang untuk empat komponen;
// itu sengaja, supaya di Pertemuan 9 kamu merasakan sendiri gunanya fungsi.
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;
    cout << "=== SiNilai v0.6 ===\n";
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah_mahasiswa;
   while (cin.fail() || jumlah_mahasiswa < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Coba lagi: ";
        cin >> jumlah_mahasiswa;
    }
    // TODO 1: do-while di atas berputar tanpa henti kalau pengguna mengetik huruf (cin gagal, isi jadi 0).
    //         Ganti dengan pola input_aman.cpp: baca sekali, lalu while (cin.fail() || jumlah_mahasiswa < 1)
    //         { cin.clear(); cin.ignore(1000, '\n'); minta lagi; }.
    cin.ignore(1000, '\n');   // buang Enter yang tersisa setelah angka, supaya getline nama tidak memungutnya

    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;
    double nilai_tertinggi = -1;
    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i << " dari " << jumlah_mahasiswa << " ---\n";

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
            cout << "Nama tidak boleh kosong atau hanya spasi.\n";
        } else if (ada_angka) {
            cout << "Nama tidak boleh mengandung angka.\n";
        } else {
            sah = true;
        }
    } while (!sah);
        // TODO 2: bungkus pembacaan nama dengan do-while seperti validasi_nama.cpp: ulangi selama nama
        //         kosong atau hanya spasi, atau mengandung angka. Periksa huruf per huruf dengan for.
    int panjang = nama.length();
    bool awal_kata = true;
    for (int i = 0; i < panjang; i++) {
        if (nama[i] == ' ') {
            awal_kata = true;
        } else if (awal_kata) {
            nama[i] = toupper(nama[i]);
            awal_kata = false;
        } else {
            nama[i] = tolower(nama[i]);
        }
    }
        // TODO 3: rapikan nama seperti rapikan_nama.cpp: huruf pertama tiap kata besar, sisanya kecil.

        cout << "NPM       : ";
        getline(cin, npm);

        cout << "Kehadiran : ";
        cin >> kehadiran;
        while (cin.fail() || kehadiran < 0 || kehadiran > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100 : ";
            cin >> kehadiran;
        }
        // TODO 4: tambahkan while (cin.fail() || kehadiran < 0 || kehadiran > 100) { clear; ignore; minta lagi; }
        cout << "Mingguan  : ";
        cin >> mingguan;
        while (cin.fail() || mingguan < 0 || mingguan > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100 : ";
            cin >> mingguan;
        }
        cout << "UTS       : ";
        cin >> uts;
        while (cin.fail() || uts < 0 || uts > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100 : ";
            cin >> uts;
        }
        cout << "UAS       : ";
        cin >> uas;
        while (cin.fail() || uas < 0 || uas > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100 : ";
            cin >> uas;
        }
        // TODO 5: ulangi pola TODO 4 untuk mingguan, uts, dan uas (ya, empat kali; catat rasanya).
        cin.ignore(1000, '\n');   // buang Enter setelah uas, supaya getline nama mahasiswa berikutnya bersih

        double nilai_akhir = kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN
                           + uts * BOBOT_UTS + uas * BOBOT_UAS;

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

        bool lulus = nilai_akhir >= 60;

        cout << "  " << left << setw(20) << nama << right << setw(7) << nilai_akhir
             << "  " << left << setw(3) << huruf_mutu;
        if (lulus) {
            cout << "Lulus\n";
        } else {
            cout << "Belum lulus\n";
        }

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }

        switch (huruf_mutu[0]) {
            case 'A':
                jumlah_a++;
                break;
            case 'B':
                jumlah_b++;
                break;
            case 'C':
                jumlah_c++;
                break;
            case 'D':
                jumlah_d++;
                break;
            default:
                jumlah_e++;
        }

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << total_nilai / jumlah_mahasiswa << "\n";
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        if (huruf == 'A') {
            banyak = jumlah_a;
        } else if (huruf == 'B') {
            banyak = jumlah_b;
        } else if (huruf == 'C') {
            banyak = jumlah_c;
        } else if (huruf == 'D') {
            banyak = jumlah_d;
        } else {
            banyak = jumlah_e;
        }

        cout << huruf << " | ";
        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }
        cout << " " << banyak << "\n";
    }
    return 0;
}
```

Hasil:

```text
=== SiNilai v0.6 ===
Jumlah mahasiswa (paling sedikit 1): 6

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
Harus angka 0 sampai 100 : 90
UTS       : 90
UAS       : 90
  Dewi Lestari          90.00  A  Lulus

--- Mahasiswa ke-5 dari 6 ---
Nama      : eko PRASETYO
NPM       : 2024010105
Kehadiran : 75
Mingguan  : 72
UTS       : 120
Harus angka 0 sampai 100 : 70
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

Folder `p07` di repository `pt-NPM` berisi `sinilai_v06.cpp`. Lihat Modul Pertemuan 7 bagian E.

## Deklarasi AI

Tuliskan AI yang digunakan, prompt, dan umpan balik AI
CHATGPT
Prompt : Perbedaan cin.fail menggunakan if dan tidak, apakah sangat berpengaruh?
Menjelaskan dengan cukup mudah dimengerti