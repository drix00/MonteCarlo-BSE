#ifndef MONTECARLO_BSE_INPUT_H
#define MONTECARLO_BSE_INPUT_H
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
#include "inputs/Element.h"
// Project private headers

class Input
{
  public:
    Input(Element element_, double initial_energy_eV_, int number_trajectories_, int repetition_id_=1)
        : element{ element_ }, initial_energy_eV{ initial_energy_eV_ }, number_trajectories{ number_trajectories_ }, repetition_id{repetition_id_} {};

  public:
    Element element;
    double initial_energy_eV;
    int number_trajectories;
    double thickness_nm = 1.0e9;
    int repetition_id;
};

#endif//MONTECARLO_BSE_INPUT_H
