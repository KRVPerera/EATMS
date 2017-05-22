#include "model/WorkingPerson.h"
#include <string>

namespace eatms
{
    namespace model
    {
        WorkingPerson::WorkingPerson(const std::string &id, const std::string &name) : Person(name){
            updateId(id);
        }
        WorkingPerson::~WorkingPerson(){};

        int WorkingPerson::getIdNum() const{
            return idNum_;
        }

        const std::string WorkingPerson::getPrefix() const{
            return idPrefix_;
        }

        const std::string WorkingPerson::getId() const{
            auto tempString = idPrefix_;
            return tempString + std::to_string(idNum_);
        }

        void WorkingPerson::updateId(const std::string &idString){
            idPrefix_ = idString.substr (0,2);
            idNum_ = std::stoi(idString.substr(2));
        }
    } /* model */ 
} /* eatms */
