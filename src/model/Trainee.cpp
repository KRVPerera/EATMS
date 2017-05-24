#include "model/Trainee.h"
#include <string>
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
            monthlyAllowance_ = monthlyAllowance;
        }

        void Trainee::setDuration(int duration){
            duration_ = duration;
        }

        int Trainee::getDuration(){
            return duration_;
        }

        const std::string Trainee::toString() const {
            //TODO :: implement
            return "Return string of Trainee";
        }

    } /* model */
} /* eatms */
