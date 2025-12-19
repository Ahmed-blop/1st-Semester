#include <iostream>
using namespace std;
int add(int a,int b){
return a+b;
}
int add(int a,int b,int c){
return a+b+c;
}
double add(double a,double b){
return a+b;
}
int main(){
cout<<add(2,3)<<endl;
cout<<add(1,2,3)<<endl;
cout<<add(2.5,3.5)<<endl;
return 0;
}
