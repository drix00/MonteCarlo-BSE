#ifndef MONTECARLO_BSE_DIRECTION_COSINE_H
#define MONTECARLO_BSE_DIRECTION_COSINE_H
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

// Forwards declarations
// C system headers
// C++ system header
// Library headers
// Project headers
// Project private headers

class DirectionCosine
{
  public:
    DirectionCosine(double ca_, double cb_, double cc_) : ca{ ca_ }, cb{ cb_ }, cc{ cc_ } {};
    void compute(double theta_rad, double phi_rad);
    void compute_joy1995(double theta_rad, double phi_rad);

  public:
    double ca;
    double cb;
    double cc;
};

#endif//MONTECARLO_BSE_DIRECTION_COSINE_H
