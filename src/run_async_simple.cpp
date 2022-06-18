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
#include <string>
// Library headers
// Precompiled header
#pragma hdrstop
// Current declaration header file of this implementation file.
// Project headers
#include "inputs.h"
#include "simulate.h"
// Project private headers

// Global and constant variables/functions.

void simulate_number_trajectories_repetitions(std::string suffix)
{
    run_simulations_async_simple("simulate_async_simple_number_trajectories_repetitions", suffix, get_inputs_number_trajectories_repetitions());
}

void simulate_elements_energies(std::string suffix)
{
    run_simulations_async_simple("simulate_async_simple_elements_energies", suffix, get_inputs_elements_energies());
}

void simulate_atomic_numbers(std::string suffix)
{
    run_simulations_async_simple("simulate_async_simple_atomic_numbers", suffix, get_inputs_atomic_numbers());
}

void simulate_densities(std::string suffix)
{
    run_simulations_async_simple("simulate_async_simple_densities", suffix, get_inputs_densities());
}

void simulate_thickness(std::string suffix)
{
    run_simulations_async_simple("simulate_async_simple_thickness", suffix, get_inputs_thickness());
}

int main(int , const char **)
{
    std::string suffix = get_suffix();

    simulate_number_trajectories_repetitions(suffix);
    simulate_elements_energies(suffix);
    simulate_atomic_numbers(suffix);
    simulate_densities(suffix);
    simulate_thickness(suffix);
}
