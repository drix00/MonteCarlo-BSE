#ifndef MONTECARLO_BSE_TIMER_H
#define MONTECARLO_BSE_TIMER_H

/**
 * @file
 *
 * @brief Utilities to compute the elapsed time in the program.
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

// Forwards declarations
// C system headers
// C++ system header
#include <iostream>
#include <string>
#include <chrono>
// Library headers
// Project headers
// Project private headers

/**
 * Timer to compute the elapsed time in part of the program.
 *
 * @todo Refactor the design of the class to be more useful in the program.
 * @todo Compare with spdlog/stopwatch.h.
 */
class Timer
{
  public:
    /**
     * Empty constructor, members initialized using std::chrono::steady_clock::now().
     */
    Timer(): start_time{std::chrono::steady_clock::now()}, last{std::chrono::steady_clock::now()} {}

    /**
     * Compute the elapse time from the last call (or object construction) and now.
     *
     * @return elapse time in second.
     */
    double get_elapse_time_s();

    /**
     * Compute the elapse time from the object construction and now.
     *
     * @return elapse time in second.
     */
    double get_total_elapse_time_s();

  private:
    /**
     * @brief Compute the elapse time between two time points.
     *
     * @param[in] start_time_
     * @param[in] end_time
     * @return elapse time in second.
     */
    double compute_elapse_time_s(std::chrono::steady_clock::time_point start_time_, std::chrono::steady_clock::time_point end_time);

    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point last;
};

#endif//MONTECARLO_BSE_TIMER_H
