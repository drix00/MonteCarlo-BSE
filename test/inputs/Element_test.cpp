//
// Created by Hendrix Demers on 2020-05-08.
//
#include <catch2/catch.hpp>

#include "inputs/Element.h"

TEST_CASE("Element are tested", "[inputs]")
{
    Element element = get_ag();
    REQUIRE(element.atomic_number == 47);
    REQUIRE(element.atomic_weight_g_mol == 107.87);
    REQUIRE(element.density_g_cm3 == 10.5);
}
