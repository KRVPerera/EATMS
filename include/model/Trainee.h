#ifndef EATMS_MODEL_TRAINEE_H
#define EATMS_MODEL_TRAINEE_H

#include <string>
#include <vector>
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace model
    {
        class Trainee : public WorkingPerson
        {
            private:
                int duration_;
                float monthlyAllowance_;

            public:
                Trainee(const std::string &id, const std::string &name);
                Trainee(std::vector<std::string> & in);
                virtual ~Trainee();

                float getMonthlyPay() const;

                void  setDuration(int duration);
                int  getDuration();
                void  setMonthlyAllowance(float monthlyAllowance);
                const std::string toString() const;
        };
    } /* model */ 
} /* eatms */ 

#endif /* EATMS_MODEL_TRAINEE_H */
