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
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if constexpr tests were find", "[test]")
{
//   REQUIRE(false);
   REQUIRE(true);
}

constexpr unsigned int Factorial(unsigned int number)
{
  return number > 1 ? Factorial(number - 1) * number : 1;
}

TEST_CASE("Factorials are computed with constexpr", "[factorial]")
{
  STATIC_REQUIRE(Factorial(0) == 1);
  STATIC_REQUIRE(Factorial(1) == 1);
  STATIC_REQUIRE(Factorial(2) == 2);
  STATIC_REQUIRE(Factorial(3) == 6);
  STATIC_REQUIRE(Factorial(10) == 3628800);
}
