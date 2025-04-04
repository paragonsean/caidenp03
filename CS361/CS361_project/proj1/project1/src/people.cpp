#include "people.h"

using namespace std;

people P;

/*friend people& operator << (people& os, const people& P)
{
    os << P.adult << " " << endl;
    return os;
}*/

bool people::adult(int age)
{
    if(people::age >= 18)
        {return true;}
    else
        {return false;}
}

people::people()
{
    //ctor
}

people::~people()
{
    //dtor
}
