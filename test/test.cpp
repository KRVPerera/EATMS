#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include "model/SalariedEmployee.h"
#include "model/WorkingPersonFactory.h"
#include "model/WorkingPerson.h"
#include "model/Trainee.h"
#include "model/HourlyPaidEmployee.h"

using namespace std;

TEST_CASE("Testing Slaried Employee", "[SalariedEmployee]"){
    eatms::model::SalariedEmployee employeeTest0("EM01", "Sam Jayarathna");
    ///    eatms::model::WorkingPersonFactory
    employeeTest0.setMonthlySalary(2500.5f);

    SECTION (" Updating and reading salary "){
        REQUIRE(employeeTest0.getMonthlyPay() == 2500.5f);
        employeeTest0.setMonthlySalary(200.56f);
        REQUIRE(employeeTest0.getMonthlyPay() == 200.56f);
    }

    SECTION (" Employee ID "){
        REQUIRE(employeeTest0.getIdNum() == 1);
        REQUIRE(employeeTest0.getPrefix() == "EM");
    }

    SECTION(" Person class related", "[Person]"){
        REQUIRE(employeeTest0.getName() == "Sam Jayarathna");
        REQUIRE(employeeTest0.getAge() == 18);
        employeeTest0.setAge(20);
        REQUIRE(employeeTest0.getAge() == 20);

        employeeTest0.setAge(25);

        REQUIRE(employeeTest0.getAge() >= 18);
    }

    SECTION(" Working Person Factory all objects"){
        SECTION( " Salaried employee creation and own setter and getters" ){
            vector<string> list = {"EM01", "A", "31", "34000"};
            eatms::model::WorkingPerson * wp0 = eatms::model::WorkingPersonFactory::createWorkingPerson(list);

            REQUIRE(wp0 != NULL);

            REQUIRE(wp0->getAge()        == 31);
            REQUIRE(wp0->getName()       == "A");
            REQUIRE(wp0->getMonthlyPay() == 34000);

            eatms::model::SalariedEmployee * semp0 = static_cast<eatms::model::SalariedEmployee*>(wp0);
            semp0->setMonthlySalary(380000);
            REQUIRE(wp0->getMonthlyPay() == 380000);
            delete wp0;

        }

        SECTION( " HourlyPaidEmployee creation and own setter and getters" ){

            vector<string> list = {"EM01", "B", "34", "300", "120"};
            eatms::model::WorkingPerson * wp0 = eatms::model::WorkingPersonFactory::createWorkingPerson(list);

            REQUIRE(wp0 != NULL);

            REQUIRE(wp0->getAge()        == 34);
            REQUIRE(wp0->getName()       == "B");
            REQUIRE(wp0->getMonthlyPay() == 300*120);


            eatms::model::HourlyPaidEmployee * hemp0 = static_cast<eatms::model::HourlyPaidEmployee*>(wp0);
            REQUIRE(hemp0->getHourlyRate() == 300);
            REQUIRE(hemp0->getHoursWorked() == 120);

            hemp0->setHourlyRate(20);
            hemp0->setHoursWorked(200);

            REQUIRE(hemp0->getHourlyRate() == 20);
            REQUIRE(hemp0->getHoursWorked() == 200);
            REQUIRE(wp0->getMonthlyPay() == 20*200);
            delete wp0;
        }

        SECTION( " Trainee creation and own setter and getters" ){
            vector<string> list = {"TR22", "H", "22", "12000", "8"};
            eatms::model::WorkingPerson * wp0 = eatms::model::WorkingPersonFactory::createWorkingPerson(list);

            REQUIRE(wp0 != NULL);

            REQUIRE(wp0->getAge()        == 22);
            REQUIRE(wp0->getName()       == "H");
            REQUIRE(wp0->getMonthlyPay() == 12000);

            eatms::model::Trainee * temp0 = static_cast<eatms::model::Trainee*>(wp0);
            temp0->setMonthlyAllowance(12000);
            REQUIRE(temp0->getMonthlyPay() == 12000);
            REQUIRE(wp0->getMonthlyPay() == 12000);
            
            REQUIRE(temp0->getDuration() == 8);
            temp0->setDuration(20);
            REQUIRE(temp0->getDuration() == 20);

            delete wp0;
        }
    }
}
