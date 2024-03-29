/**
 * @file
 *
 * Tests for runner/inputs.cpp and runner/inputs.h.
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
#include <vector>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "runner/inputs.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if inputs tests were find.
 */
TEST_CASE("Test if inputs tests were find", "[test]")
{
    REQUIRE(true);
}

/**
 * Test get_inputs_number_trajectories_repetitions.
 */
TEST_CASE("Test get_inputs_number_trajectories_repetitions", "[test]")
{
    const std::vector<Data> data_list = get_inputs_number_trajectories_repetitions();

    REQUIRE(data_list.size() == 60);
}

/**
 * Test get_inputs_elements_energies.
 */
TEST_CASE("Test get_inputs_elements_energies", "[test]")
{
    const std::vector<Data> data_list = get_inputs_elements_energies();

    REQUIRE(data_list.size() == 91);
}

/**
 * Test get_inputs_atomic_numbers.
 */
TEST_CASE("Test get_inputs_atomic_numbers", "[test]")
{
    const std::vector<Data> data_list = get_inputs_atomic_numbers();

    REQUIRE(data_list.size() == 96);
}

/**
 * Test get_inputs_densities.
 */
TEST_CASE("Test get_inputs_densities", "[test]")
{
    const std::vector<Data> data_list = get_inputs_densities();

    REQUIRE(data_list.size() == 210);
}

/**
 * Test get_inputs_thickness.
 */
TEST_CASE("Test get_inputs_thickness", "[test]")
{
    const std::vector<Data> data_list = get_inputs_thickness();

    REQUIRE(data_list.size() == 154);
}

/**
 * Test get_inputs_profile_serial_simple.
 */
TEST_CASE("Test get_inputs_profile_serial_simple", "[test]")
{
    const std::vector<Data> data_list = get_inputs_profile_serial_simple();

    REQUIRE(data_list.size() == 10);
}

/**
 * Test get_inputs_valgrind.
 */
TEST_CASE("Test get_inputs_valgrind", "[test]")
{
    const std::vector<Data> data_list = get_inputs_valgrind();

    REQUIRE(data_list.size() == 1);
}
