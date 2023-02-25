#ifndef MONTECARLO_BSE_INPUTS_H
#define MONTECARLO_BSE_INPUTS_H

/**
 * @file
 *
 * @brief Input data for simulation runner.
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
#include <vector>
// Library headers
// Project headers
#include "Data.h"
// Project private headers

/**
 * Input data for runner of number trajectories and repetitions.
 *
 * @return vector of input data.
 */
std::vector<Data> get_inputs_number_trajectories_repetitions();

/**
 * Input data for runner of elements and energies.
 *
 * @return vector of input data.
 */
std::vector<Data> get_inputs_elements_energies();

/**
 * Input data for runner of atomic numbers.
 *
 * @return vector of input data.
 */
std::vector<Data> get_inputs_atomic_numbers();

/**
 * Input data for runner of densities.
 *
 * @return vector of input data.
 */
std::vector<Data> get_inputs_densities();

/**
 * Input data for runner of thickness.
 *
 * @return vector of input data.
 */
std::vector<Data> get_inputs_thickness();

/**
 * Input data for profiling the program.
 *
 * @return vector of input data.
 */
std::vector<Data> get_inputs_profile_serial_simple();

/**
 * Input data for profiling with valgrind the program.
 *
 * @return vector of input data.
 */
std::vector<Data> get_inputs_valgrind();

#endif//MONTECARLO_BSE_INPUTS_H
