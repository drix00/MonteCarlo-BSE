#ifndef MONTECARLO_BSE_SIMULATION_H
#define MONTECARLO_BSE_SIMULATION_H
/**
 * @file
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2022
 */

//   Copyright 2022 Hendrix Demers
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

// Forwards declarations
// C system headers
// C++ system header
#include <chrono>
// Library headers
// Project headers
#include "inputs/Input.h"
#include "models/EnergyLoss.h"
#include "models/MeanFreePath.h"
#include "models/Rutherford.h"
#include "models/RandomNumber.h"
#include "results/Counter.h"
// Project private headers

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

    std::chrono::nanoseconds elapse_time_ns{0};

    double const nm2cm = 1.0e-7;
    double const keV2eV = 1.0e3;
};

#endif//MONTECARLO_BSE_SIMULATION_H
