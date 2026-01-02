#include <iostream>
using namespace std;
struct Employee {
    string FirstName;
    string LastName;
    string Designation;
    double Salary;
};
int main() {
    Employee e1 = {"Ahmed","Hassan","Developer",75000};
    Employee e2;
    e2 = e1;
    cout << e2.FirstName << " " << e2.LastName << " " << e2.Designation << " " << e2.Salary << endl;
    return 0;
}
