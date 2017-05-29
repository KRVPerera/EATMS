#ifndef EATMS_UTIL_MENU_H
#define EATMS_UTIL_MENU_H

#include <unordered_map>
#include <regex>
#include "util/util.h"

namespace eatms
{
    namespace util
    {
        /*! \enum menuChoice
         *
         *  This has all the available menu choices and please add new ones here and use this in rest of the code
         */
        typedef enum menuChoice {
            MENU_CHOICE_EXIT,
            MENU_CHOICE_LIST_ALL,
            MENU_CHOICE_LIST_MONTHLY_PAY,
            MENU_CHOICE_GET_TOTAL_PAY,
            MENU_CHOICE_GET_DETAILS_ID,
            MENU_CHOICE_REMOVE_ID,
            MENU_CHOICE_HELP,
            MENU_CHOICE_UNKNOWN,
        } menuCoice;

        typedef struct choiceOut{
            menuChoice command;
            std::string id;
        }choiceOut;

        static inline void ltrim(std::string &s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                        std::not1(std::ptr_fun<int, int>(std::isspace))));
        }

        const std::regex userInputParserRegex ("^(\\s*\\w+|\\w+)(\\s*|\\s(TR|EM)\\d+)\\s*$",
            std::regex_constants::ECMAScript | std::regex_constants::icase | std::regex_constants::optimize);

        const std::unordered_map<std::string, menuChoice> menuMap_{
            {"list_all",         MENU_CHOICE_LIST_ALL},
                {"list_monthly_pay", MENU_CHOICE_LIST_MONTHLY_PAY},
                {"get_total_pay",    MENU_CHOICE_GET_TOTAL_PAY},
                {"get_details",      MENU_CHOICE_GET_DETAILS_ID},
                {"remove",           MENU_CHOICE_REMOVE_ID},
                {"help",             MENU_CHOICE_HELP},
                {"exit",             MENU_CHOICE_EXIT},
                {"0",             MENU_CHOICE_EXIT},
                {"1",                MENU_CHOICE_LIST_ALL},
                {"2",                MENU_CHOICE_LIST_MONTHLY_PAY},
                {"3",                MENU_CHOICE_GET_TOTAL_PAY},
                {"4",                MENU_CHOICE_GET_DETAILS_ID},
                {"5",                MENU_CHOICE_EXIT},
                {"6",                MENU_CHOICE_HELP},
        };

        class Menu
        {
            public:
                static void showHelpMenu();
                static void showWelcomeMessage();
                static choiceOut getUserChoice();
        };
    } /* util */ 
} /* eatms */ 

#endif /* EATMS_UTIL_MENU_H */
