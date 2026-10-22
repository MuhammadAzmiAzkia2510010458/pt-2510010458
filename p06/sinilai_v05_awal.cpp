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

    double total_nilai = 0;
    int jumlah_lulus = 0;
    // TODO 2: deklarasikan lima penghitung: jumlah_a, jumlah_b, jumlah_c, jumlah_d, jumlah_e (int, mulai 0).
    // TODO 3: deklarasikan double nilai_tertinggi = -1; dan string nama_tertinggi;

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
        cout << "\n--- Kartu Nilai Mahasiswa ---\n";
        cout << "Nama        : " << nama << "\n";
        cout << "NPM         : " << npm << "\n";
        cout << "Nilai akhir : " << nilai_akhir << "\n";
        cout << "Huruf mutu  : " << huruf_mutu << "\n";
        if (lulus) {
            cout << "Status      : Lulus\n";
        } else {
            cout << "Status      : Belum lulus\n";
        }

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }

        // TODO 5: switch pada huruf_mutu[0] untuk menambah penghitung yang sesuai
        //         ('A' jumlah_a, 'B' jumlah_b, 'C' jumlah_c, 'D' jumlah_d, default jumlah_e).
        //         B+ dan B sama-sama masuk hitungan B; C+ dan C masuk hitungan C.

        // TODO 6: kalau nilai_akhir lebih tinggi dari nilai_tertinggi, perbarui nilai_tertinggi dan nama_tertinggi.
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << total_nilai / jumlah_mahasiswa << "\n";
    // TODO 7: cetak "Tertinggi        : " diikuti nama_tertinggi dan nilai_tertinggi dalam kurung.

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        // TODO 8: isi banyak dari penghitung yang sesuai dengan huruf (if-else bertingkat pada huruf).

        cout << huruf << " | ";
        // TODO 9: perulangan dalam: cetak tanda # sebanyak banyak.
        cout << " " << banyak << "\n";
    }
    return 0;
}
