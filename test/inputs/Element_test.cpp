/**
* @file
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
