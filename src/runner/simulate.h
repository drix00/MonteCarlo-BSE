#ifndef MONTECARLO_BSE_SIMULATE_H
#define MONTECARLO_BSE_SIMULATE_H

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
#include <string>
#include <vector>
#include <fstream>
// Library headers
// Project headers
#include "models/RandomSeed.h"
#include "Data.h"
#include "utilities/Timer.h"
#include "inputs.h"
// Project private headers

/**
 * Run a single simulation from the input parameters and write a result file.
 *
 * @param[in,out] datum
 * @param[in] rand_seed
 */
void run_simulation(Data& datum, RandomSeed rand_seed);

/**
 * Write the simulation results in a csv file.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void write_results_file(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Run a simple serial simulation.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void run_simulations_serial_simple(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Run an async simulation.
 *
 * @todo Check if it is correct as not async method is used in this function.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void run_simulations_async_simple(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Run multiple simulations using for each in default mode.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void run_simulations_for_each_simple(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Run multiple simulations using for each in sequential mode.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void run_simulations_for_each_seq_simple(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Run multiple simulations using for each in unsequential mode.
 *
 * Not implemented as std::execution::unseq is a C++20 feature.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void run_simulations_for_each_unseq_simple(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Run multiple simulations using for each in parallel mode.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void run_simulations_for_each_par_simple(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Run multiple simulations using for each in parallel and unsequential mode.
 *
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[in,out] data simulation results
 */
void run_simulations_for_each_par_unseq_simple(std::string name, std::string suffix, std::vector<Data> data);

/**
 * Generate a date and time suffix for when the simulation is run.
 *
 * @return date and time suffix.
 */
std::string get_suffix();

/**
 * Template function to run a simulation set, i.e. an experimental set of simulation.
 *
 * @tparam Function runner of the simulation
 * @param[in] name basename of the file
 * @param[in] suffix simulation suffix
 * @param[out] output_file
 * @param[in] timer
 * @param[in] function runner of the simulation
 */
template<class Function>
void run_simulations_set(std::string name, std::string suffix, std::ofstream& output_file, Timer& timer, Function function) {

    std::string run_name = name + "_number_trajectories_repetitions";
    function(run_name, suffix, get_inputs_number_trajectories_repetitions());
    output_file << run_name << ": " << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_elements_energies";
    function(run_name, suffix, get_inputs_elements_energies());
    output_file << run_name << ": " << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_atomic_numbers";
    function(run_name, suffix, get_inputs_atomic_numbers());
    output_file << run_name << ": " << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_densities";
    function(run_name, suffix, get_inputs_densities());
    output_file << run_name << ": " << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_thickness";
    function(run_name, suffix, get_inputs_thickness());
    output_file << run_name << ": " << timer.get_elapse_time_s() << " s\n";
}

#endif//MONTECARLO_BSE_SIMULATE_H
