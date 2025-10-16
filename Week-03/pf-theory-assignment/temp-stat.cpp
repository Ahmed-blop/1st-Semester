#include <iostream>
using namespace std;
int main()
{
    float temp;
    cout << "Enter Temperature in Celsius: ";
    cin >> temp;
    if (temp < 20)
        cout << "Cold" << endl;
    else if (temp >= 20 && temp <= 30)
        cout << "Normal" << endl;
        else if (temp > 30)
        cout << "Hot" << endl;
        else 
        cout << "Invalid Input" << endl;
    return 0; 
}