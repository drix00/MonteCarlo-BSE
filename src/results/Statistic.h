//
// Created by Hendrix Demers on 2020-05-09.
//

#ifndef MONTECARLO_BSE_STATISTIC_H
#define MONTECARLO_BSE_STATISTIC_H


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
