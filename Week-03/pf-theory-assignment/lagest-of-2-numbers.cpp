#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;
    if (num1 > num2)
        cout << num1 << " is the largest number." << endl;
    else if (num2 > num1)
        cout << num2 << " is the largest number." << endl;
    else
        cout << "Both numbers are equal." << endl;
        return 0;
}