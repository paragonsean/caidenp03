#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <istream>
#include <algorithm>
#include <stdlib.h>
#include <ostream>
#include "library.h"
// including the header files for access to the libraries

using namespace std;


int main()
{
    menu();
    //calls for the menu
    return 0;
}

int menu()
{
    book novel[11];
    library people[7];
     while(true)
    {
    int input;
    cout << "\nPlease make a selection: " << endl;
    cout << "1: Print books \n"
         << "2: Print authors \n"
         << "3: Print matches \n"
         << "4: Terminate \n" << endl;
    cin >> input;
    //lets the user ask for what they want to see

    if (input != 1 && input != 2 && input != 3 && input != 4)
    {
        cout << "Sorry, that's not a valid input, terminating... " << endl;
        break;
    }
    //if the input is wrong then terminate the program

    if (input == 1)
    {
        for(int i=0; i<1; i++)
        {novel[i].printBook();
        novel[i].readBook();}
        menu();}
    if (input == 2)
        {
            for(int o=0; o<1; o++)
            {
        people[o].readAuthor();
        people[o].printAuthor();}
        menu();}
    if (input == 3)
        {
        printMatches();
        menu();}
    if (input == 4)
    {
        cout << "Program terminating..." << endl;

        exit(0);
    }
    //runs the input
    }
    return 0;
}


void book::printBook()
{
    cout << setw(0) << right << "Title"
         << setw(25) << right << "Author"
         << setw(25) << right << "Release year"
         << setw(20) << right << "Language"
         << setw(20) << right << "Genre"
         << setw(12) << right << "Sales"//headers
         << endl;

}

void book::readBook()
{
    library lib;
    int size = 0;
    //author writer[size];

    ifstream inFile;
    inFile.open("books.txt");
    if (!inFile) {
        cout << "Unable to open file" << endl;
        exit(1); // terminate with error
    }
    ofstream outFile;
    outFile.open("OrderedBooks.txt");
    if (!outFile){
        cout << "Unable to open file" << endl;
        exit(1);
    }
    inFile >> size;
    book novel[11];
    for (int i = 0; i < 11; i++)
    {
        inFile >> novel[i].name;
        inFile >> novel[i].author;
        inFile >> novel[i].year;
        inFile >> novel[i].language;
        inFile >> novel[i].genre;
        inFile >> novel[i].sales;
        replace(novel[i].name.begin(), novel[i].name.end(), '_',' ');//calls to search for _ and replace it with ' '
        replace(novel[i].author.begin(), novel[i].author.end(), '_',' ');
    }
        //reads the book text file and assigns data to the varriables
        //string str;
        //str=novel[i].name;
        /*for(int t = 0; t < novel[i].name.length(); t++)
        {
            if(novel[i].name[t]=='_')
                novel[i].name[t]=' ';
        }
        for(int t = 0; t < novel[i].author.length(); t++)
        {
            if(novel[i].author[t]=='_')
                novel[i].author[t]=' ';
                //i--;
        }*/
        //removes the underscores
        lib.sortSales(novel);
         for (int i = 0; i < 11; i++)
    {
        cout << setw(0) << right << novel[i].name
         << setw(25) << right << novel[i].author
         << setw(5) << right << novel[i].year
         << setw(20) << right << novel[i].language
         << setw(10) << right << novel[i].genre
         << setw(10) << right << novel[i].sales
         << endl;

         //prints the information
    /*}
    for (int i = 0; i < 11; i++)
    {*/
        outFile << setw(0) << novel[i].name;//outputs to the file
        outFile << setw(25) << novel[i].author;
        outFile << setw(5) << novel[i].year;
        outFile << setw(20) << novel[i].language;
        outFile << setw(10) << novel[i].genre;
        outFile << setw(10) << novel[i].sales;
        outFile << endl;
    }
    inFile.close();//close the files
    outFile.close();
}

void printMatches()
{
    int size = 0;
    //author writer[size];

    ifstream inFile;
    inFile.open("books.txt");
    if (!inFile) {
        cout << "Unable to open file" << endl;
        exit(1); // terminate with error
    }

    inFile >> size;
    book novel[11];
    for (int i =0; i<11;i++)
    {
        inFile >> novel[i].name;
        inFile >> novel[i].author;
        inFile >> novel[i].year;
        inFile >> novel[i].language;
        inFile >> novel[i].genre;
        inFile >> novel[i].sales;
        replace(novel[i].name.begin(), novel[i].name.end(), '_',' ');//replace function tests for _ and puts ' '
        replace(novel[i].author.begin(), novel[i].author.end(), '_',' ');
    }
    cout << setw(0) << right << "Name"
         << setw(25) << right << "Nationality"
         << setw(25) << right << "Book"
         << endl;
    for(int i=0;i<3;i++)
    {
    cout << setw(0) << right << novel[i].author
         << setw(15) << right << novel[i].language
         << setw(30) << right << novel[i].name
         << endl;
    }
}

void library::printAuthor()
{
    int size = 0;
    //author writer[size];

    ifstream inFile;
    inFile.open("authors.txt");
    if (!inFile) {
        cout << "Unable to open file" << endl;
        exit(1); // terminate with error
    }
    ofstream outFile;
    outFile.open("OrderedAuthors.txt");
    if(!outFile){
        cout << "Unable to open file" << endl;;//if there is an error terminate
        exit(1);
    }
    inFile >> size;
    authors people[7];
    Date now;//establish struct type and array
    char tmp;
    for (int i =0; i<7;i++)
    {
        inFile >> people[i].name;

        inFile >> now.month >> tmp >> now.day >> tmp >> now.year;
        people[i].DoB = now;
        inFile >> people[i].book;
        replace(people[i].name.begin(), people[i].name.end(), '_',' ');//replace function tests for _ and puts ' '
        replace(people[i].book.begin(), people[i].book.end(), '_',' ');
    }
    sortBdays(people);
    for (int i =0; i<7;i++)
    {
        cout << setw(0) << right << people[i].name
         << setw(20) << right << people[i].DoB.month << tmp << people[i].DoB.year
         << setw(25) << right << people[i].book
         << endl;

        outFile << setw(0) << people[i].name;//output to the file the same as the output terminal
        outFile << setw(20) << people[i].DoB.month << tmp << people[i].DoB.year;
        outFile << setw(25) << people[i].book;
        outFile << endl;
    }
    inFile.close();//close our files
    outFile.close();

}

void library::readAuthor()
{
    cout << setw(0) << right << "Name"
         << setw(35) << right << "Date of Birth"
         << setw(25) << right << "Notable Work"
         << endl;
}

void library::sortSales(book novel[])//sort the sales from highest to lowest
{
    book temp;
    for (int j = 0; j<10; j++)
    {
    for (int i = 0; i<10; i++)
    {
        if(novel[i].sales<novel[i+1].sales)
        {
            temp = novel[i];
            novel[i] = novel[i+1];
            novel[i+1] = temp;
        }
    }
    }
}

void sortBdays(authors DoB[])//sort the birthdays using the stuct date within the authors struct
{
    authors temp;
    for (int j = 0; j<7; j++)//loops the correct number of times
    {
    for (int i = 0; i<6; i++)//loops the correct number of times -1
    {
        if(DoB[i].DoB.year>DoB[i+1].DoB.year)//testing the values to see which is older
        {
            temp = DoB[i];
            DoB[i] = DoB[i+1];
            DoB[i+1] = temp;
        }
    }
    }
}
