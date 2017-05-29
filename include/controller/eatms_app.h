#ifndef EATMS_APP_H
#define EATMS_APP_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "util/easylogging++.h"
#include "EatmsConfig.h"
#include "model/SalariedEmployee.h"
#include "model/WorkingPersonFactory.h"
#include "model/WorkingPerson.h"
#include "data/WorkingPersonDaoHashMap.h"
#include "util/util.h"

using namespace eatms::util;
namespace eatms
{
    namespace controller
    {
        //TODO : make this a single instance
        class EatmsApp
        {
            private:
                eatms::data::WorkingPersonDaoHashMap daoService_;
            public:
                EatmsApp();
                EatmsApp(int argc, char *argv[]);
                EatmsApp(EatmsApp const&)       = delete;
                void operator=(EatmsApp const&) = delete;

                void    init();
                void    init(std::string fileName);
                int     run();
                virtual ~EatmsApp();
                void    getService(choiceOut userChoice);

        };
    } /* controller */
} /* eatms */

#endif /* EATMS_APP_H */
