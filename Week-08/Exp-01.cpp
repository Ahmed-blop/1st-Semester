#include <iostream>
using namespace std;

int main()
{
    int arr[4][2];
    cout << "Printing a 2D Array:\n";
    
    // Input
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Displaying the array
    cout << "\nYou entered:\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}