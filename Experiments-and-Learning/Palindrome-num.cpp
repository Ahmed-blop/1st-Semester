#include <iostream>
#include <windows.h>
using namespace std;

// Sets console color theme for better readability of output
void setConsoleTheme()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15); // White text on black background
}

int main()
{
    setConsoleTheme();   // Apply console theme

    int number, originalNumber, reversedNumber = 0, remainder;

    // Step 1: Input
    cout << "Enter a number: ";
    cin >> number;

    originalNumber = number;

    // Step 2: Reverse the number
    while(number > 0)
    {
        remainder = number % 10;
        reversedNumber = (reversedNumber * 10) + remainder;
        number = number / 10;
    }

    // Step 3: Check palindrome
    if(originalNumber == reversedNumber)
    {
        cout << "\nResult: Palindrome Number" << endl;
    }
    else
    {
        cout << "\nResult: Not a Palindrome Number" << endl;
    }

    return 0;
}
