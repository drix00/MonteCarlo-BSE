/**
 * @file
 *
 * Tests for options/program_options_parser.cpp and options/program_options_parser.h.
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
#include <array>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "options/program_options_parser.h"
// Project private headers

// Global and constant variables/functions.

/**
 * Test if ProgramOptionsParser tests were find.
 */
TEST_CASE("Test if ProgramOptionsParser tests were find", "[options]")
{
    REQUIRE(true);
}

/**
 * Test parse_command_line no option.
 */
TEST_CASE("Test parse_command_line no option", "[options]")
{
    const int argc = 1;
    std::array<const char*,argc> argv{ "mcbse" };

    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line input filename.
 */
TEST_CASE("Test parse_command_line input filename", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "input_file.in" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line output filename wo input file.
 */
TEST_CASE("Test parse_command_line output filename wo input file", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "-o", "output_file.out" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name == "output_file.out"); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == 107); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line output filename together short.
 */
TEST_CASE("Test parse_command_line output filename together short", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "input_file.in", "-ooutput_file.out" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name == "output_file.out"); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line output filename seperated short.
 */
TEST_CASE("Test parse_command_line output filename seperated short", "[options]")
{

    const int argc = 4;
    std::array<const char*,argc> argv{ "mcbse", "input_file.in", "-o", "output_file.out" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name == "output_file.out"); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line output filename seperated long.
 */
TEST_CASE("Test parse_command_line output filename seperated long", "[options]")
{

    const int argc = 4;
    std::array<const char*,argc> argv{ "mcbse", "input_file.in", "--output", "output_file.out" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name == "output_file.out"); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line output filename with =.
 */
TEST_CASE("Test parse_command_line output filename with =", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "input_file.in", "--output=output_file.out" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name == "output_file.out"); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line version option short.
 */
TEST_CASE("Test parse_command_line version option short", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "-v" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == true); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line version option long.
 */
TEST_CASE("Test parse_command_line version option long", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--version" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == true); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line version option long with input file.
 */
TEST_CASE("Test parse_command_line version option long with input file", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--version", "input_file.in" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == true); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == 108); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line overwrite option.
 */
TEST_CASE("Test parse_command_line overwrite option", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--overwrite" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == true); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == 107); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line no overwrite option.
 */
TEST_CASE("Test parse_command_line no overwrite option", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--no-overwrite" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == 107); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line overwrite option with input file.
 */
TEST_CASE("Test parse_command_line overwrite option with input file", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--overwrite", "input_file.in" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == true); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line threads option short no number.
 */
TEST_CASE("Test parse_command_line threads option short no number", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "-t" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == 114); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line threads option long no number.
 */
TEST_CASE("Test parse_command_line threads option long no number", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--threads" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == 114); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line threads option short with number.
 */
TEST_CASE("Test parse_command_line threads option short with number", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "-t", "5" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 5); // NOLINT
    REQUIRE(program_options.exit_value == 107); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line threads option long with number.
 */
TEST_CASE("Test parse_command_line threads option long with number", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--threads", "5" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 5); // NOLINT
    REQUIRE(program_options.exit_value == 107); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line threads option long with input file.
 */
TEST_CASE("Test parse_command_line threads option long with input file", "[options]")
{
    const int argc = 4;
    std::array<const char*,argc> argv{ "mcbse", "--threads", "5", "input_file.in" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 5); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger option.
 */
TEST_CASE("Test parse_command_line console_logger option", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line no console_logger option.
 */
TEST_CASE("Test parse_command_line no console_logger option", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--no-console_logger" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == false); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger option with input file.
 */
TEST_CASE("Test parse_command_line console_logger option with input file", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--no-console_logger", "input_file.in" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == false); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger_level option off.
 */
TEST_CASE("Test parse_command_line console_logger_level option off", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger_level", "off" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::off); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger_level option critical.
 */
TEST_CASE("Test parse_command_line console_logger_level option critical", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger_level", "critical" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::critical); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger_level option error.
 */
TEST_CASE("Test parse_command_line console_logger_level option error", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger_level", "error" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::err); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger_level option warning.
 */
TEST_CASE("Test parse_command_line console_logger_level option warning", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger_level", "warning" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger_level option info.
 */
TEST_CASE("Test parse_command_line console_logger_level option info", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger_level", "info" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::info); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger_level option debug.
 */
TEST_CASE("Test parse_command_line console_logger_level option debug", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger_level", "debug" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::debug); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line console_logger_level option trace.
 */
TEST_CASE("Test parse_command_line console_logger_level option trace", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--console_logger_level", "trace" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::trace); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line file_logger option.
 */
TEST_CASE("Test parse_command_line file_logger option", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line no file_logger option.
 */
TEST_CASE("Test parse_command_line no file_logger option", "[options]")
{
    const int argc = 2;
    std::array<const char*,argc> argv{ "mcbse", "--no-file_logger" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == false); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line file_logger option with input file.
 */
TEST_CASE("Test parse_command_line file_logger option with input file", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--no-file_logger", "input_file.in" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name == "input_file.in"); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == false); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line file_logger_level option off.
 */
TEST_CASE("Test parse_command_line file_logger_level option off", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger_level", "off" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::off);
}

/**
 * Test parse_command_line file_logger_level option critical.
 */
TEST_CASE("Test parse_command_line file_logger_level option critical", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger_level", "critical" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::critical);
}

/**
 * Test parse_command_line file_logger_level option error.
 */
TEST_CASE("Test parse_command_line file_logger_level option error", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger_level", "error" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::err);
}

/**
 * Test parse_command_line file_logger_level option warning.
 */
TEST_CASE("Test parse_command_line file_logger_level option warning", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger_level", "warning" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::warn);
}

/**
 * Test parse_command_line file_logger_level option info.
 */
TEST_CASE("Test parse_command_line file_logger_level option info", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger_level", "info" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::info);
}

/**
 * Test parse_command_line file_logger_level option debug.
 */
TEST_CASE("Test parse_command_line file_logger_level option debug", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger_level", "debug" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::debug);
}

/**
 * Test parse_command_line file_logger_level option trace.
 */
TEST_CASE("Test parse_command_line file_logger_level option trace", "[options]")
{
    const int argc = 3;
    std::array<const char*,argc> argv{ "mcbse", "--file_logger_level", "trace" };
    const ProgramOptions program_options = parse_command_line(argc, argv.data());

    REQUIRE(program_options.input_file_name.empty()); // NOLINT
    REQUIRE(program_options.output_file_name.empty()); // NOLINT
    REQUIRE(program_options.display_version == false); // NOLINT
    REQUIRE(program_options.overwrite == false); // NOLINT
    REQUIRE(program_options.number_threads == 0); // NOLINT
    REQUIRE(program_options.exit_value == EXIT_SUCCESS); // NOLINT
    REQUIRE(program_options.console_logger == true); // NOLINT
    REQUIRE(program_options.console_logger_level == spdlog::level::warn); // NOLINT
    REQUIRE(program_options.file_logger == true); // NOLINT
    REQUIRE(program_options.file_logger_level == spdlog::level::trace);
}
