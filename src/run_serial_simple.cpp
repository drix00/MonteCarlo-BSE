//
// Created by Hendrix Demers on 2020-05-10.
//
#include <string>
#include <fstream>

#include "simulate.h"
#include "utilities/Timer.h"

int main(int , const char **)
{
    std::string suffix = get_suffix();

    std::string name{"simulate_serial_simple_elapse_time"};
    std::string file_name = name + suffix + ".csv";
    std::ofstream output_file(file_name);

    Timer timer;

    run_simulations_set("serial", suffix, output_file, timer, run_simulations_serial_simple);

    output_file << name << ": " << timer.get_total_elapse_time_s() << " s\n";
}
