#include <catch2/catch_all.hpp>
#include <mdcore/c/logger.h>

TEST_CASE("Logger")
{
    mdcore::Logger logger("c test suite");
}