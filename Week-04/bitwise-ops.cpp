#include <iostream>
using namespace std;
int main(){
    int a = 5; // 0101 in binary
    int b = 9; // 1001 in binary
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "a << 1 = " << (a << 1) << endl;
    cout << "b >> 1 = " << (b >> 1) << endl;
    return 0;     
}
