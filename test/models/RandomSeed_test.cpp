//
// Created by Hendrix Demers on 2020-05-09.
//
#include <catch2/catch.hpp>
#include <spdlog/spdlog.h>
#include <random>
#include <thread>
#include <sstream>
#include <chrono>

#include "models/RandomSeed.h"

TEST_CASE("RandomSeed check log", "[models]")
{
    std::random_device device;

    spdlog::info("***********************************************************");
    spdlog::info("Random device entropy: {}", device.entropy());
    spdlog::info("Random device min    : {}", device.min());
    spdlog::info("Random device max    : {}", device.max());
    spdlog::info("Random device value 1: {}", device());
    spdlog::info("Random device value 2: {}", device());
    spdlog::info("Random device value 3: {}", device());
    spdlog::info("Random device value 4: {}", device());
    spdlog::info("Random device value 5: {}", device());

    std::ostringstream ss;
    ss << std::this_thread::get_id();
    spdlog::info("This thread id       : {}", ss.str());

    auto time_now{ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() };
    spdlog::info("Steady clock now     : {}", time_now);

    CHECK(true);
}


TEST_CASE("RandomSeed seed", "[models]")
{
    RandomSeed rand_seed;

    unsigned int long seed1 = rand_seed();
    unsigned int long seed2 = rand_seed();
    unsigned int long seed3 = rand_seed();
    unsigned int long seed4 = rand_seed();
    unsigned int long seed5 = rand_seed();

    CHECK(seed1 != seed2);
    CHECK(seed1 != seed3);
    CHECK(seed1 != seed4);
    CHECK(seed1 != seed5);

    CHECK(seed2 != seed3);
    CHECK(seed2 != seed4);
    CHECK(seed2 != seed5);

    CHECK(seed3 != seed4);
    CHECK(seed3 != seed5);

    CHECK(seed4 != seed5);
}
