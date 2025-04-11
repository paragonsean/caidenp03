#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

///Function prototype
char examGrade(int score);

int main()
{
  int i;
  char ch;
  int score;
  int len;
  int noOfQuestions = 20; ///Number of students
  char ID[9]; ///Array to hold the student's ID
  char *keyString; ///char pointer for answer key
  char *answerString; ///char pointer for the student's answer

  ///Declare input stream variable
  ifstream infile;

  ///open the input file
  infile.open("input.txt");
  if(!infile)
  {
      cout << "Cannot open input file. Program terminates!" << endl;
      return 1;
  }
  ///Use two dynamic arrays
  ///The first dynamic array for the answer key
  ///The second dynamic array for the student answers
  keyString = new char[noOfQuestions + 1];
  answerString = new char[noOfQuestions + 1];

  ///Read the answer key
  cout << "Processing Data" << endl;
  infile.get(keyString, noOfQuestions + 1);

  ///Output the answer key
  cout << "Key: " << keyString << endl << endl;

  cout << left << setw(15) << "Student ID"
       << setw(25) << "Student Answers"
       << setw(10) << "Score"
       << setw(10) << "Grade"<< endl;

       ///Read the data for the first student
       infile >> ID;
       infile.get(ch);
       infile.get(answerString, noOfQuestions +1);

       while (infile)
       {
           len = strlen(answerString);
           for (i = len; i < noOfQuestions; i++)
            answerString[i] = ' ';

           answerString[noOfQuestions] = '\0';

           score = 0;

           ///loop to calculate the score
           for (i = 0; i < noOfQuestions; i++)
           if (answerString[i] != ' ')
            {
                if (answerString[i] == keyString[i])
                {
                    ///Correct answer is awarded two points
                    score = score + 2;
                }
                else
                {
                    ///wrong answer gets one point deducted
                    score = score - 1;
                }
            }

        ///Output the student's answers, score, and grade
        cout << left << setw(15) << ID
             << setw(25) << answerString
             << setw(10) << score
             << setw(10) << examGrade(score) << endl;

         ///Read the data for the next student
         infile >> ID;
         infile.get(ch);
         infile.get(answerString, noOfQuestions + 1);
    }

    cout << endl;

    ///Close the input file
    infile.close();

    ///Delete the arrays
    delete [] keyString;
    delete [] answerString;

    return 0;
}

///Function to calculate and return the grade
char examGrade(int score)
{
    switch (static_cast<int>(score / 40.0 * 10))
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return 'F';
    case 6:
        return 'D';
    case 7:
        return 'C';
    case 8:
        return 'B';
    case 9:
    case 10:
        return 'A';
    default:
        return 'F';
    }
}
