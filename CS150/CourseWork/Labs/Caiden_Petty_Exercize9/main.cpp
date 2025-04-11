#include <iostream>
#include <iomanip>
using namespace std;

class sportsType ///change the struct to a class
{
    public:/// make the first four variables a public
        string sportName;
        string teamName;
        int numberOfPlayers;
        double teamPayroll;
/// make functions to get and print the coach salary because the coach's salary is private
        void setcoachSalary()
        {
            cout << "Enter the coach salary $";
            cin >> coachSalary;
        }

        void printcoachSalary()
        {
            cout << "Coach salary: $";
            cout << coachSalary << endl;
        }

    private:///make coach salary private
        double coachSalary;
};


int main()
{
    sportsType soccer;

    cout << "Enter the name of the sport: ";
    cin >> soccer.sportName;

    cout << "Enter the name of the team: ";
    cin >>soccer.teamName;

    cout << "Enter the number of the players: ";
    cin >> soccer.numberOfPlayers;

    cout << "Enter the team Payroll: ";
    cin >> soccer.teamPayroll;
/// remove the coach salary
///call the void function that asks the user for the coach's salary
    soccer.setcoachSalary();

    ///cout << setprecision(0);
    cout<< "-----------------------------------------"<< endl;
    cout << "The Team:"<< endl
        << "Name of the sport: " << soccer.sportName << endl
        << "Name of the team: " << soccer.teamName << endl
        << "Number of the players: " << soccer.numberOfPlayers << endl
        << "Team Payroll:" << soccer.teamPayroll << endl
        << endl <<endl;
///remove the coach salary portion from above and add the printcoachsalary function here
    soccer.printcoachSalary();


    return 0;
}



