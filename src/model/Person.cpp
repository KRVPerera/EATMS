#include "model/Person.h"
#include <string>
#include <algorithm>

namespace eatms
{
    namespace model
    {
        Person::Person(const std::string &name){
            setName(name);
            setAge(18);
        }
        Person::~Person(){};

        void Person::setAge(const int &age)
        {
            if(age < 18){
                age_ = 18;
                throw "Invalid Age! Age cannot be less than 18 years";
            }
            age_ = age;
        }

        void Person::setName(const std::string &name)
        {
            if(name.empty()){
                throw "Invalid Name! Name cannot be empty!";
            }
            name_  = std::move(name);
        }

        std::string Person::getName()
        {
            return name_;
        }

        int Person::getAge(){
            return age_;
        }
    } /* model */
} /* eatms */
