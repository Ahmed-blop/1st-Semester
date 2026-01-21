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
    setConsoleTheme();

    // ---- Your Logic Starts Here ----


    // ---- Your Logic Ends Here ----

    return 0;
}
