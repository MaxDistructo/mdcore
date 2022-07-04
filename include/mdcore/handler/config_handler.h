#pragma once

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "mdcore/manager/file_manager.h"

namespace mdcore
{

class ConfigHandler
{
    public:
        ConfigHandler()
        {
            backend = {};
            searchPath = {"config/"};
        };
        ~ConfigHandler()
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
        bool load(std::fstream& stream);
        bool load(nlohmann::json json);
        std::string getAbsoluteFilePath(std::string fileName);
        FileManager<std::fstream> io_manager;
};

}