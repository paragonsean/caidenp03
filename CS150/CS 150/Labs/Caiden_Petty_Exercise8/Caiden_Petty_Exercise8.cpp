#include <iostream>
#include <string>
using namespace std;
struct sportsType
{
 string sportName;
 string teamName;
 int numberOfPlayers;
 double teamPayroll;
 double coachSalary;
};

int main()
{
   sportsType soccer; ///struct name
   cout << "Enter the name of the sport: " << endl;///ask for the user to input the information to the struct
   cin >> soccer.sportName;///read and assign the information the user input to the correct struct spot
   cout << "Enter the name of the team: " << endl;
   cin >> soccer.teamName;
   cout << "Enter the number of players: " << endl;
   cin >> soccer.numberOfPlayers;
   cout << "Enter the team payroll: " << endl;
   cin >> soccer.teamPayroll;
   cout << "Enter the coach salary: " << endl;
   cin >> soccer.coachSalary;

   cout << "------------------------" << endl;

   cout << "Name of the sport: " << soccer.sportName << endl;///read back the the user the information to make sure all of the inputs were correct
   cout << "Name of the team: " << soccer.teamName << endl;
   cout << "Number of the players: " << soccer.numberOfPlayers << endl;
   cout << "Team payroll: " << soccer.teamPayroll << endl;
   cout << "Coach's salary: " << soccer.coachSalary << endl;

    return 0;
}
