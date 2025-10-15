#include <iostream>
using namespace std;
float kelvin;
float fahrenheit;
int main() {
    float celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    kelvin = celsius + 273.15;
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    cout << "Temperature in Kelvin: " << kelvin << endl;
    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    return 0;
}