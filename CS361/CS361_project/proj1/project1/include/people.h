#ifndef PEOPLE_H
#define PEOPLE_H
#include "forwardDeclarations.h"
#include "groups.h"

#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <list>
#include <fstream>
#include <string>

using namespace std;

class people
{
    public:
        people();
        ~people();
        list<groups> Mygroups;

        people(int i){id = i;}

        void display(){cout<<"person id: " <<
         id << " age: " << getAge() <<
         " Is adult?: " << adult(age) <<
          " groups: " << getPGroup() <<
           "Infection status: 0" << endl;}

        int getStatus () {return status;}
        void setStatus (int status) {status = 0;}

        int getAge () {return age;}
        void setAge (int a) {age = a;}

        int getPGroup () {return    pGroup;}
        void setPGroup (int c) {pGroup = c;}

        /*bool getAdult() {return adult;}
        void setAdult (bool true) {adult = true;}*/
        bool adult(int age);
        //int length;
        //int test [length];

    private:
        int id;
        int age;
        int status;
        int pGroup;

};

#endif // PEOPLE_H
