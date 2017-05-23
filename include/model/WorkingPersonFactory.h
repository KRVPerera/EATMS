#ifndef EATMS_MODEL_WORKINGPERSONFACTORY_H
#define EATMS_MODEL_WORKINGPERSONFACTORY_H

#include <string>
#include <vector>
#include "model/WorkingPerson.h"
#include "model/HourlyPaidEmployee.h"
#include "model/Trainee.h"
#include "model/SalariedEmployee.h"

namespace eatms
{
    namespace model
    {
        enum WorkingPersonStringSize{
            BLANK = 0,
            SALARIED_EMPLOYEE = 4,
            HOURLYPAID_EMPLOYEE = 5,
            TRAINEE = 5,
        };
        //TODO :: make this a singleton if needed
        class WorkingPersonFactory
        {
            private:
                /* no private data */
                static bool isEmployee_(const std::string & id);
            public:
                static WorkingPerson * createWorkingPerson(const std::string & sourceLine);
                static WorkingPerson * createWorkingPerson(std::vector<std::string> & stringList);
        };
    } /* model */ 
} /* eatms */ 

#endif /* EATMS_MODEL_WORKINGPERSONFACTORY_H */