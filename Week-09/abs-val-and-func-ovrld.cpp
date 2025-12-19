#include <iostream>
using namespace std;
int absolute(int x){
if(x<0) x=-x;
return x;
}
float absolute(float x){
if(x<0) x=-x;
return x;
}
int main(){
int a=-10;
float b=-5.5;
cout<<absolute(a)<<endl;
cout<<absolute(b)<<endl;
return 0;
}
