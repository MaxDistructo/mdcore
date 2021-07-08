#include "../include/mdcore/utils.h"
#include <fstream>
#include <iostream>

bool openFile(std::string filename, std::ifstream& stream)
{
    stream.open(filename);
    if(stream.is_open())
    {
        return true;
    }
    return false;
};
bool openFile(std::string filename, std::ifstream* stream)
{
    stream->open(filename);
    if(stream->is_open())
    {
        return true;
    }
    return false;
};
bool openFile(std::string filename, std::ofstream& stream)
{
    stream.open(filename);
    if(stream.is_open())
    {
        return true;
    }
    return false;
};
bool writeFile(std::string filename, std::string contents)
{
    std::ofstream stream;
    stream.open(filename);
    if(!stream.is_open())
    {
        stream.close();
        return false;
    }
    stream << contents;
    stream.close();
    return true;
};
