/**
 * @file
 *
 * Tests for InputElement.
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
#include "inputs/InputElement.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if InputElement tests were find.
 */
TEST_CASE("Test if InputElement tests were find", "[inputs]")
{
    REQUIRE(true);
}

/**
 * get_c are tested.
 */
TEST_CASE("get_c are tested", "[inputs]")
{
    const InputElement element = get_c();
    REQUIRE(element.atomic_number == 6);
    REQUIRE(element.atomic_weight_g_mol == 12.011);// NOLINT
    REQUIRE(element.density_g_cm3 == 2.62);// NOLINT
}

/**
 * get_al are tested.
 */
TEST_CASE("get_al are tested", "[inputs]")
{
    const InputElement element = get_al();
    REQUIRE(element.atomic_number == 13);
    REQUIRE(element.atomic_weight_g_mol == 26.98);// NOLINT
    REQUIRE(element.density_g_cm3 == 2.7);// NOLINT
}

/**
 * get_si are tested.
 */
TEST_CASE("get_si are tested", "[inputs]")
{
    const InputElement element = get_si();
    REQUIRE(element.atomic_number == 14);
    REQUIRE(element.atomic_weight_g_mol == 28.09);// NOLINT
    REQUIRE(element.density_g_cm3 == 2.33);// NOLINT
}

/**
 * get_fe are tested.
 */
TEST_CASE("get_fe are tested", "[inputs]")
{
    const InputElement element = get_fe();
    REQUIRE(element.atomic_number == 26);
    REQUIRE(element.atomic_weight_g_mol == 55.85);// NOLINT
    REQUIRE(element.density_g_cm3 == 7.86);// NOLINT
}

/**
 * get_cu are tested.
 */
TEST_CASE("get_cu are tested", "[inputs]")
{
    const InputElement element = get_cu();
    REQUIRE(element.atomic_number == 29);
    REQUIRE(element.atomic_weight_g_mol == 63.55);// NOLINT
    REQUIRE(element.density_g_cm3 == 8.96);// NOLINT
}

/**
 * get_ag are tested.
 */
TEST_CASE("get_ag are tested", "[inputs]")
{
    const InputElement element = get_ag();
    REQUIRE(element.atomic_number == 47);
    REQUIRE(element.atomic_weight_g_mol == 107.87);// NOLINT
    REQUIRE(element.density_g_cm3 == 10.5);// NOLINT
}

/**
 * get_au are tested.
 */
TEST_CASE("get_au are tested", "[inputs]")
{
    const InputElement element = get_au();
    REQUIRE(element.atomic_number == 79);
    REQUIRE(element.atomic_weight_g_mol == 196.97);// NOLINT
    REQUIRE(element.density_g_cm3 == 19.3);// NOLINT
}
