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


set(SOURCE_FILES src/main.cpp src/model/Person.cpp)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")
#include_directories("${PROJECT_SOURCE_DIR}/include/model")
#include_directories("${PROJECT_SOURCE_DIR}/include/view")
#include_directories("${PROJECT_SOURCE_DIR}/include/controller")
#include_directories("${SRC_MODEL_DIR}")
#include_directories("${SRC_VIEW_DIR}")
#include_directories("${SRC_CONTROLLER_DIR}")

add_executable(eatms ${SOURCE_FILES})
