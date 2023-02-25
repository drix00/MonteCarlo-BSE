#ifndef MONTECARLO_BSE_DIRECTION_COSINE_H
#define MONTECARLO_BSE_DIRECTION_COSINE_H

/**
 * @file
 *
 * @brief Model to compute the direction cosine.
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
// Library headers
// Project headers
// Project private headers

/**
 * @brief Model to compute the direction cosine.
 */
class DirectionCosine
{
  public:
    /**
     * Constructor with initial value of the direction cosines.
     *
     * @param[in] ca_ direction cosine for the x axis
     * @param[in] cb_ direction cosine for the y axis
     * @param[in] cc_ direction cosine for the z axis
     */
    DirectionCosine(double ca_, double cb_, double cc_) : ca{ ca_ }, cb{ cb_ }, cc{ cc_ } {};

    /**
     * @brief General method to compute the direction cosines from two scattering angles.
     *
     * @param[in] theta_rad deflection scattering angle
     * @param[in] phi_rad azimuthal scattering angle
     */
    void compute(double theta_rad, double phi_rad);

    /**
     * @brief Compute the direction cosines from two scattering angles using Joy (1995) model.
     *
     * @param[in] theta_rad deflection scattering angle
     * @param[in] phi_rad azimuthal scattering angle
     */
    void compute_joy1995(double theta_rad, double phi_rad);

    /**
     * Current direction cosine for the x axis.
     */
    double ca;

    /**
     * Current direction cosine for the y axis.
     */
    double cb;

    /**
     * Current direction cosine for the z axis.
     */
    double cc;
};

#endif//MONTECARLO_BSE_DIRECTION_COSINE_H
