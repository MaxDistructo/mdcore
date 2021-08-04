#pragma once

#include "json.hpp"
#include <map>

namespace mdcore
{
    nlohmann::json readJsonFromFile(std::string filename);
    std::vector<std::string> readJsonArray(std::string filename, std::string element);
    bool writeJsonToFile(std::string filename, nlohmann::json json_object);
    bool jsonToMap(nlohmann::json json, std::map<std::string, std::string>& map);
    template<class T, class K>
    using MapIterator = typename std::map<T, K>::const_iterator;
    
    template <class T, class K>
    std::string toJson(std::map<T, K> m)
    {
        std::string out = "{\n";
        for (MapIterator<T, K> i = m.begin(); i < m.end(); i++)
        {
            if (i == m.size())
            {
                out += "\"" + (*i).first + "\"" + " : " + "\"" + (*i).second + "\", \n";
            }
            else
            {
                out += "\"" + (*i).first + "\"" + " : " + "\"" + (*i).second + "\"\n";
            }
        }
        out += "}";
        return out;
    }
}