#pragma once

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "file_manager.h"

namespace mdcore
{

class ConfigManager
{
    public:
        ConfigManager()
        {
            backend = {};
            searchPath = {"config/"};
        };
        ~ConfigManager()
        {
            if(path != ""){
                writeToFile();
            }
        };
        void write(const std::string& identifier, std::string string);
        const std::string read(const std::string& identifier);
    
        bool load(const std::string& fileName);

        void addSearchPath(const std::string& path);
        void removeSearchPath(const std::string& path);
        bool searchPathContains(const std::string& path);

        void writeToFile();

    private:
        std::map<std::string, std::string> backend;
        std::vector<std::string> searchPath;
        std::string path = "";
        bool load(std::ifstream& stream);
        bool load(nlohmann::json json);
        std::string getAbsoluteFilePath(std::string fileName);
        InputFileManager i_manager;
        OutputFileManager o_manager;
};

}