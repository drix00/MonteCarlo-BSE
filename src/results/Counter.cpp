/**
 * @file
 *
 * @brief A counter to compute statistic of a results without storing all values.
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
#include <algorithm>
#include <cmath>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "Counter.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

void Counter::add_value(double value)
{
    ++number_x;

    sum_x += value;
    sum_xx += value * value;

    min_x = std::min(min_x, value);
    max_x = std::max(max_x, value);
}

double Counter::mean() const
{
    const double value = sum_x / number_x;
    return value;
}

double Counter::variance() const
{
    const double value = (sum_xx / number_x - mean() * mean()) / number_x;
    return value;
}

double Counter::standard_deviation() const
{
    const double value = std::sqrt(variance());
    return value;
}
