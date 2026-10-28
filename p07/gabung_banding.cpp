// string: menggabung dengan +, membandingkan dengan == dan <, mengukur panjang dengan .length(),
// dan mengambil satu huruf dengan [posisi]. Posisi dihitung dari 0.
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama_depan = "Siti";
    string nama_belakang = "Aminah";

    string nama_lengkap = nama_depan + " " + nama_belakang;
    cout << "Nama lengkap  : " << nama_lengkap << "\n";
    cout << "Panjang       : " << nama_lengkap.length() << " karakter (termasuk spasi)\n";
    cout << "Huruf pertama : " << nama_lengkap[0] << "\n";
    cout << "Huruf terakhir: " << nama_lengkap[nama_lengkap.length() - 1] << "\n";

    string a = "Budi";
    string b = "budi";
    cout << "\nPerbandingan (1 berarti true):\n";
    cout << "Budi == Budi   : " << (a == "Budi") << "\n";
    cout << "Budi == budi   : " << (a == b) << "   (huruf besar dan kecil berbeda)\n";
    cout << "Aminah < Budi  : " << (nama_belakang < a) << "   (urutan kamus: A sebelum B)\n";
    cout << "Zulkifli < ade : " << (string("Zulkifli") < "ade") << "   (semua huruf besar berada sebelum huruf kecil)\n";

    string kosong;
    cout << "\nPanjang string kosong: " << kosong.length() << "\n";
    return 0;
}
