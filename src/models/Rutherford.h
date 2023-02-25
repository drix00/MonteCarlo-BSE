#ifndef MONTECARLO_BSE_RUTHERFORD_H
#define MONTECARLO_BSE_RUTHERFORD_H

/**
 * @file
 *
 * @brief Electron elastic cross section Rutherford model.
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
 * @brief Electron elastic cross section Rutherford model.
 */
class Rutherford
{
  public:
    /**
     * Constructor with the element property needed to compute the electron elastic cross section.
     *
     * @param[in] atomic_number_
     */
    Rutherford(unsigned int atomic_number_) : atomic_number{ atomic_number_ } {}

    /**
     * Compute the screening factor for the Rutherford model.
     *
     * @param[in] energy_eV
     * @return the screening factor.
     */
    double compute_alpha(double energy_eV) const;

    /**
     * Compute the total elastic cross section.
     *
     * @param[in] energy_eV
     * @return the total elastic cross section in nm2.
     */
    double compute_sigma_nm2(double energy_eV) const;

    /**
     * Compute the deflection angle.
     *
     * @param[in] energy_eV
     * @param[in] random_number
     * @return the deflection angle in radian.
     */
    double compute_scattering_angle_rad(double energy_eV, double random_number) const;

    /**
     * Compute the azimuthal scattering angle.
     *
     * @param[in] random_number
     * @return the azimuthal scattering angle in radian.
     */
    double compute_azimuthal_angle_rad(double random_number) const;

  private:
    unsigned int atomic_number;
    double const cm2nm = 1.0e7;
};

#endif//MONTECARLO_BSE_RUTHERFORD_H
