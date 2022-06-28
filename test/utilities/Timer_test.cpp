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
#include <thread>
#include <chrono>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "utilities/Timer.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if Timer tests were find", "[test]")
{
   REQUIRE(true);
}

TEST_CASE("Timer sleep", "[utilities] [!mayfail]")
{
    Timer timer;
    std::this_thread::sleep_for (std::chrono::milliseconds (100));
    double elapse_time1_s = timer.get_elapse_time_s();
    std::this_thread::sleep_for (std::chrono::milliseconds(500));
    double elapse_time2_s = timer.get_elapse_time_s();
    double total_elapse_time_s = timer.get_total_elapse_time_s();

    const double tolerance = 0.01;
    CHECK(elapse_time1_s == Approx(0.1).margin(tolerance));
    CHECK(elapse_time2_s == Approx(0.5).margin(tolerance));
    CHECK(total_elapse_time_s == Approx(0.6).margin(tolerance));
}
