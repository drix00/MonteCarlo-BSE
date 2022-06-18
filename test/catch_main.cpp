/**
* @file
* Create the main for running the MonteCarlo-BSE Project tests.
* Also used to test if the catch2 test framework is working.
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
// Library headers
//#define CATCH_CONFIG_MAIN // This tells the catch header to generate a main
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
// Project headers
// Project private headers

// Global and constant variables/functions.

#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"

int main(int argc, char *argv[])
{
    // global setup...

    auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.log");
    spdlog::set_default_logger(file_logger);

    int result = Catch::Session().run(argc, argv);

    // global clean-up...

    return result;
}

TEST_CASE("Test if catch2 test framework is working", "[test_catch2]")
{
//    REQUIRE(false);
    REQUIRE(true);
}
