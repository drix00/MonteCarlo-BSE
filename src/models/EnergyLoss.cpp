//
// Created by Hendrix Demers on 2020-05-08.
//

#include "EnergyLoss.h"

#include <cmath>

double EnergyLoss::compute_keV_g_cm2(double energy_eV) const
{
    double value_keV_g_cm2 = compute_joy_luo1989(energy_eV);
    return value_keV_g_cm2;
}

double EnergyLoss::compute_bethe1930(double energy_eV) const
{
    double const energy_keV = energy_eV * 1.0e-3;
    double const factor1 = -78500.0 * atomic_number / (atomic_weight_g_mol * energy_keV);
    double const J_keV = compute_mean_ionisation_potential_eV() * 1.0e-3;
    double const factor2 = std::log(1.166 * energy_keV / J_keV);
    double const value = factor1 * factor2;

    return value;
}

double EnergyLoss::compute_joy_luo1989(double energy_eV) const
{
    double const energy_keV = energy_eV * 1.0e-3;
    double const factor1 = -78500.0 * atomic_number / (atomic_weight_g_mol * energy_keV);
    double const J_keV = compute_mean_ionisation_potential_eV() * 1.0e-3;
    double const factor2 = std::log(1.166 * (energy_keV + 0.85 * J_keV) / J_keV);
    double const value = factor1 * factor2;

    return value;
}

double EnergyLoss::compute_mean_ionisation_potential_eV() const
{
    double const value = (9.76 * atomic_number + 58.5 / std::pow(atomic_number, 0.19));
    return value;
}
