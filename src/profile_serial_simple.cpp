//
// Created by hendrix on 2020-05-25.
//

#include <string>
#include <iomanip>
#include <iostream>

#include "inputs.h"
#include "simulate.h"
#include "utilities/Timer.h"

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
