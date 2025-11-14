#include <iostream>
using namespace std;

int main()
{
    // Outer loop controls the number of rows
    for (int i = 1; i <= 5; i++)
    {
        // Inner loop controls the number of columns
        for (int j = 1; j <= 3; j++)
        {
            cout << "* "; // print a star followed by a space
        }
        cout << endl; // move to next line after one row
    }
    return 0;
}