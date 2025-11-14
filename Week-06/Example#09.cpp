#include <iostream>
using namespace std;

int main()
{
    int rows = 5; // Number of rows for the pyramid
    
    // Outer loop for each row
    for (int i = 1; i <= rows; ++i)
    {
        // Inner loop for spaces
        for (int j = 1; j <= rows - i; ++j)
        {
            cout << " ";
        }
        
        // Inner loop for stars
        for (int k = 1; k <= 2 * i - 1; ++k)
        {
            cout << "*";
        }

        cout << endl; // Newline after each row
    }
    return 0;
}