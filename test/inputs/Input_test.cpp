/**
 * @file
 *
 * Tests for Input.
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2023
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
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "inputs/Input.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if Input tests were find.
 */
TEST_CASE("Test if Input tests were find", "[inputs]")
{
    REQUIRE(true);
}

/**
 * Input are tested.
 */
TEST_CASE("Input are tested", "[inputs]")// NOLINT
{
    const auto initial_energy_eV{ 10.0e3 };
    const auto number_trajectories{ 10000 };
    const auto thickness_nm{ 1.0e9 };

    const Input input{ get_au(), initial_energy_eV, number_trajectories };

    REQUIRE(input.initial_energy_eV == initial_energy_eV);// NOLINT
    REQUIRE(input.number_trajectories == number_trajectories);// NOLINT
    REQUIRE(input.thickness_nm == thickness_nm);// NOLINT

    const auto atomic_number{ 79 };
    const auto atomic_weight_g_mol{ 196.97 };
    const auto density_g_cm3{ 19.3 };

    REQUIRE(input.element.atomic_number == atomic_number);// NOLINT
    REQUIRE(input.element.atomic_weight_g_mol == atomic_weight_g_mol);// NOLINT
    REQUIRE(input.element.density_g_cm3 == density_g_cm3);// NOLINT
}
