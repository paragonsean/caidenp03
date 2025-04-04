#include <iostream>
#include <string>
#include <fstream>
//#include "cipher.h"

using namespace std;

//function declarations
string cipher(string Input);
void upperCase(string &Input);
void translateLetterKeyBoard(char &letter);
string translateLetterMorseCode(char letter);

void printOutput(string original, string encoded);
string readInput(fstream& inFile);

int main()
{

    cout << "Combination Cipher\n";

    //Read the Input String from a File
    fstream inFile;
    inFile.open("input.txt");
    string userInput = readInput(inFile);

    //Create another string to hold the encoded message
    string translatedMessage =userInput;



    //Send the string through the cipher
    translatedMessage = cipher(translatedMessage);//MorseCode(KeyboardCipher(userInput));

    //print the output
    printOutput(userInput, translatedMessage);

    return 0;
}

void printOutput(string original, string encoded){
    cout << endl << "You Gave me the Message: " << endl << original << endl << endl << "Your Message Encoded is: " << endl << encoded << endl;
}

string readInput(fstream & inFile){
    string userInput ="";
    getline(inFile, userInput);
    return userInput;
}




void upperCase(string &Input){
    //Make the string all upper case
    for(int i = 0; i < Input.size(); i++)
        Input[i] = toupper(Input[i]);

}

string cipher(string Input){
    string output = "";
    upperCase(Input);
    for(int i = 0; i < Input.size(); i++){
        translateLetterKeyBoard(Input[i]);
        translateLetterKeyBoard(Input[i]);
        output += translateLetterMorseCode(Input[i]);
    }
    return output;
}

void translateLetterKeyBoard(char &letter){
    switch (letter){
        case 'A':
             letter = 'Q';
             break;
        case 'B':
             letter = 'W';
             break;
        case 'C':
             letter = 'E';
             break;
        case 'D':
             letter = 'R';
             break;
        case 'E':
             letter = 'T';
             break;
        case 'F':
             letter = 'Y';
             break;
        case 'G':
             letter = 'U';
             break;
        case 'H':
             letter = 'I';
             break;
        case 'I':
             letter = 'O';
             break;
        case 'J':
             letter = 'P';
             break;
        case 'K':
             letter = 'A';
             break;
        case 'L':
             letter = 'S';
             break;
        case 'M':
             letter = 'D';
             break;
        case 'N':
             letter = 'F';
             break;
        case 'O':
             letter = 'G';
             break;
        case 'P':
             letter = 'H';
             break;
        case 'Q':
             letter = 'J';
             break;
        case 'R':
             letter = 'K';
             break;
        case 'S':
             letter = 'L';
             break;
        case 'T':
             letter = 'Z';
             break;
        case 'U':
             letter = 'X';
             break;
        case 'V':
             letter = 'C';
             break;
        case 'W':
             letter = 'V';
             break;
        case 'X':
             letter = 'B';
             break;
        case 'Y':
             letter = 'N';
             break;
        case 'Z':
             letter = 'M';
             break;
        default :
            break;
    }
}

string translateLetterMorseCode(char letter){
    string output = "";
    switch(letter){
            case 'A':
                output =  ".- ";
                break;
            case 'B':
                output =  "-... ";
                break;
            case 'C':
                output =  "-.-. ";
                break;
            case 'D':
                output =  "-.. ";
                break;
            case 'E':
                output =  ". ";
                break;
            case 'F':
                output =  "..-. ";
                break;
            case 'G':
                output =  "--. ";
                break;
            case 'H':
                output =  ".... ";
                break;
            case 'I':
                output =  ".. ";
                break;
            case 'J':
                output =  ".--- ";
                break;
            case 'K':
                output =  "-.- ";
                break;
            case 'L':
                output =  ".-.. ";
                break;
            case 'M':
                output =  "-- ";
                break;
            case 'N':
                output =  "-. ";
                break;
            case 'O':
                output =  "--- ";
                break;
            case 'P':
                output =  ".--. ";
                break;
            case 'Q':
                output =  "--.- ";
                break;
            case 'R':
                output =  ".-. ";
                break;
            case 'S':
                output =  "... ";
                break;
            case 'T':
                output =  "- ";
                break;
            case 'U':
                output =  "..- ";
                break;
            case 'V':
                output =  "...- ";
                break;
            case 'W':
                output =  ".-- ";
                break;
            case 'X':
                output =  ".-- ";
                break;
            case 'Y':
                output =  "-.-- ";
                break;
            case 'Z':
                output =  "--.. ";
                break;
            case ' ':
                output =  " ";
                break;
            case '1':
                output =  ".---- ";
                break;
            case '2':
                output =  "..--- ";
                break;
            case '3':
                output =  "...-- ";
                break;
            case '4':
                output =  "....- ";
                break;
            case '5':
                output =  "..... ";
                break;
            case '6':
                output =  "-.... ";
                break;
            case '7':
                output =  "--... ";
                break;
            case '8':
                output =  "---.. ";
                break;
            case '9':
                output =  "----. ";
                break;
            case '0':
                output =  "----- ";
                break;
            default:
                output = letter;
        }
    return output;

}
