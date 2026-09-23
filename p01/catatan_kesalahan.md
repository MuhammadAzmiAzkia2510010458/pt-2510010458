# Catatan Kesalahan Praktikum 5

| Berkas | Jenis kesalahan | Pesan yang muncul (salin baris pertamanya) | Cara kamu mengetahuinya |
|---|---|---|---|
| k1_sintaks.cpp | Ada satu sintaks tanda titik koma nya hilang | k1_sintaks.cpp: In function 'int main()': k1_sintaks.cpp:6:1: error: expected ',' or ';' before 'std' | Memperhatikan line dan pesan error |
| k2_nama.cpp | Kesalahan nama Variabel bonus dipakai sebelum dideklarasikan dan variabel nilai salah ketik | k2_nama.cpp:8:27: error: 'bonus' was not declared in this scope, k2_nama.cpp:6:5: warning: unused variable 'nilai' | Memperhatkan variabel bonus dan nilai dengan cermat |
| k3_runtime.cpp | Kesalahan saat runtime | Jumlah mahasiswa: 0  | Program berhenti/error ketika jumlah mahasiswa diisi 0 |
| k4_logika.cpp | Kesalahan pada logika Program berjalan tapi hasilnya salah | Rata-rata: 81 | Karena 3 berupa bilangan bulat bukan double |

## Kesalahan Paling Berbahaya
Menurut saya, kesalahan jenis logika paling berbahaya karena program tetap berjalan tanpa menampilkan pesan kesalahan, tetapi dapat menghasilkan output yang salah jika tidak diperhatikan
