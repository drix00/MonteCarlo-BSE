//
// Created by Hendrix Demers on 2020-05-10.
//
#include <string>

#include "inputs.h"
#include "simulate.h"

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
