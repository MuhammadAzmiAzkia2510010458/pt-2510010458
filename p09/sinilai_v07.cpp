// SiNilai v0.7: v0.6 yang dipecah menjadi fungsi. Perilakunya HARUS sama persis dengan v0.6
// (uji dengan contoh_masukan.txt yang sama). Fungsi main dan semua prototipe sudah jadi; tiga fungsi
// sudah diisi sebagai contoh. Enam TODO adalah memindahkan potongan v0.6 milikmu ke dalam fungsi.
// Sampai semua TODO selesai, baseline kelas memberi warning unused parameter; itu wajar.
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Konstanta bobot dibagi lewat parameter? Tidak perlu: konstanta global yang tidak pernah berubah
// aman dan lazim. Yang dihindari adalah VARIABEL global.
const double BOBOT_KEHADIRAN = 0.10;
const double BOBOT_MINGGUAN = 0.45;
const double BOBOT_UTS = 0.25;
const double BOBOT_UAS = 0.20;

int bacaJumlah();
string bacaNama();
double bacaKomponen(string label);
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas);
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas);
string hurufMutu(double nilai_akhir);
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus);
void perbaruiPenghitung(char awal, int& a, int& b, int& c, int& d, int& e);
void cetakSebaran(int a, int b, int c, int d, int e);

int main() {
    cout << "=== SiNilai v0.7 ===\n";
    int jumlah_mahasiswa = bacaJumlah();
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
        bacaData(nama, npm, kehadiran, mingguan, uts, uas);

        double nilai_akhir = hitungNilaiAkhir(kehadiran, mingguan, uts, uas);
        string huruf = hurufMutu(nilai_akhir);
        bool lulus = nilai_akhir >= 60;
        cetakBaris(nama, nilai_akhir, huruf, lulus);

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }
        perbaruiPenghitung(huruf[0], jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);
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
    cetakSebaran(jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e);
    return 0;
}

// Meminta jumlah mahasiswa (bilangan bulat paling sedikit 1) sampai sah, lalu membuang sisa baris.
int bacaJumlah() {
    int jumlah = 0;
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Coba lagi: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');
    return jumlah;
}

// TODO 2: pindahkan pembacaan nama v0.6 (do-while validasi + perapian Huruf Besar Di Awal Kata) ke sini.
//         Fungsi ini TIDAK menerima parameter: nama dibuat di dalam dan dikembalikan lewat return.
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
            cout << "Nama tidak boleh kosong atau hanya spasi.\n";
        }
        else if (ada_angka) {
            cout << "Nama tidak boleh mengandung angka.\n";
        }
        else {
            sah = true;
        }
    } while (!sah);

    int panjang = nama.length();
    bool awal_kata = true;
    for (int i = 0; i < panjang; i++)
    {
        if (nama[i] == ' ') {
            awal_kata = true;
        }
        else if (awal_kata) {
            nama[i] = toupper(nama[i]);
            awal_kata = false;
        }
        else {
            nama[i] = tolower(nama[i]);
        }
    }
    return nama;
}

// TODO 1: pindahkan SATU salinan pembacaan aman v0.6 ke sini, dengan label dari parameter.
//         Pola: cetak label lalu ": ", baca, while (cin.fail() || di luar 0..100) { clear; ignore; pesan; baca lagi }.
//         Pesan penolakan: "Harus angka 0 sampai 100. " diikuti label dan ": ". Kembalikan nilai yang sah.
double bacaKomponen(string label) {
    double nilai = 0;
    cout << label << ": ";
    cin >> nilai;
    while (cin.fail() || nilai < 0 || nilai > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. " << label << " : ";
            cin >> nilai;
        }
    return nilai;
}

// TODO 3: isi keenam parameter referensi: nama dari bacaNama(), npm dengan getline, empat komponen
//         dari bacaKomponen dengan label "Kehadiran ", "Mingguan  ", "UTS       ", "UAS       " (sejajar),
//         lalu cin.ignore(1000, '\n') supaya getline nama mahasiswa berikutnya bersih.
//         Perhatikan: tidak ada return, tetapi keenam variabel milik main terisi. Itulah referensi.
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

// TODO 4: if-else bertingkat v0.6, tetapi setiap cabang langsung return "A", "B+", dan seterusnya.
//         Tidak perlu variabel huruf_mutu; return menghentikan fungsi saat itu juga.
string hurufMutu(double nilai_akhir) {
    if (nilai_akhir >= 80) {
            return  "A";
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
        } else {
            return "E";
        }

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

// TODO 5: switch v0.6 pada awal ('A' a++, 'B' b++, 'C' c++, 'D' d++, default e++).
//         Karena parameternya referensi, a sampai e adalah jumlah_a sampai jumlah_e milik main.
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

// TODO 6: pindahkan perulangan bersarang sebaran huruf v0.6 ke sini, termasuk baris judul "Sebaran huruf mutu:".
//         Perhatikan a sampai e di sini pass by value: fungsi ini hanya membaca, tidak mengubah.
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
