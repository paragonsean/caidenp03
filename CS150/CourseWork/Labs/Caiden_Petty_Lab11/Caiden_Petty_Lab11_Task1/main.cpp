#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int sumVotes(int list[], int size);
int winnerIndex(int list[], int size);

int main()
{
    ///Declaring
    int numberOfCandidates;
    string *candidates;
    int *votes;
    int totalVotes;
    int i;


    /// prompt the user to enter the candidate's name and votes
    cout << "Enter the number of candidates: " << endl;
    cin >> numberOfCandidates;

    /// two dynamic arrays
    candidates = new string[numberOfCandidates];
    votes = new int[numberOfCandidates];

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "Enter the candidate's name and and the votes: " << endl;

    ///use a loop to read the user's input
    ///store he name in a dynamic array
    ///store the votes in a dynamic array
    for(i = 0; i < numberOfCandidates; i++)
        cin >> candidates[i] >> votes[i];

    ///call the function totalVotes() to calculate the total votes
    totalVotes = sumVotes(votes, numberOfCandidates);

    ///use a loop to print the output
    cout << "Candidate    Votes received    % of total votes" << endl;
    for(i = 0; i < numberOfCandidates; i++)
        cout << left << setw(10) << candidates[i]
             << right << " " << setw(10) << votes[i] << "  " << setw(15)
             << (static_cast<double>(votes[i]) / static_cast<double>(totalVotes)) *100 << endl;

    cout << "Total             " << totalVotes << endl;

    cout << "The winner of the election is:      " << candidates[winnerIndex(votes, numberOfCandidates)] << endl;


    /// delete the arrays
    delete [] candidates;
    delete [] votes;

    return 0;
}

int sumVotes(int list[], int size)
{
    int sum = 0;
    ///use a loop and add all the components
    for (int i =0; i < size; i++)
        sum = sum + list[i];
        ///return sum
        return sum;
}
 int winnerIndex(int list[], int size)
 {
     int winInd = 0;
     for ( int i =0; i < size; i++)
     if (list[i] > list[winInd])
        winInd = i;

     return winInd;
 }
