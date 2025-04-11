#include <iostream>
#include <iomanip>

using namespace std;

///Structure for a bank certification of deposit:
struct CDAccount
{
    double balance;
    double interestRate;
    int term; ///months until maturity
};

void getData(CDAccount& theAccount);

int main()
{
    CDAccount account;

    ///Call the function to read the data
    getData(account);

    double rateFraction, interest;

    ///Calculate the balance
    rateFraction = account.interestRate/100.0;
    interest = account.balance * rateFraction * (account.term/12.0);
    account.balance = account.balance + interest;

    ///Output the results
    cout << endl;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "When your CD matures in "
         << account.term << " months,\n"
         << "it will have a balance of $"
         << account.balance << endl;
    return 0;
}

///function to read the data
void getData(CDAccount& theAccount)
{
    cout << "Enter account balance: $";
    cin >> theAccount.balance;

    cout << "Enter account interest rate: ";
    cin >> theAccount.interestRate;

    cout << "Enter the number of months until maturity\n"
         << "(must be 12 or fewer months): ";
    cin >> theAccount.term;
}
