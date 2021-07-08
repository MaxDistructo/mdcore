#include "../include/mdcore/logger.h"
#include <ctime>

using namespace mdcore::Logger;
const TerminalColor COLOR;
const std::string currentDateTime();

Logger::~Logger(){};
void Logger::info(std::string message)
{
    if(level <= LoggerLevel::INFO){
        printf("%s", COLOR.WHITE);
        printf("%s", ((std::string)"[INFO] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::debug(std::string message)
{
    if(level <= LoggerLevel::DEBUG){
        printf("%s", COLOR.YELLOW);
        printf("%s", ((std::string)"[DEBUG] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::warning(std::string message)
{
    if(level <= LoggerLevel::WARNING){
        printf("%s", COLOR.BOLD_YELLOW);
        printf("%s", ((std::string)"[WARNING] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::error(std::string message)
{
    if(level <= LoggerLevel::ERROR){
        printf("%s", COLOR.RED);
        printf("%s", ((std::string)"[ERROR] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::fatal(std::string message)
{
    if(level <= LoggerLevel::FATAL){
        printf("%s", COLOR.BOLD_RED);
        printf("%s", ((std::string)"[FATAL] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}