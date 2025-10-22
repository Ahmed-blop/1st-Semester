#include<iostream>
using namespace std;
int main (){
    int a = 10 , b = 20;
    bool equality, inequality, greaterThan;
    bool lessThan, greaterThanOrEqual, lessThanOrEqual;
    cout << "a==b: " << (equality = (a == b)) << endl;
    cout << "a!=b: " << (inequality = (a != b)) << endl;
    cout << "a>b: " << (greaterThan = (a > b)) << endl;
    cout << "a<b: " << (lessThan = (a < b)) << endl;
    cout << "a>=b: " << (greaterThanOrEqual = (a >= b)) << endl;
    cout << "a<=b: " << (lessThanOrEqual = (a <= b)) << endl;
}