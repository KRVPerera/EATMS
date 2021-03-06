#ifndef EATMS_MODEL_SALARIEDEMPLOYEE_H
#define EATMS_MODEL_SALARIEDEMPLOYEE_H

#include <string>
#include <vector>
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace model
    {
        class SalariedEmployee : public WorkingPerson
        {
            private:
                float monthlySalary_;

            public:
                SalariedEmployee(const std::string &id, const std::string &name);
                SalariedEmployee(std::vector<std::string> & in);
                virtual ~SalariedEmployee();

                float getMonthlyPay() const;
                void  setMonthlySalary(float monthlySalary);
                const std::string toString()         const;
        };

    } /* model */ 
} /* eatms */ 

#endif /* EATMS_MODEL_SALARIEDEMPLOYEE_H */
