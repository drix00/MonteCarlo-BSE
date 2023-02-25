#ifndef MONTECARLO_BSE_RANDOM_NUMBER_H
#define MONTECARLO_BSE_RANDOM_NUMBER_H

/**
 * @file
 *
 * @brief Random number generator model.
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
#include <random>
// Project private headers

/**
 * @brief Random number generator model.
 */
class RandomNumber
{
  public:
    /**
     * Constructor of the random number generator from a seed.
     *
     * @param[in] seed
     */
    explicit RandomNumber(unsigned int long seed) : engine{ seed }, distribution{ 0.0, 1.0 } {};

    /**
     * Compute a random number using the generator.
     *
     * @return a random number.
     */
    double operator()() { return distribution(engine); };

    /**
     * Set the seed for the random number generator.
     *
     * @param[in] seed
     */
    void seed(unsigned int seed) { engine.seed(seed); };

    /**
     * Magic number seed used testing and debugging.
     */
    static unsigned int const magic_seed = 42;

  private:
    std::mt19937_64 engine;
    std::uniform_real_distribution<double> distribution;
};

#endif//MONTECARLO_BSE_RANDOM_NUMBER_H
