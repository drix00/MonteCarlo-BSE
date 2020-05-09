//
// Created by Hendrix Demers on 2020-05-08.
//

#ifndef MONTECARLO_BSE_RUTHERFORD_H
#define MONTECARLO_BSE_RUTHERFORD_H


class Rutherford
{
  public:
    Rutherford(int atomic_number_) : atomic_number{ atomic_number_ }
    {}
    double compute_alpha(double energy_eV) const;
    double compute_sigma_nm2(double energy_eV);
    double compute_scattering_angle_rad(double energy_eV, double random_number);
    double compute_azimuthal_angle_rad(double random_number) const;

  private:
    int atomic_number;
};


#endif//MONTECARLO_BSE_RUTHERFORD_H
