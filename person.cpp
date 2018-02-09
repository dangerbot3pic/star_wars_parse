#include <string>

#include "person.hpp"


bool Person::operator==(const Person &a) const
{
    if (this->name == a.name) return true;
    
    return false;
}


std::ostream& operator<<(std::ostream &os, const Person &a)
{
    os<<a.name<<" "<<a.person_state<<" "<<a.timestamp<<" "<<" "<<a.name<<" "<<a.action<<std::endl;
    return os;
}