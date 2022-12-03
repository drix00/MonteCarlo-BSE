#ifndef MONTECARLO_BSE_LOGGER_H
#define MONTECARLO_BSE_LOGGER_H

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
// Library headers
// Project headers
// Project private headers

/**
 * Create a logger for the program.
 *
 * @param console_logger flag to create a console logger
 * @param file_logger flag to create a file logger
 */
void create_logger(const bool console_logger=true, const bool file_logger=true);

/**
 * Log the program arguments.
 * @param argc number of arguments
 * @param argv  array of arguments
 */
void log_program_arguments(const int argc, const char *const *argv);

/**
 * Log various program information.
 */
void log_program_information();

#endif// MONTECARLO_BSE_LOGGER_H
