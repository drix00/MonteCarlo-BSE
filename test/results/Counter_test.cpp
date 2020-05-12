//
// Created by hendr on 2020-05-11.
//
#include <cmath>

#include <catch2/catch.hpp>

#include "results/Counter.h"

TEST_CASE("Counter variance", "[results]")
{
    Counter counter;

    counter.add_value(1);
    counter.add_value(2);
    counter.add_value(3);
    counter.add_value(4);
    counter.add_value(5);

    CHECK(counter.counts() == 5);
    CHECK(counter.min() == Approx(1.0).margin(0.0001));
    CHECK(counter.max() == Approx(5.0).margin(0.0001));
    CHECK(counter.mean() == Approx(3.0).margin(0.0001));
    CHECK(counter.variance() == Approx(0.4).margin(0.0001));
    CHECK(counter.standard_deviation() == Approx(0.632455532).margin(0.0001));
}

TEST_CASE("Counter bse", "[results]")
{
    Counter counter;

    counter.add_value(1);
    counter.add_value(1);
    counter.add_value(0);
    counter.add_value(0);
    counter.add_value(0);
    counter.add_value(1);
    counter.add_value(1);
    counter.add_value(0);
    counter.add_value(0);
    counter.add_value(0);

    double variance_ref = (0.4 * (1.0 - 0.4)) / 10.0;
    CHECK(counter.counts() == 10);
    CHECK(counter.min() == Approx(0.0).margin(0.0001));
    CHECK(counter.max() == Approx(1.0).margin(0.0001));
    CHECK(counter.mean() == Approx(0.4).margin(0.0001));
    CHECK(counter.variance() == Approx(variance_ref).margin(0.0001));
    CHECK(counter.standard_deviation() == Approx(std::sqrt(variance_ref)).margin(0.0001));
}
