//
// Created by hendrix on 2020-06-07.
//
#include <catch2/catch.hpp>
#include <thread>
#include <chrono>

#include "utilities/Timer.h"

TEST_CASE("Timer sleep", "[utilities]")
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