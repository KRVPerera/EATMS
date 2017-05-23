#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "EatmsConfig.h"
#include "model/SalariedEmployee.h"
#include "model/WorkingPersonFactory.h"
#include "model/WorkingPerson.h"

//using namespace eatms::model;


int main(int argc, char *argv[])
{
    //   std::cout << "Hello EATMS Loading : " <<
    // "eatms." << EATMS_RELEASE_YEAR << "." << EATMS_RELEASE_MONTH << std::endl;

    std::vector<std::string> list = {"EM01","A","31","34000"};
    eatms::model::SalariedEmployee p("EM120","Sam");
    eatms::model::WorkingPerson * wp0 = eatms::model::WorkingPersonFactory::createWorkingPerson(list);
    std::cout << p.toString() << std::endl;
    return 0;
}
