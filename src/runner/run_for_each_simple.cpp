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
#include <fstream>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
// Project headers
#include "simulate.h"
#include "utilities/Timer.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Run and compare for_each loop using default sequential and parallel algorythm.
 *
 * @return success of the main.
 */
int main(int , const char **)
{
    std::string suffix = get_suffix();

    std::string name{"simulate_for_each_simple_elapse_time"};
    std::string file_name = name + suffix + ".csv";
    std::ofstream output_file(file_name);

    Timer timer;

    run_simulations_set("for_each", suffix, output_file, timer, run_simulations_for_each_simple);
    run_simulations_set("for_each_seq", suffix, output_file, timer, run_simulations_for_each_seq_simple);
//    run_simulations_set("for_each_unseq", suffix, output_file, timer, run_simulations_for_each_unseq_simple);
    run_simulations_set("for_each_par", suffix, output_file, timer, run_simulations_for_each_par_simple);
    run_simulations_set("for_each_par_unseq", suffix, output_file, timer, run_simulations_for_each_par_unseq_simple);

    output_file << name << ": " << timer.get_total_elapse_time_s() << " s\n";
}
