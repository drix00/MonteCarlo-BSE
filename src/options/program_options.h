#ifndef MONTECARLO_BSE_PROGRAM_OPTIONS_H
#define MONTECARLO_BSE_PROGRAM_OPTIONS_H

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
#include <cstdlib>
#include <string>
// Library headers
#include <spdlog/common.h>
// Project headers
// Project private headers

class ProgramOptions
{
  public:
    std::string input_file_name{};
    std::string output_file_name{};
    bool display_version{false};
    bool overwrite{false};
    int number_threads{0};
    int exit_value{EXIT_SUCCESS};
    bool console_logger{true};
    spdlog::level::level_enum console_logger_level{spdlog::level::warn};
    bool file_logger{true};
    spdlog::level::level_enum file_logger_level{spdlog::level::debug};
};


#endif// MONTECARLO_BSE_PROGRAM_OPTIONS_H
