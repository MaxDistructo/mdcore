#include "mdcore/c/logger.h"
#include <ctime>

namespace mdcore{
const TerminalColor COLOR;
const char* currentDateTime();

void Logger::info(char* message)
{
    if(level <= LoggerLevel::INFO){
        printf("%s", COLOR.WHITE);
        printf("%s%s%s%s%s%s", "[INFO] [", currentDateTime(), "] [" , this->logger_name , "] " , message);    
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::debug(char* message)
{
    if(level <= LoggerLevel::DEBUG){
        printf("%s", COLOR.YELLOW);
        printf("%s%s%s%s%s%s", "[DEBUG] [", currentDateTime(), "] [" , this->logger_name , "] " , message);    
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::warning(char* message)
{
    if(level <= LoggerLevel::WARNING){
        printf("%s", COLOR.BOLD_YELLOW);
        printf("%s%s%s%s%s%s", "[WARN] [", currentDateTime(), "] [" , this->logger_name , "] " , message);      
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::error(char* message)
{
    if(level <= LoggerLevel::ERROR){
        printf("%s", COLOR.RED);
        printf("%s%s%s%s%s%s", "[ERROR] [", currentDateTime(), "] [" , this->logger_name , "] " , message);     
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
void Logger::fatal(char* message)
{
    if(level <= LoggerLevel::FATAL){
        printf("%s", COLOR.BOLD_RED);
        printf("%s%s%s%s%s%s", "[FATAL] [", currentDateTime(), "] [" , this->logger_name , "] " , message);      
        printf("%s", COLOR.RESET);
        printf("%s", "\n");
    }
};
const char* currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime_r(&now, &tstruct);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
}