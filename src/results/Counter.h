//
// Created by hendr on 2020-05-11.
//

#ifndef MONTECARLO_BSE_COUNTER_H
#define MONTECARLO_BSE_COUNTER_H


class Counter
{
  public:
    void add_value(double value_);
    int counts() const { return number_x; };
    double min() const { return min_x; };
    double max() const { return max_x; };
    double mean() const;
    double variance() const;
    double standard_deviation() const;

  private:
    int number_x = 0;

    double sum_x = 0.0;
    double sum_xx = 0.0;

    double min_x = 1.0e9;
    double max_x = -1.0e9;
};


#endif//MONTECARLO_BSE_COUNTER_H
