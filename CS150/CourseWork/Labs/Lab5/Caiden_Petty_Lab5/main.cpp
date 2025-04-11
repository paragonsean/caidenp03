#include <iostream>

using namespace std;

int main()
{
    ///declare variables
    int previous1;
    int previous2;
    int current;
    int counter;
    int nthFibonacci;

    ///ask for the first two Fibonacci numbers
    cout << "Enter the first two Fibonacci numbers" << endl;
    ///get the first two numbers
    cin >> previous1 >> previous2;
    cout << endl;
    ///echo the input to the user
    cout << "The first two numbers are "
         << previous1 << " and " << previous2
         << endl;
    ///ask for the desired position of the Fibonacci sequence
    cout << "Enter the desired position for the sequence" << endl;
    ///return it
    cin >> nthFibonacci;
    cout << endl;

    switch(nthFibonacci){
case 1:
    current = previous1;
    break;
    case 2:
        current = previous2;
        break;
    default:
        ///set the counter to 3
        counter = 3;

        ///calculate the number
        while (counter <= nthFibonacci)
        {
            current = previous2 + previous1;
            previous1 = previous2;
            previous2 = current;
            counter++;
        }///end while
        break;
    }
    /*if (nthFibonacci == 1)
        current = previous1;
    else if (nthFibonacci == 2)
        current = previous2;
    else
    {
        ///set the counter to 3
        counter = 3

        ///calculate the number
        while (counter <= nthFibonacci)
        {
            current = previous2 + previous1;
            previous1 = previous2;
            previous2 = current;
            counter++;
        }///end while
    }///end else*/
    cout << "The Fibonacci number at position "
         << nthFibonacci << " is " << current
         << endl;
    return 0;
}
