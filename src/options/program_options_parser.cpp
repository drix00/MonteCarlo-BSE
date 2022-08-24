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
// Library headers
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "spdlog/spdlog.h"
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

    return program_options;
}
