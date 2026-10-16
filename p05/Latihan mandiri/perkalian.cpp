
#include <iostream>
using namespace std;

int main() {
    int n = 0;

    cout << "Masukkan n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << " x " << j
                 << " = " << i * j << "\t";
        }

        cout << "\n";
    }

    return 0;
}
