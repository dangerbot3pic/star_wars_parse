#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

class Person 
{
    public:
    std::string name;
    std::string person_state;
    std::string action;
    long timestamp;
    long node_time;

    Person (std::string new_name, std::string condition, std::string person_action, long time, long n_time) 
        : name(new_name), person_state(condition), action(person_action), timestamp(time), node_time(n_time) {}

    friend void update(const std::string condition, const std::string person_action, const long stamp, const long time, Person &a);
};



#endif