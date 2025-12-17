#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main ()
{
    while (true){
    system ("color 1F");
        system ("cls");
    cout << "Hello, My Name is Ahmed Hassan"<<endl;
    Sleep (2000);

     system ("color 2E");
        system("cls");
        cout << "I am 20 Years Old"<<endl;
    }
    for (int i=0 ; i<20 ; i++){
        system ("cls");
        system ("color 2F");
        
        for (int j=0 ; j<1; j++)
        {
            cout << " ";
            cout << "<<<<<<<";
            Sleep (100);
        }
    }

}