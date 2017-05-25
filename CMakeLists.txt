cmake_minimum_required(VERSION 2.8)
project(EmployeeAndTraineeMS)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra")
set(CMAKE_CXX_FLAGS "-std=c++0x")

# The version number
set (EATMS_RELEASE_YEAR 2017)
set (EATMS_RELEASE_MONTH 05)
set (EATMS_RELEASE_VERSION "TD")

#  Configurations
set (EATMS_MAX_EMPLOYEE_NUM 100)
set (EATMS_MAX_TRAINEE_NUM 25)
set (EATMS_EMPLOYEE_MIN_AGE 18)

set(SRC_MODEL_DIR /src/model)
set(SRC_VIEW_DIR /src/view)
set(SRC_CONTROLLER_DIR /src/controller)


if( NOT CMAKE_BUILD_TYPE )
    set( CMAKE_BUILD_TYPE Debug CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo
        MinSizeRel."
        FORCE )
endif()


configure_file(
    "${PROJECT_SOURCE_DIR}/config/EatmsConfig.h.in"
    "${PROJECT_BINARY_DIR}/EatmsConfig.h"
    )
configure_file(
    "${PROJECT_SOURCE_DIR}/config/loggerconfig.in"
    "${PROJECT_BINARY_DIR}/loggerconfig.in"
    )


set(SOURCE_FILES src/model/Person.cpp src/model/WorkingPerson.cpp src/model/SalariedEmployee.cpp
    src/model/WorkingPersonFactory.cpp src/model/HourlyPaidEmployee.cpp src/model/Trainee.cpp src/util/easylogging++.cc
    src/data/WorkingPersonDaoHashMap.cpp src/util/util.cpp)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/include/util")

add_executable(eatms src/main.cpp ${SOURCE_FILES})
add_executable(test0 ${PROJECT_SOURCE_DIR}/test/test.cpp ${SOURCE_FILES})
