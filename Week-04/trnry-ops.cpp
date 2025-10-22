#include <iostream>
using namespace std;
int main (){
    int x;
    cout << "Enter an integer: ";
    cin >> x;
    int parity = (x % 2 == 0) ? 0 : 1;
    cout << parity << '\n';
    return 0;
}