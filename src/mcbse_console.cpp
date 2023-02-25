/**
 * @file
 *
 * @brief Main entry of the MC-BSE console program.
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

// C system headers
// C++ system header
#include <cstdlib>
#include <iostream>
// Library headers
#include "spdlog/spdlog.h"
// Precompiled header
// Current declaration header file of this implementation file.
// Project headers
#include "utilities/logger.h"
#include "utilities/version.h"
#include "options/program_options_parser.h"
#include "options/program_options.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Log the exit value for the program.
 *
 * @param[in] exit_value
 * @return A integer value to indicate the success or failure of the program run.
 */
int mcbse_exit(const int exit_value = EXIT_SUCCESS)
{
    if (exit_value == EXIT_SUCCESS) {
        SPDLOG_INFO("MC-BSE run successfully: {}", exit_value);
    } else {
        SPDLOG_INFO("MC-BSE has error: {}", exit_value);
    }

    spdlog::info("========================================================================================================================");
    return exit_value;
}

/**
 * MC-BSE console main.
 *
 * @todo Add timing feature for each major part of the program.
 * @todo Add progress bar.
 *
 * @param[in] argc Non-negative value representing the number of arguments passed to the program from the environment
 * in which the program is run.
 * @param[in] argv Pointer to the first element of an array of argc + 1 pointers, of which the last one is null
 * and the previous ones, if any, point to null-terminated multibyte strings that represent the arguments passed to
 * the program from the execution environment. If argv[0] is not a null pointer (or, equivalently, if argc > 0),
 * it points to a string that represents the name used to invoke the program, or to an empty string.
 * @return A integer value to indicate the success or failure of the program run.
 */
int main(int argc, char *argv[])
{
    try {
        create_logger();

        const ProgramOptions program_options = parse_command_line(argc, argv);

        create_logger(program_options.console_logger, program_options.file_logger);

        SPDLOG_INFO("MC-BSE logging is started");
        log_program_arguments(argc, argv);
        log_program_information();

        if (program_options.exit_value != EXIT_SUCCESS) {
            return mcbse_exit(program_options.exit_value);
        }

        if (program_options.display_version) {
            std::cout << "Monte Carlo BSE version: " << get_version_str() << std::endl;
            return mcbse_exit(EXIT_SUCCESS);
        }
    } catch (...) {
        SPDLOG_ERROR("Uncaught exception in main function of MC-BSE. Program terminated");
        return mcbse_exit(EXIT_FAILURE);
    }

    return mcbse_exit(EXIT_SUCCESS);
}
