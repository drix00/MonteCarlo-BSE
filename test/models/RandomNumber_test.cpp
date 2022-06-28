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
#include "models/RandomNumber.h"
#include "results/Statistic.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if RandomNumber tests were find", "[test]")
{
   REQUIRE(true);
}

TEST_CASE("RandomNumber magic seed", "[models]")
{
    RandomNumber random_number{ RandomNumber::magic_seed };

    CHECK(random_number() == Approx(0.755155533).margin(0.0001));
    CHECK(random_number() == Approx(0.6390313939).margin(0.0001));
    CHECK(random_number() == Approx(0.7521452007).margin(0.0001));
    CHECK(random_number() == Approx(0.1362726836).margin(0.0001));
    CHECK(random_number() == Approx(0.9032689664).margin(0.0001));
    CHECK(random_number() == Approx(0.0940683118).margin(0.0001));
    CHECK(random_number() == Approx(0.5745703041).margin(0.0001));
    CHECK(random_number() == Approx(0.3728876995).margin(0.0001));
    CHECK(random_number() == Approx(0.2738741017).margin(0.0001));
    CHECK(random_number() == Approx(0.3902708814).margin(0.0001));
}

TEST_CASE("RandomNumber statistic 1M", "[models]")
{
    RandomNumber random_number{ RandomNumber::magic_seed };

    Statistic stats;
    int const number_values = 1000000;

    for (int i = 0; i < number_values; ++i) {
        stats.add_value(random_number());
    }

    CHECK(stats.counts() == number_values);
    CHECK(stats.min() == Approx(0.0000008088).margin(0.0001));
    CHECK(stats.max() == Approx(0.9999985263).margin(0.0001));
    CHECK(stats.mean() == Approx(0.5004564637).margin(0.0001));
    CHECK(stats.variance() == Approx(0.0832747386).margin(0.0001));
    CHECK(stats.standard_deviation() == Approx(0.2885736278).margin(0.0001));
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(0.0001));
    CHECK(stats.skewness() == Approx(-0.0028158571).margin(0.0001));
    CHECK(stats.kurtosis() == Approx(0.0).margin(0.0001));
}
