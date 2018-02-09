#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "person.hpp"

using namespace std;


int main(int args, char **arg)
{
    if (args != 1)
    {
        cout<<"Incorrect number of arguments"<<endl;
        exit(-1);
    }

    ifstream infile;
    string filename = arg[0];

    long monitor_time = 0;
    long node_time = 0;
    string person, person_2, action;

    vector<Person*>node;
    vector<Person*>::iterator it;

    try 
    {
        infile.open(filename.c_str());

        while (!infile.eof())
        {
            infile >> monitor_time;
            infile >> node_time;
            infile >> person;
            infile >> action;

            if (action == "HELLO")
            {
                it = find(node.begin(), node.end(), person);

                if (it == node.end()) node.push_back(new Person(person, "ALIVE", person+"HELLO", monitor_time));
                else (*it) -> person_state = "ALIVE";
            }

            else if (action == "LOST")
            {
                it = find(node.begin(), node.end(), person);

                if (it == node.end()) node.push_back(new Person(person, "ALIVE", "HELLO", monitor_time));
                else 
                {
                    (*it) -> person_state = "ALIVE"; 
                    (*it) -> action = person + action + person_2;
                    (*it) -> timestamp = monitor_time;
                }

                infile >> person_2;

                it = find(node.begin(), node.end(), person_2);

                if (it == node.end()) node.push_back(new Person(person, "DEAD", person+action+person_2, monitor_time));
                else 
                {
                    (*it) -> person_state = "DEAD"; 
                    (*it) -> action = person + action + person_2;
                    (*it) -> timestamp = monitor_time;
                }
            }

            else if (action == "FOUND")
            {
                it = find(node.begin(), node.end(), person);

                if (it == node.end()) node.push_back(new Person(person, "ALIVE", "HELLO", monitor_time));
                               else 
                {
                    (*it) -> person_state = "ALIVE"; 
                    (*it) -> action = person + action + person_2;
                    (*it) -> timestamp = monitor_time;
                }

                infile >> person_2;

                it = find(node.begin(), node.end(), person_2);

                if (it == node.end()) node.push_back(new Person(person, "ALIVE", person+action+person_2, monitor_time));
                else 
                {
                    (*it) -> person_state = "ALIVE"; 
                    (*it) -> action = person + action + person_2;
                    (*it) -> timestamp = monitor_time;
                }
            }
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

    for (int i = 0; i < node.size(); i++)
    {
        cout<<node[i];
    }
}