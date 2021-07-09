#pragma once

#include "../logger.h"
#include "../manager/memory_manager.h"

namespace mdcore{
    class LoggerHandler : public NamedMemoryManager<Logger>
    {
        public:
            LoggerHandler(std::string name)
            {
                getOrCreate(defaultLogger, name);
            };
            ~LoggerHandler();
            bool getDefaultLogger(Logger*& logger);

        private:
            LoggerHandler();
            Logger* defaultLogger;
    };
}