#ifndef EATMS_DATA_WORKINGPERSONDAOHASHMAP_H
#define EATMS_DATA_WORKINGPERSONDAOHASHMAP_H

#include <string>
#include <sstream>
#include <array>
#include <forward_list>
#include "model/WorkingPerson.h"
#include "model/WorkingPersonFactory.h"
#include "data/WorkingPersonDao.h"

#ifndef EATMS_MAX_EMPLOYEE_NUM
#define EATMS_MAX_EMPLOYEE_NUM 100
#endif

#ifndef EATMS_MAX_TRAINEE_NUM
#define EATMS_MAX_TRAINEE_NUM 25
#endif

namespace eatms
{
    namespace data
    {
        class WorkingPersonDaoHashMap : public WorkingPersonDao
        {
            private:

                bool        dataModified_;
                bool        initilized_;
                bool        cacheInvalidated_;
                std::string fileName_;
                float       cachedTotalPay_;

                std::array<model::WorkingPerson*, EATMS_MAX_EMPLOYEE_NUM> employees_;
                std::array<model::WorkingPerson*, EATMS_MAX_TRAINEE_NUM> trainees_;

                void clearTrainees_();
                void clearEmployees_();
                void clearEmployee_(int index);
                void clearTrainee_(int index);
                void setModified_();
                void unsetModified_();
                bool isModified_();
                void loadFromFile_(std::string fileName);
                int  getHash_(const std::string & id) const;

            public:
                // constructors and destructors
                WorkingPersonDaoHashMap();
                WorkingPersonDaoHashMap(std::string fileName);
                virtual ~WorkingPersonDaoHashMap();

                // Overridden methods
                std::vector<const model::WorkingPerson *>    getAllWorkingPerson() const;
                bool                                         addWorkingPerson(model::WorkingPerson * person);
                void                                         deleteWorkingPerson(std::string id);
                float                                        getTotalPay();
                std::forward_list<std::array<std::string,3>> listMonthlyPay();
                std::string                                  getDetails(const std::string id) const;
                const model::WorkingPerson    *              getPerson(const std::string id) const;

                // Own methods
                void reloadFromFile(std::string fileName);
                void appendFromFile(std::string fileName);
                void clear();
        };
    } /* data */ 
} /* eatms */ 

#endif /* EATMS_DATA_WORKINGPERSONDAOHASHMAP_H */
