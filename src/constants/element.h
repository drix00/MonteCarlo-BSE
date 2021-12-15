//
// Created by Hendrix Demers on 2021-07-27.
//

#ifndef MONTECARLO_BSE_ELEMENT_H
#define MONTECARLO_BSE_ELEMENT_H
#include <array>
#include <map>
#include <string>

namespace monte_carlo::constants::element {

std::string get_symbol(int atomic_number);
std::string get_name(int atomic_number);
double get_atomic_weight_g_mol(int atomic_number);
double get_atomic_mass_density_g_cm3(int atomic_number);

}// namespace monte_carlo

#endif//MONTECARLO_BSE_ELEMENT_H
