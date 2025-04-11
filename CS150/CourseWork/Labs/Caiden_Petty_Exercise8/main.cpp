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
   sportsType soccer;
   cout << "Enter the name of the sport: " << endl;
   cin >> soccer.sportName;
   cout << "Enter the name of the team: " << endl;
   cin >> soccer.teamName;
   cout << "Enter the number of players: " << endl;
   cin >> soccer.numberOfPlayers;
   cout << "Enter the team payroll: " << endl;
   cin >> soccer.teamPayroll;
   cout << "Enter the coach salary: " << endl;
   cin >> soccer.coachSalary;

   cout << "------------------------" << endl;

   cout << "Name of the sport: " << soccer.sportName << endl;
   cout << "Name of the team: " << soccer.teamName << endl;
   cout << "Number of the players: " << soccer.numberOfPlayers << endl;
   cout << "Team payroll: " << soccer.teamPayroll << endl;
   cout << "Coach's salary: " << soccer.coachSalary << endl;

    return 0;
}
