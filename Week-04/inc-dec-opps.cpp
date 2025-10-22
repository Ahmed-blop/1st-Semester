#include <iostream>
using namespace std;
int main() {
    int a = 5 , b = 25;
    float x =2.5 , y = 7.5;
    cout << "initial values: " << endl;
    cout << "a = " << a << "b = " << b << endl;
    cout << "x = " << x << "y = " << y << endl;
    cout << "post increment and post decrement: " << endl;
    cout << "a++ = " << a++ << "b-- = " << b-- << endl;
    cout << "x++ = " << x++ << "y-- = " << y-- << endl;
    cout << "values after post increment and post decrement: " << endl;
    cout << "a = " << a << "b = " << b << endl;
    cout << "x = " << x << "y = " << y << endl;
    cout << "pre increment and pre decrement: " << endl;
    cout << "++a = " << ++a << "--b = " << --b << endl;
    cout << "++x = " << ++x << "--y = " << --y << endl;
    return 0;
}