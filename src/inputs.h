//
// Created by hendrix on 2020-06-07.
//

#ifndef MONTECARLO_BSE_INPUTS_H
#define MONTECARLO_BSE_INPUTS_H
#include <vector>

#include "Data.h"

std::vector<Data> get_inputs_number_trajectories_repetitions();
std::vector<Data> get_inputs_elements_energies();
std::vector<Data> get_inputs_atomic_numbers();
std::vector<Data> get_inputs_densities();
std::vector<Data> get_inputs_thickness();
std::vector<Data> get_inputs_profile_serial_simple();

#endif//MONTECARLO_BSE_INPUTS_H
