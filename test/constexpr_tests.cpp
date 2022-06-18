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
