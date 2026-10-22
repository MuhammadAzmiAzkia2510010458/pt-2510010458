// continue: lewati sisa badan untuk putaran ini, langsung ke putaran berikutnya.
// Daftar remediasi hanya memuat mahasiswa yang nilainya di bawah 60; yang lain dilewati.
#include <iostream>

using namespace std;

int main() {
    int jumlah = 0;
    cout << "Jumlah mahasiswa: ";
    cin >> jumlah;

    int perlu_remediasi = 0;
    cout << "--- Daftar remediasi ---\n";
    for (int i = 1; i <= jumlah; i++) {
        double nilai = 0;
        cout << "Nilai mahasiswa ke-" << i << ": ";
        cin >> nilai;
        if (nilai >= 60) {
            continue;
        }
        perlu_remediasi++;
        cout << "  Mahasiswa ke-" << i << " perlu remediasi (" << nilai << ")\n";
    }

    cout << "Total perlu remediasi: " << perlu_remediasi << " dari " << jumlah << "\n";
    return 0;
}
