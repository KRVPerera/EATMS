#ifndef EATMS_MODEL_WORKINGPERSON_H
#define EATMS_MODEL_WORKINGPERSON_H

#include<string>

namespace eatms
{
    namespace model
    {
        class WorkingPerson : public Person
        {
            private:
                std::string idPrefix;
                int idNum;


            public:
                WorkingPerson(const std::string &id , const std::string &name) : Perspn(name);
                virtual ~WorkingPerson()     = 0;

                int         getHashCode();
                int         getIdNum();
                std::string getId();
                std::string getPrefix();


                void        getPrintString() = 0;
                float       getMonthlyPay()  = 0;

            private:
                void updateId(const std::string &idString);
        };
    } /* model */ 
} /* eatms */ 

#endif /* EATMS_MODEL_WORKINGPERSON_H */
