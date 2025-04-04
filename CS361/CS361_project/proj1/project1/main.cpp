#include "people.h"
#include "groups.h"

#include <random>
#include <ctime>
#include <cmath>
#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
default_random_engine gen(time(NULL));
uniform_int_distribution<int> ageDist(1,80);
uniform_int_distribution<int> numGroups(2,6);
uniform_int_distribution<int> groupNums(1,100);
    //generate random age groups and group size

    list<people*>::iterator litr;

    string str;
     int population = 0;

    groups G;
    people P;

    people * pptr;

    cout << "Enter population number: " << endl;
    cin >> population;
    cout << "\nStatus key:\n----------------------------------- \n(0): healthy (1): exposed (2): infected (3): dead" << endl;
    //create population and start simulation

    /*while(true)
    {
        cout << "Enter string (\"continue\" to continue): ";
        getline(cin, str);
        if(str=="continue")
            break;
    }*/
    //test code

    for(int i=0; i<population; i++)
    {
        pptr = new people(i);
        G.Addthing(pptr);
    }//populate

    litr = G.GetLitrBegin();
    while(litr != G.GetLitrEnd())
    {
        pptr = *litr;
        int a = ageDist(gen);
        pptr->setAge(a);
        int b = numGroups(gen);
        pptr->setPGroup(b);
        pptr->display();
            for(int g=0; g<b; g++)
            {
                int c = groupNums(gen);
                cout << c << endl;

            }

               litr++;
    }//make age and groups



     G.Display();
    return 0;
}
