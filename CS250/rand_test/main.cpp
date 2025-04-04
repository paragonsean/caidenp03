#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    for(int i=16;i<35;i++)
    cout << (rand()%20) << endl;
    return 0;
}
