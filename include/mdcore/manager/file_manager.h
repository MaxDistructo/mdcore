#pragma once

#include <fstream>
#include <map>
#include <string>

template<class T>
using BackendIterator = typename std::map<std::string, T*>::const_iterator;

namespace mdcore
{
    template<class T>
    class FileManager
    {
        public:
            FileManager(){};
            ~FileManager()
            {
                for(auto entry : backend)
                {
                    remove(entry.first);
                }
                backend.clear();
            };
            bool get(T*& t, std::string fileName)
            {
                BackendIterator<T> it = backend.find(fileName);
                if(it != backend.end())
                {
                    t = it->second;
                    if(t == nullptr)
                    {
                        //In backend but it does not exist anymore
                        return false;
                    }
                    //Valid entry, return it
                    return true;
                }
                //Not in backend
                return false;
            }
            bool open(std::string fileName)
            {
                T* s = new T;
                if(!get(s, fileName)){
                    s->open(fileName);
                    if(s->is_open())
                    {
                        backend[fileName] = s;
                        return true;
                    }
                    return false;
                }
                return true;
            }
            void remove(std::string fileName)
            {
                T* s;
                if(get(s, fileName))
                {
                    close(fileName);
                    delete s;
                    backend[fileName] = nullptr;
                }
            }
            bool close(std::string fileName)
            {
                T* s;
                if(get(s, fileName))
                {
                    s->close();
                    return true;
                }
                return false;
            };
        protected:
            std::map<std::string, T*> backend;
    };
    class InputFileManager : public FileManager<std::ifstream>
    {
        public:
            InputFileManager(){};
            ~InputFileManager(){};
    };
    class OutputFileManager : public FileManager<std::ofstream>
    {
        public:
            OutputFileManager(){};
            ~OutputFileManager(){};
    };
    class InputOutputFileManager : public FileManager<std::fstream>
    {
        //Overrides superclass's open method as we need to now open with rw perms
        //instead of just input or output perms
        bool open(std::string fileName)
        {
            std::fstream* s = new std::fstream;
            if(!get(s, fileName)){
                s->open(fileName, std::ios::in | std::ios::out);
                if(s->is_open())
                {
                    backend[fileName] = s;
                    return true;
                }
                return false;
            }
            return true;
        };
    };
}