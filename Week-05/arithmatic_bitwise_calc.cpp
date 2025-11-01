#include<iostream>
using namespace std;
main()
{
    int op , num1 , num2 , res;
    cout << "----------Calculator Menu----------"<<endl;
    cout <<"1. Arithmatic Operations" << endl;
    cout <<"2. Bitwise Operations" << endl;
    cout <<"Enter your choice: ";
    cin >> op;
     switch(op)
        {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Select Arithmatic Operation: " << endl;
                cout << "1. Addition" << endl;
                cout << "2. Subtraction" << endl;
                cout << "3. Multiplication" << endl;
                cout << "4. Division" << endl;
                cin >> op;
                switch(op)
                {
                    case 1:
                        res = num1 + num2;
                        cout << "Result: " << res;
                        break;
                    case 2:
                        res = num1 - num2;
                        cout << "Result: " << res;
                        break;
                    case 3:
                        res = num1 * num2;
                        cout << "Result: " << res;
                        break;
                    case 4:
                        if(num2 != 0)
                        {
                            res = num1 / num2;
                            cout << "Result: " << res;
                        }
                        else
                        {
                            cout << "Error: Division by zero!";
                        }
                        break;
                    default:
                        cout << "Invalid Arithmatic Operation!";
                }
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Select Bitwise Operation: " << endl;
                cout << "1. AND" << endl;
                cout << "2. OR" << endl;
                cout << "3. XOR" << endl;
                cout << "4. NOT(FOR 1st NUMBER ONLY)" << endl;
                cin >> op;
                switch(op)
                {
                    case 1:
                        res = num1 & num2;
                        cout << "Result: " << res;
                        break;
                    case 2:
                        res = num1 | num2;
                        cout << "Result: " << res;
                        break;
                    case 3:
                        res = num1 ^ num2;
                        cout << "Result: " << res;
                        break;
                        case 4:
                            res = ~num1;
                            cout << "Result: " << res;
                             break;
                    default:
                        cout << "Invalid Bitwise Operation!";
                }
                break;
            default:
                cout << "Invalid Menu Choice!";
        }
}