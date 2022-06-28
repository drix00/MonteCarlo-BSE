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
#include <random>
#include <thread>
#include <sstream>
#include <chrono>
// Library headers
#include <catch2/catch.hpp>
#include <spdlog/spdlog.h>
// Precompiled header
// Project headers
#include "models/RandomSeed.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if RandomSeed tests were find", "[test]")
{
   REQUIRE(true);
}

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
    unsigned int long seed6 = rand_seed();
    unsigned int long seed7 = rand_seed();
    unsigned int long seed8 = rand_seed();
    unsigned int long seed9 = rand_seed();
    unsigned int long seed10 = rand_seed();

    CHECK(seed1 != seed2);
    CHECK(seed1 != seed3);
    CHECK(seed1 != seed4);
    CHECK(seed1 != seed5);
    CHECK(seed1 != seed6);
    CHECK(seed1 != seed7);
    CHECK(seed1 != seed8);
    CHECK(seed1 != seed9);
    CHECK(seed1 != seed10);

    CHECK(seed2 != seed3);
    CHECK(seed2 != seed4);
    CHECK(seed2 != seed5);
    CHECK(seed2 != seed6);
    CHECK(seed2 != seed7);
    CHECK(seed2 != seed8);
    CHECK(seed2 != seed9);
    CHECK(seed2 != seed10);

    CHECK(seed3 != seed4);
    CHECK(seed3 != seed5);
    CHECK(seed3 != seed6);
    CHECK(seed3 != seed7);
    CHECK(seed3 != seed8);
    CHECK(seed3 != seed9);
    CHECK(seed3 != seed10);

    CHECK(seed4 != seed5);
    CHECK(seed4 != seed6);
    CHECK(seed4 != seed7);
    CHECK(seed4 != seed8);
    CHECK(seed4 != seed9);
    CHECK(seed4 != seed10);

    CHECK(seed5 != seed6);
    CHECK(seed5 != seed7);
    CHECK(seed5 != seed8);
    CHECK(seed5 != seed9);
    CHECK(seed5 != seed10);

    CHECK(seed6 != seed7);
    CHECK(seed6 != seed8);
    CHECK(seed6 != seed9);
    CHECK(seed6 != seed10);

    CHECK(seed7 != seed8);
    CHECK(seed7 != seed9);
    CHECK(seed7 != seed10);

    CHECK(seed8 != seed9);
    CHECK(seed8 != seed10);

    CHECK(seed9 != seed10);
}
