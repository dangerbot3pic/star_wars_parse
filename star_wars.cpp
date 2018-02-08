#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

enum State
{
    ALIVE = 1,
    UNKNOWN = 2,
    DEAD = 3
};

enum Action
{
    HELLO = 0,
    LOST = 1,
    FOUND = 2
};

union Type 
{
    string *Name;
    State person_state;
    Action person_action;
};

struct Person 
{
    string name;
    State person_state;
};


int main(int arg, char **args)
{
    if (arg != 0)
    {
        cout<<"Incorrect number of arguments"<<endl;
        exit(-1);
    }

    ifstream infile;
    string filename = args[0];

    long monitor_time = 0;
    long node_time = 0;
    string person;

    vector<Person>node;
    Type tmp;

    try 
    {
        infile.open(filename.c_str());

        while (!infile.eof())
        {
            infile >> monitor_time;
            infile >> node_time;
        }
    }

    catch (std::ifstream::failure &e)
    {
        cout<<"Error in opening/reading file"<<e.what()<<endl;
        exit(-1);
    }

    catch (exception const &e)
    {
        cout<<"ERROR: "<<e.what()<<endl;
        exit(-1);
    }
}