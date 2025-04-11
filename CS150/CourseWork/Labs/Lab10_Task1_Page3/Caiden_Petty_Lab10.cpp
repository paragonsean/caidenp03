#include <iostream>
#include "juiceMachine.h"

using namespace std;

void showSelection();
void sellProduct(dispenserType& product,
                 cashRegister& PCounter);

int main()
{
    cashRegister counter;
    dispenserType orange(100, 50);
    dispenserType apple(100, 65);
    dispenserType mango(75, 80);
    dispenserType strawberryBanana(100, 85);

    int choice;

    showSelection();
    cin >> choice;

    while (choice !=9)
    {
        switch (choice)
        {
        case 1:
            sellProduct(orange, counter);
            break;
        case 2:
            sellProduct(apple, counter);
            break;
        case 3:
            sellProduct(mango, counter);
            break;
        case 4:
            sellProduct(strawberryBanana, counter);
        default:
            cout << "Invalid selection." << endl;
        }///end while
        showSelection();
        cin >> choice;
    }///end main
    return 0;
}

void showSelection()
{
    cout << "***Welcome to Shelly's Juice Shop***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for orange juice (50 cents)" << endl;
    cout << "2 for apple juice (65 cents)" <<endl;
    cout << "3 for mango juice (80 cents)" << endl;
    cout << "4 for strawberry-banana (85 cents)" << endl;
    cout << "9 to exit" << endl;
}///end show selection

void sellProduct(dispenserType& product,
                 cashRegister& pCounter)
{
    int amount;///variable to hold amount entered
    int amount2;///variable to hold any extra amount

    if (product.getNoOfItems() > 0)///if the dispenser is not empty
    {
        cout << "Please deposit " << product.getCost()
             << " cents" << endl;
        cin >> amount;

        if (amount < product.getCost())
        {
            cout << "Please deposit another "
                 << product.getCost() - amount
                 << " cents" << endl;
            cin >> amount2;
            amount = amount + amount2;
        }

        if (amount >= product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Collect your item at the bottom and "
                 << "enjoy." << endl;
        }
        else
            cout << "The amount is not enough "
                 << "collect what you deposited." << endl;

        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
             << endl << endl;
    }
    else
        cout << "Sorry, this item is sold out." << endl;
}
///end sell product
