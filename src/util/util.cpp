#include "util/util.h"
#include <iostream>
#include <unordered_map>
#include <regex>
#include "util/easylogging++.h"

namespace eatms
{
    namespace util
    {
        void Menu::showHelpMenu(){
            std::cout << "\t\t--- EATMS Menu ---" << std::endl;
            std::cout << "You can use below list of commandes to interact with the system\n" << std::endl;
            std::cout << "1. List all eloyees/trainees\t\t\t: list_all" << std::endl;
            std::cout << "2. List monthly pay of employees/trainees\t: list_monthly_pay" << std::endl;
            std::cout << "3. Get the total pay\t\t\t\t: get_total_pay" << std::endl;
            std::cout << "4. Get full details of an employee/trainee\t: get_details <id>" << std::endl;
            std::cout << "5. Remove an employee/trainee\t\t\t: remove <id>" << std::endl;
            std::cout << "6. Show help menu\t\t\t\t: help" << std::endl;
            std::cout << "0. Exit" << std::endl;
            std::cout << "Enter your choice : ";
        }

        choiceOut Menu::getUserChoice(){
            std::string userChoice;
            std::cmatch matches;
            std:getline(std::cin, userChoice);

            //parse here and divide to two arguments
            choiceOut choice;
            if(std::regex_match(userChoice.c_str(), matches, userInputParserRegex)){
                try{
                    std::string firstArgument = matches[1];
                    std::string secondArgument = matches[2];
                    ltrim(firstArgument);
                    ltrim(secondArgument);
                    LOG(INFO) << firstArgument;
                    LOG(INFO) << secondArgument;
                    choice.command = menuMap_.at(firstArgument);
                    choice.id = secondArgument;
                }catch(const std::out_of_range& e){
                    choice.command = MENU_CHOICE_UNKNOWN;
                    LOG(WARNING) << "Invalid menu choice!";
                }
            }else{
                choice.command = MENU_CHOICE_UNKNOWN;
            }
            return choice;
        }

        void Menu::showWelcomeMessage(){
            std::cout << "********* " << "Employee And Trainee Mangement System - EATMS " <<
                "*********" << std::endl;
        }
    } /* util */ 
} /* eatms */ 

