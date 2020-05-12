//
// Created by Hendrix Demers on 2020-05-09.
//

#ifndef MONTECARLO_BSE_SIMULATION_H
#define MONTECARLO_BSE_SIMULATION_H

#include <chrono>

#include "inputs/Input.h"
#include "models/EnergyLoss.h"
#include "models/MeanFreePath.h"
#include "models/Rutherford.h"
#include "models/RandomNumber.h"
#include "results/Counter.h"

class Simulation
{
  public:
    Simulation(Input input_, unsigned int long seed) : input{ input_ },
                                                  energy_loss{ input_.element.atomic_number, input_.element.atomic_weight_g_mol },
                                                  mean_free_path{ input_.element.atomic_weight_g_mol, input_.element.density_g_cm3 },
                                                  cross_section{ input_.element.atomic_number },
                                                  random_number{ seed } {};
    void do_simulation();
    double elapse_time_s();

  public:
    Counter bse;
    Counter te;

  private:
    Input input;

    EnergyLoss energy_loss;
    MeanFreePath mean_free_path;
    Rutherford cross_section;
    RandomNumber random_number;

    std::chrono::nanoseconds elapse_time_ns;

    double const nm2cm = 1.0e-7;
    double const keV2eV = 1.0e3;
};


#endif//MONTECARLO_BSE_SIMULATION_H
