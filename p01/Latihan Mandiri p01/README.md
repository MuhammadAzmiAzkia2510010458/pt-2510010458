# Latihan Mandiri P01

## Perkenalan Mahasiswa

* **Nama :** Muhammad Azmi Azkia
* **NPM :** 2510010458
* **Mata Kuliah :** Pemrograman Terstruktur

## Latihan Mandiri

### 1. Mengubah `rerata.cpp`

Program `rerata.cpp` diubah agar dapat menghitung rata-rata dari lima nilai.

Bagian yang terpengaruh:

1. Penambahan variabel `kehadiran` dan `kelompok`.
2. Perubahan perhitungan `jumlah` agar menjumlahkan lima nilai.
3. Perubahan pembagi rata-rata dari `3.0` menjadi `5.0`.

Hasil program:

```text
Jumlah : 415
Rata-rata : 83.00
```

### 2. Menghapus tanda kutip penutup pada `hello.cpp`

Setelah tanda kutip pada string dihapus dan program dibangun ulang, muncul pesan error:

```text
hello.cpp:4:31: error: stray '\' in program
    4 |     std::cout << Halo dari C++\n;
      |                               ^
hello.cpp: In function 'int main()':
hello.cpp:4:18: error: 'Halo' was not declared in this scope
    4 |     std::cout << Halo dari C++\n;
      |                  ^~~~
```

Kesalahan terjadi karena teks `Halo dari C++\n` tidak lagi berada di dalam tanda kutip. 

### 3. Menghapus `#include <iostream>`

Setelah baris:

```cpp
#include <iostream>
```

dihapus dari `hello.cpp`, program dibangun ulang dan menghasilkan error:

```text
hello.cpp: In function 'int main()':
hello.cpp:4:10: error: 'cout' is not a member of 'std'
    4 |     std::cout << "Halo dari C++\n";
      |          ^~~~
```

Tahap yang gagal adalah **kompilasi**.

Error terjadi karena `std::cout` didefinisikan melalui header `<iostream>`. Ketika header tersebut dihapus, compiler tidak mengetahui definisi `std::cout`.

Pesan error berbeda dengan latihan nomor 2 karena penyebab kesalahannya berbeda. Pada nomor 2 terjadi kesalahan pada penulisan string, sedangkan pada nomor 3 `std::cout` tidak dikenali karena header yang diperlukan tidak disertakan.

### 4. Membangun `rerata_awal.cpp` tanpa `-Wall -Wextra`

Perintah yang digunakan:

```bash
g++ -std=c++20 -Wpedantic -g rerata_awal.cpp -o rerata_awal
```

Pada percobaan ini, opsi `-Wall` dan `-Wextra` tidak digunakan.

Akibatnya, pesan **warning** yang biasanya diberikan oleh compiler dengan kedua opsi tersebut dapat tidak ditampilkan.
Hal ini merugikan karena warning dapat memberikan informasi mengenai potensi masalah dalam program, walaupun program masih dapat dikompilasi.


