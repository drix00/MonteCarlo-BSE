//
// Created by hendrix on 2020-06-07.
//

#ifndef MONTECARLO_BSE_SIMULATE_H
#define MONTECARLO_BSE_SIMULATE_H
#include <string>
#include <vector>

#include "inputs/Input.h"
#include "models/RandomSeed.h"
#include "Data.h"

void run_simulation(Data& datum, RandomSeed rand_seed);
void write_results_file(std::string name, std::string suffix, std::vector<std::string> lines);
void run_simulations_serial_simple(std::string name, std::string suffix, std::vector<Data> data);
void run_simulations_async_simple(std::string name, std::string suffix, std::vector<Data> data);
void run_simulations_for_each_simple(std::string name, std::string suffix, std::vector<Data> data);
std::string get_suffix();

#endif//MONTECARLO_BSE_SIMULATE_H
