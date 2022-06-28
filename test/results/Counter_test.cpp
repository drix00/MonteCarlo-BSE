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
#include <cmath>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "results/Counter.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if Counter tests were find", "[test]")
{
   REQUIRE(true);
}

TEST_CASE("Counter variance", "[results]")
{
    Counter counter;

    counter.add_value(1);
    counter.add_value(2);
    counter.add_value(3);
    counter.add_value(4);
    counter.add_value(5);

    CHECK(counter.counts() == 5);
    CHECK(counter.min() == Approx(1.0).margin(0.0001));
    CHECK(counter.max() == Approx(5.0).margin(0.0001));
    CHECK(counter.mean() == Approx(3.0).margin(0.0001));
    CHECK(counter.variance() == Approx(0.4).margin(0.0001));
    CHECK(counter.standard_deviation() == Approx(0.632455532).margin(0.0001));
}

TEST_CASE("Counter bse", "[results]")
{
    Counter counter;

    counter.add_value(1);
    counter.add_value(1);
    counter.add_value(0);
    counter.add_value(0);
    counter.add_value(0);
    counter.add_value(1);
    counter.add_value(1);
    counter.add_value(0);
    counter.add_value(0);
    counter.add_value(0);

    double variance_ref = (0.4 * (1.0 - 0.4)) / 10.0;
    CHECK(counter.counts() == 10);
    CHECK(counter.min() == Approx(0.0).margin(0.0001));
    CHECK(counter.max() == Approx(1.0).margin(0.0001));
    CHECK(counter.mean() == Approx(0.4).margin(0.0001));
    CHECK(counter.variance() == Approx(variance_ref).margin(0.0001));
    CHECK(counter.standard_deviation() == Approx(std::sqrt(variance_ref)).margin(0.0001));
}
