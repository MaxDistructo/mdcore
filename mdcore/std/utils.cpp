#include "../include/mdcore/std/utils.h"
#include <fstream>
#include <iostream>

bool open_file(std::string filename, std::ifstream& stream)
{
    stream.open(filename);
    if(stream.is_open())
    {
        return true;
    }
    return false;
};
bool open_file(std::string filename, std::ifstream* stream)
{
    stream->open(filename);
    if(stream->is_open())
    {
        return true;
    }
    return false;
};
bool open_file(std::string filename, std::ofstream& stream)
{
    stream.open(filename);
    if(stream.is_open())
    {
        return true;
    }
    return false;
};
bool write_file(std::string filename, std::string contents)
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
