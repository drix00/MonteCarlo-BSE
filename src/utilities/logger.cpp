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
// Library headers
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
// Precompiled header
// Current declaration header file of this implementation file.
// Project headers
#include "utilities/version.h"
#include "utilities/ProgramVersion.h"
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

void log_program_arguments(int argc, char *argv[])
{
    spdlog::info("argc == {}", argc);

    for(int index{}; index != argc; ++index) { // NOLINT(altera-unroll-loops)
        spdlog::info( "argv[{}] == {}", index, argv[index]);
    }
}

void log_program_information()
{
    spdlog::info( "Program name: {}", get_project_name());
    spdlog::info( "MC-BSE version: {}", get_version_str());
    spdlog::info( "MC-BSE version major: {}", get_version_major());
    spdlog::info( "MC-BSE version minor: {}", get_version_minor());
    spdlog::info( "MC-BSE version patch: {}", get_version_patch());
    spdlog::info( "MC-BSE version tweak: {}", get_version_tweak());

    spdlog::info("Program build: {}", mcbse::version::CURRENT_PROGRAM_VERSION.get_build_date_time_string());
    spdlog::info("Program compiler build: {}", mcbse::version::CURRENT_PROGRAM_VERSION.get_compiler_build_parameters_string());

}
