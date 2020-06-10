//
// Created by Hendrix Demers on 2020-05-09.
//

#include "Simulation.h"

#include <chrono>

#include "models/DirectionCosine.h"

void Simulation::do_simulation()
{
    std::chrono::steady_clock::time_point start_time{ std::chrono::steady_clock::now() };

    double minimum_energy_eV = 50.0;

    for (int trajectory_id = 0; trajectory_id < input.number_trajectories; ++trajectory_id) {
        DirectionCosine direction = DirectionCosine{ 0.0, 0.0, -1.0 };
        double energy_eV = input.initial_energy_eV;
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;

        double sigma_nm2 = cross_section.compute_sigma_nm2(energy_eV);
        double mfp_nm = mean_free_path.compute_nm(sigma_nm2);
        double step_nm = mean_free_path.step_nm(mfp_nm, random_number());

        double theta_rad = 0.0;
        double phi_rad = 0.0;
        direction.compute(theta_rad, phi_rad);

        double delta_energy_eV = step_nm * nm2cm * energy_loss.compute_keV_g_cm2(energy_eV) * input.element.density_g_cm3 * keV2eV;
        energy_eV += delta_energy_eV;

        x += step_nm * direction.ca;
        y += step_nm * direction.cb;
        z += step_nm * direction.cc;

        if (z < -input.thickness_nm) {
            bse.add_value(0.0);
            te.add_value(1.0);
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

            x += step_nm * direction.ca;
            y += step_nm * direction.cb;
            z += step_nm * direction.cc;

            if (z > 0.0) {
                bse.add_value(1.0);
                te.add_value(0.0);
                break;
            }

            if (z < -input.thickness_nm) {
                bse.add_value(0.0);
                te.add_value(1.0);
                break;
            }
        }
        if (z <= 0.0 && z >= -input.thickness_nm) {
            bse.add_value(0.0);
            te.add_value(0.0);
        }
    }

    std::chrono::steady_clock::time_point end_time{ std::chrono::steady_clock::now() };
    std::chrono::duration elapse_time = end_time - start_time;
    elapse_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapse_time);
}

double Simulation::elapse_time_s()
{
    auto elapse_time_s = std::chrono::duration_cast<std::chrono::seconds>(elapse_time_ns).count();
    double fraction = static_cast<double>(elapse_time_ns.count()) - static_cast<double>(elapse_time_s) * 1.0e9;
    double time_s = static_cast<double>(elapse_time_s) + fraction * 1.0e-9;
    return time_s;
}
