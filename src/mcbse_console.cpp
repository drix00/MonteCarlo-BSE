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

// C system headers
// C++ system header
#include <iostream>
#include <cstdlib>
// Library headers
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
// Precompiled header
// Current declaration header file of this implementation file.
// Project headers
// Project private headers

// Global and constant variables/functions.

void create_logger(const bool console_logger=true, const bool file_logger=true) {
    try
    {
        std::vector<spdlog::sink_ptr> sinks;

        if (console_logger) {
            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            console_sink->set_level(spdlog::level::warn);
            console_sink->set_pattern("[mcbse_console] [%^%l%$] : %v");
            sinks.push_back(console_sink);
        }

        if (file_logger) {
            auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/mcbse_console.log", true);
            file_sink->set_level(spdlog::level::trace);
            file_sink->set_pattern("[%Y-%m-%d] [%H:%M:%S %z] [mcbse_console] [%^%l%$] [thread %t] : %v");
            sinks.push_back(file_sink);
        }

        spdlog::logger logger("mcbse_console", sinks.begin(), sinks.end());
        logger.set_level(spdlog::level::debug);
        logger.info("MC-BSE logging is started");

        // Set mcbse_console logger as default logger
        spdlog::set_default_logger(std::make_shared<spdlog::logger>("mcbse_console", begin(sinks), end(sinks)));

    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}

/**
 * MC-BSE console main.
 *
 * \todo Add timing feature for each major part of the program.
 * \todo Add command line feature.
 * \todo Add progress bar.
 *
 * @param[in] argc Non-negative value representing the number of arguments passed to the program from the environment in which the program is run.
 * @param[in] argv Pointer to the first element of an array of argc + 1 pointers, of which the last one is null and the previous ones, if any, point to null-terminated multibyte strings that represent the arguments passed to the program from the execution environment. If argv[0] is not a null pointer (or, equivalently, if argc > 0), it points to a string that represents the name used to invoke the program, or to an empty string.
 * @return A integer value to indicate the success or failure of the program run.
 */
int main(int argc, char *argv[]) {
    try {
        create_logger();

        spdlog::info("argc == {}", argc);

        for(int index{}; index != argc; ++index) { // NOLINT(altera-unroll-loops)
            spdlog::info( "argv[{}] == {}", index, argv[index]);
        }
    }
    catch (...) {
        spdlog::error( "Un caught exception in main function of MC-BSE. Program terminated");
        return EXIT_FAILURE;
    }

    spdlog::info( "MC-BSE run successfully");
    return EXIT_SUCCESS;
}
