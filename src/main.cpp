#include <iostream>
#include <memory>
#include "EatmsConfig.h"
#include "model/SalariedEmployee.h"
//using namespace eatms::model;


int main(int argc, char *argv[])
{
    //   std::cout << "Hello EATMS Loading : " <<
    // "eatms." << EATMS_RELEASE_YEAR << "." << EATMS_RELEASE_MONTH << std::endl;

    eatms::model::SalariedEmployee p("EM120","Sam");
    std::cout << p.toString() << std::endl;
    return 0;
}
