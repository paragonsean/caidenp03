#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <istream>
#include <ostream>
#include <algorithm>
#include <stdlib.h>
#include "library.h"
// including the header files for access to the libraries

using namespace std;


struct book
{
    string name;
    string author;
    int year;
    string language;
    string genre;
    int sales;
    void printBook();
    void readBook();

    book()
    {
        name = " ";
        author = " ";
        year = 0;
        language = " ";
        genre = " ";
        sales = 0;
    }
};

struct library
{
    book novel;
    void printAuthor();
    void readAuthor();
    void sortSales(book[]);
};

 struct Date
{
    int day;
    int month;
    int year;

    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
};
struct authors
{
    string name;
    string book;
    Date DoB;

    authors()
    {
        name = " ";
        book = " ";
    }

};
//declaring the structs for access to information within different variables


void sortBdays(authors DoB[]);
void printMatches();
void Terminate();
int menu();
//declaring function prototypes


#endif // LIBRARY_H_INCLUDED
