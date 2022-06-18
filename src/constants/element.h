#ifndef MONTECARLO_BSE_CONSTANTS_ELEMENT_H
#define MONTECARLO_BSE_CONSTANTS_ELEMENT_H

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
#include <string>
// Library headers
// Project headers
// Project private headers

namespace monte_carlo::constants::element {

std::string get_symbol(int atomic_number);
std::string get_name(int atomic_number);
double get_atomic_weight_g_mol(int atomic_number);
double get_atomic_mass_density_g_cm3(int atomic_number);

}// namespace monte_carlo

#endif//MONTECARLO_BSE_CONSTANTS_ELEMENT_H
