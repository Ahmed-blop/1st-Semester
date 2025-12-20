#include <iostream>
#include <string>
using namespace std;
int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    if (str1.length() == str2.length()) {
        cout << "The strings have equal length." << endl;
    } else {
        cout << "The strings have different lengths." << endl;
    } 
    return 0;
}
