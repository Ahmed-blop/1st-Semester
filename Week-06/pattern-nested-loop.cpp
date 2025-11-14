#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int r;
    cout << "Input number of rows: ";
    if (!(cin >> r) || r <= 0) {
        return 1;
    }
    int x = 1;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= r - i; ++j) {
            cout << "    ";
        }
        for (int k = 1; k <= i; ++k) {
            cout << setw(4) << x;
            x++;
        }
        cout << endl;
    }
    return 0;
}