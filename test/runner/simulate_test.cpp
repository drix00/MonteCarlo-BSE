/**
 * @file
 *
 * Tests for runner/simulate.cpp and runner/simulate.h.
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
#include <string>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "runner/simulate.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if simulate tests were find.
 */
TEST_CASE("Test if simulate tests were find", "[test]")
{
    REQUIRE(true);
}

/**
 * Test get_suffix.
 */
TEST_CASE("Test get_suffix", "[test]")
{
    const std::string suffix = get_suffix();

    REQUIRE(suffix.empty() == false);
    REQUIRE(suffix.size() == 16);
}
