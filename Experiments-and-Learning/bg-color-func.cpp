#include <iostream>
#include <windows.h>
using namespace std;

// Function to set console color theme
void setConsoleTheme()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15); // White text on black background
}

int main()
{
    setConsoleTheme();  // Apply console theme

    cout << "---- PROGRAM OUTPUT ----" << endl;
    cout << "Hello, Coding Battle!" << endl;

    return 0;
}
