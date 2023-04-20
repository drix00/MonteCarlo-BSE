/**
 * @file
 *
 * Tests for Material.
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
#include "sample/material.h"
// Project private headers

// Global and constant variables/functions.
/**
 * The absolute value by which a result can differ from Approx's value before it is rejected.
 */
constexpr double tolerance{ 0.0001 };

/**
 * Test if material tests were find.
 */
TEST_CASE("Test if material tests were find", "[material]")
{
    REQUIRE(true);
}

/**
 * Test Material constructor.
 */
TEST_CASE("Test Material constructor", "[material]")
{
    const Material material;

    REQUIRE(true);
}

/**
 * Test Material add single atomic number with weight fraction.
 */
TEST_CASE("Test Material add single atomic number with weight fraction", "[material]")
{
    Material material;

    REQUIRE(material.number_elements() == 0);
    const unsigned int atomic_number_ref{ 6U };
    material.add_atomic_number_with_weight_fraction(atomic_number_ref);
    REQUIRE(material.number_elements() == 1);
}

/**
 * Test Material add multiple atomic numbers with weight fraction.
 */
TEST_CASE("Test Material add multiple atomic numbers with weight fraction", "[material]")
{
    Material material;

    REQUIRE(material.number_elements() == 0);
    const unsigned int atomic_number_mg_ref{ 12U };
    material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.5);// NOLINT
    REQUIRE(material.number_elements() == 1);
    const unsigned int atomic_number_al_ref{ 13U };
    material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.5);// NOLINT
    REQUIRE(material.number_elements() == 2);
}

/**
 * Test Material add single atomic number with atomic fraction.
 */
TEST_CASE("Test Material add single atomic number with atomic fraction", "[material]")
{
    Material material;

    REQUIRE(material.number_elements() == 0);
    const unsigned int atomic_number_ref{ 6U };
    material.add_atomic_number_with_atomic_fraction(atomic_number_ref);
    REQUIRE(material.number_elements() == 1);
    REQUIRE(material.is_total_atomic_fraction_valid());
    REQUIRE(material.is_total_weight_fraction_valid());
}

/**
 * Test Material add multiple atomic numbers with atomic fraction.
 */
TEST_CASE("Test Material add multiple atomic numbers with atomic fraction", "[material]")
{
    Material material;

    REQUIRE(material.number_elements() == 0);
    const unsigned int atomic_number_mg_ref{ 12U };
    material.add_atomic_number_with_atomic_fraction(atomic_number_mg_ref, 0.5);// NOLINT
    REQUIRE(material.number_elements() == 1);
    REQUIRE(material.is_total_atomic_fraction_valid() == false);
    REQUIRE(material.is_total_weight_fraction_valid() == false);
    const unsigned int atomic_number_al_ref{ 13U };
    material.add_atomic_number_with_atomic_fraction(atomic_number_al_ref, 0.5);// NOLINT
    REQUIRE(material.number_elements() == 2);
    REQUIRE(material.is_total_atomic_fraction_valid());
    REQUIRE(material.is_total_weight_fraction_valid());
}

/**
 * Test Material is_total_weight_fraction_valid.
 */
TEST_CASE("Test Material is_total_weight_fraction_valid", "[material]")
{
    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.5);// NOLINT
        const unsigned int atomic_number_al_ref{ 13U };
        material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.5);// NOLINT

        REQUIRE(material.is_total_weight_fraction_valid());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_weight_fraction_valid());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 1.0 / 3.0, 1.0 / 3.0, 2.0 / 3.0 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_weight_fraction_valid() == false);
    }


    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 0.5, 0.1, 0.39999 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_weight_fraction_valid() == false);
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 0.5, 0.1, 0.39999, 0.00001 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_weight_fraction_valid());
    }
}

/**
 * Test Material mass_density_g_cm3.
 */
TEST_CASE("Test Material mass_density_g_cm3", "[material]")
{
    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.5);// NOLINT
        const unsigned int atomic_number_al_ref{ 13U };
        material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.5);// NOLINT
        const double mass_density_g_cm3_ref{ 2.1162162162 };

        REQUIRE(Approx(mass_density_g_cm3_ref).margin(tolerance) == material.mass_density_g_cm3());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 6U };
        material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.5);// NOLINT
        const unsigned int atomic_number_al_ref{ 48U };
        material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.5);// NOLINT
        const double mass_density_g_cm3_ref{ 3.5959167655 };

        REQUIRE(Approx(mass_density_g_cm3_ref).margin(tolerance) == material.mass_density_g_cm3());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 6U };
        material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.5);// NOLINT
        const unsigned int atomic_number_al_ref{ 48U };
        material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.6);// NOLINT

        REQUIRE(0.0 == material.mass_density_g_cm3());
    }


    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 6U };
        material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.5);// NOLINT
        const unsigned int atomic_number_al_ref{ 48U };
        material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.4);// NOLINT

        REQUIRE(0.0 == material.mass_density_g_cm3());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 6U };
        material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.1);// NOLINT
        const unsigned int atomic_number_al_ref{ 48U };
        material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.9);// NOLINT
        const double mass_density_g_cm3_ref{ 6.7714673633 };

        REQUIRE(Approx(mass_density_g_cm3_ref).margin(tolerance) == material.mass_density_g_cm3());
    }
}

/**
 * Test Material compute_atomic_fraction and compute_weight_fraction.
 */
TEST_CASE("Test Material compute_atomic_fraction and compute_weight_fraction", "[material]")
{
    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, 0.5);// NOLINT
        const unsigned int atomic_number_al_ref{ 13U };
        material.add_atomic_number_with_weight_fraction(atomic_number_al_ref, 0.5);// NOLINT

        REQUIRE(material.is_total_atomic_fraction_valid());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_atomic_fraction_valid());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 1.0 / 3.0, 1.0 / 3.0, 2.0 / 3.0 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_atomic_fraction_valid() == false);
        material.compute_atomic_fraction();
        REQUIRE(material.is_total_atomic_fraction_valid() == false);
    }


    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 0.5, 0.1, 0.39999 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_atomic_fraction_valid() == false);
        material.compute_atomic_fraction();
        REQUIRE(material.is_total_atomic_fraction_valid() == false);
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 0.5, 0.1, 0.39999, 0.00001 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_atomic_fraction_valid());
    }

    {
        Material material;
        const unsigned int atomic_number_mg_ref{ 12U };
        for (const double weight_fraction : { 0.5, 0.1, 0.39999, 0.00001 }) {// NOLINT
            material.add_atomic_number_with_weight_fraction(atomic_number_mg_ref, weight_fraction);
        }

        REQUIRE(material.is_total_atomic_fraction_valid());
        REQUIRE(material.is_total_weight_fraction_valid());

        material.compute_atomic_fraction();
        REQUIRE(material.is_total_atomic_fraction_valid());
        REQUIRE(material.is_total_weight_fraction_valid());

        material.compute_weight_fraction();
        REQUIRE(material.is_total_atomic_fraction_valid());
        REQUIRE(material.is_total_weight_fraction_valid());

        const int maximum_iteration{ 10 };
        for (int iteration = 0; iteration < maximum_iteration; ++iteration) {
            material.compute_atomic_fraction();
            REQUIRE(material.is_total_atomic_fraction_valid());
            REQUIRE(material.is_total_weight_fraction_valid());

            material.compute_weight_fraction();
            REQUIRE(material.is_total_atomic_fraction_valid());
            REQUIRE(material.is_total_weight_fraction_valid());
        }

        for (int iteration = 0; iteration < maximum_iteration; ++iteration) {
            material.compute_weight_fraction();
            REQUIRE(material.is_total_atomic_fraction_valid());
            REQUIRE(material.is_total_weight_fraction_valid());

            material.compute_atomic_fraction();
            REQUIRE(material.is_total_atomic_fraction_valid());
            REQUIRE(material.is_total_weight_fraction_valid());
        }
    }
}
