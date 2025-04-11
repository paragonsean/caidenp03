#include<iostream>
#include<string>
#include<fstream>
///include the header file
using namespace std;

class Stamp
{///opens the class stamp
private:
   string country;
   int price;
   string condition;
   int year;
public:
   Stamp();
   Stamp(string, int, string, int);
   string getCountry();
   int getPrice();
   int getYear();
   string getCondition();

};

Stamp::Stamp() {}
///shortening variables
Stamp::Stamp(string cun, int prc, string con, int yr)
{
   country = cun;
   price = prc;
   condition = con;
   year = yr;
}
///adds the variables to the stamp class
string Stamp::getCountry()
{
   return country;
}
int Stamp::getPrice()
{
   return price;
}
int Stamp::getYear()
{
   return year;
}
string Stamp::getCondition()
{
   return condition;
}
///initializes the void functions to be used
void readData(Stamp[]);
void printStamps(Stamp[],int);
void sortStamps(Stamp[], int);

int main()
{
///sets the size to be the same
const int size = 10;
   Stamp stamps[size];
   readData(stamps);///starts the void function
   printStamps(stamps, size);
   cout << "\nSorted list..." << endl << endl;
   sortStamps(stamps, size);
   printStamps(stamps, size);
   return 1;
}
void readData(Stamp stmps[])
{
   ifstream infile("stamps.txt");
   string country, condition;
   int price, year;
   int i = 0;
   while (!infile.eof())
   {
       infile >> country >> price >> condition >> year;
       stmps[i] = Stamp(country, price, condition, year);
       i++;
   }
}

void printStamps(Stamp stmps[], int size)
{

cout.width(15); cout << left<<"Country";
   cout.width(15); cout << left << "Price";
   cout.width(15); cout << left << "Condition";
   cout.width(15); cout << left << "Year"<<endl;
   cout.width(15); cout << left << "=======";
   cout.width(15); cout << left << "=====";
   cout.width(15); cout << left << "==========";
   cout.width(15); cout << left << "====" << endl;
   for (int i = 0; i < size; i++)
   {
       cout.width(15); cout << left << stmps[i].getCountry();
       cout.width(15); cout << left << stmps[i].getPrice();
       cout.width(15); cout << left << stmps[i].getCondition();
       cout.width(15); cout << left << stmps[i].getYear() << endl;
}
}
void sortStamps(Stamp stmps[], int size)
{
   Stamp temp;
   for (int i = 0; i < size - 1; i++)
   {
       for (int j = i + 1; j < size; j++)
       {
           if (stmps[i].getYear() > stmps[j].getYear())
           {
               temp = stmps[i];
               stmps[i] = stmps[j];
               stmps[j] = temp;
           }
       }
   }
}
