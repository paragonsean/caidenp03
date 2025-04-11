#include <ioStream>

using namespace std;

const double DECIMAL = 5.50;
//removed the #
double PAY_RATE = 10.75;
const string blanks = " ";
//added semicolon
int main()

{
int height, weight;
double discount;
// removed the 10%
double billingAmount;
//removed $
double bonus;
int hoursWorked = 45;
double price;
//declared variable for price

height = 6.2;
weight = 156;

cout << "Height = " << height << endl
<< "weight = " << weight << endl;

discount = (2 * height + weight) % 10;
//added semicolon
price = 49.99;
billingAmount = price * (1 - discount) - DECIMAL ;
//DECIMAL = 7.55;
//made a comment
cout << "Price = " << price << blanks << endl
<< "Billing Amount = " << billingAmount << endl;
//added an l in endl
//added a space bar at the end of billing amount statement

bonus = hoursWorked * PAY_RATE / 50;
//spell bonus right

cout << "Bonus = " << bonus << endl;
return 0;
}
