#include <iostream>
using namespace std;
int main()
{
    float cp, sp;
    cout << "Enter Cost Price: " << endl;
    cin >> cp;
    cout << "Enter Selling Price: " << endl;
    cin >> sp;
    if (sp > cp)
    {
        cout << "Profit: " << sp - cp << endl;
    }
    else if (cp > sp)
    {
        cout << "Loss: " << cp - sp << endl;
    }
    else
    {
        cout << "No Profit No Loss" << endl;
    }
}