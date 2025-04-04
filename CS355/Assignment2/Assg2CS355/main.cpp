#include <iostream>

using namespace std;

struct student
{
    char name[50];
    int age;
    float gpa;
    string grade;
};

int main() {
    student s1[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "student " << i << ":" << endl;
        cout << "enter student name: \n" << endl;
        cin >> s1[i].name;
        cout << "\n enter student age: \n" << endl;
        cin >> s1[i].age;
        cout << "\n enter student gpa: \n" << endl;
        cin >> s1[i].gpa;
        cout << "\n enter student grade (freshman, etc.) \n" << endl;
        cin >> s1[i].grade;
    }
    for (int j = 0; j<5; j++)
    {
        cout << "student " << j << "information: " << endl;
        cout << "name: " << s1[j].name;
        cout << "\n age: " << s1[j].age;
        cout << "\n gpa: " << s1[j].gpa;
        cout << "\n grade: " << s1[j].grade << endl;

        }
    return 0;
}
