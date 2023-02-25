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

// C system headers
// C++ system header
#include <chrono>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "Simulation.h"
// Project headers
#include "models/DirectionCosine.h"
// Project private headers

// Global and constant variables/functions.

/**
 * @todo Refactor in smaller methods.
 */
void Simulation::do_simulation()
{
    std::chrono::steady_clock::time_point start_time{ std::chrono::steady_clock::now() };

    for (int trajectory_id = 0; trajectory_id < input.number_trajectories; ++trajectory_id) {
        DirectionCosine direction = DirectionCosine{ 0.0, 0.0, -1.0 };
        double energy_eV = input.initial_energy_eV;
        double x_nm = 0.0;
        double y_nm = 0.0;
        double z_nm = 0.0;

        double sigma_nm2 = cross_section.compute_sigma_nm2(energy_eV);
        double mfp_nm = mean_free_path.compute_nm(sigma_nm2);
        double step_nm = mean_free_path.step_nm(mfp_nm, random_number());

        double theta_rad = 0.0;
        double phi_rad = 0.0;
        direction.compute(theta_rad, phi_rad);

        double delta_energy_eV = step_nm * nm2cm * energy_loss.compute_keV_g_cm2(energy_eV) * input.element.density_g_cm3 * keV2eV;
        energy_eV += delta_energy_eV;

        x_nm += step_nm * direction.ca;
        y_nm += step_nm * direction.cb;
        z_nm += step_nm * direction.cc;

        if (z_nm < -input.thickness_nm) {
            bse.add_value(0.0);
            te.add_value(1.0);
            continue;
        }

        if (x_nm < -max_lateral_distance_nm || x_nm > max_lateral_distance_nm) {
            continue;
        }

        if (y_nm < -max_lateral_distance_nm || y_nm > max_lateral_distance_nm) {
            continue;
        }

        while (energy_eV > minimum_energy_eV) {
            sigma_nm2 = cross_section.compute_sigma_nm2(energy_eV);
            mfp_nm = mean_free_path.compute_nm(sigma_nm2);
            step_nm = mean_free_path.step_nm(mfp_nm, random_number());

            theta_rad = cross_section.compute_scattering_angle_rad(energy_eV, random_number());
            phi_rad = cross_section.compute_azimuthal_angle_rad(random_number());
            direction.compute(theta_rad, phi_rad);

            delta_energy_eV = step_nm * nm2cm * energy_loss.compute_keV_g_cm2(energy_eV) * input.element.density_g_cm3 * keV2eV;
            energy_eV += delta_energy_eV;

            x_nm += step_nm * direction.ca;
            y_nm += step_nm * direction.cb;
            z_nm += step_nm * direction.cc;

            if (z_nm > 0.0) {
                bse.add_value(1.0);
                te.add_value(0.0);
                break;
            }

            if (z_nm < -input.thickness_nm) {
                bse.add_value(0.0);
                te.add_value(1.0);
                break;
            }

            if (x_nm < -max_lateral_distance_nm || x_nm > max_lateral_distance_nm) {
                break;
            }

            if (y_nm < -max_lateral_distance_nm || y_nm > max_lateral_distance_nm) {
                break;
            }
        }

        if (z_nm <= 0.0 && z_nm >= -input.thickness_nm) {
            bse.add_value(0.0);
            te.add_value(0.0);
        }
    }

    std::chrono::steady_clock::time_point end_time{ std::chrono::steady_clock::now() };
    std::chrono::duration elapse_time = end_time - start_time;
    elapse_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapse_time);
}

/**
 * @todo Use the Timer utility for conversion between ns to s.
 */
double Simulation::elapse_time_s()
{
    auto elapse_time_s = std::chrono::duration_cast<std::chrono::seconds>(elapse_time_ns).count();
    double fraction = static_cast<double>(elapse_time_ns.count()) - static_cast<double>(elapse_time_s) * 1.0e9;
    double time_s = static_cast<double>(elapse_time_s) + fraction * 1.0e-9;
    return time_s;
}

void Simulation::set_minimum_energy_eV(const double new_minimum_energy_eV)
{
    minimum_energy_eV = new_minimum_energy_eV;
}

void Simulation::set_max_lateral_distance_nm(const double new_max_lateral_distance_nm)
{
    max_lateral_distance_nm = new_max_lateral_distance_nm;
}
