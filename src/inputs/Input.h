//
// Created by Hendrix Demers on 2020-05-08.
//

#ifndef MONTECARLO_BSE_INPUT_H
#define MONTECARLO_BSE_INPUT_H

#include "inputs/Element.h"

class Input
{
  public:
    Input(Element element_, double initial_energy_eV_, int number_trajectories_)
        : element{ element_ }, initial_energy_eV{ initial_energy_eV_ }, number_trajectories{ number_trajectories_ } {};

  public:
    Element element;
    double initial_energy_eV;
    int number_trajectories;
    double thickness_nm = 1.0e9;
};

#endif//MONTECARLO_BSE_INPUT_H
