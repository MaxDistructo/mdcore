#include "../include/mdcore/handler/logger_handler.h"

namespace mdcore
{
    bool LoggerHandler::getDefaultLogger(Logger*& logger)
    {
        return defaultLogger;
    };
}