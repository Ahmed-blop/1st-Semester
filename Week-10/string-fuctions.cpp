#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main () {
    string s1 ;
    string s2 ;
    cout<<"Enter first string: ";
    getline (cin , s1) ;
    cout<<"Enter second string: ";
    getline (cin , s2) ;
    char str1[100];
    char str2[100];
    strcpy (str1 , s1.c_str()) ;
    strcpy (str2 , s2.c_str()) ;
    cout<<"After strcpy, str1: "<<str1<<endl;
    strcat (str1 , str2) ;
    cout<<"After strcat, str1: "<<str1<<endl;
    int length = strlen (str2) ;
    cout<<"Length of str2: "<<length<<endl;
    int cmpResult = strcmp (str1 , str2) ;
    if (cmpResult == 0) {
        cout<<"str1 and str2 are equal."<<endl;
    } else if (cmpResult < 0) {
        cout<<"str1 is less than str2."<<endl;
    } else {
        cout<<"str1 is greater than str2."<<endl;
    }
    return 0;
}