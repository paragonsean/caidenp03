#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ///declare the variables
    int num1, num2;
    int large, small;
    bool flag = true;


    while(flag){

        ///prompt the user to enter the two numbers
        cout << "Enter the two numbers you would like to divide separated by returns: " << endl << endl;

           ///read the two numbers
        cin >> num1 >> num2;

          ///Check the user's inputs and find the biggest number
        if(num1>num2){
            large = num1;
            small = num2;
        }
        else{
            large = num2;
            small = num1;
        }

        ///calculate the large number % small number
        ///if the remainder is zero, then the numbers are divisible.
        ///else, output "These numbers are not divisible"
        if(large%small == 0){
        cout << small << " goes into " << large << ", " << large/small << " times " << endl;
        }
        else{
        cout << "These numbers are not divisible." << endl<<endl;
        }


        ///ask the user if he/she would like to continue running the program or not
        cout << "To continue, type 1. /nTo exit type any other character. " << endl;
        cin >> flag;

    }
    return 0;
}
