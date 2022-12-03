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
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "options/program_options_parser.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if ProgramOptionsParser tests were find", "[options]")
{
    REQUIRE(true);
}

TEST_CASE("Test parse_command_line no option", "[options]")
{
    int argc = 1;
    const char *argv[] = { "mcbse" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line input filename", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "input_file.in" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line output filename wo input file", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "-o", "output_file.out" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "output_file.out");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == 107);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line output filename together short", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "input_file.in", "-ooutput_file.out" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "output_file.out");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line output filename seperated short", "[options]")
{

    int argc = 4;
    const char *argv[] = { "mcbse", "input_file.in", "-o", "output_file.out" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "output_file.out");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line output filename seperated long", "[options]")
{

    int argc = 4;
    const char *argv[] = { "mcbse", "input_file.in", "--output", "output_file.out" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "output_file.out");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line output filename with =", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "input_file.in", "--output=output_file.out" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "output_file.out");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line version option short", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "-v" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == true);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line version option long", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--version" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == true);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line version option long with input file", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--version", "input_file.in" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == true);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == 108);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line overwrite option", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--overwrite" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == true);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == 107);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line no overwrite option", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--no-overwrite" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == 107);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line overwrite option with input file", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--overwrite", "input_file.in" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == true);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line threads option short no number", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "-t" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == 114);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line threads option long no number", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--threads" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == 114);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line threads option short with number", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "-t", "5" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 5);
    REQUIRE(po.exit_value == 107);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line threads option long with number", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--threads", "5" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 5);
    REQUIRE(po.exit_value == 107);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line threads option long with input file", "[options]")
{
    int argc = 4;
    const char *argv[] = { "mcbse", "--threads", "5", "input_file.in" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 5);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger option", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--console_logger" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line no console_logger option", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--no-console_logger" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == false);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger option with input file", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--no-console_logger", "input_file.in" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == false);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger_level option off", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--console_logger_level", "off" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::off);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger_level option critical", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--console_logger_level", "critical" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::critical);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger_level option error", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--console_logger_level", "error" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::err);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger_level option warning", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--console_logger_level", "warning" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger_level option info", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--console_logger_level", "info" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::info);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger_level option debug", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--console_logger_level", "debug" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::debug);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line console_logger_level option trace", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--console_logger_level", "trace" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::trace);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line file_logger option", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--file_logger" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line no file_logger option", "[options]")
{
    int argc = 2;
    const char *argv[] = { "mcbse", "--no-file_logger" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == false);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line file_logger option with input file", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--no-file_logger", "input_file.in" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "input_file.in");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == false);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line file_logger_level option off", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--file_logger_level", "off" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::off);
}

TEST_CASE("Test parse_command_line file_logger_level option critical", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--file_logger_level", "critical" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::critical);
}

TEST_CASE("Test parse_command_line file_logger_level option error", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--file_logger_level", "error" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::err);
}

TEST_CASE("Test parse_command_line file_logger_level option warning", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--file_logger_level", "warning" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::warn);
}

TEST_CASE("Test parse_command_line file_logger_level option info", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--file_logger_level", "info" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::info);
}

TEST_CASE("Test parse_command_line file_logger_level option debug", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--file_logger_level", "debug" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::debug);
}

TEST_CASE("Test parse_command_line file_logger_level option trace", "[options]")
{
    int argc = 3;
    const char *argv[] = { "mcbse", "--file_logger_level", "trace" };
    ProgramOptions po = parse_command_line(argc, argv);

    REQUIRE(po.input_file_name == "");
    REQUIRE(po.output_file_name == "");
    REQUIRE(po.display_version == false);
    REQUIRE(po.overwrite == false);
    REQUIRE(po.number_threads == 0);
    REQUIRE(po.exit_value == EXIT_SUCCESS);
    REQUIRE(po.console_logger == true);
    REQUIRE(po.console_logger_level == spdlog::level::warn);
    REQUIRE(po.file_logger == true);
    REQUIRE(po.file_logger_level == spdlog::level::trace);
}
