/**
 * @file
 *
 * Tests for Simulation.
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
#include "simulation/Simulation.h"
#include "models/RandomSeed.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if Simulation tests were find.
 */
TEST_CASE("Test if Simulation tests were find", "[simulation]")
{
    REQUIRE(true);
}

/**
 * Test Simulation do_simulation C.
 */
TEST_CASE("Simulation do_simulation C", "[simulation]")// NOLINT
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    const Input input{ get_c(), initial_energy_eV, number_trajectories };
    Simulation simulation{ input, RandomNumber::magic_seed };

    simulation.do_simulation();

    double const tolerance = 0.0001;
    REQUIRE(simulation.bse.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.bse.mean() == Approx(0.071).margin(tolerance));// NOLINT
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.0081215146).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.te.mean() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.elapse_time_s() < 10.0);// NOLINT
}

/**
 * Test Simulation do_simulation random seed.
 */
TEST_CASE("Simulation do_simulation random seed", "[simulation] [!mayfail]")// NOLINT
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    const Input input{ get_cu(), initial_energy_eV, number_trajectories };

    RandomSeed rand_seed;

    Simulation simulation1{ input, rand_seed() };
    simulation1.do_simulation();

    Simulation simulation2{ input, rand_seed() };
    simulation2.do_simulation();

    Simulation simulation3{ input, rand_seed() };
    simulation3.do_simulation();

    Simulation simulation4{ input, rand_seed() };
    simulation4.do_simulation();

    Simulation simulation5{ input, rand_seed() };
    simulation5.do_simulation();

    double const tolerance = 0.0001;
    CHECK(simulation1.bse.mean() != Approx(simulation2.bse.mean()).margin(tolerance));// NOLINT
    CHECK(simulation1.bse.mean() != Approx(simulation3.bse.mean()).margin(tolerance));// NOLINT
    CHECK(simulation1.bse.mean() != Approx(simulation4.bse.mean()).margin(tolerance));// NOLINT
    CHECK(simulation1.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));// NOLINT

    CHECK(simulation2.bse.mean() != Approx(simulation3.bse.mean()).margin(tolerance));// NOLINT
    CHECK(simulation2.bse.mean() != Approx(simulation4.bse.mean()).margin(tolerance));// NOLINT
    CHECK(simulation2.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));// NOLINT

    CHECK(simulation3.bse.mean() != Approx(simulation4.bse.mean()).margin(tolerance));// NOLINT
    CHECK(simulation3.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));// NOLINT

    CHECK(simulation4.bse.mean() != Approx(simulation5.bse.mean()).margin(tolerance));
}

/**
 * Test Simulation do_simulation C thin film.
 */
TEST_CASE("Simulation do_simulation C thin film", "[simulation]")// NOLINT
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    Input input{ get_c(), initial_energy_eV, number_trajectories };
    input.thickness_nm = 100.0;
    Simulation simulation{ input, RandomNumber::magic_seed };

    simulation.do_simulation();

    double const tolerance = 0.0001;
    REQUIRE(simulation.bse.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.bse.mean() == Approx(0.011).margin(tolerance));// NOLINT
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.0032983329).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.te.mean() == Approx(0.988).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0034432543).margin(tolerance));// NOLINT
    REQUIRE(simulation.elapse_time_s() < 10.0);// NOLINT
}

/**
 * Test Simulation do_simulation C thin film with 25 eV.
 */
TEST_CASE("Simulation do_simulation C thin film with 25 eV", "[simulation]")// NOLINT
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    Input input{ get_c(), initial_energy_eV, number_trajectories };
    input.thickness_nm = 100.0;
    Simulation simulation{ input, RandomNumber::magic_seed };
    simulation.set_minimum_energy_eV(25.0);// NOLINT

    simulation.do_simulation();

    double const tolerance = 0.0001;
    REQUIRE(simulation.bse.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.bse.mean() == Approx(0.011).margin(tolerance));// NOLINT
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.0032983329).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.te.mean() == Approx(0.988).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0034432543).margin(tolerance));// NOLINT
    REQUIRE(simulation.elapse_time_s() < 10.0);// NOLINT
}

/**
 * Test Simulation do_simulation C very thin film.
 */
TEST_CASE("Simulation do_simulation C very thin film", "[simulation]")// NOLINT
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    Input input{ get_c(), initial_energy_eV, number_trajectories };
    input.thickness_nm = 1.0;
    Simulation simulation{ input, RandomNumber::magic_seed };

    simulation.do_simulation();

    double const tolerance = 0.0001;
    REQUIRE(simulation.bse.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.bse.mean() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.te.mean() == Approx(1.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.elapse_time_s() < 10.0);// NOLINT
}

/**
 * Test Simulation do_simulation C very small width.
 */
TEST_CASE("Simulation do_simulation C very small width", "[simulation]")// NOLINT
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    Input input{ get_c(), initial_energy_eV, number_trajectories };
    input.thickness_nm = 100.0;
    Simulation simulation{ input, RandomNumber::magic_seed };

    simulation.set_max_lateral_distance_nm(1.0);

    simulation.do_simulation();

    double const tolerance = 0.0001;
    REQUIRE(simulation.bse.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.bse.mean() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.te.mean() == Approx(0.028).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0052168956).margin(tolerance));// NOLINT
    REQUIRE(simulation.elapse_time_s() < 10.0);// NOLINT
}

/**
 * Test Simulation do_simulation C no width.
 */
TEST_CASE("Simulation do_simulation C no width", "[simulation]")// NOLINT
{
    int const number_trajectories = 1000;
    double const initial_energy_eV = 10.0e3;
    Input input{ get_c(), initial_energy_eV, number_trajectories };
    input.thickness_nm = 100.0;
    Simulation simulation{ input, RandomNumber::magic_seed };

    simulation.set_max_lateral_distance_nm(0.0);

    simulation.do_simulation();

    double const tolerance = 0.0001;
    REQUIRE(simulation.bse.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.bse.mean() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.bse.standard_deviation() == Approx(0.0).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.counts() == number_trajectories);// NOLINT
    REQUIRE(simulation.te.mean() == Approx(0.008).margin(tolerance));// NOLINT
    REQUIRE(simulation.te.standard_deviation() == Approx(0.0028170907).margin(tolerance));// NOLINT
    REQUIRE(simulation.elapse_time_s() < 10.0);// NOLINT
}
