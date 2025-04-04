#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    struct game;
    {
        string playerpiece();
        int decision1();
        int selection1();
        int selection2();
        int selection12();
        int selection11();
        int selection10();
        int selection9();
        int selection8();
        int selection7();
        int selection6();
        int selection5();
        int selection4();
        int selection3();
    };
        game play();
    cout << "Hello player! this is a text based story game where your decisions will determine the ending of your game: " << endl;
    cout << setw(15) << right << "****************" << endl;
    cout << "the first option will be to pick your character; note that each character will have a story unique attribute." << endl
         << "here are the options: 1: __ 2: __ 3: __ " << endl;
    cin >> play.playerpiece();
    return 0;
}
