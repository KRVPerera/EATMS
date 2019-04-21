#include "model/SalariedEmployee.h"
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
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
            std::stringstream tempStringStream;
            tempStringStream << "ID : ";
            tempStringStream << std::setw(7) << std::left << getId();
            tempStringStream << " Name : ";
            tempStringStream << std::setw(30) << std::left << getName();
            tempStringStream << " Age : ";
            tempStringStream << std::setw(3) << std::left << getAge();
            tempStringStream << " MonthlyPay       : Rs. ";
            tempStringStream << std::setw(15) << std::right << getMonthlyPay();
            return tempStringStream.str();
        }

    } /* model */ 
}                /* eatms */
