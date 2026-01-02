#include <iostream>
#include <string>
using namespace std;
struct Employee {
    string FirstName;
    string LastName;
    string Designation;
    double Salary;
};
int main() {
    Employee e[10];
    int n = 10;
    for(int i = 0; i < n; i++){
        cout << "Enter First Name: "; getline(cin, e[i].FirstName);
        cout << "Enter Last Name: "; getline(cin, e[i].LastName);
        cout << "Enter Designation: "; getline(cin, e[i].Designation);
        cout << "Enter Salary: "; cin >> e[i].Salary;
        cin.ignore();
    }
    for(int i = 0; i < n; i++)
        cout << e[i].FirstName << " " << e[i].LastName << " " << e[i].Designation << " " << e[i].Salary << endl;
}
