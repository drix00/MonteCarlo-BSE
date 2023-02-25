#ifndef MONTECARLO_BSE_ENERGY_LOSS_H
#define MONTECARLO_BSE_ENERGY_LOSS_H

/**
 * @file
 *
 * @brief Model for the electron energy loss.
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

/**
 * @brief Model for the electron energy loss.
 */
class EnergyLoss
{
  public:
    /**
     * Constructor with the element properties needed to compute the energy loss.
     *
     * @param[in] atomic_number_
     * @param[in] atomic_weight_g_mol_
     */
    explicit EnergyLoss(unsigned int atomic_number_, double atomic_weight_g_mol_)
        : atomic_number{ atomic_number_ }, atomic_weight_g_mol{ atomic_weight_g_mol_ } {};

    /**
     * Compute the mean ionisation potential.
     *
     * @return the mean ionisation potential in eV.
     */
    [[nodiscard]] double compute_mean_ionisation_potential_eV() const;

    /**
     * General method to compute the energy loss for the current energy.
     *
     * @param[in] energy_eV the current electron energy in eV
     * @return the energy loss in eV.
     */
    [[nodiscard]] double compute_keV_g_cm2(double energy_eV) const;

    /**
     * Compute the energy loss with the Bethe (1930) model.
     *
     * @param[in] energy_eV the current electron energy in eV
     * @return the energy loss in eV.
     */
    [[nodiscard]] double compute_bethe1930(double energy_eV) const;

    /**
     * Compute the energy loss with the Joy and Luo (1989) model.
     * @param[in] energy_eV the current electron energy in eV
     * @return the energy loss in eV.
     */
    [[nodiscard]] double compute_joy_luo1989(double energy_eV) const;

  private:
    unsigned int atomic_number;
    double atomic_weight_g_mol;
};

#endif//MONTECARLO_BSE_ENERGY_LOSS_H
