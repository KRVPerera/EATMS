#include "data/WorkingPersonDaoHashMap.h"

#include <string>
#include <sstream>
#include <array>
#include <exception>
#include <fstream>
#include <regex>

#include "util/easylogging++.h"
#include "model/WorkingPersonFactory.h"
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace data
    {
        WorkingPersonDaoHashMap::WorkingPersonDaoHashMap()
        {

            dataModified_         = true;
            initilized_           = false;
            cachedTotalPay_       = 0;
            cacheInvalidated_     = true;
            cachedTotalEmployees_ = 0;

            for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i)
            {
                employees_[i] = nullptr;
            }

            for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i)
            {
                trainees_[i] = nullptr;
            }
        }

        WorkingPersonDaoHashMap::~WorkingPersonDaoHashMap()
        {
            clearTrainees_();
            clearEmployees_();
        }

        void WorkingPersonDaoHashMap::clearTrainees_()
        {
            for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i)
            {
                if(trainees_[i])
                {
                    delete trainees_[i];
                    trainees_[i] = nullptr;
                }
            }
        }

        void WorkingPersonDaoHashMap::clearEmployees_()
        {
            for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i)
            {
                if(employees_[i])
                {
                    delete employees_[i];
                    employees_[i] = nullptr;
                }
            }
        }

        void WorkingPersonDaoHashMap::setModified_()
        {
            dataModified_     = true;
            cacheInvalidated_ = true;
        }

        void WorkingPersonDaoHashMap::unsetModified_()
        {
            dataModified_ = false;
        }

        bool WorkingPersonDaoHashMap::isModified_()
        {
            return dataModified_;
        }

        int WorkingPersonDaoHashMap::getHash_(const std::string & id) const
        {
            //TODO : sanitation check
            LOG(DEBUG) << id;
            if(id.size() > 2){
                return std::stoi(id.substr(2));
            }else{
                return -1;
            }
        }

        void WorkingPersonDaoHashMap::clearEmployee_(int index)
        {
            if(index >= 0 && index < EATMS_MAX_EMPLOYEE_NUM)
            {
                delete employees_[index];
                employees_[index] = nullptr;
                setModified_();
            }
        }

        void WorkingPersonDaoHashMap::clearTrainee_(int index)
        {
            if(index >= 0 && index < EATMS_MAX_TRAINEE_NUM)
            {
                delete trainees_[index];
                trainees_[index] = nullptr;
                setModified_();
            }
        }

        // Overridden methods
        bool WorkingPersonDaoHashMap::addWorkingPerson(model::WorkingPerson * person)
        {
            // TODO : move the person to hashmap
            bool result = false;
            LOG(DEBUG) << "Addding Person : " << person->toString();
            if(model::WorkingPersonType::WORKING_PERSON_TYPE_UNKNOWN != 
                    model::WorkingPersonFactory::getWorkingPersonType(person->getId())){

                int index = getHash_(person->getId());
                LOG(DEBUG) << "Hash of the to be added employee : " << index;
                if(model::WorkingPersonFactory::isEmployee(person->getId()))
                {
                    if(employees_[index] == nullptr)
                    {
                        employees_[index] = person;
                    }
                    else
                    {
                        LOG(ERROR) << "Duplicated ID employee not added" << person->getName();
                    }
                }else{
                    if(trainees_[index] == nullptr)
                    {
                        trainees_[index] = person;
                    }
                    else
                    {
                        LOG(ERROR) << "Duplicated ID trainee not added" << person->getName();
                    }
                }
            }else{

                LOG(ERROR) << "Invalid ID! employee not added";
                throw "Invalid ID! Person not added " + person->getName();
            }
        }

        std::vector<const model::WorkingPerson *> WorkingPersonDaoHashMap::getAllWorkingPerson() const
        {
            std::vector<const model::WorkingPerson *> workingPersonVector;

            for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i)
            {
                workingPersonVector.push_back(employees_[i]);
            }

            for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i)
            {
                workingPersonVector.push_back(trainees_[i]);
            }
            return workingPersonVector;
        }

        void WorkingPersonDaoHashMap::loadFromFile_(const std::string & fileName)
        {
            std::ifstream inFile (fileName);

            if(!inFile.is_open())
            {
                LOG(ERROR) << "Error! file is not open";
            }
            else
            {
                std::string line;
                std::cmatch matches;
                fileName_ = fileName;
                std::regex e ("^\\s*((EM|TR)(\\d+))\\s*,(\\s*\\w+\\s*),(\\s*\\d+\\s*),"\
                        "(\\s*(?:\\d*\\.)?\\d+\\s*),?(\\s*(?:\\d*\\.)?\\d+\\s*)?$",
                        std::regex_constants::ECMAScript | std::regex_constants::icase |
                        std::regex_constants::optimize);

                while(std::getline(inFile, line))
                {
                    if(std::regex_match(line.c_str(), matches, e))
                    {
                        std::vector<std::string> processedList;
                        processedList.push_back(matches[1]);
                        for (int i = 4; i < matches.size(); ++i)
                        {
                            if(matches[i] != "")
                            {
                                LOG(DEBUG) << "[" << matches[i] << "] ";
                                processedList.push_back(matches[i]);
                            }
                        }
                        try {
                            if(model::WorkingPersonType::WORKING_PERSON_TYPE_UNKNOWN !=
                                    model::WorkingPersonFactory::getWorkingPersonType(matches[2])){

                                model::WorkingPerson * tempWorkingPerson = 
                                    model::WorkingPersonFactory::createWorkingPerson(processedList);
                                addWorkingPerson(tempWorkingPerson);
                            }
                        }catch(std::exception& ex) {
                            LOG(ERROR) << ex.what();
                        }
                    }
                    else
                    {
                        LOG(WARNING) << "Invalide line! ignored : " << line ;
                    }
                }
                inFile.close();

            }
        }

        void WorkingPersonDaoHashMap::deleteWorkingPerson(std::string id)
        {
            int index = getHash_(id);
            if(model::WorkingPersonFactory::isEmployee(id))
            {
                clearEmployee_(index);
            }
            else
            {
                clearTrainee_(index);
            }
        }

        float WorkingPersonDaoHashMap::getTotalPay()
        {
            if(!cacheInvalidated_)
            {
                return cachedTotalPay_;
            }
            else
            {
                float totalpay = 0.0f;
                cachedTotalEmployees_ = 0;
                for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i)
                {
                    if(employees_[i])
                    {
                        totalpay += employees_[i]->getMonthlyPay();
                        cachedTotalEmployees_ += 1;
                    }
                }

                for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i)
                {
                    if(trainees_[i])
                    {
                        totalpay += trainees_[i]->getMonthlyPay();
                        cachedTotalEmployees_ += 1;
                    }
                }

                cachedTotalPay_   = totalpay;
                cacheInvalidated_ = false;
                return totalpay;
            }
        }

        std::forward_list<std::array<std::string,3>> WorkingPersonDaoHashMap::listMonthlyPay()
        {
            std::forward_list<std::array<std::string,3>> retList;

            for (int i = 0; i < EATMS_MAX_EMPLOYEE_NUM; ++i)
            {
                const model::WorkingPerson * tempPerson = employees_[i];
                if(tempPerson)
                {
                    std::array<std::string,3> tmpArray;
                    tmpArray[0] = tempPerson->getId();
                    tmpArray[1] = tempPerson->getName();
                    tmpArray[2] = std::to_string(tempPerson->getMonthlyPay());
                    retList.push_front(tmpArray);
                }
            }

            for (int i = 0; i < EATMS_MAX_TRAINEE_NUM; ++i)
            {
                const model::WorkingPerson * tempPerson = trainees_[i];
                if(tempPerson)
                {
                    std::array<std::string,3> tmpArray;
                    tmpArray[0] = tempPerson->getId();
                    tmpArray[1] = tempPerson->getName();
                    tmpArray[2] = std::to_string(tempPerson->getMonthlyPay());
                    retList.push_front(tmpArray);
                }
            }

            return retList;
        }

        std::string WorkingPersonDaoHashMap::getDetails(const std::string id) const{
            int index = getHash_(id);

            if(model::WorkingPersonType::WORKING_PERSON_TYPE_EMPLOYEE ==
                    model::WorkingPersonFactory::getWorkingPersonType(id)){

                return employees_[index]->toString();
            }else if(model::WorkingPersonType::WORKING_PERSON_TYPE_TRAINEE ==
                    model::WorkingPersonFactory::getWorkingPersonType(id)){

                return trainees_[index]->toString();
            }
            return "";
        }

        const model::WorkingPerson * WorkingPersonDaoHashMap::getPerson(const std::string id) const{
            int index = getHash_(id);

            LOG(DEBUG) << "Index : " << index << "id : " << id;
            if(model::WorkingPersonType::WORKING_PERSON_TYPE_EMPLOYEE ==
                    model::WorkingPersonFactory::getWorkingPersonType(id)){

                return employees_[index];
            }else if(model::WorkingPersonType::WORKING_PERSON_TYPE_TRAINEE ==
                    model::WorkingPersonFactory::getWorkingPersonType(id)){

                return trainees_[index];
            }
            return nullptr;
        }

        // own method implementations
        void WorkingPersonDaoHashMap::reloadFromFile(std::string fileName)
        {
            clearTrainees_();
            clearEmployees_();
            loadFromFile_(fileName);
        }

        void WorkingPersonDaoHashMap::appendFromFile(std::string fileName)
        {
            throw "Not implemented";
        }

        void WorkingPersonDaoHashMap::clear()
        {
            clearTrainees_();
            clearEmployees_();
        }

        void WorkingPersonDaoHashMap::graceFulExit(){
            LOG(ERROR) << "Graceful exit not implemented";
        }

    } /* data */
} /* eatms */

