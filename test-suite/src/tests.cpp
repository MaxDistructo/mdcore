#include <catch2/catch_all.hpp>
#include <mdcore/std/logger.h>

TEST_CASE("Test")
{
    REQUIRE(1==1);
}

TEST_CASE("Logger")
{
    mdcore::Logger logger("std test suite");
    SECTION("Info - std::string")
    {
        std::string info_test = "Info Test";
        //const char* info_test2 = "Info Test";
        logger.info(info_test);
        
    }
    SECTION("Info - char*")
    {
        const char* info_test = "Info Test";
        logger.info(info_test);
    }
}