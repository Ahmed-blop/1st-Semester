#include <iostream>
using namespace std;
int main ()
{
float length, width;
int area , perimeter;
cout << "Enter length" << endl;
cin >> length;
cout << "Enter width" << endl;
cin >> width;
area = length * width;
perimeter = 2 * (length + width);
cout << "Area is " << area << endl;
cout << "Perimeter is " << perimeter << endl;
return 0;
}