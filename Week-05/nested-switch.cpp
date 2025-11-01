#include<iostream>
using namespace std;
main ()
{
    int MainChoice , SubChoice;
    cout<< "     -- MAIN MENU --     "<< endl;
    cout<< "1.    FOOD MENU "<< endl;
    cout<< "2.    DRINK MENU "<< endl;
    cout<< "Enter your choice (1-2): ";
    cin>> MainChoice;
    switch (MainChoice)
    {
        case 1:
            cout<< "     -- FOOD MENU --     "<< endl;
            cout<< "1.    PIZZA "<< endl;
            cout<< "2.    BURGER "<< endl;
            cout<< "Enter your choice (1-2): ";
            cin>> SubChoice;
            switch (SubChoice)
            {
                case 1:
                    cout<< "You have selected PIZZA. "<< endl;
                    break;
                case 2:
                    cout<< "You have selected BURGER. "<< endl;
                    break;
                default:
                    cout<< "Invalid choice in FOOD MENU. "<< endl;
            }
            break;
        case 2:
            cout<< "     -- DRINK MENU --     "<< endl;
            cout<< "1.    COFFEE "<< endl;
            cout<< "2.    TEA "<< endl;
            cout<< "Enter your choice (1-2): ";
            cin>> SubChoice;
            switch (SubChoice)
            {
                case 1:
                    cout<< "You have selected COFFEE. "<< endl;
                    break;
                case 2:
                    cout<< "You have selected TEA. "<< endl;
                    break;
                default:
                    cout<< "Invalid choice in DRINK MENU. "<< endl;
            }
            break;
        default:
            cout<< "Invalid choice in MAIN MENU. "<< endl;
    }
}