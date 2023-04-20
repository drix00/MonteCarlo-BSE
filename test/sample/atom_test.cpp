/**
 * @file
 *
 * Tests for Atom.
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2023
 */

//   Copyright 2023 Hendrix Demers
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
#include "sample/atom.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if Atom tests were find.
 */
TEST_CASE("Test if Atom tests were find", "[atom]")
{
    REQUIRE(true);
}

/**
 * Test Atom constructor.
 */
TEST_CASE("Test Atom constructor", "[atom]")
{
    const Atom atom(42);

    REQUIRE(42 == atom.get_atomic_number());
}

/**
 * Test Atom set/get_atomic_number.
 */
TEST_CASE("Test Atom set/get_atomic_number", "[atom]")
{
    Atom atom(0);
    REQUIRE(0 == atom.get_atomic_number());

    const unsigned int atomic_number_ref = 34;
    atom.set_atomic_number(atomic_number_ref);
    REQUIRE(atomic_number_ref == atom.get_atomic_number());
}

/**
 * Test Atom get_symbol.
 */
TEST_CASE("Test Atom get_symbol", "[atom]")
{
    const Atom atom(42);

    REQUIRE("Mo" == atom.get_symbol());
}

/**
 * Test Atom get_name.
 */
TEST_CASE("Test Atom get_name", "[atom]")
{
    const Atom atom(42);

    REQUIRE("Molybdenum" == atom.get_name());
}

/**
 * Test Atom get_atomic_weight_g_mol.
 */
TEST_CASE("Test Atom get_atomic_weight_g_mol", "[atom]")
{
    const Atom atom(42);
    const double atomic_weight_ref_g_mol = 95.94;

    REQUIRE(atomic_weight_ref_g_mol == atom.get_atomic_weight_g_mol());
}

/**
 * Test Atom get_atomic_mass_density_g_cm3.
 */
TEST_CASE("Test Atom get_atomic_mass_density_g_cm3", "[atom]")
{
    const Atom atom(42);
    const double atomic_mass_density_ref_g_cm3 = 10.22;

    REQUIRE(atomic_mass_density_ref_g_cm3 == atom.get_atomic_mass_density_g_cm3());
}

/**
 * Test Atom get_atomic_density_1_cm3 B.
 */
TEST_CASE("Test Atom get_atomic_density_1_cm3 B", "[atom]")
{
    const Atom atom(5);
    const double atomic_density_ref_1_cm3 = 130346955678475616256000.0;

    REQUIRE(atomic_density_ref_1_cm3 == atom.get_atomic_density_1_cm3());
}

/**
 * Test Atom get_atomic_density_1_cm3 C.
 */
TEST_CASE("Test Atom get_atomic_density_1_cm3 C", "[atom]")
{
    const Atom atom(6);
    const double atomic_density_ref_1_cm3 = 113666922851457440940032.0;

    REQUIRE(atomic_density_ref_1_cm3 == atom.get_atomic_density_1_cm3());
}

/**
 * Test Atom get_atomic_density_1_cm3 Mo.
 */
TEST_CASE("Test Atom get_atomic_density_1_cm3 Mo", "[atom]")
{
    const Atom atom(42);
    const double atomic_density_ref_1_cm3 = 64150801091515532705792.0;

    REQUIRE(atomic_density_ref_1_cm3 == atom.get_atomic_density_1_cm3());
}
