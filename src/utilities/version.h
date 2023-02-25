#ifndef MONTECARLO_BSE_VERSION_H
#define MONTECARLO_BSE_VERSION_H

/**
 * @file
 *
 * @brief Utility to get the program version from CMake project file.
 *
 * CMake use the file utilities/version.cpp.in to generate the utilities/version.cpp file with the version numbers
 * defined in cmake/ProjectVersionDetails.cmake.
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
#include <string>
// Library headers
// Project headers
// Project private headers

/**
 * Access the project name defined in CMake.
 *
 * @return the program name.
 */
std::string get_project_name();

/**
 * Access the string of the version numbers defined in CMake.
 *
 * @return a string of the version numbers.
 */
std::string get_version_str();

/**
 * Access the major value defined in CMake.
 *
 * @return the version major value.
 */
unsigned int get_version_major();

/**
 * Access the minor value defined in CMake.
 *
 * @return the version minor value.
 */
unsigned int get_version_minor();

/**
 * Access the patch value defined in CMake.
 *
 * @return the version patch value.
 */
unsigned int get_version_patch();

/**
 * Access the tweak value defined in CMake.
 *
 * @return the version tweak value.
 */
unsigned int get_version_tweak();

#endif// MONTECARLO_BSE_VERSION_H
