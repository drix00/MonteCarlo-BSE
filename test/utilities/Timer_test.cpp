/**
* @file
*
* @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
* @copyright 2022
*/

// C system headers
// C++ system header
#include <thread>
#include <chrono>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
#pragma hdrstop
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
