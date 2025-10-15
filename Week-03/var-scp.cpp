#include <iostream>
using namespace std;
int globalVar = 100;
int main() {

    int mainVar = 200;
    cout << "Global variable: " << globalVar << endl;
    cout << "Main local variable: " << mainVar << endl;
    {
        int nestedVar = 300; 
        cout << "Global variable (inside nested block): " << globalVar << endl;
        cout << "Main local variable (inside nested block): " << mainVar << endl;
        cout << "Nested local variable: " << nestedVar << endl;
    }
    return 0;
}