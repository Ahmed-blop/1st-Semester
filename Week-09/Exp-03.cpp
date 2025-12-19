#include <iostream>
using namespace std;
void sum(int,int);
int main(){
int a,b;
cout<<"Enter 1st value: ";
cin>>a;
cout<<"Enter 2nd value: ";
cin>>b;
sum(a,b);
cout<<"Exit"<<endl;
cin.get();
}
void sum(int x,int y){
int s;
s=x+y;
cout<<"Sum is = "<<s<<endl;
}
