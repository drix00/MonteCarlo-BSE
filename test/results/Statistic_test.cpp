//
// Created by Hendrix Demers on 2020-05-09.
//
#include <catch2/catch.hpp>

#include "results/Statistic.h"
#include "models/RandomNumber.h"

TEST_CASE("Statistic random counts", "[results]")
{
    RandomNumber random_number{ RandomNumber::magic_seed };

    Statistic stats;
    int const number_values = 20;

    for (int i = 0; i < number_values; ++i) {
        stats.add_value(random_number());
    }

    CHECK(stats.counts() == 20);
    CHECK(stats.min() == Approx(0.0123827711).margin(0.0001));
    CHECK(stats.max() == Approx(0.9456984866).margin(0.0001));
    CHECK(stats.mean() == Approx(0.4918011615).margin(0.0001));
    CHECK(stats.variance() == Approx(0.0874879358).margin(0.0001));
    CHECK(stats.standard_deviation() == Approx(0.2957835963).margin(0.0001));
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(0.0001));
    CHECK(stats.skewness() == Approx(-0.2486961137).margin(0.0001));
    CHECK(stats.kurtosis() == Approx(0.0).margin(0.0001));
}

TEST_CASE("Statistic skewness", "[results]")
{
    Statistic stats;

    stats.add_value(2);
    stats.add_value(7);
    stats.add_value(4);
    stats.add_value(9);
    stats.add_value(3);

    CHECK(stats.counts() == 5);
    CHECK(stats.min() == Approx(2.0).margin(0.0001));
    CHECK(stats.max() == Approx(9.0).margin(0.0001));
    CHECK(stats.mean() == Approx(5.0).margin(0.0001));
    CHECK(stats.variance() == Approx(6.8).margin(0.0001));
    CHECK(stats.standard_deviation() == Approx(2.6076809621).margin(0.0001));
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(0.0001));
    CHECK(stats.skewness() == Approx(0.406040288214).margin(1.0e-6));
    CHECK(stats.kurtosis() == Approx(0.0).margin(0.0001));
}

TEST_CASE("Statistic variance", "[results]")
{
    Statistic stats;

    stats.add_value(1);
    stats.add_value(2);
    stats.add_value(3);
    stats.add_value(4);
    stats.add_value(5);

    CHECK(stats.counts() == 5);
    CHECK(stats.min() == Approx(1.0).margin(0.0001));
    CHECK(stats.max() == Approx(5.0).margin(0.0001));
    CHECK(stats.mean() == Approx(3.0).margin(0.0001));
    CHECK(stats.variance() == Approx(2.0).margin(0.0001));
    CHECK(stats.standard_deviation() == Approx(1.4142135624).margin(0.0001));
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(0.0001));
    CHECK(stats.skewness() == Approx(0.0).margin(1.0e-6));
    CHECK(stats.kurtosis() == Approx(0.0).margin(0.0001));
}
