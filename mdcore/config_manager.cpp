#include "../include/mdcore/manager/config_manager.h"
#include "../include/mdcore/utils.h"
#include "../include/mdcore/json_utils.h"

namespace mdcore{
    void ConfigManager::write(const std::string& identifier, std::string string)
    {
        backend[identifier] = string;
    };
    const std::string ConfigManager::read(const std::string& identifier)
    {
        return backend[identifier];
    };
    bool ConfigManager::load(const std::string& fileName)
    {
        std::ifstream* stream;
        std::string filePath = getAbsoluteFilePath(fileName);
        if(filePath != ""){
            i_manager.open(fileName);
        i_manager.get(stream, fileName);
            return load(*stream);
        }
        return false;
    };
    bool ConfigManager::load(std::ifstream& stream)
    {
        //Streams are JSON, convert to json then convert to map.
        nlohmann::json j = nlohmann::json::parse(stream);
        return load(j);
    };
    bool ConfigManager::load(nlohmann::json json)
    {
        jsonToMap(json, backend);
        return true;
    };
    void ConfigManager::addSearchPath(const std::string& path)
    {
        searchPath.push_back(path);
    };
    void ConfigManager::removeSearchPath(const std::string& path)
    {
        if(vectorContains(searchPath, path) > 0)
        {
            searchPath.erase(getIterLocation(searchPath, path));
        }
    };
    bool ConfigManager::searchPathContains(const std::string& path)
    {
        return vectorContains(searchPath, path);
    };

    //Kind of a lazy function but allows users to forget writing to file
    //When ConfigHandler gets destroyed, it attempts to write to the known file
    //it came from, IF it is able to trace where it came from.
    void ConfigManager::writeToFile()
    {
        std::ofstream* stream;
        if(path != ""){
            o_manager.open(getAbsoluteFilePath(path));
            o_manager.get(stream, path);
            //backend >> stream;
        }
        //We have no clue where the data is from, cannot write to file.
    };

    std::string ConfigManager::getAbsoluteFilePath(std::string fileName)
    {
        std::ifstream stream;
        for(auto path : searchPath)
        {
            std::string testPath = path + fileName;
            if(openFile(testPath, stream))
            {
                stream.close();
                return testPath;
            }
            stream.close();
        }
        return "";
    }
}