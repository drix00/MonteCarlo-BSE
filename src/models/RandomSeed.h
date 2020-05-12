//
// Created by Hendrix Demers on 2020-05-09.
//

#ifndef MONTECARLO_BSE_RANDOMSEED_H
#define MONTECARLO_BSE_RANDOMSEED_H


class RandomSeed
{
  public:
    unsigned int long operator()();

  private:
    int const minimum_entropy = 10;
};


#endif//MONTECARLO_BSE_RANDOMSEED_H
