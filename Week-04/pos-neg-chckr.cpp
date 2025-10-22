#include <iostream>
using namespace std;
int main() {
    int x;
    cout << "Enter an integer: ";
    if (!(cin >> x)) return 0;
    cout << ( (x > 0) ? "Positive" : "Non-positive" ) << endl;
    return 0;
}