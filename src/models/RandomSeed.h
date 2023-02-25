#ifndef MONTECARLO_BSE_RANDOM_SEED_H
#define MONTECARLO_BSE_RANDOM_SEED_H

/**
 * @file
 *
 * @brief Model to compute the seed for the random generator.
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
 * @brief Model to compute the seed for the random generator.
 */
class RandomSeed
{
  public:
    /**
     * Constructor for the random generator seed using the minimum entropy value.
     *
     * @param[in] new_minimum_entropy
     */
    RandomSeed(int new_minimum_entropy = 10): minimum_entropy{new_minimum_entropy} {};

    /**
     * Compute the random number seed.
     *
     * @return the random number seed.
     */
    unsigned int long operator()();

  private:
    int minimum_entropy;
};

#endif // MONTECARLO_BSE_RANDOM_SEED_H
