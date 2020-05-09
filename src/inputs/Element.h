//
// Created by Hendrix Demers on 2020-05-08.
//

#ifndef MONTECARLO_BSE_ELEMENT_H
#define MONTECARLO_BSE_ELEMENT_H

class Element
{
  public:
    Element(int atomic_number_, double atomic_weight_g_mol_, double density_g_cm3_)
        : atomic_number{ atomic_number_ }, atomic_weight_g_mol{ atomic_weight_g_mol_ }, density_g_cm3{ density_g_cm3_ } {};

  public:
    int atomic_number;
    double atomic_weight_g_mol;
    double density_g_cm3;
};

Element get_c();
Element get_al();
Element get_si();
Element get_fe();
Element get_cu();
Element get_ag();
Element get_au();

#endif//MONTECARLO_BSE_ELEMENT_H
