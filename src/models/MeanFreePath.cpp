//
// Created by Hendrix Demers on 2020-05-09.
//

#include "MeanFreePath.h"

#include <cmath>
#include <cassert>

double MeanFreePath::compute_nm(double sigma_nm2) const
{
    double sigma_cm2 = sigma_nm2 * nm2cm * nm2cm;
    double value_cm = atomic_weight_g_mol / (avogadro_number_1_mol * density_g_cm3 * sigma_cm2);
    double value_nm = value_cm * cm2nm;
    return value_nm;
}

double MeanFreePath::step_nm(double mfp_nm, double random_number) const
{
    assert(random_number >= 0.0);
    assert(random_number < 1.0);

    double value = -1.0 * mfp_nm * std::log(1.0 - random_number);
    return value;
}
