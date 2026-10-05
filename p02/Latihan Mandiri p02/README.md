# Latihan Mandiri P01
## Identitas Mahasiswa

* **Nama :** Muhammad Azmi Azkia
* **NPM :** 2510010458
* **Mata Kuliah:** Pemrograman Terstruktur 

## D. Latihan Mandiri

### 1. Tambah Variabel

Pada SiNilai v0.1, ditambahkan satu data baru yaitu Program Studi.

Tipe data yang digunakan adalah:

string prodi = "Teknik Informatika";

Tipe string dipilih karena Program Studi berupa teks dan dapat terdiri dari beberapa kata, seperti "Teknik Informatika".

Data Program Studi kemudian ditampilkan pada kartu data mahasiswa:
```cpp
cout << "Program Studi  : " << prodi << "\n";
```
Sehingga data yang ditampilkan menjadi:
```text
=== SiNilai v0.1 ===
Nama           : ...
NPM            : 2510010458
Program Studi  : Teknik Informatika
Kehadiran      : 100
Nilai Mingguan : 85.5
Nilai UTS      : 80
Nilai UAS      : 85.5

--- Kartu Data Mahasiswa ---
Nama           : ...
NPM            : 2510010458
Program Studi  : Teknik Informatika
Kehadiran      : 100
Nilai Mingguan : 85.5
Nilai UTS      : 80
Nilai UAS      : 85.5
```

### 2. Menampilkan nilai Boolean sebagai true/false
Pada tipe_dasar.cpp, variabel lulus bertipe bool digunakan untuk menyimpan nilai benar atau salah.
```cpp
bool lulus = true;
```
Agar nilai boolean ditampilkan sebagai true atau false, bukan 1 atau 0, digunakan boolalpha pada cout:
```cpp
cout << "Lulus            : " << boolalpha << lulus << "\n";
```
Sebelum menggunakan boolalpha, nilai bool biasanya ditampilkan sebagai angka:
```text
Lulus            : 1
```
Setelah menggunakan boolalpha, hasilnya menjadi:
```text
Lulus            : true
```

### 3. Perbandingan `int`

Percobaan pertama menggunakan:

```cpp
int nilai = 85.7;
std::cout << nilai << "\n";
```

Pada bentuk ini, compiler memberikan **warning** karena terjadi konversi dari tipe `double` ke `int`. Bagian desimal dari nilai tersebut akan dipotong sehingga hasil yang dicetak adalah:

```text
85
```

Kemudian kode diubah menjadi:

```cpp
int nilai{85.7};
std::cout << nilai << "\n";
```

Pesan Error :

```text
intNilai.cpp: In function 'int main()':
intNilai.cpp:6:15: error: narrowing conversion of '8.5700000000000003e+1' from 'double' to 'int' [-Wnarrowing]
    6 |     int nilai{85.7};
      |               ^~~~

```

Pada bentuk ini, compiler memberikan **error** karena *brace initialization* tidak mengizinkan *narrowing conversion*, yaitu konversi dari `double` ke `int` yang dapat menyebabkan kehilangan data.


### 4. Nama Variabel yang Kurang Jelas

Berikut lima contoh nama variabel yang kurang jelas dan usulan nama yang lebih baik:

| No. | Nama Variabel Buruk | Nama Variabel Lebih Jelas | Alasan                                                                |
| --- | ------------------- | ------------------------- | --------------------------------------------------------------------- |
| 1   | `nilai`                 | `nilaiUjian`              |nilai terlalu umum sehingga tidak diketahui nilai apa yang dimaksud.                     |
| 2   | `jumlahmahasiswa`                 | `jumlahMahasiswa`         | jumlahmahasiswa sulit dibaca karena tidak ada pemisah antara kata jumlah dan mahasiswa.                |
| 3   | `data`              | `dataMahasiswa`           | `data` data terlalu umum sehingga tidak menjelaskan data apa yang disimpan.               |
| 4   | `nilai sementara`               | `nilai_sementara`          | nilai sementara menggunakan spasi yang tidak diperbolehkan dalam nama variabel C++. |
| 5   | `jumlah`                 | `jumlah_nilai`             | jumlah terlalu umum sehingga tidak menjelaskan jumlah dari data apa yang disimpan                   |

