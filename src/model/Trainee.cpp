#include "model/Trainee.h"
#include <string>
#include <sstream>
#include <iomanip>
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace model
    {
        Trainee::Trainee(const std::string &id, const std::string &name) : WorkingPerson(id, name){}
        Trainee::Trainee(std::vector<std::string> & in) : WorkingPerson(in[0], in[1]){
            setAge(std::stoi(in[2]));
            setMonthlyAllowance(std::stof(in[3]));
            setDuration(std::stoi(in[4]));
        }
        Trainee::~Trainee(){}

        float Trainee::getMonthlyPay() const{
            return monthlyAllowance_;
        }

        void Trainee::setMonthlyAllowance(float monthlyAllowance) {
            if(monthlyAllowance != 0){
                monthlyAllowance_ = monthlyAllowance;
            }
        }

        void Trainee::setDuration(int duration){
            if(duration < 0){
                duration = 0;
            }else{
                duration_ = duration;
            }
        }

        int Trainee::getDuration(){
            return duration_;
        }

        const std::string Trainee::toString() const {
            std::stringstream tempStringStream;
            tempStringStream << "ID : ";
            tempStringStream << std::setw(7) << std::left << getId();
            tempStringStream << " Name : ";
            tempStringStream << std::setw(30) << std::left << getName();
            tempStringStream << " Age : ";
            tempStringStream << std::setw(3) << std::left << getAge();
            tempStringStream << " MonthlyAllowance : Rs. ";
            tempStringStream << std::setw(15) << std::right << getMonthlyPay();
            tempStringStream << " Duration : ";
            tempStringStream << std::setw(3) << std::right << duration_ << " Months";
            return tempStringStream.str();
        }

    } /* model */
} /* eatms */
