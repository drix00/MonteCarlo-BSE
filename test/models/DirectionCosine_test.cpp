//
// Created by Hendrix Demers on 2020-05-09.
//
#define _USE_MATH_DEFINES
#include <cmath>

#include <catch2/catch.hpp>


#include "models/DirectionCosine.h"


TEST_CASE("DirectionCosine compute", "[models]")
{
    const double tolerance = 1.0e-6;

    DirectionCosine model(0.0, 0.0, 1.0);
    model.compute(0.0, 0.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(-M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(-0.70710678118654746).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(0.0, M_PI / 4.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model.compute(0.0, -M_PI / 4.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, M_PI / 4.0);
    CHECK(model.ca == Approx(0.5).margin(tolerance));
    CHECK(model.cb == Approx(0.5).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(-M_PI / 4.0, M_PI / 4.0);
    CHECK(model.ca == Approx(-0.5).margin(tolerance));
    CHECK(model.cb == Approx(-0.5).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, -M_PI / 4.0);
    CHECK(model.ca == Approx(0.5).margin(tolerance));
    CHECK(model.cb == Approx(-0.5).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(-M_PI / 4.0, -M_PI / 4.0);
    CHECK(model.ca == Approx(-0.5).margin(tolerance));
    CHECK(model.cb == Approx(0.5).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(2.0 * M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(1.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(3.0 * M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(-0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(4.0 * M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(-1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(5.0 * M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(-0.70710678118654757).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(-0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(6.0 * M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(-1.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(7.0 * M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(-0.70710678118654757).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(8.0 * M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 2.0 * M_PI / 4.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.70710678118654757).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 3.0 * M_PI / 4.0);
    CHECK(model.ca == Approx(-0.5).margin(tolerance));
    CHECK(model.cb == Approx(0.5).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 4.0 * M_PI / 4.0);
    CHECK(model.ca == Approx(-0.70710678118654757).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 5.0 * M_PI / 4.0);
    CHECK(model.ca == Approx(-0.5).margin(tolerance));
    CHECK(model.cb == Approx(-0.5).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 6.0 * M_PI / 4.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(-0.70710678118654757).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 7.0 * M_PI / 4.0);
    CHECK(model.ca == Approx(0.5).margin(tolerance));
    CHECK(model.cb == Approx(-0.5).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 8.0 * M_PI / 4.0);
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance));

    model = DirectionCosine(0.0, 1.0, 0.0);
    model.compute(0.0, 0.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(1.0).margin(tolerance));
    CHECK(model.cc == Approx(0.0).margin(tolerance));

    model = DirectionCosine(0.0, 1.0, 0.0);
    model.compute(M_PI / 4.0, 0.0);
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance));
    CHECK(model.cb == Approx(0.70710678118654757).margin(tolerance));
    CHECK(model.cc == Approx(0.0).margin(tolerance));
}
