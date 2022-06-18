#ifndef MONTECARLO_BSE_STATISTIC_H
#define MONTECARLO_BSE_STATISTIC_H
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

class Statistic
{
  public:
    void add_value(double value_);
    int counts() const { return number_x; };
    double min() const { return min_x; };
    double max() const { return max_x; };
    double mean() const;
    double variance() const;
    double standard_deviation() const;
    double mean_absolute_deviation() const;
    double skewness() const;
    double kurtosis() const;

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
