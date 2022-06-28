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
#define _USE_MATH_DEFINES
#include <cmath>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "Rutherford.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

double Rutherford::compute_alpha(double energy_eV) const
{
    double const energy_keV = energy_eV * 1.0e-3;

    double alpha = 3.4e-3 * std::pow(atomic_number, 0.67) / energy_keV;

    return alpha;
}

double Rutherford::compute_sigma_nm2(double energy_eV) const
{
    double const energy_keV = energy_eV * 1.0e-3;

    double const factor1 = 5.21e-21 * cm2nm * cm2nm * (atomic_number * atomic_number) / (energy_keV * energy_keV);

    double const alpha = compute_alpha(energy_eV);
    double const factor2 = 4.0 * M_PI / (alpha * (1.0 + alpha));
    double const factor3 = (energy_keV + 511.0) / (energy_keV + 1024.0);

    double const value_nm2 = factor1 * factor2 * factor3 * factor3;
    return value_nm2;
}

double Rutherford::compute_scattering_angle_rad(double energy_eV, double random_number) const
{
    double const alpha = compute_alpha(energy_eV);
    double const nominator = 2.0 * alpha * random_number;
    double const denominator = 1.0 + alpha - random_number;
    double const cos_theta = 1.0 - nominator / denominator;
    double const theta_rad = std::acos(cos_theta);

    return theta_rad;
}

double Rutherford::compute_azimuthal_angle_rad(double random_number) const
{
    double value = 2.0 * M_PI * random_number;
    return value;
}
