
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int total = 0;

    cout << "Masukkan n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        total += i;
    }

    cout << "Jumlah = " << total << "\n";

    return 0;
}
