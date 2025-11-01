#include <iostream>
using namespace std;

int main() {
    int year, month;
    cout << "------------------------------"<<endl;
    cout << "  Month Days Calculator"<<endl;
    cout << "------------------------------"<<endl;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month (1-12): ";
    cin >> month;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            cout << "31 days"<<endl;
            break;
        case 4: case 6: case 9: case 11:
            cout << "30 days"<<endl;
            break;
        case 2:
            switch ((year % 400 == 0) ? 1 : (year % 100 == 0) ? 2 : (year % 4 == 0) ? 3 : 4) {
                case 1: case 3:
                    cout << "29 days"<<endl;
                    break;
                default:
                    cout << "28 days"<<endl;
            }
            break;
        default:
            cout << "Invalid month"<<endl;
    }
}
