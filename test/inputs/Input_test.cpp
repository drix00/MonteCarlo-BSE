//
// Created by Hendrix Demers on 2020-05-08.
//
#include <catch2/catch.hpp>

#include "inputs/Input.h"
#include "inputs/Element.h"

TEST_CASE("Input are tested", "[inputs]")
{
    Input input{ get_au(), 10.0e3, 10000 };

    REQUIRE(input.element.atomic_number == 79);
    REQUIRE(input.element.atomic_weight_g_mol == 196.97);
    REQUIRE(input.element.density_g_cm3 == 19.3);

    REQUIRE(input.initial_energy_eV == 10000.0);
    REQUIRE(input.number_trajectories == 10000);
    REQUIRE(input.thickness_nm == 1.0e9);
}
