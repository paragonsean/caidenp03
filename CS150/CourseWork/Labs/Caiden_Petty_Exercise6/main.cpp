#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void trackVar(double& x, double y, double& z); ///Added double& z to the void

int main()
{
    double one, two;
    double z; /// Moved double z variable into the int main

    cout << fixed << showpoint << setprecision(2);
    cout << "Enter two numbers: ";
    cin >> one >> two;
    cout << endl;

    trackVar(one, two, z);
    ///took cout << "z = " << z << ", "; and combined it with this cout statement
    cout << "z = " << z << ", one = " << one << ", two = " << two << endl;


    trackVar(two, one, z);
    ///took cout << "z = " << z << ", "; and combined it with this cout statement
    cout << "z = " << z << ", one = " << one << ", two = " << two << endl;



   ///Removed return because void does not use return
}

void trackVar(double& x, double y, double& z) ///Added double& z to the void
{

    z = floor(x) + ceil(y);
    x = x + z;
    y = y - z;

}
