// Kesalahan 4: logika. Program berjalan mulus, tidak ada pesan apa pun,
// tetapi hasilnya salah. Rata-rata 80, 75, dan 90 seharusnya 81.67, bukan 81.
#include <iostream>
int main() {
int tugas = 80;
int uts = 75;
int uas = 90;
double rerata = (tugas + uts + uas) / 3;
std::cout << "Rata-rata: " << rerata << "\n";
return 0;
}