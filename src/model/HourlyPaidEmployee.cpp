#include "model/HourlyPaidEmployee.h"
#include <string>
#include <sstream>
#include <iomanip>
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace model
    {
        HourlyPaidEmployee::HourlyPaidEmployee(const std::string &id, const std::string &name) : WorkingPerson(id, name){}
        HourlyPaidEmployee::HourlyPaidEmployee(std::vector<std::string> & in) : WorkingPerson(in[0], in[1]){
            setAge(std::stoi(in[2]));
            setHourlyRate(std::stof(in[3]));
            setHoursWorked(std::stof(in[4]));
        }
        HourlyPaidEmployee::~HourlyPaidEmployee(){}

        float HourlyPaidEmployee::getMonthlyPay() const{
            return hourlyRate_ * hoursWorked_;
        }

        float HourlyPaidEmployee::getHourlyRate() const{
            return hourlyRate_;
        }

        float HourlyPaidEmployee::getHoursWorked() const{
            return hoursWorked_;
        }

        void HourlyPaidEmployee::setHourlyRate(float hourlyRate){
            hourlyRate_ = hourlyRate;
        }

        void HourlyPaidEmployee::setHoursWorked(float hoursWorked){
            hoursWorked_ = hoursWorked;
        }

        const std::string HourlyPaidEmployee::toString() const {
            std::stringstream tempStringStream;
            tempStringStream << "ID : ";
            tempStringStream << std::setw(7) << std::left << getId();
            tempStringStream << " Name : ";
            tempStringStream << std::setw(30) << std::left << getName();
            tempStringStream << " Age : ";
            tempStringStream << std::setw(3) << std::left << getAge();
            tempStringStream << " MonthlyPay       : Rs. ";
            tempStringStream << std::setw(15) << std::right << getMonthlyPay();
            tempStringStream << " Hours Worked : ";
            tempStringStream << std::setw(7) << std::right << getHoursWorked();
            tempStringStream << " Hourly Rate : Rs. ";
            tempStringStream << std::setw(7) << std::left << getHourlyRate();
            return tempStringStream.str();
        }
    } /* model */ 
} /* eatms */ 



