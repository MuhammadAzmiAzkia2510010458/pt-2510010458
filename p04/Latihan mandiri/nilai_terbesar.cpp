#include <iostream>
using namespace std;
 
int main() {
    double nilai1 = 0;
    double nilai2 = 0;
    double nilai3 = 0;
    cout << "Bilangan pertama : ";
    cin >> nilai1;
    cout << "Bilangan kedua   : ";
    cin >> nilai2;
    cout << "Bilangan ketiga  : ";
    cin >> nilai3;
 
    double terbesar = 0;
    if (nilai1 >= nilai2 && nilai1 >= nilai3) {
        terbesar = nilai1;
    } else if (nilai2 >= nilai1 && nilai2 >= nilai3) {
        terbesar = nilai2;
    } else {
        terbesar = nilai3;
    }
 
    cout << "Bilangan Terbesar adalah : " << terbesar << "\n";
    return 0;
}
 

