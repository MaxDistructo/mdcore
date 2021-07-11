#pragma once

#include "../logger.h"
#include "../manager/memory_manager.h"

namespace mdcore{
    class LoggerHandler : public NamedMemoryManager<Logger>
    {
        public:
            LoggerHandler(std::string name)
            {
                defaultLogger = getOrCreate(name);
            };
            ~LoggerHandler(){};
            Logger* getDefaultLogger();

        private:
            LoggerHandler();
            Logger* defaultLogger;
    };
}