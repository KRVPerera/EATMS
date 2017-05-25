#include "util/easylogging++.h"
#include "controller/eatms_app.h"

//using namespace eatms::model;
INITIALIZE_EASYLOGGINGPP

using namespace eatms;

int main(int argc, char *argv[])
{
    // Configuring the easylogger library
    std::string logConfig("loggerconfig.in");
    el::Configurations conf(logConfig);
    el::Loggers::reconfigureAllLoggers(conf);

    LOG(INFO) << "Starting main";

    eatms::controller::EatmsApp eatmsMain(argc, argv);
    int status = eatmsMain.run();

    return status;
}
