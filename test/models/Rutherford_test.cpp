/**
 * @file
 *
 * Tests for Rutherford.
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
#define _USE_MATH_DEFINES // NOLINT
#include <cmath>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "models/Rutherford.h"
// Project private headers

// Global and constant variables/functions.
/**
 * The coefficient by which a result can differ from Approx's value before it is rejected.
 */
constexpr double epsilon{0.01};

/**
 * Test if Rutherford tests were find.
 */
TEST_CASE("Test if Rutherford tests were find", "[test]")
{
    REQUIRE(true);
}

/**
 * Test Rutherford compute_alpha.
 */
TEST_CASE("Rutherford compute_alpha", "[models]")
{
    const Rutherford model{ 13 };

    REQUIRE(model.compute_alpha(1000.0) == Approx(0.0189592417).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_alpha(10000.0) == Approx(0.0018959242).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_alpha(100000.0) == Approx(0.0001895924).epsilon(epsilon)); // NOLINT
}

/**
 * Test Rutherford compute_sigma_nm2.
 */
TEST_CASE("Rutherford compute_sigma_nm2", "[models]")
{
    const Rutherford model{ 13 };

    REQUIRE(model.compute_sigma_nm2(1000.0) == Approx(0.0142905422).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_sigma_nm2(10000.0) == Approx(0.0014788533).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_sigma_nm2(100000.0) == Approx(0.0001724173).epsilon(epsilon)); // NOLINT
}

/**
 * Test Rutherford compute_scattering_angle_rad.
 */
TEST_CASE("Rutherford compute_scattering_angle_rad", "[models]")
{
    const Rutherford model{ 13 };

    REQUIRE(model.compute_scattering_angle_rad(10000.0, 0.0) == Approx(0.0).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 0.1) == Approx(0.0289986301).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 0.5) == Approx(0.0869471704).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 1.0) == Approx(3.1415924959).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 1.0) == Approx(M_PI).epsilon(epsilon)); // NOLINT
}

/**
 * Test Rutherford compute_azimuthal_angle_rad.
 */
TEST_CASE("Rutherford compute_azimuthal_angle_rad", "[models]")
{
    const Rutherford model{ 13 };

    REQUIRE(model.compute_azimuthal_angle_rad(0.0) == Approx(0.0).epsilon(epsilon));
    REQUIRE(model.compute_azimuthal_angle_rad(0.1) == Approx(0.6283185307).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_azimuthal_angle_rad(0.5) == Approx(3.1415926536).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_azimuthal_angle_rad(1.0) == Approx(6.2831853072).epsilon(epsilon)); // NOLINT
    REQUIRE(model.compute_azimuthal_angle_rad(1.0) == Approx(2.0 * M_PI).epsilon(epsilon)); // NOLINT
}
