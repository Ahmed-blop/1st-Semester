#include <iostream>
using namespace std;

int main() {
    int x = 5;
    cout << "Initial x: " << x << endl;
    cout << "Before increment: " << x << endl;
    ++x;
    cout << "After increment: " << x << endl;
    cout << "Before decrement: " << x << endl;
    --x;
    cout << "After decrement: " << x << endl;
    cout << "Before negation: " << x << endl;
    x = -x;
    cout << "After negation: " << x << endl;
    return 0;
}