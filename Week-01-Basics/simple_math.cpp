#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many numbers you want to sum (either 4 or 5): " << endl;
    cin >> n;

    if (n != 4 && n != 5) {
        cout << "Enter a valid Number" << endl;
        return 1;
    }

    if (n == 4) {
        float a, b, c, d, sum;
        cout << "Enter 4 numbers" << endl;
        cin >> a >> b >> c >> d;
        sum = a + b + c + d;
        cout << "The sum of given 4 numbers is: " << sum << endl;
    }
    else if (n == 5) {
        float a, b, c, d, e, sum;
        cout << "Enter 5 numbers" << endl;
        cin >> a >> b >> c >> d >> e;
        sum = a + b + c + d + e;
        cout << "The sum of given 5 numbers is: " << sum << endl;
    }

    return 0;
}

