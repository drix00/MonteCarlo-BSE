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
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "EnergyLoss.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

double EnergyLoss::compute_keV_g_cm2(double energy_eV) const
{
    double value_keV_g_cm2 = compute_joy_luo1989(energy_eV);
    return value_keV_g_cm2;
}

double EnergyLoss::compute_bethe1930(double energy_eV) const
{
    double const energy_keV = energy_eV * 1.0e-3;
    double const factor1 = -78500.0 * atomic_number / (atomic_weight_g_mol * energy_keV);
    double const J_keV = compute_mean_ionisation_potential_eV() * 1.0e-3;
    double const factor2 = std::log(1.166 * energy_keV / J_keV);
    double const value = factor1 * factor2;

    return value;
}

double EnergyLoss::compute_joy_luo1989(double energy_eV) const
{
    double const energy_keV = energy_eV * 1.0e-3;
    double const factor1 = -78500.0 * atomic_number / (atomic_weight_g_mol * energy_keV);
    double const J_keV = compute_mean_ionisation_potential_eV() * 1.0e-3;
    double const factor2 = std::log(1.166 * (energy_keV + 0.85 * J_keV) / J_keV);
    double const value = factor1 * factor2;

    return value;
}

double EnergyLoss::compute_mean_ionisation_potential_eV() const
{
    double const value = (9.76 * atomic_number + 58.5 / std::pow(atomic_number, 0.19));
    return value;
}
