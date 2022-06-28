#ifndef MONTECARLO_BSE_ENERGY_LOSS_H
#define MONTECARLO_BSE_ENERGY_LOSS_H
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

// Forwards declarations
// C system headers
// C++ system header
// Library headers
// Project headers
// Project private headers

class EnergyLoss
{
  public:
    EnergyLoss(unsigned int atomic_number_, double atomic_weight_g_mol_) : atomic_number{ atomic_number_ }, atomic_weight_g_mol{ atomic_weight_g_mol_ } {};
    double compute_mean_ionisation_potential_eV() const;
    double compute_keV_g_cm2(double energy_eV) const;
    double compute_bethe1930(double energy_eV) const;
    double compute_joy_luo1989(double energy_eV) const;

  private:
    unsigned int atomic_number;
    double atomic_weight_g_mol;
};

#endif//MONTECARLO_BSE_ENERGY_LOSS_H
