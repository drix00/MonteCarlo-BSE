//
// Created by Hendrix Demers on 2020-05-08.
//

#ifndef MONTECARLO_BSE_ENERGY_LOSS_H
#define MONTECARLO_BSE_ENERGY_LOSS_H


class EnergyLoss
{
  public:
    EnergyLoss(double atomic_number_, double atomic_weight_g_mol_) : atomic_number{ atomic_number_ }, atomic_weight_g_mol{ atomic_weight_g_mol_ } {};
    double compute_mean_ionisation_potential_eV() const;
    double compute(double energy_eV) const;
    double compute_bethe1930(double energy_eV) const;
    double compute_joy_luo1989(double energy_eV) const;

  private:
    double atomic_number;
    double atomic_weight_g_mol;
};


#endif//MONTECARLO_BSE_ENERGY_LOSS_H
