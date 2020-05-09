//
// Created by Hendrix Demers on 2020-05-09.
//

#ifndef MONTECARLO_BSE_RANDOM_NUMBER_H
#define MONTECARLO_BSE_RANDOM_NUMBER_H

#include <random>

class RandomNumber
{
  public:
    explicit RandomNumber(unsigned int seed) : engine{ seed }, distribution{ 0.0, 1.0 } {};
    double operator()() { return distribution(engine); };
    void seed(unsigned int seed) { engine.seed(seed); };

  public:
    static unsigned int const magic_seed = 42;

  private:
    std::mt19937_64 engine;
    std::uniform_real_distribution<double> distribution;
};


#endif//MONTECARLO_BSE_RANDOM_NUMBER_H
