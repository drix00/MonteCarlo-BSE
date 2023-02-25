#ifndef MONTECARLO_BSE_PROGRAM_OPTIONS_PARSER_H
#define MONTECARLO_BSE_PROGRAM_OPTIONS_PARSER_H

/**
 * @file
 *
 * @brief Parser for the command line options.
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
// Library headers
// Project headers
#include "options/program_options.h"
// Project private headers

/**
 * @brief Parse the command line to get the program options.
 *
 * @param[in] argc number of command line arguments
 * @param[in] argv command line arguments
 * @return program options object.
 */
ProgramOptions parse_command_line(const int argc, const char *const *argv);

#endif// MONTECARLO_BSE_PROGRAM_OPTIONS_PARSER_H
