#include <iostream>
using namespace std;
int main()
{
    float num;
    cout << "Enter either a positive or negative number or zero: ";
    cin >> num;
    if (num > 0)
        cout << "You entered a positive number." << endl;
    else if (num < 0)
        cout << "You entered a negative number." << endl;
        else if (num == 0)
        cout << "You entered zero." << endl;
    else
        cout << "You did not enter a number." << endl;
    return 0;
}