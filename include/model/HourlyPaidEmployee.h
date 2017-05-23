#ifndef EATMS_MODEL_HOURLYPAIDEMPLOYEE_H
#define EATMS_MODEL_HOURLYPAIDEMPLOYEE_H

#include <string>
#include <vector>
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace model
    {
        class HourlyPaidEmployee : public WorkingPerson
        {
            private:
                float hourlyRate_;
                float hoursWorked_;
            public:
                HourlyPaidEmployee(const std::string &id, const std::string &name);
                HourlyPaidEmployee(std::vector<std::string> & in);
                virtual ~HourlyPaidEmployee();

                float getHourlyRate()      const;
                float getHoursWorked()     const;
                void  setHourlyRate(float  hourlyRate);
                void  setHoursWorked(float hoursWorked);

                float getMonthlyPay() const;
                const std::string toString() const;
        };
    } /* model */ 
} /* eatms */ 


#endif /* EATMS_MODEL_HOURLYPAIDEMPLOYEE_H */
