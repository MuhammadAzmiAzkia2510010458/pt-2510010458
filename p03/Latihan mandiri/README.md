# Latihan Mandiri C++

## 1. Konversi Detik

Program membaca jumlah detik kemudian mengubahnya menjadi jam, menit, dan detik menggunakan operator `/` dan `%`.

### Kode

```cpp
#include <iostream>
using namespace std;

int main() {
    int jumlah_detik; 
    cout << "Masukkan jumlah detik = ";
    cin >> jumlah_detik;
    cout << jumlah_detik / 3600 << " jam, ";
    cout << (jumlah_detik % 3600) / 60 << " menit, ";
    cout << jumlah_detik % 60 << " detik";
    return 0;
}
```

---

## 2. Hasil Bagi dan Sisa

Program membaca dua bilangan bulat lalu menampilkan hasil pembagian dan sisa pembagiannya menggunakan operator `/` dan `%`.

### Kode

```cpp
#include <iostream>
using namespace std;

int main (){
    int nilai1;
    int nilai2;
    cout << "Masukkan Nilai pertama = ";
    cin >> nilai1;
    cout << "Masukkan Nila kedua = ";
    cin >> nilai2;

    cout << "Hasil Pembagian = " << nilai1 / nilai2 << "\n";
    cout << "Sisa Pembagian = " << nilai1 % nilai2;

    return 0;
}
```

---

## 3. Selisih Nilai Akhir dan Rerata Polos

Menambah baris selisih Nilai akhir dan Rerata polos

### Kode

```cpp
cout << "Nilai Akhir : " << nilai_akhir << "\n";
cout << "Rerata polos: " << rerata_polos << "\n";
cout << "Selisih      : " << nilai_akhir - rerata_polos;
```

Keduanya sama persis apabila nilai akhir dan rerata polos menghasilkan nilai yang sama, sehingga selisihnya adalah `0`.

---

## 4. Perbandingan C++ dan Python

Tiga ekspresi dari `prioritas.cpp` diterjemahkan ke Python dan dibandingkan hasilnya.

| Ekspresi      | C++ | Python | Hasil |
| ------------- | --: | -----: | ----- |
| `2 + 3 * 4`   |  14 |     14 | Sama  |
| `(2 + 3) * 4` |  20 |     20 | Sama  |
| `10 - 4 - 3`  |   3 |      3 | Sama  |

### Python

```python
print(2 + 3 * 4)
print((2 + 3) * 4)
print(10 - 4 - 3)
```

Dari ketiga ekspresi tersebut, tidak ada hasil yang berbeda antara C++ dan Python. Hal ini karena aturan prioritas operator pada ketiga ekspresi tersebut sama, yaitu perkalian dikerjakan lebih dahulu, tanda kurung dikerjakan terlebih dahulu, dan pengurangan dilakukan dari kiri ke kanan.


