#ifndef MONTECARLO_BSE_DATA_H
#define MONTECARLO_BSE_DATA_H

/**
 * @file
 *
 * @brief Data used by the simulation runner.
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
#include <string>
// Library headers
// Project headers
#include "inputs/Input.h"
// Project private headers

/**
 * @brief Data (input and results) used by the simulation runner.
 */
class Data
{
  public:
    /**
     * Constructor.
     *
     * @param[in] input_ input parameters for the simulation
     * @param[in] line_ simulation results
     */
    Data(const Input input_, const std::string line_): input{input_}, line{line_} {}

    /**
     * The input parameters for the simulation.
     */
    Input input;

    /**
     * The simulation results.
     */
    std::string line;
};

#endif//MONTECARLO_BSE_DATA_H
