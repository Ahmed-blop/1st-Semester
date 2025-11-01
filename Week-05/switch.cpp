#include <iostream>
using namespace std;
main ()
{
    int X;
    cout << "Enter a number 10 , 20 or 30: ";
    cin >> X;
    switch (X)
    {
        case 10:
            cout << "X is Ten" << endl;
            break;
        case 20:
            cout << "X is Twenty" << endl;
            break;
        case 30:
            cout << "X is Thirty" << endl;
            break;
        default:
            cout << "X is not 10 , 20 or 30" << endl;
}