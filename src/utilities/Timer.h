//
// Created by hendrix on 2020-06-07.
//

#ifndef MONTECARLO_BSE_TIMER_H
#define MONTECARLO_BSE_TIMER_H

#include <iostream>
#include <string>
#include <chrono>

/**
 * Timer to print elapsed time.
 */
class Timer
{
  public:
    Timer(): start_time{std::chrono::steady_clock::now()}, last{std::chrono::steady_clock::now()} {}
    double get_elapse_time_s();
    double get_total_elapse_time_s();

  public:
    double compute_elapse_time_s(std::chrono::steady_clock::time_point start_time, std::chrono::steady_clock::time_point end_time);
  private:
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point last;
};


#endif//MONTECARLO_BSE_TIMER_H
