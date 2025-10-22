#include <iostream>
using namespace std;
int main (){
    int a , b;
    cout << "Enter Two Numbers: ";
    cin >> a >> b;
    cout << "Sum is: " << a+b << endl;
    cout << "Difference is: " << a-b << endl;
    cout << "Product is : " <<a*b << endl;
    if (b != 0){
        cout << "Quotient is : " << a/b << endl;
        cout << "Remainder is : " << a%b << endl;
    }
    else {
        cout << "Division by zero is not allowed." << endl;
}
    return 0;
}