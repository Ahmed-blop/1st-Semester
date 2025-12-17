#include <iostream>
#include <windows.h>
using namespace std;

int main ()
{
    char colors[] = {'1', '2', '3', '4', '5', '6', '7'};
    while (true){
for (int i = 0; i < 7; i++)
{
    string cmd = "color ";
    cmd += colors[i];
    cmd += "F";

    system (cmd.c_str());
    system("cls");
    cout << "COLOURED BACKGROUND";
    Sleep (150);
}
    } 
}