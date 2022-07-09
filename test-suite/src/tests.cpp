#include <catch2/catch_all.hpp>
#include <mdcore/std/logger.h>
#include <cstdio>
#include "test_functions.h"

TEST_CASE("Test")
{
    REQUIRE(1==1);
}

TEST_CASE("Logger")
{
    mdcore::Logger logger("std test suite");
    FILE* memory_file = tmpfile();

    logger.set_outputstream(memory_file);

    SECTION("Info - std::string")
    {
        std::string info_test = "Info Test";
        //const char* info_test2 = "Info Test";
        REQUIRE_NOTHROW(logger.info(info_test));
    }
    SECTION("Info - char*")
    {
        const char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.info(info_test));
    }

    SECTION("Debug - std::string")
    {
        std::string info_test = "Info Test";
        //const char* info_test2 = "Info Test";
        REQUIRE_NOTHROW(logger.debug(info_test));
    }
    SECTION("Debug - char*")
    {
        const char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.debug(info_test));
    }

    SECTION("Warning - std::string")
    {
        std::string info_test = "Info Test";
        //const char* info_test2 = "Info Test";
        REQUIRE_NOTHROW(logger.warn(info_test));
    }
    SECTION("Warning - char*")
    {
        const char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.warn(info_test));
    }

    SECTION("Error - std::string")
    {
        std::string info_test = "Info Test";
        //const char* info_test2 = "Info Test";
        REQUIRE_NOTHROW(logger.error(info_test));
    }
    SECTION("Error - char*")
    {
        const char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.error(info_test));
    }

    SECTION("Fatal - std::string")
    {
        std::string info_test = "Info Test";
        //const char* info_test2 = "Info Test";
        REQUIRE_NOTHROW(logger.fatal(info_test));
    }
    SECTION("Fatal - char*")
    {
        const char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.fatal(info_test));
    }
}