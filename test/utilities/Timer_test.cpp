/**
 * @file
 *
 * Test for Timer.
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
#include <thread>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "utilities/Timer.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if Timer tests were find.
 */
TEST_CASE("Test if Timer tests were find", "[test]")
{
    REQUIRE(true);
}

/**
 * Test Timer sleep.
 */
TEST_CASE("Timer sleep", "[utilities] [!mayfail]")
{
    const double elapse_time1_ref_s{0.1};
    const double elapse_time2_ref_s{0.5};
    const double elapse_time_total_ref_s{elapse_time1_ref_s + elapse_time2_ref_s};
    const long long s2ns{1000};

    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(elapse_time1_ref_s * s2ns)));
    const double elapse_time1_s = timer.get_elapse_time_s();
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(elapse_time2_ref_s * s2ns)));
    const double elapse_time2_s = timer.get_elapse_time_s();
    const double total_elapse_time_s = timer.get_total_elapse_time_s();

    const double tolerance = 0.01;
    CHECK(elapse_time1_s == Approx(elapse_time1_ref_s).margin(tolerance)); // NOLINT
    CHECK(elapse_time2_s == Approx(elapse_time2_ref_s).margin(tolerance)); // NOLINT
    CHECK(total_elapse_time_s == Approx(elapse_time_total_ref_s).margin(tolerance));
}
