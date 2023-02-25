/**
 * @file
 *
 * Tests for Statistic.
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
#include "results/Statistic.h"
#include "models/RandomNumber.h"
// Project private headers

// Global and constant variables/functions.
/**
 * The absolute value by which a result can differ from Approx's value before it is rejected.
 */
constexpr double tolerance{0.0001};
/**
 * A smaller absolute value by which a result can differ from Approx's value before it is rejected.
 */
constexpr double smaller_tolerance{1.0e-6};

/**
 * Test if Statistic tests were find.
 */
TEST_CASE("Test if Statistic tests were find", "[test]")
{
    REQUIRE(true);
}

/**
 * Test Statistic random counts.
 */
TEST_CASE("Statistic random counts", "[results]")
{
    RandomNumber random_number{ RandomNumber::magic_seed };

    Statistic stats;
    int const number_values = 20;

    for (int i = 0; i < number_values; ++i) { // NOLINT
        stats.add_value(random_number());
    }

    CHECK(stats.counts() == 20);
    CHECK(stats.min() == Approx(0.0123827711).margin(tolerance)); // NOLINT
    CHECK(stats.max() == Approx(0.9456984866).margin(tolerance)); // NOLINT
    CHECK(stats.mean() == Approx(0.4918011615).margin(tolerance)); // NOLINT
    CHECK(stats.variance() == Approx(0.0874879358).margin(tolerance)); // NOLINT
    CHECK(stats.standard_deviation() == Approx(0.2957835963).margin(tolerance)); // NOLINT
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(tolerance)); // NOLINT
    CHECK(stats.skewness() == Approx(-0.2486961137).margin(tolerance)); // NOLINT
    CHECK(stats.kurtosis() == Approx(0.0).margin(tolerance)); // NOLINT
}

/**
 * Test Statistic skewness.
 */
TEST_CASE("Statistic skewness", "[results]")
{
    Statistic stats;

    stats.add_value(2);
    stats.add_value(7); // NOLINT
    stats.add_value(4);
    stats.add_value(9); // NOLINT
    stats.add_value(3);

    CHECK(stats.counts() == 5);
    CHECK(stats.min() == Approx(2.0).margin(tolerance)); // NOLINT
    CHECK(stats.max() == Approx(9.0).margin(tolerance)); // NOLINT
    CHECK(stats.mean() == Approx(5.0).margin(tolerance)); // NOLINT
    CHECK(stats.variance() == Approx(6.8).margin(tolerance)); // NOLINT
    CHECK(stats.standard_deviation() == Approx(2.6076809621).margin(tolerance)); // NOLINT
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(tolerance));
    CHECK(stats.skewness() == Approx(0.406040288214).margin(smaller_tolerance)); // NOLINT
    CHECK(stats.kurtosis() == Approx(0.0).margin(tolerance));
}

/**
 * Test Statistic variance.
 */
TEST_CASE("Statistic variance", "[results]")
{
    Statistic stats;

    stats.add_value(1);
    stats.add_value(2);
    stats.add_value(3);
    stats.add_value(4);
    stats.add_value(5); // NOLINT

    CHECK(stats.counts() == 5);
    CHECK(stats.min() == Approx(1.0).margin(tolerance));
    CHECK(stats.max() == Approx(5.0).margin(tolerance)); // NOLINT
    CHECK(stats.mean() == Approx(3.0).margin(tolerance)); // NOLINT
    CHECK(stats.variance() == Approx(2.0).margin(tolerance)); // NOLINT
    CHECK(stats.standard_deviation() == Approx(1.4142135624).margin(tolerance)); // NOLINT
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(tolerance));
    CHECK(stats.skewness() == Approx(0.0).margin(smaller_tolerance));
    CHECK(stats.kurtosis() == Approx(0.0).margin(tolerance));
}
