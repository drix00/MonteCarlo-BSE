#ifndef MONTECARLO_BSE_MEAN_FREE_PATH_H
#define MONTECARLO_BSE_MEAN_FREE_PATH_H

/**
 * @file
 *
 * @brief Model to compute the mean free path and distance between two elastic collisions.
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
 * @brief Model to compute the mean free path and distance between two elastic collisions
 */
class MeanFreePath
{
  public:
    /**
     * @brief Constructor with the element properties needed for the calculation.
     *
     * @param[in] atomic_weight_g_mol_
     * @param[in] density_g_cm3_
     */
    MeanFreePath(double atomic_weight_g_mol_, double density_g_cm3_) : atomic_weight_g_mol{ atomic_weight_g_mol_ },
                                                                       density_g_cm3{ density_g_cm3_ } {};

    /**
     * Compute the mean free path from the total elastic cross section.
     *
     * @param[in] sigma_nm2 the total elastic cross section in nm2
     * @return mean free path value in nm.
     */
    [[nodiscard]] double compute_nm(double sigma_nm2) const;

    /**
     * Compute the distance between two elastic collisions from the mean free path and a random number.
     *
     * @param[in] mfp_nm the mean free path in nm
     * @param[in] random_number a random number between 0.0 and 1.0
     * @return distance between two elastic collisions in nm.
     */
    [[nodiscard]] double step_nm(double mfp_nm, double random_number) const;

  private:
    double atomic_weight_g_mol;
    double density_g_cm3;
    double const avogadro_number_1_mol{ 6.02214076e23 };
    double const nm2cm{1.0e-7};
    double const cm2nm{1.0e7};
};

#endif//MONTECARLO_BSE_MEAN_FREE_PATH_H
