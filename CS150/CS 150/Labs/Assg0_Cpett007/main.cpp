#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void getVec(int v1[], int v2[], int v_size);//creating the void functions and the double function to simplify the program
void vectorId(int v1[], int v2[], int ceiling, int v_size);
double vecAvg(double run_sum, double v_size);
void printVec(int v1[], int v2[]);

getVec()

int main()
{
    int v_size = 0; //variable for the size of the arrays, its the same for both so that we can do addition and subtraction
    int v_id = 0;   //use it to determine which vector to operate on, used for average computation
    int ceiling = 0;    //when generating random numbers to place in vector, this constraints the maximum number attainable by the random number generator
    int action = 0; //determine which course of action the program will take
    double avg = 0.0;

    GetSize:
    cout<<"Enter size for vectors: ";
    cin>>v_size;

    if(cin.fail() == true)
    {
        system("CLS");
        cout<<"Invalid Input. Please Re-enter vector size: ";
        cin.clear();
        cin.ignore(10000, '\n');
        goto GetSize;
    }

    GetCeiling:
    cout<<"Enter Maximum Random Number for Vector: ";
    cin>>ceiling;

    if(cin.fail() == true)
    {
        system("CLS");
        cout<<"Invalid Input. Please Re-enter Maximum Random Number: ";
        cin.clear();
        cin.ignore(10000, '\n');
        goto GetCeiling;
    }

    int v1[v_size];
    int v2[v_size];

    int result[v_size];
    int run_sum =0;
    //randomly initialize the vectors
    srand (time(NULL));  //seed
    for(int i=0; i<v_size; i++)
    {
        v1[i]=rand() % ceiling;
        v2[i]=rand() % ceiling;
        cout<<setw(5)<<v1[i]<<setw(5)<<v2[i]<<endl;
    }

    GetAction:
    cout<<"Enter Action: vector addition(0), vector subtraction(1), average(2), edit(3), print vectors(4), clear screen(5), exit(-1): ";
    cin>>action;
    //system("CLS");
    if(cin.fail() == true || action<-1 || action>5)
    {
        system("CLS");
        cout<<"Invalid Input. Please Re-enter Desired Action: ";
        cin.clear();
        cin.ignore(10000, '\n');
        goto GetAction;
    }

    if(action == -1)
        goto end;

    if(action == 0)
    {
         for(int i=0; i<v_size; i++)
         {
             result[i]=v1[i]+v2[i];
             cout<<result[i]<<endl;
         }
    }

    else if(action == 1)
         for(int i=0; i<v_size; i++)
         {
             result[i]=v1[i]-v2[i];
             cout<<result[i]<<endl;
         }

    else if(action == 2)
    {
        getVector:
        cout<<"Average of Vector 1, or Vector 2 (Enter 1 or 2)? "<<endl;
        cin>>v_id;
        if(cin.fail() == true || (v_id!=1 && v_id!=2))
        {
        system("CLS");
        cout<<"Invalid Input. Please Re-enter Vector Selection(1 or 2): ";
        cin.clear();
        cin.ignore(10000, '\n');
        goto getVector;
        }
        if(v_id == 1 )
            for(int i=0; i<v_size; i++)
                run_sum += v1[i];

        else if(v_id == 2)
            for(int i=0; i<v_size; i++)
                run_sum += v2[i];

    avg = (double)run_sum/(double)v_size;
    cout<<"Average: "<<avg<<endl;
    run_sum = 0; //reset
    }

    else if(action == 3)
    {
        int index;
        GetVector:
        cout<<"Which Vector would you like to edit? (Enter 1 or 2): ";
        cin>>v_id;
        if(cin.fail() == true || (v_id!=1 && v_id!=2))
        {
        system("CLS");
        cout<<"Invalid Input. Please Re-enter Vector Selection(1 or 2): ";
        cin.clear();
        cin.ignore(10000, '\n');
        goto GetVector;
        }
        GetIndex:
        cout<<"Select Index to be Updated: "<<endl;
        cin>>index;
        if(cin.fail() == true || index<0 || index>(v_size-1))
        {
        system("CLS");
        cout<<"Invalid Input. Please Re-enter index to be updated: ";
        cin.clear();
        cin.ignore(10000, '\n');
        goto GetIndex;
        }
        cout<<"Enter updated value: ";
        if(v_id == 1)
        {
            cin>>v1[index];
            for(int i=0; i< v_size; i++)
                cout<<v1[i]<<endl;

        }

        else if(v_id == 2)
        {
             cin>>v2[index];
             for(int i=0; i< v_size; i++)
                cout<<v2[i]<<endl;
        }
    }
    if(action == 4)
         for(int i=0; i<v_size; i++)
             cout<<setw(5)<<v1[i]<<setw(5)<<v2[i]<<endl;


    if(action == 5)
        system("CLS");

    goto GetAction;
    end:
    return 0;
}
