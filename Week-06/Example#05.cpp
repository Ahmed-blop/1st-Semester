#include <iostream>
using namespace std;

int main()
{
    int number;
    
    cout << "Enter a positive number: ";
    
    while (true)
    {
        cin >> number;

        if (number > 0)
        {
            cout << "You entered a positive number: " << number << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a positive number: ";
        }
    }

    return 0;
}