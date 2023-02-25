/**
 * @file
 *
 * Tests related to logging in file utilities/logger.cpp and utilities/logger.h.
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2022
 */

//   Copyright 2022 Hendrix Demers
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

// C system headers
// C++ system header
#include <sstream>
#include <string>
#include <array>
// Library headers
#include <catch2/catch.hpp>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/ostream_sink.h"
// Precompiled header
// Project headers
#include "utilities/logger.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if logger tests were find.
 */
TEST_CASE("Test if logger tests were find", "[logger]")
{
    REQUIRE(true);
}

/**
 * Test create_logger.
 */
TEST_CASE("create_logger", "[logger]")
{
    create_logger(false, false);

    create_logger(true, true);

    REQUIRE(true);
}

/**
 * Test log_program_arguments.
 */
TEST_CASE("log_program_arguments", "[logger]")
{
    std::ostringstream _oss;
    auto ostream_logger = spdlog::get("catch2_logger");
    if (!ostream_logger) {
        auto ostream_sink = std::make_shared<spdlog::sinks::ostream_sink_st>(_oss);
        ostream_logger = std::make_shared<spdlog::logger>("gtest_logger", ostream_sink);
        ostream_logger->set_pattern("%v");
        ostream_logger->set_level(spdlog::level::debug);
    }
    spdlog::set_default_logger(ostream_logger);

    const int argc = 1;
    std::array<const char*,argc> argv{ "test23" };
    log_program_arguments(argc, argv.data());

    const std::string test = _oss.str();
    auto result = test.find('0');

    REQUIRE(result != std::string::npos);
}

/**
 * Test log_program_information.
 */
TEST_CASE("log_program_information", "[logger]")
{
    std::ostringstream _oss;
    auto ostream_logger = spdlog::get("catch2_logger");
    if (!ostream_logger) {
        auto ostream_sink = std::make_shared<spdlog::sinks::ostream_sink_st>(_oss);
        ostream_logger = std::make_shared<spdlog::logger>("gtest_logger", ostream_sink);
        ostream_logger->set_pattern("%v");
        ostream_logger->set_level(spdlog::level::debug);
    }
    spdlog::set_default_logger(ostream_logger);

    log_program_information();

    const std::string test = _oss.str();
    auto result = test.find("MonteCarlo-BSE");

    REQUIRE(result != std::string::npos);
}
