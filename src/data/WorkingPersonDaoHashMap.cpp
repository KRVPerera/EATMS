#include "data/WorkingPersonDaoHashMap.h"

#include <string>
#include <sstream>
#include <array>
#include <exception>
#include <fstream>

#include "model/WorkingPersonFactory.h"
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace data
    {
        WorkingPersonDaoHashMap::WorkingPersonDaoHashMap(){

            dataModified_     = true;
            initilized_       = false;
            cachedTotalPay_   = 0;
            cacheInvalidated_ = true;

            for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i) {
                employees_[i] = nullptr;
            }

            for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i) {
                trainees_[i] = nullptr;
            }
        }

        WorkingPersonDaoHashMap::~WorkingPersonDaoHashMap(){
            clearTrainees_();
            clearEmployees_();
        }

        void WorkingPersonDaoHashMap::clearTrainees_(){
            for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i) {
                if(trainees_[i]){
                    delete trainees_[i];
                    trainees_[i] = nullptr;
                }
            }
        }

        void WorkingPersonDaoHashMap::clearEmployees_(){
            for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i) {
                if(employees_[i]){
                    delete employees_[i];
                    employees_[i] = nullptr;
                }
            }
        }

        void WorkingPersonDaoHashMap::setModified_(){
            dataModified_     = true;
            cacheInvalidated_ = true;
        }

        void WorkingPersonDaoHashMap::unsetModified_(){
            dataModified_ = false;
        }

        bool WorkingPersonDaoHashMap::isModified_(){
            return dataModified_;
        }

        int WorkingPersonDaoHashMap::getHash_(std::string id){
            //TODO : sanitation check
            return std::stoi(id.substr(2));
        }

        void WorkingPersonDaoHashMap::clearEmployee_(int index){
            if(index >= 0 && index < EATMS_MAX_EMPLOYEE_NUM){
                delete employees_[index];
                employees_[index] = nullptr;
                setModified_();
            }
        }

        void WorkingPersonDaoHashMap::clearTrainee_(int index){
            if(index >= 0 && index < EATMS_MAX_TRAINEE_NUM){
                delete trainees_[index];
                trainees_[index] = nullptr;
                setModified_();
            }
        }

        // Overridden methods
        bool WorkingPersonDaoHashMap::addWorkingPerson(model::WorkingPerson & person){
            // TODO : move the person to hashmap
            throw std::logic_error("Function not implemented");
        }

        std::vector<const model::WorkingPerson *> WorkingPersonDaoHashMap::getAllWorkingPerson() const{
            std::vector<const model::WorkingPerson *> workingPersonVector;

            for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i) {
                workingPersonVector.push_back(employees_[i]);
            }

            for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i) {
                workingPersonVector.push_back(trainees_[i]);
            }
            return workingPersonVector;
        }

        void WorkingPersonDaoHashMap::loadFromFile_(std::string fileName){
            std::ifstream inFile (fileName);
            if(!inFile.is_open()){

            }else{
                std::string line;
                while(std::getline(inFile, line)){

                }
                inFile.close();
            }
        }

        void WorkingPersonDaoHashMap::deleteWorkingPerson(std::string id){
            int index = getHash_(id);
            if(model::WorkingPersonFactory::isEmployee(id)){
                clearEmployee_(index);
            }else{
                clearTrainee_(index);
            }
        }

        float WorkingPersonDaoHashMap::getTotalPay(){
            if(!cacheInvalidated_){
                return cachedTotalPay_;
            }else{
                float totalpay = 0.0f;


                for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i) {
                    if(employees_[i]){
                        totalpay += employees_[i]->getMonthlyPay();
                    }
                }
                for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i) {
                    if(trainees_[i]){
                        totalpay += trainees_[i]->getMonthlyPay();
                    }
                }
                cachedTotalPay_   = totalpay;
                cacheInvalidated_ = false;
                return totalpay;
            }
        }



    } /* data */ 
} /* eatms */ 

