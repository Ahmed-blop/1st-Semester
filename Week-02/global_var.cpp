#include <iostream>
using namespace std;
int age = 25; 
void display() {
    cout << "Age inside function: " << age << endl;
}
int main()
{
    cout << "Age in main: " << age << endl;
    display();
    return 0;
}
