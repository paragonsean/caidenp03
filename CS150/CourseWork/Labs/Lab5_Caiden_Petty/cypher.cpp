#include "cypher.h"
#include <string>

using namespace std;

string cipher(string Input)
{
    string output = "";
    for(int i = 0; i < Input.size(); i++)
    {
        translateLetterKeyBoard(Input[i]);
        translateLetterKeyBoard(Input[i]);
        output += translateLetterMorseCode(Input[i]);
    }
    return output;
}
