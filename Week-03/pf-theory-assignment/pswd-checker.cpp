#include <iostream>
using namespace std;
int main()
{
    string pass1, pass;
    pass1 = "ahmed";
    pass = "AHMED";
    cout << "Enter Password: ";
    cin >> pass;
    if (pass == "ahmed")
        cout << "Access Granted" << endl;
    else if(pass == "AHMED")
        cout << "Access Granted" << endl;
    else 
        cout << "Access Denied" << endl;

}