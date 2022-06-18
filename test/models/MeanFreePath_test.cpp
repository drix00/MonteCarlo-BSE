/**
* @file
*
* @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
* @copyright 2022
*/

// C system headers
// C++ system header
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
#pragma hdrstop
// Project headers
#include "models/MeanFreePath.h"
#include "models/Rutherford.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if MeanFreePath tests were find", "[test]")
{
   REQUIRE(true);
}

TEST_CASE("MeanFreePath lambda", "[models]")
{
    MeanFreePath model{ 12.011, 2.62 };
    Rutherford model_cs{ 6 };

    REQUIRE(model.compute_nm(model_cs.compute_sigma_nm2(1000.0)) == Approx(1.4784352041).epsilon(0.01));
    REQUIRE(model.compute_nm(model_cs.compute_sigma_nm2(10000.0)) == Approx(14.3837782086).epsilon(0.01));
    REQUIRE(model.compute_nm(model_cs.compute_sigma_nm2(100000.0)) == Approx(123.4571899308).epsilon(0.01));
}

TEST_CASE("MeanFreePath step", "[models]")
{
    MeanFreePath model{ 12.011, 2.62 };
    Rutherford model_cs{ 6 };

    double lambda_nm = model.compute_nm(model_cs.compute_sigma_nm2(10000.0));
    //    REQUIRE(model.step_nm(lambda_nm, 1.0) == Approx(80.0).epsilon(0.01));
    REQUIRE(model.step_nm(lambda_nm, 0.999) == Approx(99.3596198521).epsilon(0.01));
    REQUIRE(model.step_nm(lambda_nm, 0.5) == Approx(9.9700753111).epsilon(0.01));
    REQUIRE(model.step_nm(lambda_nm, 0.01) == Approx(0.1445618018).epsilon(0.01));
    REQUIRE(model.step_nm(lambda_nm, 0.0) == Approx(0.0).epsilon(0.01));
}
