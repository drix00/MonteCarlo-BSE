//
// Created by Hendrix Demers on 2020-05-09.
//

#include "models/RandomSeed.h"

#include <random>
#include <thread>
#include <sstream>
#include <chrono>

unsigned int RandomSeed::operator()()
{
    std::random_device device;
    if (device.entropy() > minimum_entropy) {
        return device();
    } else {
        std::ostringstream ss;
        ss << std::this_thread::get_id();
        auto time_now{ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() };
        return std::stoul(ss.str()) + static_cast<unsigned int>(time_now);
    }
}
