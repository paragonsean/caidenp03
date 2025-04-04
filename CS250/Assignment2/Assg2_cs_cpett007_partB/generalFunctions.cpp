#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>  // for string streams
#include <stdlib.h>
#include "generalFunctions.h"
#include "openings.h"
#include "candadites.h"

using namespace std;

int StringToInt(string s)
{
    stringstream temp(s);
    int integer = 0;
    temp >> integer;
    return integer;
}

//this converts integers to strings
string IntToString(int i)
{
    ostringstream str1;
    str1<<i;
    string temp = str1.str();
    return temp;
}

//Find all candidates that match any opening and print them
void FindMatches(string candidates[][6], int cand_size, string openings[][7], int opening_size)
{
    ///FILLED
    getName:
        cout<<"Enter Last Name:";
        string Name;
        cin>>Name;
        if(cin.fail()==true)
        {
            system("CLS");
            cout<<"Invalid Input"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto getName;
        }

    cout<<endl<<endl;
    for(int i=0; i<cand_size; i++)
        if(candidates[i][1]==Name)
        {
            for(int t=0; t<opening_size; t++)
            {
                if(openings[t][1]==candidates[i][2])
                {
                    for (int p = 0; p<7; p++)
                    cout<<setw(15)<<std::left<<openings[t][p];
            cout<<endl;
                }
            }
        }
    cout<<endl<<endl;
}


//Receives input from the user and performs appropriate command
//all operations require constant reading and writing of files
void Menu()
{
    int input;

    ifstream inOpenings;    //this variable will allow input operations for the openings file
    int num_openings;
    ifstream inCandidates;  //this variable will allow input operations for the candidates file
    int num_candidates;

    redo:
    //we need to load every time
    inOpenings.open("openings.txt", ios::in);   //open files
    inOpenings>>num_openings;                   //read # of entries in file
    inCandidates.open("candidates.txt", ios::in);
    inCandidates>>num_candidates;

    string openings[num_openings][7];       //create array to store info currently in file
    string candidates[num_candidates][6];
    LoadOpenings(inOpenings, openings, num_openings);   //this loads the contents to the array, so that we can use it in subsequent operations
    LoadCandidates(inCandidates, candidates, num_candidates);
    inOpenings.close(); //close the files
    inCandidates.close();

    GetSelection:          //This is a label, a destination for a goto statement. Allows us to reenter the menu without writing a while loop

    cout<<"1.   "<<setw(40)<<std::left<<"Add Opening"<<endl;
    cout<<"2.   "<<setw(40)<<std::left<<"Delete Opening"<<endl;
    cout<<"3.   "<<setw(40)<<std::left<<"Show Openings"<<endl;
    cout<<"4.   "<<setw(40)<<std::left<<"Match Candidates to all Openings"<<endl<<endl;

    cout<<"5.   "<<setw(40)<<std::left<<"Add Candidate"<<endl;
    cout<<"6.   "<<setw(40)<<std::left<<"Show Candidates"<<endl;
    cout<<"7.   "<<setw(40)<<std::left<<"Show Candidates by position"<<endl;
    cout<<"8.   "<<setw(40)<<std::left<<"Filter Candidates By Rating"<<endl<<endl;

    cout<<"9.   "<<setw(40)<<std::left<<"Clear Screen"<<endl;
    cout<<"Enter Selection:";
    cin>>input;

    if(cin.fail() == true || input>9)
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"Invalid Input. Please Re-enter Selection"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto GetSelection;
    }
    else if(input == 1)
        AddOpening(openings, num_openings);

    else if(input == 2)
        DeleteOpening(openings, num_openings);

    else if(input == 3)
        PrintOpenings(openings, num_openings);
    else if(input == 4)
        FindMatches(candidates, num_candidates, openings, num_openings);

    else if(input == 5)
        AddCandidate(candidates, num_candidates);

    else if(input == 6)
        PrintCandidates(candidates,  num_candidates);
    else if(input == 7)
        ShowCandidatesByPosition(candidates, num_candidates);
    else if(input == 8)
        FilterCandidatesByRating(candidates, num_candidates);
    else if(input == 9)
    {
        system("CLS");
    }
    else
        goto end;
    goto redo;
    end:
    cout<<endl<<endl;
    cout<<"Termination"<<endl;
}
