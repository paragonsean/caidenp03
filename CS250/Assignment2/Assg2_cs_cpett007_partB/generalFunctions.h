#ifndef GENERALFUNCTIONS_H_INCLUDED
#define GENERALFUNCTIONS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>  // for string streams
#include <stdlib.h>
using namespace std;

std::string IntToString(int i);
int StringToInt(string s);
void Menu();
void FindMatches(string candidates[][6], int cand_size, string openings[][7], int opening_size);


#endif // GENERALFUNCTIONS_H_INCLUDED
