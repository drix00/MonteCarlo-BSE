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
// Precompiled header
// Current declaration header file of this implementation file.
#include "Timer.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

double Timer::get_elapse_time_s() {
    double time_s = compute_elapse_time_s(last, std::chrono::steady_clock::now());
    last = std::chrono::steady_clock::now();
    return time_s;
}
double Timer::get_total_elapse_time_s() {
    double time_s = compute_elapse_time_s(start_time, std::chrono::steady_clock::now());
    return time_s;
}

double Timer::compute_elapse_time_s(std::chrono::steady_clock::time_point start_time_, std::chrono::steady_clock::time_point end_time) {
    std::chrono::duration elapse_time = end_time - start_time_;
    auto elapse_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapse_time);
    auto elapse_time_s = std::chrono::duration_cast<std::chrono::seconds>(elapse_time_ns).count();
    double fraction = static_cast<double>(elapse_time_ns.count()) - static_cast<double>(elapse_time_s) * 1.0e9;
    double time_s = static_cast<double>(elapse_time_s) + fraction * 1.0e-9;

    return time_s;
}
