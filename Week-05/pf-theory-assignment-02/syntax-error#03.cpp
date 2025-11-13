#include <iostream>
using namespace std;

int main()
{
    int num, i = 1;
    cout << "Enter number: ";
    cin >> num;

    while(i <= 5)
    {
        cout << num * i << endl;
        i++;
    }

    return 0;
}
