#ifndef EATMS_DATA_WORKINGPERSONDAO_H
#define EATMS_DATA_WORKINGPERSONDAO_H

#include <vector>
#include <sstream>
#include <forward_list>
#include <array>
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace data
    {
        class WorkingPersonDao
        {

            public:
                WorkingPersonDao() = default;
                virtual ~WorkingPersonDao();


                // Pure virtual methods of the Data Access Object
                virtual std::vector<model::WorkingPerson> getAllWorkingPerson() = 0;
                virtual bool addWorkingPerson(model::WorkingPerson person) = 0;
                virtual deleteWorkingPerson(std::string id) = 0;
                virtual float getTotalPay() = 0;
                virtual std::stringstream& listMonthlyPay() = 0;
                virtual std::forward_list<std::array<std::string,3>>>& listMonthlyPay() = 0;

        };
    } /* data */ 
} /* eatms */ 


#endif /* EATMS_DATA_WORKINGPERSONDAO_H */
