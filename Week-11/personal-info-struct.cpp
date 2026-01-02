#include <iostream>
using namespace std;
struct Person {
    string FirstName;
    string LastName;
    int Age;
    string City;
};
int main() {
    Person p;
    cout << "Enter First Name: "; cin >> p.FirstName;
    cout << "Enter Last Name: "; cin >> p.LastName;
    cout << "Enter Age: "; cin >> p.Age;
    cout << "Enter City: "; cin >> p.City;
    cout << "==========================="<<endl;
    cout << " Personal Information"<<endl;
    cout << "==========================="<<endl; 
    cout <<"First Name: "<< p.FirstName<<endl<<"Last Name: "<< p.LastName<<endl<<"Age: "<< p.Age<<endl;
    cout<<"City: "<< p.City<<endl;
    return 0;
}