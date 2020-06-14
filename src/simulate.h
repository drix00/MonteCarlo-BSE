//
// Created by hendrix on 2020-06-07.
//

#ifndef MONTECARLO_BSE_SIMULATE_H
#define MONTECARLO_BSE_SIMULATE_H
#include <string>
#include <vector>
#include <fstream>

#include "inputs/Input.h"
#include "models/RandomSeed.h"
#include "Data.h"
#include "utilities/Timer.h"
#include "inputs.h"

void run_simulation(Data& datum, RandomSeed rand_seed);
void write_results_file(std::string name, std::string suffix, std::vector<std::string> lines);
void run_simulations_serial_simple(std::string name, std::string suffix, std::vector<Data> data);
void run_simulations_async_simple(std::string name, std::string suffix, std::vector<Data> data);
void run_simulations_for_each_simple(std::string name, std::string suffix, std::vector<Data> data);
void run_simulations_for_each_seq_simple(std::string name, std::string suffix, std::vector<Data> data);
//void run_simulations_for_each_unseq_simple(std::string name, std::string suffix, std::vector<Data> data);
void run_simulations_for_each_par_simple(std::string name, std::string suffix, std::vector<Data> data);
void run_simulations_for_each_par_unseq_simple(std::string name, std::string suffix, std::vector<Data> data);
std::string get_suffix();

template<class Function>
void run_simulations_set(std::string name, std::string suffix, std::ofstream& output_file, Timer& timer, Function function) {

    std::string run_name = name + "_number_trajectories_repetitions";
    function(run_name, suffix, get_inputs_number_trajectories_repetitions());
    output_file << run_name << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_elements_energies";
    function(run_name, suffix, get_inputs_elements_energies());
    output_file << run_name << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_atomic_numbers";
    function(run_name, suffix, get_inputs_atomic_numbers());
    output_file << run_name << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_densities";
    function(run_name, suffix, get_inputs_densities());
    output_file << run_name << timer.get_elapse_time_s() << " s\n";

    run_name = name + "_thickness";
    function(run_name, suffix, get_inputs_thickness());
    output_file << run_name << ": " << timer.get_elapse_time_s() << " s\n";
}

#endif//MONTECARLO_BSE_SIMULATE_H
