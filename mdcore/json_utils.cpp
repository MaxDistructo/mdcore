#include "../include/mdcore/json_utils.h"
#include "../include/mdcore/std/utils.h"
#include <fstream>

nlohmann::json readJsonFromFile(std::string filename)
{
    std::ifstream file;
    open_file("config/config.json", file);
    nlohmann::json f_json = nlohmann::json::parse(file);
    return f_json;
}
std::vector<std::string> readJsonArray(std::string filename, std::string element)
{
    nlohmann::json j = readJsonFromFile(filename);
    return j;
}
bool writeJsonToFile(std::string filename, nlohmann::json json_object)
{
    return false;
}
bool jsonToMap(nlohmann::json json, std::map<std::string,std::string>& map)
{
    for(const auto& element : json.items())
    {
        map[element.key()] = element.value();
    }
    return true;
}
