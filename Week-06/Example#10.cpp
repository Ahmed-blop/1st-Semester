#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    // Outer loop for rows
    while (i <= 3)
    {
        int j = 1;
        // Inner loop for columns
        while (j <= 3)
        {
            cout << i << " * " << j << " = " << i * j << endl;
            j++;
        }
        i++;
    }
    return 0;
}