#include <iostream>
using namespace std;
struct Employee {
    string FirstName;
    string LastName;
    string Designation;
    double Salary;
    string DOB;
    string City;
};
int main() {
    Employee e = {"Ahmed", "Hassan", "Developer", 75000, "2004-03-29", "Islamabad"};
    cout<<e.FirstName<<" "<< e.LastName<<" "<<e.Designation<<" "<<e.Salary<<" "<<e.DOB<<" "<< e.City<<endl;
    return 0;
}
