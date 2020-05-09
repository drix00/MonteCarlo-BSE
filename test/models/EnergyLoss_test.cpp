//
// Created by Hendrix Demers on 2020-05-08.
//
#include <catch2/catch.hpp>

#include "models/EnergyLoss.h"

TEST_CASE("EnergyLoss compute_mean_ionisation_potential_eV", "[models]")
{
    EnergyLoss model{ 13, 26.98 };

    REQUIRE(model.compute_mean_ionisation_potential_eV() == Approx(162.8140881753).margin(0.01));
}

TEST_CASE("EnergyLoss compute_bethe1933", "[models]")
{
    EnergyLoss model{ 13, 26.98 };

    REQUIRE(model.compute_bethe1930(200.0) == Approx(-67949.0105710835).margin(0.01));
    REQUIRE(model.compute_bethe1930(300.0) == Approx(-96420.8060125956).margin(0.01));
    REQUIRE(model.compute_bethe1930(1000.0) == Approx(-74465.6875715554).margin(0.01));
    REQUIRE(model.compute_bethe1930(10000.0) == Approx(-16155.9389847331).margin(0.01));
    REQUIRE(model.compute_bethe1930(100000.0) == Approx(-2486.5309212311).margin(0.01));
}

TEST_CASE("EnergyLoss compute_joy_luo1989", "[models]")
{
    EnergyLoss model{ 13, 26.98 };

    //    REQUIRE(model.compute_joy_luo1989(1.0) == Approx(-167405.6897613208).margin(0.01));
    REQUIRE(model.compute_joy_luo1989(10.0) == Approx(-230075.2937567497).margin(0.01));
    REQUIRE(model.compute_joy_luo1989(50.0) == Approx(-226563.7595207261).margin(0.01));
    REQUIRE(model.compute_joy_luo1989(200.0) == Approx(-167405.6897613208).margin(0.01));
    REQUIRE(model.compute_joy_luo1989(300.0) == Approx(-144247.2503022708).margin(0.01));
    REQUIRE(model.compute_joy_luo1989(1000.0) == Approx(-79368.3510660936).margin(0.01));
    REQUIRE(model.compute_joy_luo1989(10000.0) == Approx(-16207.925895783).margin(0.01));
    REQUIRE(model.compute_joy_luo1989(100000.0) == Approx(-2487.0540175087).margin(0.01));
}

TEST_CASE("EnergyLoss compute_keV_g_cm2", "[models]")
{
    EnergyLoss model{ 13, 26.98 };

    //    REQUIRE(model.compute_joy_luo1989(1.0) == Approx(-167405.6897613208).margin(0.01));
    REQUIRE(model.compute_keV_g_cm2(10.0) == Approx(-230075.2937567497).margin(0.01));
    REQUIRE(model.compute_keV_g_cm2(50.0) == Approx(-226563.7595207261).margin(0.01));
    REQUIRE(model.compute_keV_g_cm2(200.0) == Approx(-167405.6897613208).margin(0.01));
    REQUIRE(model.compute_keV_g_cm2(300.0) == Approx(-144247.2503022708).margin(0.01));
    REQUIRE(model.compute_keV_g_cm2(1000.0) == Approx(-79368.3510660936).margin(0.01));
    REQUIRE(model.compute_keV_g_cm2(10000.0) == Approx(-16207.925895783).margin(0.01));
    REQUIRE(model.compute_keV_g_cm2(100000.0) == Approx(-2487.0540175087).margin(0.01));
}
