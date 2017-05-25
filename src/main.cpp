#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "util/easylogging++.h"
#include "EatmsConfig.h"
#include "model/SalariedEmployee.h"
#include "model/WorkingPersonFactory.h"
#include "model/WorkingPerson.h"
#include "util/util.h"

//using namespace eatms::model;
INITIALIZE_EASYLOGGINGPP

using namespace eatms;

int main(int argc, char *argv[])
{
    // Configuring the easylogger library
    std::string logConfig("loggerconfig.in");
    el::Configurations conf(logConfig);
    el::Loggers::reconfigureAllLoggers(conf);

    LOG(INFO) << "Starting the EATMS";

    eatms::util::menuChoice choice = eatms::util::menuChoice::MENU_CHOICE_HELP;
    eatms::util::Menu::showWelcomeMessage();

    do{
        eatms::util::Menu::showHelpMenu();
        choice = eatms::util::Menu::getUserChoice();
        if(choice == eatms::util::menuChoice::MENU_CHOICE_EXIT){
            break;
        }
        //eatms::controller::getService(choice);
    }while(true);

    std::cout << "Thank you for using the EATMS servie" << std::endl;
    std::cout << "Hace a nice day!" << std::endl;

    LOG(INFO) << "Exiting the EATMS";
    return 0;
}
