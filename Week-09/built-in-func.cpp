#include <iostream>
#include <cmath>
using namespace std;
int main(){
double n;
cout << "Enter a number: ";
cin>>n;
cout<<"Absolute value: " << abs(n)<<endl;
cout<<"Square root: "<< sqrt(abs(n))<<endl;
cout<<"Power: "<< pow(n,2)<<endl;
cout<<"Ceiling: "<< ceil(n)<<endl;
cout<<"Floor: "<< floor(n)<<endl;
return 0;
}
