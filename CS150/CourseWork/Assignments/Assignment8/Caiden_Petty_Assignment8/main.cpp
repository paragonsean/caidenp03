#include<string>
#include<iostream>
///include the right header for the program
using namespace std;
///make the concert promoter struct have 4 components
struct ConcertPromoter
{
   string name;
   double price;
   int capacity=100;
   int remainingTckt;
};
int main()
///name the concert promoter concert to start a new struct
{
    ///initialize the price variable
    ///make a loop to have the user choose if they want to continue buying
   ConcertPromoter concert;
   concert.name = "ODU Concert Promoter";
   concert.price = 10.0;
   concert.remainingTckt = concert.capacity;
   string choice;


   int ticketBuy;
   cout << "----------------------------------------" << endl;
   cout << concert.name << " Sales Program" << endl;
   cout << "----------------------------------------" << endl;
   cout << "\nEnter B to buy tickets" << endl;
   cout << "Enter F to finish buying" << endl;
   cin >> choice;

   while(choice!="F")
  {
       if (choice != "B")
           cout << "Sorry the response " << choice << " was not valid." << endl;
       else
       {
           ///ask how many tickets they would like to purchase and tell them the price
           cout << "How many tickets to buy? (Maximum" << concert.remainingTckt << ")" << endl;
           cin >> ticketBuy;
           if (ticketBuy <= concert.remainingTckt)
           {
               cout << "The cost of the ticket is $" << concert.price << endl;
               cout << "The total cost is $" << (ticketBuy*concert.price) << endl;
               concert.remainingTckt -= ticketBuy;
           }
           else
               cout << "Sorry, unable to complete that sale" << endl;
       }
       ///output the remaining tickets and ask if they would like to continue buying

       cout << "Tickets remaining: " << concert.remainingTckt << endl;
       cout << "----------------------------------------" << endl;
       cout << "\nEnter B to buy tickets" << endl;
       cout << "Enter F to finish buying" << endl;
       cin >> choice;
   }

   cout << "Tickets remaining: " << concert.remainingTckt << endl;
   cout << "----------------------------------------" << endl;
   ///stop the program
   system("pause");
   return 0;
}
