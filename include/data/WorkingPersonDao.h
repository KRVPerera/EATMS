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

                // Pure virtual methods of the Data Access Object
                virtual std::vector<const model::WorkingPerson *>    getAllWorkingPerson() const                     = 0;
                virtual bool                                         addWorkingPerson(model::WorkingPerson * person) = 0;
                virtual void                                         deleteWorkingPerson(std::string id)             = 0;
                virtual float                                        getTotalPay()                                   = 0;
                virtual std::forward_list<std::array<std::string,3>> listMonthlyPay()                                = 0;
                virtual std::string                                  getDetails(std::string id) const                = 0;

        };
    } /* data */ 
} /* eatms */ 


#endif /* EATMS_DATA_WORKINGPERSONDAO_H */
