#include <iostream>
using namespace std;

int main()
{
    int arr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = i * j; 
        }
    }
    cout << "The 5x5 initialized array is:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}