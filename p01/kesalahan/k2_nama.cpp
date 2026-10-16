// Kesalahan 2: nama yang belum dikenal. Variabel dipakai sebelum dideklarasikan,
// dan ada salah ketik huruf besar. Di Python kesalahan ini baru terasa saat baris
// itu dijalankan; di C++ ditolak compiler sebelum program pernah berjalan.
#include <iostream>
int main() {
int nilai = 80;
std::cout << "Nilai: " << Nilai << "\n";
std::cout << "Bonus: " << bonus << "\n";
return 0;
}