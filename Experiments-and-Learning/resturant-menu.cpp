#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy (int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

void drawGradient()
{
    char shade[] = {'2', 'A'};

    for (int y = 0; y < 25; y++) {
        system(y % 2 == 0 ? "color 2F" : "color AF");
        gotoxy(0, y);
        cout << string(80, ' ');
    }
}
void title(){
    system("color 2F");
    string t1 = "THE GREEN LEAF";
    string t2 = "RESTAURANT";

    gotoxy (25, 3);
    for (char c : t1){
        cout << c;
        Sleep (70); 
    }
    gotoxy (2, 5);
    for (char c : t2){
        cout << c;
        Sleep (0);
    }
}
string items [] = {
    "1. Burger --------- 600 Rs",
    "2. Pizza ---------- 800 Rs",
    "3. Salad ---------- 400 Rs",
    "4. Pasta ---------- 700 Rs",
    "5. Soda ----------- 100 Rs"
};
 void menu (int selected) {
    for (int i = 0; i < 5; i++){
        gotoxy (28, 9+i * 2);

        if (i == selected){
        system ("color 6F");
        cout << "> " << items[i];
    }
    else {
        system ("color 2F");
        cout << "  " << items[i];
     }
   }
 }
  int main ()
  {
    int choice = 0;
    char key;

     drawGradient();
        title();

        while (true){
            menu (choice);
            key = _getch();

            if (key == 72 && choice > 0)
                choice--;
            else if (key == 80 && choice < 4) choice++;
              else if (key == 13) break;
            }
            system ("cls");
            system ("color 2F");
            gotoxy (25 , 12);
            cout << "Thank You For Visiting!";
                }