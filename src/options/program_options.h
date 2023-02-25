#ifndef MONTECARLO_BSE_PROGRAM_OPTIONS_H
#define MONTECARLO_BSE_PROGRAM_OPTIONS_H

/**
 * @file
 *
 * @brief Options of the programs.
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

/**
 * @brief Options of the programs.
 */
class ProgramOptions
{
  public:
    /**
     * Program option input file name.
     */
    std::string input_file_name{};

    /**
     * Program option output file name.
     */
    std::string output_file_name{};

    /**
     * Program option display version.
     */
    bool display_version{false};

    /**
     * Program option overwrite flag.
     */
    bool overwrite{false};

    /**
     * Program option number of thread to use during the simulation.
     */
    int number_threads{0};

    /**
     * Program option exit value of the simulation.
     */
    int exit_value{EXIT_SUCCESS};

    /**
     * Program option use console logger.
     */
    bool console_logger{true};

    /**
     * Program option logging level of the console logger.
     */
    spdlog::level::level_enum console_logger_level{spdlog::level::warn};

    /**
     * Program option use file logger.
     */
    bool file_logger{true};

    /**
     * Program option logging level of the file logger.
     */
    spdlog::level::level_enum file_logger_level{spdlog::level::debug};
};

#endif// MONTECARLO_BSE_PROGRAM_OPTIONS_H
