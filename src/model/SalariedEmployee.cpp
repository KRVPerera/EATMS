#include "model/SalariedEmployee.h"
#include <string>
#include "model/WorkingPerson.h"


namespace eatms
{
    namespace model
    {
        SalariedEmployee::SalariedEmployee(const std::string &id, const std::string &name): WorkingPerson(id, name){}
        SalariedEmployee::~SalariedEmployee(){}

        float SalariedEmployee::getMonthlySalary() const{
            return monthlySalary_;
        }

        void SalariedEmployee::setMonthlySalary(float monthlySalary){
            monthlySalary_ = monthlySalary;
        }

        /*! \brief Brief function description here
         *
         *  Detailed description
         *
         * \return Return parameter description
         */
        const std::string SalariedEmployee::toString() const{
             return "Hello I have a salary";
        }

    } /* model */ 
} /* eatms */ 
