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

    Timer timer;

    run_simulations_serial_simple("profile_serial_simple", suffix, get_inputs_profile_serial_simple());
    std::cout << "profile_serial_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_simple("profile_for_each_simple", suffix, get_inputs_profile_serial_simple());
    std::cout << "profile_for_each_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_seq_simple("profile_for_each_seq_simple", suffix, get_inputs_profile_serial_simple());
    std::cout << "profile_for_each_seq_simple: " << timer.get_elapse_time_s() << " s\n";

//    run_simulations_for_each_unseq_simple("profile_for_each_unseq_simple", suffix, get_inputs_profile_serial_simple());
//    std::cout << "profile_for_each_unseq_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_par_simple("profile_for_each_par_simple", suffix, get_inputs_profile_serial_simple());
    std::cout << "profile_for_each_par_simple: " << timer.get_elapse_time_s() << " s\n";

    run_simulations_for_each_par_unseq_simple("profile_for_each_par_unseq_simple", suffix, get_inputs_profile_serial_simple());
    std::cout << "profile_for_each_par_unseq_simple: " << timer.get_elapse_time_s() << " s\n";

    std::cout << "profile" << ": " << timer.get_total_elapse_time_s() << " s\n";
}
