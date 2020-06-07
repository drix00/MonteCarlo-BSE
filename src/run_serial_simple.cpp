//
// Created by Hendrix Demers on 2020-05-10.
//
#include <string>
#include <fstream>

#include "inputs.h"
#include "simulate.h"
#include "utilities/Timer.h"

void simulate_number_trajectories_repetitions(std::string suffix)
{
    run_simulations_serial_simple("simulate_serial_simple_number_trajectories_repetitions", suffix, get_inputs_number_trajectories_repetitions());
}

void simulate_elements_energies(std::string suffix)
{
    run_simulations_serial_simple("simulate_serial_simple_elements_energies", suffix, get_inputs_elements_energies());
}

void simulate_atomic_numbers(std::string suffix)
{
    run_simulations_serial_simple("simulate_serial_simple_atomic_numbers", suffix, get_inputs_atomic_numbers());
}

void simulate_densities(std::string suffix)
{
    run_simulations_serial_simple("simulate_serial_simple_densities", suffix, get_inputs_densities());
}

void simulate_thickness(std::string suffix)
{
    run_simulations_serial_simple("simulate_serial_simple_thickness", suffix, get_inputs_thickness());
}

int main(int , const char **)
{
    std::string suffix = get_suffix();

    std::string name{"simulate_serial_simple_elapse_time"};
    std::string file_name = name + suffix + ".csv";
    std::ofstream output_file(file_name);

    Timer timer;

    simulate_number_trajectories_repetitions(suffix);
    output_file << "simulate_number_trajectories_repetitions: " << timer.get_elapse_time_s() << " s\n";

    simulate_elements_energies(suffix);
    output_file << "simulate_elements_energies: " << timer.get_elapse_time_s() << " s\n";

    simulate_atomic_numbers(suffix);
    output_file << "simulate_atomic_numbers: " << timer.get_elapse_time_s() << " s\n";

    simulate_densities(suffix);
    output_file << "simulate_densities: " << timer.get_elapse_time_s() << " s\n";

    simulate_thickness(suffix);
    output_file << "simulate_thickness: " << timer.get_elapse_time_s() << " s\n";

    output_file << name << ": " << timer.get_total_elapse_time_s() << " s\n";
}
