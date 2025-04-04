#include "groups.h"
#include "people.h"
#include "groups.h"

using namespace std;

groups G;

void groups::Display()
{cout<<"W.I.P."<< endl;
        litr=G.GetLitrBegin();
        while(litr != G.GetLitrEnd())
            {
                (*litr)->display();
                litr++;
            }
}

groups::groups()
{
    //ctor
}

groups::~groups()
{
    //dtor
}
