//
// Created by Hendrix Demers on 2020-05-09.
//

#include "Statistic.h"
#include <algorithm>
#include <cmath>

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
