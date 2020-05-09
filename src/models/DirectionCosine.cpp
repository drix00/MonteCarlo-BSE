//
// Created by Hendrix Demers on 2020-05-09.
//

#include "DirectionCosine.h"

#include <cmath>

double const epsilon = 0.000001;

void DirectionCosine::compute(double theta_rad, double phi_rad)
{
    compute_joy1995(theta_rad, phi_rad);
}

void DirectionCosine::compute_joy1995(double theta_rad, double phi_rad)
{
    double cos_theta = std::cos(theta_rad);
    double sin_theta = std::sin(theta_rad);

    double cos_phi = std::cos(phi_rad);
    double sin_phi = std::sin(phi_rad);

    double cx = ca;
    double cy = cb;
    double cz = cc;
    if (cz == 0.0) {
        cz = epsilon;
    }

    double AN = -cx / cz;
    double AM = 1.0 / std::sqrt(1.0 + AN * AN);

    double V1 = AM * sin_theta;
    double V2 = AN * AM * sin_theta;
    double V3 = cos_phi;
    double V4 = sin_phi;

    ca = cx * cos_theta + V1 * V3 + cy * V2 * V4;
    cb = cy * cos_theta + V4 * (cz * V1 - cx * V2);
    cc = cz * cos_theta + V2 * V3 - cy * V1 * V4;
}
