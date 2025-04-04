#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ///Declare the variables
    int num1, num2;
    char opr;

    ///prompt the user to enter the two integers
    cout << "Enter two numbers to use: " << endl;
    cin >> num1 >> num2;
    cout << endl;

    ///prompt the user to enter the operation
    cout << "Enter operator: "
         << "+ (addition), - (subtraction), * (multiplication), / (division): ";

    ///read the operator
    cin >> opr;
    cout << endl;

    cout << num1 << " " << opr << " " << num2 << " = ";
    ///use switch structure to choose from different cases
    switch(opr)
    {
    case '+':
        cout << num1 + num2 << endl;
        break;
    case '-':
        cout << num1 - num2 << endl;
        break;
    case '*':
        cout << num1 * num2 << endl;
        break;
    case '/':
        if (num2 != 0){
            cout << num1 / num2;
        }
        else{
            cout << "Error /n Cannot divide by 0" << endl;
        }
        break;
    default:
        cout << " Thanks for using the code!" << endl;

    }

    return 0;
}
