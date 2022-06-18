/**
* @file
*
* @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
* @copyright 2022
*/

// C system headers
// C++ system header
#define _USE_MATH_DEFINES
#include <cmath>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
#pragma hdrstop
// Project headers
#include "models/Rutherford.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if Rutherford tests were find", "[test]")
{
   REQUIRE(true);
}

TEST_CASE("Rutherford compute_alpha", "[models]")
{
    Rutherford model{ 13 };

    REQUIRE(model.compute_alpha(1000.0) == Approx(0.0189592417).epsilon(0.01));
    REQUIRE(model.compute_alpha(10000.0) == Approx(0.0018959242).epsilon(0.01));
    REQUIRE(model.compute_alpha(100000.0) == Approx(0.0001895924).epsilon(0.01));
}

TEST_CASE("Rutherford compute_sigma_nm2", "[models]")
{
    Rutherford model{ 13 };

    REQUIRE(model.compute_sigma_nm2(1000.0) == Approx(0.0142905422).epsilon(0.01));
    REQUIRE(model.compute_sigma_nm2(10000.0) == Approx(0.0014788533).epsilon(0.01));
    REQUIRE(model.compute_sigma_nm2(100000.0) == Approx(0.0001724173).epsilon(0.01));
}

TEST_CASE("Rutherford compute_scattering_angle_rad", "[models]")
{
    Rutherford model{ 13 };

    REQUIRE(model.compute_scattering_angle_rad(10000.0, 0.0) == Approx(0.0).epsilon(0.01));
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 0.1) == Approx(0.0289986301).epsilon(0.01));
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 0.5) == Approx(0.0869471704).epsilon(0.01));
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 1.0) == Approx(3.1415924959).epsilon(0.01));
    REQUIRE(model.compute_scattering_angle_rad(10000.0, 1.0) == Approx(M_PI).epsilon(0.01));
}

TEST_CASE("Rutherford compute_azimuthal_angle_rad", "[models]")
{
    Rutherford model{ 13 };

    REQUIRE(model.compute_azimuthal_angle_rad(0.0) == Approx(0.0).epsilon(0.01));
    REQUIRE(model.compute_azimuthal_angle_rad(0.1) == Approx(0.6283185307).epsilon(0.01));
    REQUIRE(model.compute_azimuthal_angle_rad(0.5) == Approx(3.1415926536).epsilon(0.01));
    REQUIRE(model.compute_azimuthal_angle_rad(1.0) == Approx(6.2831853072).epsilon(0.01));
    REQUIRE(model.compute_azimuthal_angle_rad(1.0) == Approx(2.0 * M_PI).epsilon(0.01));
}
