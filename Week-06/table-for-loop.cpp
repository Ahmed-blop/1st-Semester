#include <iostream>
using namespace std;
int main ()
{
    int a, x;
    cout << "Enter the number you want the table of: ";
    cin >> a;
      for (int i = 1; i <= 10; i++){
          x = a * i;
            cout << a << " * " << i << " = " << x << endl;
 }
}