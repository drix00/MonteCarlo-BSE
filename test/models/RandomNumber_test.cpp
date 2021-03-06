//
// Created by Hendrix Demers on 2020-05-09.
//
#include <catch2/catch.hpp>

#include "models/RandomNumber.h"
#include "results/Statistic.h"

TEST_CASE("RandomNumber magic seed", "[models]")
{
    RandomNumber random_number{ RandomNumber::magic_seed };

    CHECK(random_number() == Approx(0.755155533).margin(0.0001));
    CHECK(random_number() == Approx(0.6390313939).margin(0.0001));
    CHECK(random_number() == Approx(0.7521452007).margin(0.0001));
    CHECK(random_number() == Approx(0.1362726836).margin(0.0001));
    CHECK(random_number() == Approx(0.9032689664).margin(0.0001));
    CHECK(random_number() == Approx(0.0940683118).margin(0.0001));
    CHECK(random_number() == Approx(0.5745703041).margin(0.0001));
    CHECK(random_number() == Approx(0.3728876995).margin(0.0001));
    CHECK(random_number() == Approx(0.2738741017).margin(0.0001));
    CHECK(random_number() == Approx(0.3902708814).margin(0.0001));
}

TEST_CASE("RandomNumber statistic 1M", "[models]")
{
    RandomNumber random_number{ RandomNumber::magic_seed };

    Statistic stats;
    int const number_values = 1000000;

    for (int i = 0; i < number_values; ++i) {
        stats.add_value(random_number());
    }

    CHECK(stats.counts() == number_values);
    CHECK(stats.min() == Approx(0.0000008088).margin(0.0001));
    CHECK(stats.max() == Approx(0.9999985263).margin(0.0001));
    CHECK(stats.mean() == Approx(0.5004564637).margin(0.0001));
    CHECK(stats.variance() == Approx(0.0832747386).margin(0.0001));
    CHECK(stats.standard_deviation() == Approx(0.2885736278).margin(0.0001));
    CHECK(stats.mean_absolute_deviation() == Approx(0.0).margin(0.0001));
    CHECK(stats.skewness() == Approx(-0.0028158571).margin(0.0001));
    CHECK(stats.kurtosis() == Approx(0.0).margin(0.0001));
}
