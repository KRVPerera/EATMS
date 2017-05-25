#include "model/SalariedEmployee.h"
#include <string>
#include <vector>
#include "model/WorkingPerson.h"


namespace eatms {

    namespace model {

        SalariedEmployee::SalariedEmployee(const std::string & id,
                const std::
                string & name):WorkingPerson(id, name) {
        }

        SalariedEmployee::SalariedEmployee(std::vector < std::string >
                &in):WorkingPerson(in[0], in[1]) {
            monthlySalary_ = std::stof(in[3]);
            setAge(std::stoi(in[2]));
        }


        SalariedEmployee::~SalariedEmployee() {}

        float SalariedEmployee::getMonthlyPay() const {
            return monthlySalary_;
        }

        void SalariedEmployee::setMonthlySalary(float monthlySalary) {
            monthlySalary_ = monthlySalary;
        }

        /*! \brief Brief function description here
         *
         *  Detailed description
         *
         * \return Return parameter description
         */
        const std::string SalariedEmployee::toString() const {
            std::string tempString("ID\t:");
            tempString += getId();
            tempString += "\nName\t:";
            tempString += getName();
            tempString += "\n";
            return tempString;
        }

    } /* model */ 
}                /* eatms */
