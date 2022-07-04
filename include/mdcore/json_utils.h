#pragma once

#include <nlohmann/json.hpp>
#include <map>

namespace mdcore
{
    nlohmann::json readJsonFromFile(std::string filename);
    std::vector<std::string> readJsonArray(std::string filename, std::string element);
    bool writeJsonToFile(std::string filename, nlohmann::json json_object);
    bool jsonToMap(nlohmann::json json, std::map<std::string, std::string>& map);
}