#pragma once

#include <string>
#include <map>

template<class T>
using BackendIterator = typename std::map<std::string, T*>::const_iterator;

namespace mdcore{
    template<class T> 
    class NamedMemoryManager
    {
        public:
            NamedMemoryManager<T>(){};
            ~NamedMemoryManager<T>()
            {
                for(auto entry : backend)
                {
                    delete entry.second;
                }
                backend.clear();
            };
            T* get(std::string name)
            {
                BackendIterator<T> it = backend.find(name);
                if(it != backend.end())
                {
                    return it->second;
                }
                //Not in backend
                return nullptr;
            };
            bool create(std::string name)
            {
                T* t = new T(name);
                if(t != nullptr)
                {
                    backend[name] = t;
                    return true;
                }
                return false;
            };
            T* getOrCreate(std::string name)
            {
                T* test = get(name);
                if(test != nullptr)
                {
                    return test;
                }
                bool result = create(name);
                if(!result)
                {
                    return nullptr;
                }
                return get(name);
            };
            void remove(std::string name)
            {
                T* t = get(name);
                if(t != nullptr)
                {
                    delete t;
                    backend[name] = nullptr;
                }
            };
        private:
            std::map<std::string, T*> backend;
    };
    template<class T> 
    class MemoryManager
    {
        public:
            MemoryManager<T>(){};
            ~MemoryManager<T>()
            {
                for(auto entry : backend)
                {
                    delete entry.second;
                }
                backend.clear();
            };
            T* get(std::string name)
            {
                BackendIterator<T> it = backend.find(name);
                if(it != backend.end())
                {
                    return it->second;
                }
                //Not in backend
                return nullptr;
            };
            bool create(std::string name)
            {
                T* t = new T();
                if(t != nullptr)
                {
                    backend[name] = t;
                    return true;
                }
                return false;
            };
            T* getOrCreate(std::string name)
            {
                T *t = get(name);
                if (t != nullptr)
                {
                    return t;
                }
                bool result = create(name);
                if(!result)
                {
                    return nullptr;
                }
                t = get(name);
                return t;
            };
            void remove(std::string name)
            {
                T* t = get(name);
                if(t != nullptr)
                {
                    delete t;
                    backend[name] = nullptr;
                } 
            };
        private:
            std::map<std::string, T*> backend;
    };
}