//
// Created by hendr on 2020-05-11.
//

#include "Counter.h"
#include <algorithm>
#include <cmath>

void Counter::add_value(double value_)
{
    ++number_x;

    sum_x += value_;
    sum_xx += value_ * value_;

    min_x = std::min(min_x, value_);
    max_x = std::max(max_x, value_);
}

double Counter::mean() const
{
    double value = sum_x / number_x;
    return value;
}

double Counter::variance() const
{
    double value = (sum_xx / number_x - mean() * mean()) / number_x;
    return value;
}

double Counter::standard_deviation() const
{
    double value = std::sqrt(variance());
    return value;
}
