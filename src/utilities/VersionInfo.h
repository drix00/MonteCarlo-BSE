#ifndef MONTECARLO_BSE_VERSIONINFO_H
#define MONTECARLO_BSE_VERSIONINFO_H

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

// Forwards declarations
// C system headers
// C++ system header
#include <string>
#include <iosfwd>
// Library headers
// Project headers
// Project private headers

class VersionInfo
{
  public:
    VersionInfo(const unsigned int major, const unsigned int minor, const unsigned int patch,
        const unsigned int tweak = 0) noexcept;
    VersionInfo() = delete;
    VersionInfo(const VersionInfo &) noexcept = default;
    VersionInfo(VersionInfo &&) noexcept = default;
    VersionInfo &operator=(const VersionInfo &) = default;
    VersionInfo &operator=(VersionInfo &&) noexcept = default;
    virtual ~VersionInfo() = default;

    [[nodiscard]] std::string to_string() const;
    void from_string(const std::string &version_string);

    [[nodiscard]] unsigned int get_version_major() const;
    [[nodiscard]] unsigned int get_version_minor() const;
    [[nodiscard]] unsigned int get_version_patch() const;
    [[nodiscard]] unsigned int get_version_tweak() const;

    [[nodiscard]] bool is_at_least(const unsigned int major, const unsigned int minor=0, const unsigned int patch=0) const;
    [[nodiscard]] bool is_at_least(const VersionInfo &version) const;
    [[nodiscard]] bool has_feature(const std::string &name) const;

    bool operator==(const VersionInfo &rhs) const;
    bool operator!=(const VersionInfo &rhs) const;
    bool operator<(const VersionInfo &rhs) const;
    bool operator>(const VersionInfo &rhs) const;
    bool operator<=(const VersionInfo &rhs) const;
    bool operator>=(const VersionInfo &rhs) const;

  private:
    unsigned int major;
    unsigned int minor;
    unsigned int patch;
    unsigned int tweak;
};

namespace mcbse::version {

/**
 * Version of MonteCarlo-BSE.
 *
 * Initial version with serial and simple Monte Carlo code to compute BSE coefficient.
 * Build 2020-05-11, see commit 38682f48529305fc85824fccd8fb98402920ef19.
 */
inline const VersionInfo VERSION_0_1_0{ 0, 1, 0 };

/**
 * Version of MonteCarlo-BSE.
 *
 * Correct compilation problems with gcc/Linux and failing tests.
 * Build 2020-05-12, see commit 5280894ab01d4e18f9b6bc47c5c161ba7bf4faf8.
 */
inline const VersionInfo VERSION_0_2_0{ 0, 2, 0 };

/**
 * Version of MonteCarlo-BSE.
 *
 * Add a Python script to analyse simulations results.
 * Remove space in csv result files.
 */
inline const VersionInfo VERSION_0_2_1{ 0, 2, 1 };

/**
 * Version of MonteCarlo-BSE.
 *
 * Add for_each simulation run.
 * Refactor run simulation code.
 * Add run valgrind.
 * Add profiling run.
 */
inline const VersionInfo VERSION_0_3_0_1{ 0, 3, 0, 1 };

/**
 * Current version of MonteCarlo-BSE.
 *
 * @note Don't forget to change the version in cmake/ProjectVersionDetails.cmake and
 * the test test_current_version in test_ProgramVersions.cpp.
 */
inline const VersionInfo CURRENT_VERSION{ VERSION_0_3_0_1 };

}// namespace mcbse::version

#endif// MONTECARLO_BSE_VERSIONINFO_H
