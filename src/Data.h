//
// Created by hendrix on 2020-06-07.
//

#ifndef MONTECARLO_BSE_DATA_H
#define MONTECARLO_BSE_DATA_H
#include <string>

#include "inputs/Input.h"


class Data
{
  public:
    Data(const Input input_, const std::string line_): input{input_}, line{line_} {}
    Input input;
    std::string line;
};


#endif//MONTECARLO_BSE_DATA_H
