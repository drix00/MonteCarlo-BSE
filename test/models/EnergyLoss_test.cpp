/**
 * @file
 *
 * Tests for EnergyLoss.
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
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "models/EnergyLoss.h"
// Project private headers

// Global and constant variables/functions.
/**
 * The absolute value by which a result can differ from Approx's value before it is rejected.
 */
constexpr double tolerance{0.01};

/**
 * Test if EnergyLoss tests were find.
 */
TEST_CASE("Test if EnergyLoss tests were find", "[test]")
{
    REQUIRE(true);
}

/**
 * EnergyLoss compute_mean_ionisation_potential_eV.
 */
TEST_CASE("EnergyLoss compute_mean_ionisation_potential_eV", "[models]")
{
    const EnergyLoss model{ 13, 26.98 };

    REQUIRE(model.compute_mean_ionisation_potential_eV() == Approx(162.8140881753).margin(tolerance)); // NOLINT
}

/**
 * EnergyLoss compute_bethe1933.
 */
TEST_CASE("EnergyLoss compute_bethe1933", "[models]")
{
    const EnergyLoss model{ 13, 26.98 };

    REQUIRE(model.compute_bethe1930(200.0) == Approx(-67949.0105710835).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_bethe1930(300.0) == Approx(-96420.8060125956).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_bethe1930(1000.0) == Approx(-74465.6875715554).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_bethe1930(10000.0) == Approx(-16155.9389847331).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_bethe1930(100000.0) == Approx(-2486.5309212311).margin(tolerance)); // NOLINT
}

/**
 * EnergyLoss compute_joy_luo1989.
 */
TEST_CASE("EnergyLoss compute_joy_luo1989", "[models]")
{
    const EnergyLoss model{ 13, 26.98 };

    //    REQUIRE(model.compute_joy_luo1989(1.0) == Approx(-167405.6897613208).margin(tolerance));
    REQUIRE(model.compute_joy_luo1989(10.0) == Approx(-230075.2937567497).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_joy_luo1989(50.0) == Approx(-226563.7595207261).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_joy_luo1989(200.0) == Approx(-167405.6897613208).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_joy_luo1989(300.0) == Approx(-144247.2503022708).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_joy_luo1989(1000.0) == Approx(-79368.3510660936).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_joy_luo1989(10000.0) == Approx(-16207.925895783).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_joy_luo1989(100000.0) == Approx(-2487.0540175087).margin(tolerance)); // NOLINT
}

/**
 * EnergyLoss compute_keV_g_cm2.
 */
TEST_CASE("EnergyLoss compute_keV_g_cm2", "[models]")
{
    const EnergyLoss model{ 13, 26.98 };

    //    REQUIRE(model.compute_joy_luo1989(1.0) == Approx(-167405.6897613208).margin(tolerance));
    REQUIRE(model.compute_keV_g_cm2(10.0) == Approx(-230075.2937567497).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_keV_g_cm2(50.0) == Approx(-226563.7595207261).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_keV_g_cm2(200.0) == Approx(-167405.6897613208).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_keV_g_cm2(300.0) == Approx(-144247.2503022708).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_keV_g_cm2(1000.0) == Approx(-79368.3510660936).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_keV_g_cm2(10000.0) == Approx(-16207.925895783).margin(tolerance)); // NOLINT
    REQUIRE(model.compute_keV_g_cm2(100000.0) == Approx(-2487.0540175087).margin(tolerance)); // NOLINT
}
