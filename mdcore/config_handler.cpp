#include "mdcore/handler/config_handler.h"
#include "mdcore/std/utils.h"
#include "mdcore/json_utils.h"

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
        std::fstream* stream;
        std::string filePath = getAbsoluteFilePath(fileName);
        if(filePath != ""){
            io_manager.open(fileName);
        io_manager.get(stream, fileName);
            return load(*stream);
        }
        return false;
    };
    bool ConfigHandler::load(std::fstream& stream)
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
        if(vector_contains(searchPath, path) > 0)
        {
            searchPath.erase(get_iter_location(searchPath, path));
        }
    };
    bool ConfigHandler::searchPathContains(const std::string& path)
    {
        return vector_contains(searchPath, path);
    };

    //Kind of a lazy function but allows users to forget writing to file
    //When ConfigHandler gets destroyed, it attempts to write to the known file
    //it came from, IF it is able to trace where it came from.
    void ConfigHandler::writeToFile()
    {
        std::fstream* stream;
        if(path != ""){
            io_manager.open(getAbsoluteFilePath(path));
            io_manager.get(stream, path);
            //*stream << toJson(backend);
        }
        //We have no clue where the data is from, cannot write to file.
    };

    std::string ConfigHandler::getAbsoluteFilePath(std::string fileName)
    {
        std::ifstream s;
        for(auto path : searchPath)
        {
            std::string testPath = path + fileName;
            if(open_file(testPath, s))
            {
                s.close();
                return testPath;
            }
            s.close();
        }
        return "";
    }
}