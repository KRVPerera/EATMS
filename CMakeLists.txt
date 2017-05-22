cmake_minimum_required(VERSION 2.8)
project(EmployeeAndTraineeMS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++0x -Wall")

# The version number
set (EATMS_RELEASE_YEAR 2017)
set (EATMS_RELEASE_MONTH 05)
set (EATMS_RELEASE_VERSION "TD")

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
    "${PROJECT_SOURCE_DIR}/src/EatmsConfig.h.in"
    "${PROJECT_BINARY_DIR}/EatmsConfig.h"
    )


set(SOURCE_FILES src/model/Person.cpp src/model/WorkingPerson.cpp src/model/SalariedEmployee.cpp)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(eatms src/main.cpp ${SOURCE_FILES})
add_executable(test0 ${PROJECT_SOURCE_DIR}/test/test.cpp ${SOURCE_FILES})
