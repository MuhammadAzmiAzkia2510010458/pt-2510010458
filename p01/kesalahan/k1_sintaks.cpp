// Kesalahan 1: sintaks. Ada satu tanda titik koma yang hilang.
// Program ini gagal pada tahap compile, berkas .exe tidak terbentuk.
#include <iostream>
int main() {
int nilai = 80
std::cout << "Nilai: " << nilai << "\n";
return 0;
}