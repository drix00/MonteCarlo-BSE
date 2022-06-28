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
#include <cmath>
#include <cassert>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "MeanFreePath.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

double MeanFreePath::compute_nm(double sigma_nm2) const
{
    double sigma_cm2 = sigma_nm2 * nm2cm * nm2cm;
    double value_cm = atomic_weight_g_mol / (avogadro_number_1_mol * density_g_cm3 * sigma_cm2);
    double value_nm = value_cm * cm2nm;
    return value_nm;
}

double MeanFreePath::step_nm(double mfp_nm, double random_number) const
{
    assert(random_number >= 0.0);
    assert(random_number < 1.0);

    double value = -1.0 * mfp_nm * std::log(1.0 - random_number);
    return value;
}
