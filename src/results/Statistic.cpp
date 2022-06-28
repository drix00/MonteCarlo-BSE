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
#include <algorithm>
#include <cmath>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "Statistic.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

void Statistic::add_value(double value_)
{
    ++number_x;

    sum_x += value_;
    sum_xx += value_ * value_;
    sum_xxx += value_ * value_ * value_;
    sum_xxxx += value_ * value_ * value_ * value_;

    min_x = std::min(min_x, value_);
    max_x = std::max(max_x, value_);
}

double Statistic::mean() const
{
    double value = sum_x / number_x;
    return value;
}

double Statistic::variance() const
{
    double value = sum_xx / number_x - mean() * mean();
    return value;
}

double Statistic::standard_deviation() const
{
    double value = std::sqrt(variance());
    return value;
}

double Statistic::mean_absolute_deviation() const
{
    return 0.0;
}

double Statistic::skewness() const
{
    double nominator = sum_xxx / number_x - 3.0 * mean() * standard_deviation() * standard_deviation() - mean() * mean() * mean();
    double denominator = standard_deviation() * standard_deviation() * standard_deviation();
    double value = nominator / denominator;

    return value;
}

double Statistic::kurtosis() const
{
    return 0.0;
}
