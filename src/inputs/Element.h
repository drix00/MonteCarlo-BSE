#ifndef MONTECARLO_BSE_INPUT_ELEMENT_H
#define MONTECARLO_BSE_INPUT_ELEMENT_H

/**
 * @file
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2021
 */

//   Copyright 2021 Hendrix Demers
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
class Element
{
  public:
    /**
     *
     * @param atomic_number_
     * @param atomic_weight_g_mol_
     * @param density_g_cm3_
     */
    Element(int atomic_number_, double atomic_weight_g_mol_, double density_g_cm3_)
        : atomic_number{ atomic_number_ }, atomic_weight_g_mol{ atomic_weight_g_mol_ }, density_g_cm3{ density_g_cm3_ } {};

  public:
    int atomic_number;
    double atomic_weight_g_mol;
    double density_g_cm3;
};

Element get_c();
Element get_al();
Element get_si();
Element get_fe();
Element get_cu();
Element get_ag();
Element get_au();

#endif//MONTECARLO_BSE_INPUT_ELEMENT_H
