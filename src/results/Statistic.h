#ifndef MONTECARLO_BSE_STATISTIC_H
#define MONTECARLO_BSE_STATISTIC_H

/**
 * @file
 *
 * @brief A utility to compute statistic of a results without storing all values.
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
 * @brief A utility to compute statistic of a results without storing all values.
 */
class Statistic
{
  public:
    /**
     * @brief Add a value to the result.
     *
     * @param[in] value new value to add to result
     */
    void add_value(double value);

    /**
     * @brief Number of values added to the result.
     *
     * @return the number of values added to the result.
     */
    [[nodiscard]] int counts() const { return number_x; };

    /**
     * @brief Minimum value of the result.
     *
     * @return the minimum value of the result.
     */
    [[nodiscard]] double min() const { return min_x; };

    /**
     * @brief Maximum value of the result.
     *
     * @return the maximum value of the result.
     */
    [[nodiscard]] double max() const { return max_x; };

    /**
     * @brief Mean value of the result.
     *
     * @return the mean value of the result.
     */
    [[nodiscard]] double mean() const;

    /**
     * @brief Variance value of the result.
     *
     * @return the variance value of the result.
     */
    [[nodiscard]] double variance() const;

    /**
     * @brief Standard deviation value of the result.
     *
     * @return the standard deviation value of the result.
     */
    [[nodiscard]] double standard_deviation() const;

    /**
     * @brief Mean absolute deviation value of the result.
     *
     * @return the mean absolute deviation value of the result.
     */
    [[nodiscard]] double mean_absolute_deviation() const;

    /**
     * @brief Skewness value of the result.
     *
     * @return the skewness value of the result.
     */
    [[nodiscard]] double skewness() const;

    /**
     * @brief Kurtosis value of the result.
     *
     * @return the kurtosis value of the result.
     */
    [[nodiscard]] double kurtosis() const;

  private:
    int number_x = 0;

    double sum_x = 0.0;
    double sum_xx = 0.0;
    double sum_xxx = 0.0;
    double sum_xxxx = 0.0;

    double min_x = 1.0e9;
    double max_x = -1.0e9;
};

#endif//MONTECARLO_BSE_STATISTIC_H
