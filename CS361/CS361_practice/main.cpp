#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <fstream>
#include <list>

#include "people.h"


using namespace std;

class item
{public:
item(){}
item(int i){id = i;}
void display(){cout<<"item #"<<id<<endl;}
int Getid(){return id;}
private:
int id;
};
///------------------------------------
class bucket
{
  public:
    bucket(int i){Bid = i;}
    void AddItem(item * iptr){MyItems.push_back(iptr);}
    void Display()
        {cout<<"bucket #"<<Bid<<" has contents:"<<endl;
         Iitr=MyItems.begin();
         while(Iitr!=MyItems.end())
         { (*Iitr)->display();
           Iitr++;
            }
        }

    void CleanUp(){MyItems.unique();}
    int GetBid(){return Bid;}
  private:
    int Bid;
    list<item*> MyItems;
    list<item*>::iterator Iitr;


};
int main ()
 {
     default_random_engine gptr(time(NULL));
     uniform_int_distribution<int> Nbuk(1,4);
     bucket * bptr;
     list<bucket>AllBuckets;
     list<bucket>::iterator Bitr;
     for(int i =0; i<4; i++) ///create all the buckets
     {
         bptr = new bucket(i);
         AllBuckets.push_back(*bptr);

     }


     item * iptr;
     int N;
     int Target;
     for(int i=0; i<5; i++)
        {iptr = new item(i+10);
          N = Nbuk(gptr);
          cout<<endl<<"item "<<iptr->Getid()<<" will be added to "<<N<<" buckets: " ;
          for(int j=0; j<N; j++)
          {
          Target = Nbuk(gptr) - 1;

          Bitr=AllBuckets.begin();
          for(int t =0; t<Target; t++){Bitr++; } ///just moving down the list of buckets
          cout<<Bitr->GetBid()<<" ";
          Bitr->AddItem(iptr);
          Bitr=AllBuckets.begin();
          }///j loop
        }
        cout<<endl;

    Bitr=AllBuckets.begin();
    while(Bitr!=AllBuckets.end())
        {Bitr->CleanUp(); Bitr->Display(); Bitr++;}  ///eliminating any extra item *s from the buckets.

    iptr = new item(99);

    cout<<"add to which bucket?"<<endl;
    cin>>Target;
    Bitr = AllBuckets.begin();
    while(Bitr!=AllBuckets.end())
    {if (Target == Bitr->GetBid()){Bitr->AddItem(iptr);}
    Bitr++;}
    Bitr=AllBuckets.begin();
      while(Bitr!=AllBuckets.end())
        {  Bitr->Display(); Bitr++;}  ///eliminating any extra item *s from the buckets.

        return 0;
 }
