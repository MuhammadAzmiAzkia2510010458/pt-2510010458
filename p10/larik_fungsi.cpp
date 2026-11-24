// Larik sebagai parameter fungsi. Dua hal yang selalu ikut: nama larik dan jumlah isinya,
// karena fungsi tidak bisa tahu sendiri berapa panjang larik yang diterimanya.
// Larik TIDAK disalin saat dikirim ke fungsi: fungsi bekerja pada larik milik pemanggil itu sendiri.
// Tulis const di depan tipe kalau fungsi hanya membaca, supaya compiler menjaga janji itu.
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

double rerata(const double nilai[], int jumlah);
int indeksTerbesar(const double nilai[], int jumlah);
int cariNama(const string nama[], int jumlah, string dicari);
void naikkanSemua(double nilai[], int jumlah, double tambah);
void cetakSemua(const string nama[], const double nilai[], int jumlah);

int main() {
    const int JUMLAH = 5;
    string nama[JUMLAH] = {"Siti", "Budi", "Rina", "Dewi", "Eko"};
    double nilai[JUMLAH] = {83.975, 67.75, 49.5, 90, 71};
    cout << fixed << setprecision(2);

    cetakSemua(nama, nilai, JUMLAH);            // kirim nama lariknya saja, tanpa []
    cout << "Rata-rata : " << rerata(nilai, JUMLAH) << "\n";

    int terbesar = indeksTerbesar(nilai, JUMLAH);
    cout << "Tertinggi : " << nama[terbesar] << " (" << nilai[terbesar] << ")\n";

    int posisi = cariNama(nama, JUMLAH, "Dewi");
    if (posisi == -1) {
        cout << "Dewi tidak ditemukan\n";
    } else {
        cout << "Dewi ada di indeks " << posisi << ", nilainya " << nilai[posisi] << "\n";
    }
    cout << "Cari Andi : " << cariNama(nama, JUMLAH, "Andi") << " (artinya tidak ada)\n\n";

    naikkanSemua(nilai, JUMLAH, 5);             // mengubah larik milik main
    cout << "Setelah naikkanSemua 5:\n";
    cetakSemua(nama, nilai, JUMLAH);
    cout << "Rata-rata : " << rerata(nilai, JUMLAH) << "\n";
    return 0;
}

// const: fungsi ini berjanji hanya membaca;
// menulis nilai[i] = ... di sini ditolak compiler.
double rerata(const double nilai[], int jumlah) {
    double total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += nilai[i];
    }
    return total / jumlah;
}

// Mengembalikan INDEKS kotak terbesar, bukan isinya, supaya pemanggil bisa mengambil
// nama[indeks] juga.
int indeksTerbesar(const double nilai[], int jumlah) {
    int terbesar = 0;
    for (int i = 1; i < jumlah; i++) {
        if (nilai[i] > nilai[terbesar]) {
            terbesar = i;
        }
    }
    return terbesar;
}

// Pencarian berurutan: berhenti dan kembali begitu ketemu; -1 kalau sampai akhir tidak ada.
int cariNama(const string nama[], int jumlah, string dicari) {
    for (int i = 0; i < jumlah; i++) {
        if (nama[i] == dicari) {
            return i;
        }
    }
    return -1;
}

// Tanpa const: fungsi ini memang mengubah larik, dan perubahannya tersimpan di pemanggil.
void naikkanSemua(double nilai[], int jumlah, double tambah) {
    for (int i = 0; i < jumlah; i++) {
        nilai[i] += tambah;
    }
}

void cetakSemua(const string nama[], const double nilai[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "  [" << i << "] " << left << setw(6) << nama[i]
             << right << setw(7) << nilai[i] << "\n";
    }
}
