/**
 * @file
 *
 * Tests for DirectionCosine.
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
#define _USE_MATH_DEFINES // NOLINT
#include <cmath>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "models/DirectionCosine.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if DirectionCosine tests were find", "[test]")
{
    REQUIRE(true);
}

TEST_CASE("DirectionCosine compute", "[models]")
{
    const double tolerance = 1.0e-6;

    DirectionCosine model(0.0, 0.0, 1.0);
    model.compute(0.0, 0.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(-M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(-0.70710678118654746).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(0.0, M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model.compute(0.0, -M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.5).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.5).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(-M_PI / 4.0, M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, -M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.5).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(-M_PI / 4.0, -M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.5).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(2.0 * M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(1.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(3.0 * M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(-0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(4.0 * M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(-1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(5.0 * M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(-0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(-0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(6.0 * M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(-1.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(7.0 * M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(-0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(8.0 * M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(1.0).margin(tolerance));

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 2.0 * M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 3.0 * M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.5).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 4.0 * M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(-0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 5.0 * M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 6.0 * M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(-0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 7.0 * M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.5).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(-0.5).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 0.0, 1.0);
    model.compute(M_PI / 4.0, 8.0 * M_PI / 4.0); // NOLINT
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.0).margin(tolerance));
    CHECK(model.cc == Approx(0.70710678118654757).margin(tolerance)); // NOLINT

    model = DirectionCosine(0.0, 1.0, 0.0);
    model.compute(0.0, 0.0);
    CHECK(model.ca == Approx(0.0).margin(tolerance));
    CHECK(model.cb == Approx(1.0).margin(tolerance));
    CHECK(model.cc == Approx(0.0).margin(tolerance));

    model = DirectionCosine(0.0, 1.0, 0.0);
    model.compute(M_PI / 4.0, 0.0); // NOLINT
    CHECK(model.ca == Approx(0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cb == Approx(0.70710678118654757).margin(tolerance)); // NOLINT
    CHECK(model.cc == Approx(0.0).margin(tolerance));
}
