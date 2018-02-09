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

    Person (std::string new_name, std::string condition, std::string person_action, long time) : name(new_name), person_state(condition), action(person_action), timestamp(time) {}

    std::ostream& operator<<(std::ostream &os, const Person &a);

    bool operator==(const Person &a) const;
};



#endif