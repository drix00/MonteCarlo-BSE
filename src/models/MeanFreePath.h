//
// Created by Hendrix Demers on 2020-05-09.
//

#ifndef MONTECARLO_BSE_MEAN_FREE_PATH_H
#define MONTECARLO_BSE_MEAN_FREE_PATH_H


class MeanFreePath
{
  public:
    MeanFreePath(double atomic_weight_g_mol_, double density_g_cm3_) : atomic_weight_g_mol{ atomic_weight_g_mol_ }, density_g_cm3{ density_g_cm3_ } {};
    double compute_nm(double sigma_nm2) const;
    double step_nm(double mfp_nm, double random_number) const;

  private:
    double atomic_weight_g_mol;
    double density_g_cm3;
    double const avogadro_number_1_mol = 6.02214076e23;
    double const nm2cm = 1.0e-7;
    double const cm2nm = 1.0e7;
};


#endif//MONTECARLO_BSE_MEAN_FREE_PATH_H
