#ifndef MONTECARLO_BSE_INPUTS_INPUT_ELEMENT_H
#define MONTECARLO_BSE_INPUTS_INPUT_ELEMENT_H

/**
 * @file
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2023
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
 * Element parameter to use in the simulation.
 */
class InputElement
{
  public:
    /**
     * Element atomic properties.
     *
     * @param[in] atomic_number_
     * @param[in] atomic_weight_g_mol_
     * @param[in] density_g_cm3_
     */
    InputElement(const unsigned int atomic_number_, const double atomic_weight_g_mol_, const double density_g_cm3_)
        : atomic_number{ atomic_number_ }, atomic_weight_g_mol{ atomic_weight_g_mol_ }, density_g_cm3{ density_g_cm3_ } {};

    /**
     * Element atomic number.
     */
    unsigned int atomic_number;

    /**
     * Element atomic weight in \f$g / mol\f$.
     */
    double atomic_weight_g_mol;

    /**
     * Element density in \f$g / cm^{3}\f$.
     */
    double density_g_cm3;
};

/**
 * Generate element properties for C.
 *
 * @return Element C.
 */
InputElement get_c();

/**
 * Generate element properties for Al.
 *
 * @return Element Al.
 */
InputElement get_al();

/**
 * Generate element properties for Si.
 *
 * @return Element Si.
 */
InputElement get_si();

/**
 * Generate element properties for Fe.
 *
 * @return Element Fe.
 */
InputElement get_fe();

/**
 * Generate element properties for Cu.
 *
 * @return Element Cu.
 */
InputElement get_cu();

/**
 * Generate element properties for Ag.
 *
 * @return Element Ag.
 */
InputElement get_ag();

/**
 * Generate element properties for Au.
 *
 * @return Element Au.
 */
InputElement get_au();

#endif// MONTECARLO_BSE_INPUTS_INPUT_ELEMENT_H
