#include <mdcore/std/logger.h>
#include <ctime>

namespace mdcore{
const TerminalColor COLOR;
const std::string currentDateTime();

void Logger::set_outputstream(FILE* file)
{
    output_stream = file;
}

void Logger::info(std::string message)
{
    if(level <= LoggerLevel::INFO){
        fprintf(output_stream, "%s", COLOR.WHITE);
        fprintf(output_stream, "%s", ((std::string)"[INFO] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
};
void Logger::debug(std::string message)
{
    if(level <= LoggerLevel::DEBUG){
        fprintf(output_stream, "%s", COLOR.YELLOW);
        fprintf(output_stream, "%s", ((std::string)"[DEBUG] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
};
void Logger::warning(std::string message)
{
    if(level <= LoggerLevel::WARNING){
        fprintf(output_stream, "%s", COLOR.BOLD_YELLOW);
        fprintf(output_stream, "%s", ((std::string)"[WARNING] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
};
void Logger::error(std::string message)
{
    if(level <= LoggerLevel::ERROR){
        fprintf(output_stream, "%s", COLOR.RED);
        fprintf(output_stream, "%s", ((std::string)"[ERROR] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
};
void Logger::fatal(std::string message)
{
    if(level <= LoggerLevel::FATAL){
        fprintf(output_stream, "%s", COLOR.BOLD_RED);
        fprintf(output_stream, "%s", ((std::string)"[FATAL] [" + currentDateTime() + "] [" + this->logger_name + "] " + message).c_str());    
        fprintf(output_stream, "%s", COLOR.RESET);
        fprintf(output_stream, "%s", "\n");
    }
};
const std::string currentDateTime() {
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