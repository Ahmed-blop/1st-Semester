#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if (a > b && a > c) {
        cout << "Largest number is: " << a << endl;
    }
    else if (b > c) {
        cout << "Largest number is: " << b << endl;
    }
    else {
        cout << "Largest number is: " << c << endl;
    }

    return 0;
}
