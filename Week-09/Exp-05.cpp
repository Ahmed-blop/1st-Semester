#include <iostream>
using namespace std;
float absolute(float var){
if(var<0.0)
var=-var;
return var;
}
int absolute(int var){
if(var<0)
var=-var;
return var;
}
int main(){
float floatNum=-5.5;
int intNum=-10;
cout<<"Absolute value of "<<floatNum<<" (float): "<<absolute(floatNum)<<endl;
cout<<"Absolute value of "<<intNum<<" (int): "<<absolute(intNum)<<endl;
return 0;
}
