#include <iostream>

using namespace std;

int main()

{
int i;
int value = 3;

while (i < 5){
    value = value * (i + 1) + i;
    i++;
}
cout << "value = " << value << endl;

return 0;
}
