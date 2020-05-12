//
// Created by Hendrix Demers on 2020-05-09.
//
#include <catch2/catch.hpp>

#include "simulation/Simulation.h"
#include "inputs/Input.h"
#include "inputs/Element.h"
#include "models/RandomNumber.h"
#include "models/RandomSeed.h"

TEST_CASE("Simulation do_simulation C", "[simulation]")
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    Input input{ get_c(), initial_energy_eV, number_trajectories };
    Simulation simulation{ input, RandomNumber::magic_seed };

    simulation.do_simulation();

    double const tolerance = 0.0001;
    REQUIRE(simulation.bse.counts() == number_trajectories);
    REQUIRE(simulation.bse.mean() == Approx(0.071).margin(tolerance));
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.0081215146).margin(tolerance));
    REQUIRE(simulation.te.counts() == number_trajectories);
    REQUIRE(simulation.te.mean() == Approx(0.0).margin(tolerance));
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0).margin(tolerance));
    REQUIRE(simulation.elapse_time_s() < 10.0);
}

TEST_CASE("Simulation do_simulation random seed", "[simulation]")
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    Input input{ get_c(), initial_energy_eV, number_trajectories };

    RandomSeed rand_seed;
    Simulation simulation1{ input, rand_seed() };
    Simulation simulation2{ input, rand_seed() };
    Simulation simulation3{ input, rand_seed() };
    Simulation simulation4{ input, rand_seed() };
    Simulation simulation5{ input, rand_seed() };

    simulation1.do_simulation();
    simulation2.do_simulation();
    simulation3.do_simulation();
    simulation4.do_simulation();
    simulation5.do_simulation();

    double const tolerance = 0.0001;
    CHECK(simulation1.bse.mean() != Approx(simulation2.bse.mean()).margin(tolerance));
    CHECK(simulation1.bse.mean() != Approx(simulation3.bse.mean()).margin(tolerance));
    CHECK(simulation1.bse.mean() != Approx(simulation4.bse.mean()).margin(tolerance));
    CHECK(simulation1.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));

    CHECK(simulation2.bse.mean() != Approx(simulation3.bse.mean()).margin(tolerance));
    CHECK(simulation2.bse.mean() != Approx(simulation4.bse.mean()).margin(tolerance));
    CHECK(simulation2.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));

    CHECK(simulation3.bse.mean() != Approx(simulation4.bse.mean()).margin(tolerance));
    CHECK(simulation3.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));

    CHECK(simulation4.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));
}
