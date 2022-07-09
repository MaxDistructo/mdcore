#include <mdcore/c/logger.h>
#include <ctime>

namespace mdcore{
const TerminalColor COLOR;
const char* currentDateTime();

void Logger::info(char* message)
{
    const char* current = currentDateTime();
    if(level <= LoggerLevel::INFO){
        fprintf(output_stream, "%s", COLOR.WHITE);
        fprintf(output_stream, "%s%s%s%s%s%s", "[INFO] [", current, "] [" , this->logger_name , "] " , message);    
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
    delete current;
};
void Logger::debug(char* message)
{
    const char* current = currentDateTime();
    if(level <= LoggerLevel::DEBUG){
        fprintf(output_stream, "%s", COLOR.YELLOW);
        fprintf(output_stream, "%s%s%s%s%s%s", "[DEBUG] [", current, "] [" , this->logger_name , "] " , message);    
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
    delete current;
};
void Logger::warning(char* message)
{
    const char* current = currentDateTime();
    if(level <= LoggerLevel::WARNING){
        fprintf(output_stream, "%s", COLOR.BOLD_YELLOW);
        fprintf(output_stream, "%s%s%s%s%s%s", "[WARN] [", current, "] [" , this->logger_name , "] " , message);      
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
    delete current;
};
void Logger::error(char* message)
{
    const char* current = currentDateTime();
    if(level <= LoggerLevel::ERROR){
        fprintf(output_stream, "%s", COLOR.RED);
        fprintf(output_stream, "%s%s%s%s%s%s", "[ERROR] [", current, "] [" , this->logger_name , "] " , message);     
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
    delete current;
};
void Logger::fatal(char* message)
{
    const char* current = currentDateTime();
    if(level <= LoggerLevel::FATAL){
        fprintf(output_stream, "%s", COLOR.BOLD_RED);
        fprintf(output_stream, "%s%s%s%s%s%s", "[FATAL] [", current, "] [" , this->logger_name , "] " , message);      
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
    delete current;
};
//This has been patched so that the char ptr is global, not function
const char* currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char*      buf = new char[80];
    tstruct = *localtime_r(&now, &tstruct);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
}