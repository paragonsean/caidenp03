#include <iostream>

using namespace std;

int main()
{
int seconds, hours, minutes;

cout << "Enter the number of seconds you'd like converted: " << endl;
cin >> seconds;

minutes = seconds / 60;
hours = minutes / 60;

cout << seconds << " seconds is equivalent to " << int(hours) << " hours " << int(minutes%60)
     << " minutes " << int(seconds%60) << " seconds.";

return 0;
}
