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
#include <string>
#include <map>
// Library headers
#if __has_include("CLI/CLI.hpp")
#include "CLI/CLI.hpp"
#else
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#endif
#include "spdlog/spdlog.h"
#include "spdlog/common.h"
// Precompiled header
// Current declaration header file of this implementation file.
#include "options/program_options_parser.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

ProgramOptions parse_command_line(int argc, char *argv[])
{
    CLI::App app{"Monte Carlo BSE simulator"};

    std::string input_file_name{};
    auto *input_file_option = app.add_option("input_file", input_file_name, "Input file name");

    std::string output_file_name{};
    app.add_option("-o,--output", output_file_name, "Output file name")->needs(input_file_option);

    bool version{false};
    app.add_flag("-v,--version", version, "Print the version")->excludes(input_file_option);

    bool overwrite{false};
    app.add_flag("--overwrite,!--no-overwrite", overwrite, "Overwrite the output file")->needs(input_file_option);

    int number_threads{0};
    app.add_option("-t,--threads", number_threads, "Number of threads to use during the simulation")->needs(input_file_option);

    bool console_logger{true};
    app.add_flag("--console_logger,!--no-console_logger", console_logger, "Activate the console logger");

    std::map<std::string, spdlog::level::level_enum> map_levels{
        {"off", spdlog::level::off},
        {"critical", spdlog::level::critical},
        {"error", spdlog::level::err},
        {"warning", spdlog::level::warn},
        {"info", spdlog::level::info},
        {"debug", spdlog::level::debug},
        {"trace", spdlog::level::trace}
    };

    spdlog::level::level_enum console_logger_level{spdlog::level::warn};
    app.add_option("--console_logger_level,", console_logger_level, "Console logger level")
        ->transform(CLI::CheckedTransformer(map_levels, CLI::ignore_case));

    bool file_logger{true};
    app.add_flag("--file_logger,!--no-file_logger", file_logger, "Activate the file logger");

    spdlog::level::level_enum file_logger_level{spdlog::level::debug};
    app.add_option("--file_logger_level,", file_logger_level, "File logger level")
        ->transform(CLI::CheckedTransformer(map_levels, CLI::ignore_case));

    ProgramOptions program_options;

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        program_options.exit_value =  app.exit(e);
        spdlog::error("{}: {}", e.get_name(), e.get_exit_code());
    }

    program_options.input_file_name = input_file_name;
    program_options.output_file_name = output_file_name;
    program_options.display_version = version;
    program_options.overwrite = overwrite;
    program_options.number_threads = number_threads;
    program_options.console_logger = console_logger;
    program_options.console_logger_level = console_logger_level;
    program_options.file_logger = file_logger;
    program_options.file_logger_level = file_logger_level;

    return program_options;
}
