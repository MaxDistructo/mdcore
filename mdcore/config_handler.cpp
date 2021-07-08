#include "../include/mdcore/config_handler.h"
#include "../include/mdcore/utils.h"
#include "../include/mdcore/json_utils.h"

namespace mdcore{
    void ConfigHandler::write(const std::string& identifier, std::string string)
    {
        backend[identifier] = string;
    };
    const std::string ConfigHandler::read(const std::string& identifier)
    {
        return backend[identifier];
    };
    bool ConfigHandler::load(const std::string& fileName)
    {
        std::ifstream *stream;
        std::string filePath = getAbsoluteFilePath(fileName);
        if(filePath != ""){
            stream->open(filePath);
            return load(*stream);
        }
        return false;
    };
    bool ConfigHandler::load(std::ifstream& stream)
    {
        //Streams are JSON, convert to json then convert to map.
        nlohmann::json j = nlohmann::json::parse(stream);
        return load(j);
    };
    bool ConfigHandler::load(nlohmann::json json)
    {
        jsonToMap(json, backend);
        return true;
    };
    void ConfigHandler::addSearchPath(const std::string& path)
    {
        searchPath.push_back(path);
    };
    void ConfigHandler::removeSearchPath(const std::string& path)
    {
        if(vectorContains(searchPath, path) > 0)
        {
            searchPath.erase(getIterLocation(searchPath, path));
        }
    };
    bool ConfigHandler::searchPathContains(const std::string& path)
    {
        return vectorContains(searchPath, path);
    };

    //Kind of a lazy function but allows users to forget writing to file
    //When ConfigHandler gets destroyed, it attempts to write to the known file
    //it came from, IF it is able to trace where it came from.
    void ConfigHandler::writeToFile()
    {
        std::ofstream stream;
        if(path != ""){
            stream.open(getAbsoluteFilePath(path));
            //backend >> stream;
            stream.close();
        }
        //We have no clue where the data is from, cannot write to file.
    };

    std::string ConfigHandler::getAbsoluteFilePath(std::string fileName)
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