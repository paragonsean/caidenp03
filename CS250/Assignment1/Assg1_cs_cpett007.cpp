#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <istream>
#include <algorithm>
#include <stdlib.h>
// including the header files for access to the libraries

using namespace std;

struct book
{
    string name;
    string author;
    int year;
    string language;
    string genre;
};
 struct Date
        {
            int day;
            int month;
            int year;
        };
struct authors
    {
        string name;
        string book;
        Date DoB;
    };
//declaring the structs for access to information within different variables

void printBook();
void printAuthor();
void printMatches();
void Terminate();
void readBook();
int menu();
//declaring function prototypes

int main()
{
    menu();
    //calls for the menu
    return 0;
}

int menu()
{
     while(true)
    {
    int input;
    cout << "Please make a selection: " << endl;
    cout << "1: Print books \n"
         << "2: Print authors \n"
         << "3: Print matches \n"
         << "4: Terminate " << endl;
    cin >> input;
    //lets the user ask for what they want to see

    if (input != 1 && input != 2 && input != 3 && input != 4)
    {
        cout << "Sorry, that's not a valid input, terminating... " << endl;
        break;
    }
    //if the input is wrong then terminate the program

    if (input == 1)
    {printBook();
        readBook();
        menu();}
    if (input == 2)
        {
        menu();}
        //printAuthor();
    if (input == 3)
        {
        printMatches();
        menu();}
        //printMatches();
    if (input == 4)
    {
        cout << "Program terminating..." << endl;

        break;
    }
    //runs the input
    }
    return 0;
}


void printBook()
{
    cout << setw(0) << right << "Title"
         << setw(20) << right << "Author"
         << setw(15) << right << "Release year"
         << setw(10) << right << "Language"
         << setw(20) << right << "Genre"
         << endl;

}

void readBook()
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
    for (int i = 0; i < 11; i++)
    {
        inFile >> novel[i].name;
        inFile >> novel[i].author;
        inFile >> novel[i].year;
        inFile >> novel[i].language;
        inFile >> novel[i].genre;
        replace(novel[i].name.begin(), novel[i].name.end(), '_',' ');
        replace(novel[i].author.begin(), novel[i].author.end(), '_',' ');
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
        cout << setw(0) << right << novel[i].name
         << setw(20) << right << novel[i].author
         << setw(15) << right << novel[i].year
         << setw(10) << right << novel[i].language
         << setw(20) << right << novel[i].genre
         << endl;
         //prints the information
    }
    inFile.close();
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
    }
    cout << setw(0) << right << "Name"
         << setw(15) << right << "Nationality"
         << setw(25) << right << "Book"
         << endl;
    for(int i=0;i<3;i++)
    {
    cout << setw(0) << right << novel[i].author
         << setw(15) << right << novel[i].language
         << setw(20) << right << novel[i].name
         << endl;
    }
}

/*void printAuthor()
{

}

void*/
