#include "controller/eatms_app.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "util/util.h"
#include "model/WorkingPerson.h"

namespace eatms
{
    namespace controller
    {
        EatmsApp::EatmsApp(){
            // initialize blank
            // set default filename
            // load from file
            // start the app
            daoService_.reloadFromFile("../test/EmployeeAndTraineeInformation.txt");
        }


        EatmsApp::EatmsApp(int argc, char *argv[]){
            // check whether file is valid
            // set file name as default
            // load from file
            // start the app
            daoService_.reloadFromFile("../test/EmployeeAndTraineeInformation.txt");
        }

        void EatmsApp::init(){
            // check default file and init with it
            throw "Not Implemented";
        }

        void EatmsApp::init(std::string fileName){
            // check file and open from it
            // if not get to degfault file
            throw "Not Implemented";
        }

        EatmsApp::~EatmsApp(){

        }

        int EatmsApp::run()
        {
            LOG(INFO) << "Starting the EATMS";

            eatms::util::menuChoice choice = eatms::util::menuChoice::MENU_CHOICE_HELP;
            eatms::util::Menu::showWelcomeMessage();
            try{
                do{
                    eatms::util::Menu::showHelpMenu();
                    auto choiceOut_st = eatms::util::Menu::getUserChoice();
                    choice = choiceOut_st.command;
                    if(choice == eatms::util::menuChoice::MENU_CHOICE_EXIT){
                        break;
                    }
                    getService(choiceOut_st);
                }while(true);

                std::cout << "Thank you for using the EATMS servie" << std::endl;
                std::cout << "Hace a nice day!" << std::endl;

                LOG(INFO) << "Exiting the EATMS";
                daoService_.graceFulExit();
                return EXIT_SUCCESS;

            }catch(const std::exception& ex){
                LOG(ERROR) << "Program error! " << ex.what() ;
            }catch(...){
                LOG(ERROR) << "Program error!";
                return EXIT_FAILURE;
            }
        }

        void EatmsApp::getService(choiceOut userChoice){
            switch(userChoice.command){
                case MENU_CHOICE_LIST_ALL:
                    {
                        std::cout << "list all menu" << std::endl;
                        std::cout << std::fixed;
                        std::cout << std::setprecision(2);
                        auto result = daoService_.getAllWorkingPerson();
                        for (auto i = result.begin(); i != result.end(); ++i) {
                            const eatms::model::WorkingPerson * p = *i;
                            if(p){
                                std::cout << (*p).toString() << std::endl;
                            }
                        }
                    }
                    break;
                case MENU_CHOICE_LIST_MONTHLY_PAY:
                    {
                        std::cout << "Displaying Monthly Pay for all employees" << std::endl;
                        auto result = daoService_.getAllWorkingPerson();
                        for (auto i = result.begin(); i != result.end(); ++i) {
                            const eatms::model::WorkingPerson * p = *i;
                            if(p){
                                std::stringstream tempStringStream;
                                tempStringStream << "ID : ";
                                tempStringStream << std::setw(7) << std::left << (*p).getId();
                                tempStringStream << " Name : ";
                                tempStringStream << std::setw(30) << std::left << (*p).getName();
                                tempStringStream << " MonthlyPay       : Rs.";
                                tempStringStream << std::setw(15) << std::right << (*p).getMonthlyPay();
                                std::cout << tempStringStream.str() << std::endl;
                            }
                        }
                    }
                    break;
                case MENU_CHOICE_GET_TOTAL_PAY:
                    {
                        float totalPay = daoService_.getTotalPay();
                        int totalEmployees = daoService_.cachedTotalEmployees_;
                        std::cout << "Total Pay \t\t: Rs " << totalPay <<std::endl;
                        std::cout << "Total employees \t: " <<  totalEmployees << std::endl;
                    }
                    break;

                case MENU_CHOICE_GET_DETAILS_ID:
                    {
                        const eatms::model::WorkingPerson * p = daoService_.getPerson(userChoice.id) ;
                        if(p){
                            std::cout << p->toString() << std::endl;
                        }else{
                            std::cout << "Employee not found!" << std::endl;
                        }
                    }
                    break;
                case MENU_CHOICE_REMOVE_ID:
                    {
                        daoService_.deleteWorkingPerson(userChoice.id);
                    }
                    break;
                case MENU_CHOICE_HELP:
                    {
                        eatms::util::Menu::showHelpMenu();
                    }
                    break;
                case MENU_CHOICE_UNKNOWN:
                    {
                        std::cout << "Unknown command!" << std::endl;
                    }
                    break;
                default:
                    std::cout << "Invalide case choice" << std::endl;
                    break;
            }
        }


    } /* controller */ 
} /* eatms */ 
