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
            bool get(T*& t, std::string name)
            {
                BackendIterator<T> it = backend.find(name);
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
            bool getOrCreate(T*& t, std::string name)
            {
                if(get(t, name))
                {
                    return true;
                }
                bool result = create(name);
                if(!result)
                {
                    return false;
                }
                get(t, name);
                return true;
            };
            void remove(std::string name)
            {
                T* t;
                if(get(t, name))
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
            bool get(T*& t, std::string name)
            {
                BackendIterator<T> it = backend.find(name);
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
            };
            virtual bool create(std::string name)
            {
                T* t = new T();
                if(t != nullptr)
                {
                    backend[name] = t;
                    return true;
                }
                return false;
            };
            bool getOrCreate(T*& t, std::string name)
            {
                if(get(t, name))
                {
                    return true;
                }
                bool result = create(name);
                if(!result)
                {
                    return false;
                }
                get(t, name);
                return true;
            };
            void remove(std::string name)
            {
                T* t;
                if(get(t, name))
                {
                    delete t;
                    backend[name] = nullptr;
                } 
            };
        private:
            std::map<std::string, T*> backend;
    };
}