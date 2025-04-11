#include <iostream>
#include "greet.h"
#include <string>
using namespace std;

int main()
{
    cout << greet() << endl;
    string
    str;

    cout << "enter a string" << endl; cin
            >> str;
    cout << endl;

    cout << "the pig latin form of " << str << "is: "
    << pigLatinString(str) << endl;

    return 0;
}
