/**
 * @file
 *
 * @brief Utilities for the logging information.
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
#include "spdlog/sinks/rotating_file_sink.h"
// Precompiled header
// Current declaration header file of this implementation file.
#include "utilities/logger.h"
// Project headers
#include "utilities/version.h"
#include "utilities/ProgramVersion.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Error log file (mcbse_console_errors.log) is always created.
 * Console logger and file logger (logs/mcbse_console.log) are only created if the corresponding option flag is true.
 *
 * @todo Check if the bug max width for message (%v) is 64 is reported in spdlog project.
 * @todo Check if the bug max width for message (%v) is 64 is fixed in new version of the spdlog project.
 */
void create_logger(const bool console_logger, const bool file_logger)
{
    try {
        std::vector<spdlog::sink_ptr> sinks;

        // Bug? max width for message (%v) is 64.
        const std::string log_pattern{ "[%Y-%m-%d] [%H:%M:%S %z] [%n] [%^%=9l%$] [process %6P, thread %6t] : %-64v [%g:%!:%#]" };
        auto error_file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/mcbse_console_errors.log", false);
        error_file_sink->set_level(spdlog::level::warn);
        error_file_sink->set_pattern(log_pattern);
        sinks.push_back(error_file_sink);

        if (console_logger) {
            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            console_sink->set_level(spdlog::level::warn);
            console_sink->set_pattern("[%n] [%^%=9l%$] : %v");
            sinks.push_back(console_sink);
        }

        if (file_logger) {
            const int max_size = 1048576 * 500;
            const int max_files = 100;
            auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/mcbse_console.log", max_size, max_files, false);
            file_sink->set_level(spdlog::level::trace);
            file_sink->set_pattern(log_pattern);
            sinks.push_back(file_sink);
        }

        auto mcbse_logger = std::make_shared<spdlog::logger>("mcbse_console", sinks.begin(), sinks.end());
        mcbse_logger->set_level(spdlog::level::trace);

        // Set mcbse_console mcbse_logger as default mcbse_logger
        spdlog::set_default_logger(mcbse_logger);
    } catch (const spdlog::spdlog_ex &ex) {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    }
}

void log_program_arguments(const int argc, const char *const *argv)
{
    spdlog::info("argc == {}", argc);

    for (int index{}; index != argc; ++index) {// NOLINT(altera-unroll-loops)
        spdlog::info("argv[{}] == {}", index, argv[index]);
    }
}

void log_program_information()
{
    spdlog::info("Program name: {}", get_project_name());
    spdlog::info("MC-BSE version: {}", get_version_str());
    spdlog::info("MC-BSE version major: {}", get_version_major());
    spdlog::info("MC-BSE version minor: {}", get_version_minor());
    spdlog::info("MC-BSE version patch: {}", get_version_patch());
    spdlog::info("MC-BSE version tweak: {}", get_version_tweak());

    spdlog::info("Program build: {}", mcbse::version::CURRENT_PROGRAM_VERSION.get_build_date_time_string());
    spdlog::info("Program compiler build: {}", mcbse::version::CURRENT_PROGRAM_VERSION.get_compiler_build_parameters_string());
}
