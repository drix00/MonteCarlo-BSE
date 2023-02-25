/**
 * @file
 *
 * @brief Executable to profile a serial Monte Carlo simulation.
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
#include <iomanip>
#include <iostream>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
// Project headers
#include "inputs.h"
#include "simulate.h"
#include "utilities/Timer.h"
// Project private headers

// Global and constant variables/functions.

/**
 * @brief Executable to profile a serial Monte Carlo simulation.
 *
 * @return status of the execution.
 */
int main(int , const char **)
{
    std::string suffix = get_suffix();
    std::string name{"profile_simple"};
    std::string file_name = name + suffix + ".csv";
    std::ofstream output_file(file_name);

    Timer timer;

    name = "profile_serial_simple";
    run_simulations_serial_simple(name, suffix, get_inputs_profile_serial_simple());
    double elapse_time_s = timer.get_elapse_time_s();
    std::cout << name << ": " << elapse_time_s << " s\n";
    output_file << name << ": " << elapse_time_s << " s\n";

    name = "profile_for_each_simple";
    run_simulations_for_each_simple(name, suffix, get_inputs_profile_serial_simple());
    elapse_time_s = timer.get_elapse_time_s();
    std::cout << name << ": " << elapse_time_s << " s\n";
    output_file << name << ": " << elapse_time_s << " s\n";

    name = "profile_for_each_seq_simple";
    run_simulations_for_each_seq_simple(name, suffix, get_inputs_profile_serial_simple());
    elapse_time_s = timer.get_elapse_time_s();
    std::cout << name << ": " << elapse_time_s << " s\n";
    output_file << name << ": " << elapse_time_s << " s\n";

//    name = "profile_for_each_unseq_simple";
//    run_simulations_for_each_unseq_simple(name, suffix, get_inputs_profile_serial_simple());
//    elapse_time_s = timer.get_elapse_time_s();
//    std::cout << name << ": " << elapse_time_s << " s\n";
//    output_file << name << ": " << elapse_time_s << " s\n";

    name = "profile_for_each_par_simple";
    run_simulations_for_each_par_simple(name, suffix, get_inputs_profile_serial_simple());
    elapse_time_s = timer.get_elapse_time_s();
    std::cout << name << ": " << elapse_time_s << " s\n";
    output_file << name << ": " << elapse_time_s << " s\n";

    name = "profile_for_each_par_unseq_simple";
    run_simulations_for_each_par_unseq_simple(name, suffix, get_inputs_profile_serial_simple());
    elapse_time_s = timer.get_elapse_time_s();
    output_file << name << ": " << elapse_time_s << " s\n";

    elapse_time_s = timer.get_total_elapse_time_s();
    name = "profile_simple";
    std::cout << name << ": " << elapse_time_s << " s\n";
    output_file << name << ": " << elapse_time_s << " s\n";

    output_file.close();
}
