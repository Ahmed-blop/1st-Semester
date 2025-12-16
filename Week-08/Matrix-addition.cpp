#include <iostream>
using namespace std;

int main()
{
    int r, c, i, j;
    int a[100][100], b[100][100], sum[100][100];

    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    cout << endl << "Enter elements of 1st matrix:" << endl;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            cout << "Enter element a" << " "<< i + 1<< " " << j + 1 << ": ";
            cin >> a[i][j];
        }
    }

    cout << endl << "Enter elements of 2nd matrix:" << endl;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            cout << "Enter element b" <<" "<<i + 1 << j + 1 << ": ";
            cin >> b[i][j];
        }
    }

        for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
    
        cout << endl << "Sum of the two matrices:" << endl;
        for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                cout << sum[i][j] << "\t";
            }
            cout << endl;
        }
    
        return 0;
    }