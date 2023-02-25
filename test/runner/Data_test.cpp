/**
 * @file
 *
 * Tests for Data.
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
#include "runner/Data.h"
#include "inputs/Input.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if Data tests were find.
 */
TEST_CASE("Test if Data tests were find", "[test]")
{
    REQUIRE(true);
}

/**
 * Test Data constructor.
 */
TEST_CASE("Test Data constructor", "[test]")
{
    const auto initial_energy_eV{ 10.0e3 };
    const auto number_trajectories{ 10000 };
    const auto thickness_nm{ 1.0e9 };

    const Input input{ get_au(), initial_energy_eV, number_trajectories };
    const std::string line{ "this is a line" };

    const Data data{ input, line };

    REQUIRE(data.input.initial_energy_eV == initial_energy_eV); // NOLINT
    REQUIRE(data.input.number_trajectories == number_trajectories); // NOLINT
    REQUIRE(data.input.thickness_nm == thickness_nm); // NOLINT

    REQUIRE(data.line == line);
}
