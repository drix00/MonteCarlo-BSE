/**
 * @file
 *
 * @brief Tests for ProgramVersion.
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
#include "utilities/ProgramVersion.h"
// Project private headers

// Global and constant variables/functions.
using namespace mcbse::version;

TEST_CASE("Test if ProgramVersion tests were find", "[version]")
{
    REQUIRE(true);
}

TEST_CASE(" ProgramVersion test_complete_build_version", "[version]")
{
    const VersionInfo version(1U, 2U, 3U, 4U);

    REQUIRE(1U == version.get_version_major());
    REQUIRE(2U == version.get_version_minor());
    REQUIRE(3U == version.get_version_patch());
    REQUIRE(4U == version.get_version_tweak()); // NOLINT

    const ProgramVersion programVersion(version);

    const std::string buildString = programVersion.get_build_date_time_string();
    REQUIRE(false == buildString.empty()); // NOLINT

    const std::string compilerBuildString = programVersion.get_compiler_build_parameters_string();
    REQUIRE(false == compilerBuildString.empty());

    REQUIRE(true);
}

TEST_CASE("Check current program version constant CURRENT_PROGRAM_VERSION", "[version]")
{
    REQUIRE(CURRENT_VERSION == CURRENT_PROGRAM_VERSION.get_version());

    REQUIRE("0.3.0.1" == CURRENT_PROGRAM_VERSION.get_version().to_string());
    REQUIRE(0U == CURRENT_PROGRAM_VERSION.get_version().get_version_major());
    REQUIRE(3U == CURRENT_PROGRAM_VERSION.get_version().get_version_minor());
    REQUIRE(0U == CURRENT_PROGRAM_VERSION.get_version().get_version_patch());
    REQUIRE(1U == CURRENT_PROGRAM_VERSION.get_version().get_version_tweak());
}

TEST_CASE("Test ProgramVersion default values", "[version]")
{
    const ProgramVersion program_version{ VersionInfo{ 1U, 2U, 3U, 4U } };
    REQUIRE("McGill University" == program_version.get_company_name());
    REQUIRE("Monte Carlo BSE." == program_version.get_file_description());
    REQUIRE("1.2.3.4" == program_version.get_file_version());
    REQUIRE("mcbse_console.exe" == program_version.get_internal_name());
    REQUIRE("Copyright (C) 2022" == program_version.get_legal_copyright());
    REQUIRE("mcbse_console.exe" == program_version.get_original_file_name());
    REQUIRE("MC-BSE" == program_version.get_product_name());
    REQUIRE("1.2.3.4" == program_version.get_product_version());
    REQUIRE(VersionInfo{ 1U, 2U, 3U, 4U } == program_version.get_version());
}

TEST_CASE("Test ProgramVersion get_build_date_time_string", "[version]")
{
    const ProgramVersion program_version{ VersionInfo{ 1U, 2U, 3U, 4U } };

    const std::string build_date_time{ program_version.get_build_date_time_string() };
    REQUIRE(build_date_time.empty() == false);
}

TEST_CASE("Test ProgramVersion get_compiler_build_parameters_string", "[version]")
{
    const ProgramVersion program_version{ VersionInfo{ 1U, 2U, 3U, 4U } };

    const std::string compiler_build_parameters{ program_version.get_compiler_build_parameters_string() };
    REQUIRE(compiler_build_parameters.empty() == false);
}

TEST_CASE("Test ProgramVersion comparison operators", "[version]")
{
    ProgramVersion program_version1{ VersionInfo{ 1U, 2U, 3U, 4U } };

    const ProgramVersion program_version2{ VersionInfo{ 1U, 2U, 3U, 4U } };

    ProgramVersion program_version3{ VersionInfo{ 5U, 2U, 3U, 4U } }; // NOLINT
    program_version3.set_company_name("true");

    ProgramVersion program_version4{ VersionInfo{ 1U, 5U, 3U, 4U } }; // NOLINT
    program_version4.set_file_description("true");

    ProgramVersion program_version5{ VersionInfo{ 1U, 2U, 6U, 4U } }; // NOLINT
    program_version5.set_internal_name("true");

    ProgramVersion program_version6{ VersionInfo{ 1U, 2U, 3U, 7U } }; // NOLINT
    program_version6.set_legal_copyright("true");

    ProgramVersion program_version7{ VersionInfo{ 1U, 2U, 6U, 4U } }; // NOLINT
    program_version7.set_original_file_name("true");

    ProgramVersion program_version8{ VersionInfo{ 1U, 2U, 3U, 7U } }; // NOLINT
    program_version8.set_product_name("true");


    REQUIRE(program_version1 == program_version2);
    REQUIRE(program_version1 != program_version3);
    REQUIRE(program_version1 != program_version4);
    REQUIRE(program_version1 != program_version5);
    REQUIRE(program_version1 != program_version6);
    REQUIRE(program_version1 != program_version7);
    REQUIRE(program_version1 != program_version8);

    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version1 < program_version3) == true);
    REQUIRE((program_version1 < program_version4) == true);
    REQUIRE((program_version1 < program_version5) == true);
    REQUIRE((program_version1 < program_version6) == true);
    REQUIRE((program_version1 < program_version7) == true);
    REQUIRE((program_version1 < program_version8) == true);

    REQUIRE((program_version1 > program_version2) == false);
    REQUIRE((program_version1 > program_version3) == false);
    REQUIRE((program_version1 > program_version4) == false);
    REQUIRE((program_version1 > program_version5) == false);
    REQUIRE((program_version1 > program_version6) == false);
    REQUIRE((program_version1 > program_version7) == false);
    REQUIRE((program_version1 > program_version8) == false);

    REQUIRE((program_version1 <= program_version2) == true);
    REQUIRE((program_version1 <= program_version3) == true);
    REQUIRE((program_version1 <= program_version4) == true);
    REQUIRE((program_version1 <= program_version5) == true);
    REQUIRE((program_version1 <= program_version6) == true);
    REQUIRE((program_version1 <= program_version7) == true);
    REQUIRE((program_version1 <= program_version8) == true);

    REQUIRE((program_version1 >= program_version2) == true);
    REQUIRE((program_version1 >= program_version3) == false);
    REQUIRE((program_version1 >= program_version4) == false);
    REQUIRE((program_version1 >= program_version5) == false);
    REQUIRE((program_version1 >= program_version6) == false);
    REQUIRE((program_version1 >= program_version7) == false);
    REQUIRE((program_version1 >= program_version8) == false);

    program_version1 = program_version2;
    program_version1.set_file_version("false");
    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version2 < program_version1) == true);

    program_version1 = program_version2;
    program_version1.set_internal_name("zebra");
    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version2 < program_version1) == true);

    program_version1 = program_version2;
    program_version1.set_legal_copyright("false");
    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version2 < program_version1) == true);

    program_version1 = program_version2;
    program_version1.set_original_file_name("zebra");
    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version2 < program_version1) == true);

    program_version1 = program_version2;
    program_version1.set_product_name("false");
    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version2 < program_version1) == true);

    program_version1 = program_version2;
    program_version1.set_product_version("false");
    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version2 < program_version1) == true);

    program_version1 = program_version2;
    program_version1.set_version(VersionInfo{ 1U, 2U, 3U, 7U }); // NOLINT
    REQUIRE((program_version1 < program_version2) == false);
    REQUIRE((program_version2 < program_version1) == true);
}
