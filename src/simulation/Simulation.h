#ifndef MONTECARLO_BSE_SIMULATION_H
#define MONTECARLO_BSE_SIMULATION_H

/**
 * @file
 *
 * @brief Simulate the electron interaction with matter.
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

/**
 * Basic Monte Carlo model for simulate electron interaction with matter.
 *
 * The single scattering model is based from the one presented in chapter 3 in the book Monte Carlo Modeling
 * for Electron Microscopy and Microanalysis by David C. Joy. The model simulate each elastic collision and
 * use continuous slowing down approximation for taking into account the inelastic collision (energy loss).
 * The geometry used is a simple box which allow to simulate bulk sample and thin film. The result obtained are
 * the backscattered electron coefficient (bse) and transmitted electron coefficient (te).
 */
class Simulation
{
  public:
    /**
     * Constructor.
     * @param input_ input parameters for the simulation
     * @param seed random number seed for the simulation
     */
    Simulation(Input input_, unsigned int long seed) : input{ input_ },
                                                       energy_loss{ input_.element.atomic_number, input_.element.atomic_weight_g_mol },
                                                       mean_free_path{ input_.element.atomic_weight_g_mol, input_.element.density_g_cm3 },
                                                       cross_section{ input_.element.atomic_number },
                                                       random_number{ seed } {};

    /**
     * Do the simulation for all electron trajectories.
     */
    void do_simulation();

    /**
     * Get the elapse time in second.
     *
     * @return elapse time in second.
     */
    double elapse_time_s();

    /**
     * Set the minimum energy in eV at which the electron is stopped.
     *
     * @param new_minimum_energy_eV
     */
    void set_minimum_energy_eV(const double new_minimum_energy_eV);

    /**
     * Set the lateral distance of the geometry box representing the sample.
     *
     * @param new_max_lateral_distance_nm
     */
    void set_max_lateral_distance_nm(const double new_max_lateral_distance_nm);

    /**
     * Backscattered electron coefficient.
     * @todo Make bse variable private and add a getter method.
     */
    Counter bse;

    /**
     * Transmitted electron coefficient.
     * @todo Make te variable private and add a getter method.
     */
    Counter te;

  private:
    /**
     * Input parameters for the simulation.
     */
    Input input;

    /**
     * Energy loss model.
     */
    EnergyLoss energy_loss;

    /**
     * Mean free path model.
     */
    MeanFreePath mean_free_path;

    /**
     * Elastic cross section.
     */
    Rutherford cross_section;

    /**
     * Random number generator.
     */
    RandomNumber random_number;

    /**
     * Elapse time of the simulation in ns.
     */
    std::chrono::nanoseconds elapse_time_ns{ 0 };

    /**
     * Conversion factor.
     */
    double const nm2cm = 1.0e-7;

    /**
     * Conversion factor.
     */
    double const keV2eV = 1.0e3;

    /**
     * The minimum energy in eV at which the electron is stopped.
     */
    double minimum_energy_eV{ 50.0 };

    /**
     * The lateral distance of the geometry box representing the sample.
     */
    double max_lateral_distance_nm{ 1.0e9 };
};

#endif// MONTECARLO_BSE_SIMULATION_H
