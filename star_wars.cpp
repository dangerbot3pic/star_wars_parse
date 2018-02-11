#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>

#include "person.hpp"

using namespace std;

void update(const std::string condition, const std::string person_action, const long stamp, const long time, Person &a);

int main(int args, char **arg)
{
    if (args != 2)
    {
        cout<<"Incorrect number of arguments"<<endl;
        exit(-1);
    }

    ifstream infile;
    string filename = arg[1];

    long monitor_time = 0;
    long node_time = 0;
    string person, person_2, action;
    const string state1 = "ALIVE";
    string state2 = state1;

    vector<Person>node;
    vector<Person>::iterator it;

    try 
    {
        infile.open(filename.c_str());
        if (!infile.is_open()) exit(-1);

        while (!infile.eof())
        {
            infile >> monitor_time;
            infile >> node_time;
            infile >> person;
            infile >> action;

            if (action == "HELLO")
            {
                for (it = node.begin(); it != node.end(); it++) if (it->name == person) break;

                
                if (it == node.end()) node.push_back(Person(person, state1, person+" "+state1, monitor_time, node_time));
                else update(state1, person+" "+action, monitor_time, node_time, *it);
            }

            else
            {
                infile >> person_2;
                state2 = state1;
                if (action == "LOST") state2 = "DEAD";

                for (it = node.begin(); it != node.end(); it++) if (it->name == person) break;
                
                if (it == node.end()) node.push_back(Person(person, state1, person+" "+action+" "+person_2, monitor_time, node_time));
                else update(state1, person+" "+action+" "+person_2, monitor_time, node_time, *it);


                for (it = node.begin(); it != node.end(); it++) if (it->name == person_2) break;

                if (it == node.end()) node.push_back(Person(person_2, state2, person+" "+action+" "+person_2, monitor_time, node_time));
                else update(state2, person+" "+action+" "+person_2, monitor_time, node_time, *it);
            }
        }
        infile.close();
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
        cout<<node[i].name<<" "<<node[i].person_state<<" "<<node[i].timestamp<<" "<<node[i].action<<endl;
    }
}


void update(const std::string condition, const std::string person_action, const long stamp, const long time, Person &a)
{
    if (time < a.node_time) return;
    else 
    {
        a.person_state = condition; 
        a.action = person_action;
        a.timestamp = stamp;
        a.node_time = time;
    }
}