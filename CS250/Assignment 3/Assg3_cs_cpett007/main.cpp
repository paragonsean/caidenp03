#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

struct Animal
{
    int x;
    int y;
    int age;
    int health;
    int id;
    string gender;
};

struct Environment
{
    string climate;
    int num_foxes;
    int grid_size_x;
    int grid_size_y;
    Animal *foxes;
};

int GetRandomBetween(int floor, int ceiling);
Animal CreateAnimal(int min_age, int max_age, int id, int gridx, int gridy, string climate);
string GetGender();
void GeneratePopulations(Environment& env);
Environment GenerateEnvironment();
int  GetHealth(string climate, int age, int grid_x, int grid_y, int x, int y);
void PrintAnimals(Animal *animals, int size);

int main()
{
    srand (time(NULL));

    Environment env = GenerateEnvironment();
    GeneratePopulations(env);
    return 0;
}

int GetRandomBetween(int floor, int ceiling)
{
    return floor + (rand() % static_cast<int>(ceiling - floor + 1));
}


Animal CreateAnimal(int max_age, int id, int gridx, int gridy, string climate)
{
    Animal animal;
    animal.age = GetRandomBetween(1, max_age);
    animal.x = GetRandomBetween(0, gridx);
    animal.y = GetRandomBetween(0, gridy);
    animal.health = GetHealth(climate, animal.age, gridx, gridy,  animal.x, animal.y);
    animal.id = id;
    animal.gender = GetGender();
    return animal;
}

string GetGender()
{
    int g = GetRandomBetween(0,10);
    if(g>5)
        return "f";
    else
        return "m";
}

void GeneratePopulations(Environment& env)
{
    int max_age;

    pop_size:
    cout<<setw(30)<<left<<"Enter Fox Population Size:";
    cin>>env.num_foxes;
    if(cin.fail()==true || env.num_foxes<0)
    {
        cout<<"Error Enter Value Again"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto pop_size;
    }
    env.foxes = new Animal[env.num_foxes];
    redo_age:
    cout<<setw(30)<<left<<"Enter Max Age:";
    cin>>max_age;
    if(cin.fail()==true || max_age<1)
    {
        cout<<"Error Enter Value Again"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto redo_age;
    }
    //create Foxes
    cout<<setw(20)<<right<<"FOXES"<<endl<<endl;
    //cout<<setw(10)<<"Leader:"<<name<<endl;

    //cout<<setw(10)<<0<<setw(10)<<age<<setw(10)<<gender<<setw(10)<<x<<setw(10)<<y<<setw(10)<<GetHealth(climate, age, grid_size_x, grid_size_y, x, y)<<endl;
    for(int i=0; i<env.num_foxes; i++)
        env.foxes[i]=CreateAnimal(max_age, i, env.grid_size_x, env.grid_size_y, env.climate);
    PrintAnimals(env.foxes, env.num_foxes);
}


Environment GenerateEnvironment()
{
    Environment env;
    cl:
    cout<<setw(30)<<left<<"Select Climate Norm(temperate, tundra, tropical):";
    cin>>env.climate;
    if(env.climate == " " || (env.climate !="temperate"    && env.climate !="TEMPERATE"
                                && env.climate !="Temperate"
                                && env.climate !="Tundra"
                                && env.climate !="tundra"
                                && env.climate !="TUNDRA"
                                && env.climate != "TROPICAL"
                                && env.climate != "tropical"
                                && env.climate !="Tropical"
                                )){

        cout<<"Please select from among specified options"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto cl;
    }

    gr_x:
    cout<<setw(30)<<left<<"Enter Grid x-dimension:";
    cin>>env.grid_size_x;
    if(env.grid_size_x<1)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        goto gr_x;
    }

    gr_y:
    cout<<setw(30)<<left<<"Enter Grid y-dimension:";
    cin>>env.grid_size_y;
    if(env.grid_size_y<1)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        goto gr_y;
    }

    return env;
}

//health ranges from 0 to 10
int GetHealth(string climate, int age, int grid_x, int grid_y, int x, int y)
{
     if(age<=3)  //young ones will always have good health
        return GetRandomBetween(7,10);

    if(climate == "tundra" || climate == "TUNDRA")
    {
            if(y/grid_y >=.8)    //for tundra the extremes are in the far north so that's where lowest health will be
                return GetRandomBetween(1,4);
            else                //rest is average health
                return GetRandomBetween(4, 7);


    }
    else  if(climate == "temperate" || climate == "TEMPERATE")
    {
        //extremes are non-existent but older generations are not resilient and will always have good health
        if(age>5)
            return  GetRandomBetween(1,4);
        else
            GetRandomBetween(4,7);
    }

    else if(climate == "tropical" || climate == "TROPICAL")
    {
        if(y/grid_y <=.2)    //extremes are in the south
                return GetRandomBetween(1,4);
            else                //rest is average health
                return GetRandomBetween(4, 7);
    }
}


void PrintAnimals(Animal *animals, int size)
{
    cout<<setw(10)<<"ID"<<setw(10)<<"Age"<<setw(10)<<"Gender"<<setw(10)<<"X"<<setw(10)<<"Y"<<setw(10)<< "Health"<<endl<<endl;
    for(int i=0; i<size; i++)
        cout<<setw(10)<<animals[i].id<<setw(10)<<animals[i].age<<setw(10)<<animals[i].gender<<setw(10)<<animals[i].x<<setw(10)<<animals[i].y<<setw(10)<<animals[i].health<<endl;
}
