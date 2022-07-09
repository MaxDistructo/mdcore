#include <catch2/catch_all.hpp>
#include <mdcore/c/logger.h>

TEST_CASE("C Logger")
{
    mdcore::Logger logger("c test suite");
    

    SECTION("Info - char*")
    {
        char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.info(info_test));
    }

    SECTION("Debug - char*")
    {
        char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.debug(info_test));
    }

    SECTION("Warning - char*")
    {
        char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.warn(info_test));
    }

    SECTION("Error - char*")
    {
        char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.error(info_test));
    }

    SECTION("Fatal - char*")
    {
        char* info_test = "Info Test";
        REQUIRE_NOTHROW(logger.fatal(info_test));
    }
}