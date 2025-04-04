#ifndef GROUPS_H
#define GROUPS_H
#include "forwardDeclarations.h"
#include "people.h"

#include <random>
#include <ctime>
#include <cmath>
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class groups
{
    public:
        groups();

        ~groups();
        people *p;
        list<people*> Mypeople;
        list<people*>::iterator litr;
        list<people*>::iterator GetLitrBegin(){litr = Mypeople.begin(); return litr;}
        list<people*>::iterator GetLitrEnd(){litr = Mypeople.end(); return litr;}

        void Addthing(people *pptr){Mypeople.push_back(pptr);}
        void Display();
        //int size;
        //int sizeGroup[size];
    private:

};

#endif // GROUPS_H
