//
// Created by Hendrix Demers on 2020-05-09.
//
#include <catch2/catch.hpp>

#include "simulation/Simulation.h"
#include "inputs/Input.h"
#include "inputs/Element.h"
#include "models/RandomNumber.h"

TEST_CASE("Simulation do_simulation C", "[simulation]")
{
    Input input{ get_c(), 10.0e3, 1000 };
    Simulation simulation{ input, RandomNumber::magic_seed };

    simulation.do_simulation();

    REQUIRE(simulation.bse.counts() == 1000);
    REQUIRE(simulation.bse.mean() == Approx(0.071).margin(0.0001));
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.256824843).margin(0.0001));
    REQUIRE(simulation.te.counts() == 1000);
    REQUIRE(simulation.te.mean() == Approx(0.0).margin(0.0001));
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0).margin(0.0001));
    REQUIRE(simulation.elapse_time_s() < 1.0);
}
