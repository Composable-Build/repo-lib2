#include <catch2/catch_test_macros.hpp>
#include "test_config.h"
#include "../src/plugin_info.h"
#include "../src/version.h"
TEST_CASE("plugin name not empty",    "[info]")    { REQUIRE(std::string(PLUGIN_NAME).size() > 0); }
TEST_CASE("plugin_version not empty", "[version]") { REQUIRE(std::string(plugin_version()).size() > 0); }
TEST_CASE("flag test",                "[flag]")    { REQUIRE(TEST_SHOULD_FAIL == 0); }
