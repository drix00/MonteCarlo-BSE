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

// C system headers
// C++ system header
#include <cmath>
// Library headers
// Precompiled header
#pragma hdrstop
// Current declaration header file of this implementation file.
#include "DirectionCosine.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

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
