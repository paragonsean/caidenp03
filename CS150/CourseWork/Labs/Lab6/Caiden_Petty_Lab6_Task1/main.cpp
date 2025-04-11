#include <iostream>

using namespace std;

int main()
{
    double number_of_items, price_for_item, total_cost;///declare variables
    int count;

    ///prompt the user to enter the number of items purchased
    cout << "How many items did you purchase today? ";

    ///read the number of items
    cin >> number_of_items;

    ///initialize the cost
    total_cost= 0;

    count = 1;
    ///set count

    ///prompt the user to enter the cost of each item
    cout << "Enter the cost of each of the " << number_of_items
    << " items you purchased: \n";

    ///start loop
    while(count++ <=number_of_items)
    {
        cin >> price_for_item;///reading the price
        total_cost = total_cost + price_for_item;///updating the cost
    }///end loop

    ///output the total cost
    cout << "Total cost = " << total_cost<< " dollars" << endl;

    return 0;
}
