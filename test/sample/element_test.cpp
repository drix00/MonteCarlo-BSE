/**
 * @file
 *
 * Tests for Element.
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
#include "sample/element.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if sample Element tests were find.
 */
TEST_CASE("Test if sample Element tests were find", "[element]")
{
    REQUIRE(true);
}

/**
 * Test sample Element constructor.
 */
TEST_CASE("Test sample Element constructor", "[element]")// NOLINT
{
    const unsigned int atomic_number_ref = 42;
    const double weight_fraction_ref = 0.8;
    const Element element{ atomic_number_ref, weight_fraction_ref };

    REQUIRE(atomic_number_ref == element.get_atomic_number());// NOLINT
    REQUIRE(weight_fraction_ref == element.get_weight_fraction());// NOLINT
    REQUIRE(0.0 == element.get_atomic_fraction());
}

/**
 * Test Element get_atomic_density_1_cm3 B.
 */
TEST_CASE("Test Element get_atomic_density_1_cm3 B", "[element]")// NOLINT
{
    const unsigned int atomic_number_ref = 5;
    const Element element{ atomic_number_ref, 1.0 };
    const double atomic_density_ref_1_cm3 = 130346955678475616256000.0;

    REQUIRE(atomic_density_ref_1_cm3 == element.get_atomic_density_1_cm3());
}
