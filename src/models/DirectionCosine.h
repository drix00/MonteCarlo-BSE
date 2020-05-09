//
// Created by Hendrix Demers on 2020-05-09.
//

#ifndef MONTECARLO_BSE_DIRECTION_COSINE_H
#define MONTECARLO_BSE_DIRECTION_COSINE_H


class DirectionCosine
{
  public:
    DirectionCosine(double ca_, double cb_, double cc_) : ca{ ca_ }, cb{ cb_ }, cc{ cc_ } {};
    void compute(double theta_rad, double phi_rad);
    void compute_joy1995(double theta_rad, double phi_rad);

  public:
    double ca;
    double cb;
    double cc;
};


#endif//MONTECARLO_BSE_DIRECTION_COSINE_H
