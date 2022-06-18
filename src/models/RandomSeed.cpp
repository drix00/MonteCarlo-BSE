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
// Precompiled header
#pragma hdrstop
// Current declaration header file of this implementation file.
#include "models/RandomSeed.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

/**
 * Seem to have a problem if the function is repeatably called quickly to seed the Simulation class.
 * Need to investigate and test further.
 *
 * @return
 */
unsigned int long RandomSeed::operator()()
{
    std::random_device device;
    if (device.entropy() > minimum_entropy) {
        return device();
    } else {
        std::ostringstream ss;
        ss << std::this_thread::get_id();
        auto time_now{ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() };
        return std::stoul(ss.str()) + static_cast<unsigned int long>(time_now);
    }
}
