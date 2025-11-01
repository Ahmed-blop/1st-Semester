#include <iostream>
using namespace std;
main ()
{
    char grade;
    cout << "---------------------------------------" << endl;
    cout << "          GRADE DESCRIPTION            " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter your grade (A, B, C, D, F): ";
    cin >> grade;
    switch (grade)
    {
        case 'A': case 'a':
            cout << "Excellent! You’ve done outstanding work!" << endl;
            break;
        case 'B': case 'b':
            cout << "Well done! Keep it up!" << endl;
            break;
        case 'C': case 'c':
            cout << "Good! Aim higher next time!" << endl;
            break;
        case 'D': case 'd':
            cout << "You passed, but improvement is needed." << endl;
            break;
        case 'F': case 'f':
            cout << "Better try again. Don’t give up!" << endl;
            break;
        default:
            cout << "Invalid grade entered." << endl;
    }

}