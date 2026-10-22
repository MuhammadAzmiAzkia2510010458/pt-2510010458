// SiNilai v0.5: laporan kelas. Dibangun di atas v0.4 (do-while, for, dua akumulator, rekap).
// Yang baru: keluaran berkolom rapi (iomanip), penghitung per huruf mutu, mahasiswa tertinggi,
// dan sebaran huruf mutu berupa batang # yang digambar dengan perulangan bersarang.
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
    cout << "=== SiNilai v0.5 ===\n";
    do {
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        cin >> jumlah_mahasiswa;
    } while (jumlah_mahasiswa < 1);

    // TODO 1: atur cout supaya semua angka pecahan tampil dengan dua angka di belakang koma.
    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;
    // TODO 2: deklarasikan lima penghitung: jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e (int, mulai 0).
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;

    // TODO 3: deklarasikan double nilai_tertinggi = -1; dan string nama_tertinggi;
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
        cout << "Nama      : ";
        getline(cin >> ws, nama);
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

        // TODO 4: ganti kartu enam baris ini dengan SATU baris berkolom:
        //   dua spasi, nama rata kiri selebar 20, nilai_akhir rata kanan selebar 7,
        //   dua spasi, huruf_mutu rata kiri selebar 3, lalu Lulus atau Belum lulus.
        cout << " " << left << setw(20) << nama 
                    << right << setw(7) << nilai_akhir 
                    << " " << left << setw(3) << huruf_mutu;
        if (lulus) {
            cout << "Lulus\n";
        } else {
            cout << "Belum lulus\n";
        }


        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }

        // TODO 5: switch pada huruf_mutu[0] untuk menambah penghitung yang sesuai
        //         ('A' jumlah_a, 'B' jumlah_b, 'C' jumlah_c, 'D' jumlah_d, default jumlah_e).
        //         B+ dan B sama-sama masuk hitungan B; C+ dan C masuk hitungan C.
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
        

        // TODO 6: kalau nilai_akhir lebih tinggi dari nilai_tertinggi, perbarui nilai_tertinggi dan nama_tertinggi.
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
    // TODO 7: cetak "Tertinggi        : " diikuti nama_tertinggi dan nilai_tertinggi dalam kurung.
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi <<")" << "\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        // TODO 8: isi banyak dari penghitung yang sesuai dengan huruf (if-else bertingkat pada huruf).
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
        // TODO 9: perulangan dalam: cetak tanda # sebanyak banyak.
        for (int j = 1; j <= banyak; j++) {
            cout << "#";
        }
        cout << " " << banyak << "\n";
    }
    return 0;
}
