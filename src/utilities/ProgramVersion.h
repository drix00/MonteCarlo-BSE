#ifndef MONTECARLO_BSE_PROGRAM_VERSION_H
#define MONTECARLO_BSE_PROGRAM_VERSION_H

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
// Library headers
// Project headers
#include "utilities/VersionInfo.h"
// Project private headers


class ProgramVersion
{
  public:
    explicit ProgramVersion(VersionInfo version) noexcept;
    ProgramVersion() = delete;
    ProgramVersion(const ProgramVersion &) = default;
    ProgramVersion(ProgramVersion &&) noexcept = default;
    ProgramVersion &operator=(const ProgramVersion &) = default;
    ProgramVersion &operator=(ProgramVersion &&) noexcept = default;
    ~ProgramVersion() = default;

    [[nodiscard]] std::string get_company_name() const;
    [[nodiscard]] std::string get_file_description() const;
    [[nodiscard]] std::string get_file_version() const;
    [[nodiscard]] std::string get_internal_name() const;
    [[nodiscard]] std::string get_legal_copyright() const;
    [[nodiscard]] std::string get_original_file_name() const;
    [[nodiscard]] std::string get_product_name() const;
    [[nodiscard]] std::string get_product_version() const;
    [[nodiscard]] VersionInfo get_version() const;

    [[nodiscard]] std::string get_build_date_time_string() const;
    [[nodiscard]] std::string get_compiler_build_parameters_string() const;

    bool operator==(const ProgramVersion &rhs) const;
    bool operator!=(const ProgramVersion &rhs) const;
    bool operator<(const ProgramVersion &rhs) const;
    bool operator>(const ProgramVersion &rhs) const;
    bool operator<=(const ProgramVersion &rhs) const;
    bool operator>=(const ProgramVersion &rhs) const;

  private:
    void set_default();
    static std::string generate_build_date_time_string();
    static std::string generate_compiler_build_parameters_string();

    std::string company_name;
    std::string file_description;
    std::string file_version;
    std::string internal_name;
    std::string legal_copyright;
    std::string original_file_name;
    std::string product_name;
    std::string product_version;

    VersionInfo version;

    std::string build_date_time;
    std::string compiler_build_parameters;
};

namespace mcbse::version {
/**
 * Current program version of MonteCarlo-BSE with build information.
 */
inline const ProgramVersion CURRENT_PROGRAM_VERSION{ CURRENT_VERSION };

}// namespace mcbse::version


#endif// MONTECARLO_BSE_PROGRAM_VERSION_H
