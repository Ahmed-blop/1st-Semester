#include <iostream>
using namespace std;
main ()
{
    int day;
    cout << "Choose Any Number Between (1-7): ";
    cin >> day;
    switch(day)
    {
        case 1:
        cout<<"MONDAY";
        break;
        case 2:
        cout <<"TUESDAY";
        break;
        case 3:
        cout<<"WEDNESDAY";
        break;
        case 4:
        cout <<"THURSDAY";
        break;
        case 5:
        cout << "FRIDAY";
        break;
        case 6:
        cout <<"SATURDAY";
        break;
        case 7:
        cout << "SUNDAY";
        break;
        default:
        cout << "INVALID DAY";
    }
}