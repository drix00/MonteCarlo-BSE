/**
 * @file
 *
 * Tests for ProgramOptions.
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
#include <cstdlib>
// Library headers
#include <catch2/catch.hpp>
#include <spdlog/common.h>
// Precompiled header
// Project headers
#include "options/program_options.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if ProgramOptions tests were find.
 */
TEST_CASE("Test if ProgramOptions tests were find", "[options]")
{
    REQUIRE(true);
}

/**
 * Test ProgramOptions default constructor.
 */
TEST_CASE("ProgramOptions default constructor", "[options]")
{
    const ProgramOptions program_options;

    REQUIRE(program_options.input_file_name.empty());
    REQUIRE(program_options.output_file_name.empty());
    REQUIRE(program_options.display_version == false);
    REQUIRE(program_options.overwrite == false);
    REQUIRE(program_options.number_threads == 0);
    REQUIRE(program_options.exit_value == EXIT_SUCCESS);
    REQUIRE(program_options.console_logger == true);
    REQUIRE(program_options.console_logger_level == spdlog::level::warn);
    REQUIRE(program_options.file_logger == true);
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}
