//
// Created by hendrix on 2020-06-07.
//

#include <string>
#include <fstream>

#include "simulate.h"
#include "utilities/Timer.h"


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
