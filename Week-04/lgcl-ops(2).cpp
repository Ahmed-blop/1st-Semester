#include <iostream>
using namespace std;
int main ()
{
    bool a , b;
    a = true;
    b = false;
    cout <<"a AND b" << (a && b) << endl;
    cout <<"a OR b" << (a || b) << endl;
    cout <<"NOT a" << (!a) << endl;
    cout <<"NOT b" << (!b) << endl;
    return 0;
}