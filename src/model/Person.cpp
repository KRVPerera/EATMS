#include "model/Person.h"
#include <string>
#include <algorithm>

namespace eatms
{
    namespace model
    {
        Person::Person(const std::string &name) : name_(std::move(name)){}

        Person::~Person(){};

        void Person::setAge(const int &age)
        {
            age_ = age;
        }

        void Person::setName(const std::string &name)
        {
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
