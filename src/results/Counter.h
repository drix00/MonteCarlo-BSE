#ifndef MONTECARLO_BSE_COUNTER_H
#define MONTECARLO_BSE_COUNTER_H

/**
 * @file
 *
 * @brief A counter to compute statistic of a results without storing all values.
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
 * @brief A counter to compute statistic of a results without storing all values.
 */
class Counter
{
  public:
    /**
     * @brief Add a value to the result.
     *
     * @param[in] value
     */
    void add_value(double value);

    /**
     * @brief Number of values added to the counter.
     *
     * @return the number of values added to the counter.
     */
    [[nodiscard]] int counts() const { return number_x; };

    /**
     * @brief Minimum value of the counter.
     *
     * @return the minimum value of the counter.
     */
    [[nodiscard]] double min() const { return min_x; };

    /**
     * @brief Maximum value of the counter.
     *
     * @return the maximum value of the counter.
     */
    [[nodiscard]] double max() const { return max_x; };

    /**
     * @brief Mean value of the counter.
     *
     * @return the mean value of the counter.
     */
    [[nodiscard]] double mean() const;

    /**
     * @brief Variance value of the counter.
     *
     * @return the variance value of the counter.
     */
    [[nodiscard]] double variance() const;

    /**
     * @brief Standard deviation value of the counter.
     *
     * @return the standard deviation value of the counter.
     */
    [[nodiscard]] double standard_deviation() const;

  private:
    int number_x = 0;

    double sum_x = 0.0;
    double sum_xx = 0.0;

    double min_x = 1.0e9;
    double max_x = -1.0e9;
};

#endif// MONTECARLO_BSE_COUNTER_H
