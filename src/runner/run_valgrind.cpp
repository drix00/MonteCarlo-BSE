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
 * Shorter simulation to be used with valgrind.
 *
 * @return success of the main.
 */
int main(int , const char **)
{
    std::string suffix = get_suffix();

    Timer timer;

    run_simulations_serial_simple("profile_serial_simple_valgrind", suffix, get_inputs_valgrind());
    std::cout << "profile_serial_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_simple("profile_for_each_simple_valgrind", suffix, get_inputs_valgrind());
    std::cout << "profile_for_each_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_seq_simple("profile_for_each_seq_simple_valgrind", suffix, get_inputs_valgrind());
    std::cout << "profile_for_each_seq_simple: " << timer.get_elapse_time_s() << " s\n";

//    run_simulations_for_each_unseq_simple("profile_for_each_unseq_simple", suffix, get_inputs_valgrind());
//    std::cout << "profile_for_each_unseq_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_par_simple("profile_for_each_par_simple_valgrind", suffix, get_inputs_valgrind());
    std::cout << "profile_for_each_par_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_par_unseq_simple("profile_for_each_par_unseq_simple_valgrind", suffix, get_inputs_valgrind());
    std::cout << "profile_for_each_par_unseq_simple: " << timer.get_elapse_time_s() << " s\n";

    std::cout << "profile" << ": " << timer.get_total_elapse_time_s() << " s\n";
}
