#include "model/WorkingPersonFactory.h"
#include <iostream> // TODO : Remove in RC
#include <vector>
#include <string>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "util/easylogging++.h"
#pragma GCC diagnostic pop
#include "model/WorkingPerson.h"
#include "model/HourlyPaidEmployee.h"
#include "model/Trainee.h"

INITIALIZE_EASYLOGGINGPP

namespace eatms
{
    namespace model
    {

        WorkingPerson * WorkingPersonFactory::createWorkingPerson(const std::string & sourceLine) {
            /* data */
            // TODO : implepene only if needed
            WorkingPerson * temp = NULL;
            return temp;
        };

        WorkingPerson * WorkingPersonFactory::createWorkingPerson(std::vector<std::string> & stringList) {
            // creating employee class
            LOG(INFO) << "Factory function started";
            WorkingPerson * temp = NULL;
            if(stringList.empty()){
                LOG(INFO) << "My first info log using default logger";
                return  temp;
            }
            else if(WorkingPersonFactory::isEmployee_(stringList.front())){
                if(stringList.size() == WorkingPersonStringSize::SALARIED_EMPLOYEE){

                    temp = new SalariedEmployee(stringList);

                }else if(stringList.size() == WorkingPersonStringSize::HOURLYPAID_EMPLOYEE){

                    temp = new HourlyPaidEmployee(stringList);

                }
            }else{ // not a employee, can be a trainee
                if(stringList.size() == WorkingPersonStringSize::TRAINEE){

                    temp = new Trainee(stringList.front(), stringList[1]);

                }
            }
            return temp;
        };

        bool WorkingPersonFactory::isEmployee_(const std::string & id){
            if(id[0] == 'E'){
                return true;
            }else{
                return false;
            }
        }
    } /* model */ 
} /* eatms */ 
