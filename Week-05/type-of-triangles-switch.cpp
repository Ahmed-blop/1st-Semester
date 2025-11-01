#include <iostream>
using namespace std;
main ()
{
   float perpendicular , base, hypotenuse;
   cout << "Enter the values in the order of perpendicular, base and hypotenuse respectively." << endl;
   cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> perpendicular >> base >> hypotenuse;
    switch ( (perpendicular*perpendicular + base*base == hypotenuse*hypotenuse) ? 1 :
                 (perpendicular == base && base == hypotenuse) ? 2 :
                 (perpendicular == base || base == hypotenuse || perpendicular == hypotenuse) ? 3 : 4 )
    {
        case 1:
            cout << "The triangle is a right-angled triangle." << endl;
            break;
        case 2:
            cout << "The triangle is an equilateral triangle." << endl;
            break;
        case 3:
            cout << "The triangle is an isosceles triangle." << endl;
            break;
        default:
        cout << "Enter Valid input.";
            break;
}
    return 0;
}