#include <iostream>
using namespace std;

int main()
{
    int num, factorial=1;
    cout << "Enter a Positive Number: ";
    cin >> num;
    
    for(int i=1; i<=num; i++)
    {
        factorial = factorial * i;
    }
    
    cout << "Factorial of Number " << num << " is= " << factorial;
    
    return 0;
}