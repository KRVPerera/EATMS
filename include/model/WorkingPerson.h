#ifndef EATMS_MODEL_WORKINGPERSON_H
#define EATMS_MODEL_WORKINGPERSON_H

#include<string>
#include "model/Person.h"

namespace eatms
{
    namespace model
    {
        class WorkingPerson : public Person
        {
            private:
                std::string idPrefix_;
                int idNum_;


            public:
                WorkingPerson(const std::string &id , const std::string &name) ;
                virtual ~WorkingPerson()  = 0;

                int                 getIdNum()      const;
                const std::string   getId()         const;
                const std::string   getPrefix()     const;


                void                toString()      const = 0;
                float               getMonthlyPay() const = 0;

            private:
                void updateId(const std::string &idString);
        };
    } /* model */ 
} /* eatms */ 

#endif /* EATMS_MODEL_WORKINGPERSON_H */
