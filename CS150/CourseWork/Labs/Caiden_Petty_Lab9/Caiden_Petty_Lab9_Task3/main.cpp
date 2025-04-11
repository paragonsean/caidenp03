#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int NO_OF_STUDENTS = 20;

///struct definition
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char Grade;
};

///Functions prototype
void getData(ifstream& inFile, studentType sList[], int listSize);
void calculateGrade(studentType sList[], int listSize);
int highestScore(const studentType sList[], int listSize);
void printResult(ofstream& outFile, const studentType sList[],
                 int listSize);

int main()
{
    ifstream inData; ///input stream variable
    ofstream outData; ///output stream variable

    ///Array of struct
    studentType studentList[NO_OF_STUDENTS];

    ///open the input file
    inData.open("data.txt");

    ///Validate the input file
    if (!inData)
    {
        cout << "The input file does not exist. Program terminate."
             << endl;
             return 1;
    }

    ///open the output file
    outData.open("Output.txt");

    ///validate the output file
    if(!outData)
    {
        cout << "Can't open the output file. Program terminate."
             << endl;
             return 1;
    }

    ///call the function
    getData(inData, studentList, NO_OF_STUDENTS);
    calculateGrade(studentList, NO_OF_STUDENTS);
    printResult(outData, studentList, NO_OF_STUDENTS);

    return 0;
}

///getData function reads the students names and test scores
void getData(ifstream& inFile, studentType sList[], int listSize)
{
    for(int i=0; i < listSize; i++)
        inFile >> sList[i].studentFName >> sList[i].studentLName
               >> sList[i].testScore;
}

///calculateGrade function calculates and stores the letter grades for the students
void calculateGrade(studentType sList[], int listSize)
{
    for (int i=0; i < listSize; i++)
    {
        switch (sList[i].testScore/10)
        {
        case 10:
        case 9:
            sList[i].Grade = 'A';
            break;
        case 8:
            sList[i].Grade = 'B';
            break;
        case 7:
            sList[i].Grade = 'C';
            break;
        case 6:
            sList[i].Grade = 'D';
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            sList[i].Grade = 'F';
        }
    }
}

///highestScore function calculates and returns the highest test score
int highestScore(const studentType sList[], int listSize)
{
   int hScore = sList[0].testScore;

   for (int i =1; i<listSize; i++)
        if (hScore < sList[i].testScore)
        hScore = sList[i].testScore;
   return hScore;
}

///printResult function prints the output to an output file
void printResult(ofstream& outFile, const studentType sList[],
                 int listSize)

{
    int maxScore = highestScore(sList, listSize);
    int i;

    outFile << setw(15) << "Student Name          "
            << setw(10) << "Test Score"
            << setw(7) << "Grade" << endl;

    for (i=0; i < listSize; i++)
        outFile << left << setw(25)
                <<sList[i].studentLName + ", " + sList[i].studentFName
                <<right << " " << setw(5) << sList[i].testScore
                <<setw(6) << " " << sList[i].Grade << endl;

    outFile << endl << "Highest Test Score: " << maxScore << endl;
    outFile << "Students having the highest test score:" << endl;

    for (i=0; i < listSize; i++)
        if (sList[i].testScore == maxScore)
            outFile << sList[i].studentLName + ",  " + sList[i].studentFName
                    << endl;
}

