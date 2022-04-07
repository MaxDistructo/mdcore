#pragma once
#include <cstdio>

bool open_file(char* filename, FILE*& stream);
bool write_file(char* filename, char* contents);

template<class T>
char* to_string(T* v, char seperator)
{
    std::string out;
    for(size_t i = 0; i < v.size(); i++)
    {
        if(i != (v.size() - 1))
        {
            out += v[i] + seperator;
        }
        else {
            out += v[i];
        }
    }
    return out;
}

template<class T>
char* to_string(T* v)
{
    return to_string(v, ", ");
}