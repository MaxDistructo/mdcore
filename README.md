# mdcore
My base set of core utilities. These try to be simple to implement down stream without being super inefficient

Designed using GCC 11

## Building
Basic CMake config. Add as any other dependency in CMake
This repo relies on nlohmann::json that it includes, files using this are marked as json. source: https://github.com/nlohmann/json
Everything else is self-sufficient, without the need for any external libraries

##License
You are able to use this code in your own projects as long as credit is given to this repo.
