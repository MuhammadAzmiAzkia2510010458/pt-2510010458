// Operator pembanding dan logika: menggabungkan beberapa syarat menjadi satu keputusan.
// Contoh: syarat mengikuti UAS adalah presensi minimal 70 DAN tugas sudah dikumpulkan.
#include <iostream>

using namespace std;

int main() {
    double presensi = 0;
    int tugas_dikumpulkan = 0;     // 1 berarti sudah, 0 berarti belum
    cout << "Presensi (0-100)          : ";
    cin >> presensi;
    cout << "Tugas dikumpulkan? (1/0)  : ";
    cin >> tugas_dikumpulkan;

    bool presensi_cukup = presensi >= 70;
    bool tugas_lengkap = tugas_dikumpulkan == 1;

    if (presensi_cukup && tugas_lengkap) {
        cout << "Boleh mengikuti UAS.\n";
    } else if (!presensi_cukup && !tugas_lengkap) {
        cout << "Tidak boleh: presensi kurang dan tugas belum lengkap.\n";
    } else if (!presensi_cukup) {
        cout << "Tidak boleh: presensi kurang dari 70.\n";
    } else {
        cout << "Tidak boleh: tugas belum dikumpulkan.\n";
    }
    return 0;
}
