#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <algorithm>
#include <map>

bool openFile(std::string filename, std::ifstream& stream);
bool openFile(std::string filename, std::ifstream* stream);
bool openFile(std::string filename, std::ofstream& stream);
bool writeFile(std::string filename, std::string contents);

template<class T>
bool vectorContains(const std::vector<T>& v, const T& t)
{
    return std::count(v.begin(), v.end(), t);
}

template<class T>
typename std::vector<T>::iterator getIterLocation(std::vector<T> v, T t)
{
    for(typename std::vector<T>::iterator iter; iter < v.end(); iter++)
    {
        if(*iter == t)
        {
            return iter;
        }
    }
    return v.end();
}

template<class T>
int getIndex(std::vector<T> v, T t)
{
    for(size_t i = 0; i < v.size(); i++)
    {
        if(v[i] == t)
        {
            return i;
        }
    }
    return -1;
}

template<class T>
std::string toString(std::vector<T> v, std::string seperator)
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
std::string toString(std::vector<T> v)
{
    return toString(v, ", ");
}

template<class T, class K>
using MapIterator = typename std::map<T, K>::const_iterator;

template<class T, class K>
std::string toString(std::map<T, K> m, std::string seperator)
{
    std::string out;
    for (MapIterator<T, K> i = m.begin(); i < m.end(); i++)
    {
        if (i != (m.end() - 1))
        {
            out += (*i).first + " : " +  (*i).second + seperator;
        }
        else
        {
            out += (*i).first + " : " + (*i).second;
        }
    }
    return out;
}

template<class T, class K>
std::string toString(std::map<T, K> m)
{
    return toString(m, ", ");
}


