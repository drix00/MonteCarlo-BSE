/**
* @file
*
* @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
* @copyright 2022
*/

// C system headers
// C++ system header
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
#pragma hdrstop
// Project headers
#include "inputs/Element.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if Element tests were find", "[test]")
{
   REQUIRE(true);
}

TEST_CASE("Element are tested", "[inputs]")
{
    Element element = get_ag();
    REQUIRE(element.atomic_number == 47);
    REQUIRE(element.atomic_weight_g_mol == 107.87);
    REQUIRE(element.density_g_cm3 == 10.5);
}
