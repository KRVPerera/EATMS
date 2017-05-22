#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "model/SalariedEmployee.h"

unsigned int Factorial(unsigned int num){
    return 9;
}

TEST_CASE("Factorials are computed", "[factorial]"){
    REQUIRE( Factorial(1) == 9 );
}

TEST_CASE("Testing Slaried Employee", "[SalariedEmployee]"){
    eatms::model::SalariedEmployee employeeTest0("EM01", "Sam Jayarathna");
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
        employeeTest0.setAge(-20);
        REQUIRE(employeeTest0.getAge() >= 18);
    }

}
