#include <iostream>
#include <string>
using namespace std;
int main (int argc, char** argv) {
cout << "Now reading from standard in" <<
endl; string line;
getline (cin, line);
while (cin)
{
cout << "I saw: " << line << endl;
getline (cin, line);
}
return 0;
}
