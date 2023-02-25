#ifndef MONTECARLO_BSE_PROGRAM_VERSION_H
#define MONTECARLO_BSE_PROGRAM_VERSION_H

/**
 * @file
 *
 * @brief Utilities for program version of MonteCarlo-BSE with build information.
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

/**
 * @brief Program version of MonteCarlo-BSE with build information.
 */
class ProgramVersion
{
  public:
    /**
     * Constructor with program version.
     *
     * @param[in] version
     */
    explicit ProgramVersion(VersionInfo version) noexcept;

    /**
     * Empty constructor is deleted.
     */
    ProgramVersion() = delete;

    /**
     * Use the default generated copy constructor.
     *
     * @param[in] program_version
     */
    ProgramVersion(const ProgramVersion & program_version) = default;

    /**
     * Use the default generated move constructor.
     *
     * @param[in,out] program_version
     */
    ProgramVersion(ProgramVersion && program_version) noexcept = default;

    /**
     * Use the default generated copy assignment.
     *
     * @param[in] program_version
     * @return a new ProgramVersion object.
     */
    ProgramVersion &operator=(const ProgramVersion & program_version) = default;

    /**
     * Use the default generated move assignment.
     *
     * @param[in,out] program_version
     * @return a new ProgramVersion object.
     */
    ProgramVersion &operator=(ProgramVersion && program_version) noexcept = default;

    /**
     * Use the default generated destructor.
     */
    virtual ~ProgramVersion() = default;

    /**
     *
     * @return company name.
     */
    [[nodiscard]] std::string get_company_name() const;

    /**
     *
     * @return file description.
     */
    [[nodiscard]] std::string get_file_description() const;

    /**
     *
     * @return file version string.
     */
    [[nodiscard]] std::string get_file_version() const;

    /**
     *
     * @return internal name.
     */
    [[nodiscard]] std::string get_internal_name() const;

    /**
     *
     * @return legal copyright.
     */
    [[nodiscard]] std::string get_legal_copyright() const;

    /**
     *
     * @return original file name.
     */
    [[nodiscard]] std::string get_original_file_name() const;

    /**
     *
     * @return product name.
     */
    [[nodiscard]] std::string get_product_name() const;

    /**
     *
     * @return product version.
     */
    [[nodiscard]] std::string get_product_version() const;

    /**
     *
     * @return version string
     */
    [[nodiscard]] VersionInfo get_version() const;

    /**
     *
     * @return string of the build date and time.
     */
    [[nodiscard]] std::string get_build_date_time_string() const;

    /**
     *
     * @return string of the compiler build parameters.
     */
    [[nodiscard]] std::string get_compiler_build_parameters_string() const;

    /**
     *
     * @param[in] new_value
     */
    void set_company_name(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_file_description(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_file_version(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_internal_name(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_legal_copyright(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_original_file_name(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_product_name(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_product_version(const std::string new_value);

    /**
     *
     * @param[in] new_value
     */
    void set_version(const VersionInfo new_value);

    /**
     * Compare equality between left and right program version.
     *
     * @param[in] rhs right hand side program version.
     * @return true if the left program version is equal to the right program version.
     */
    bool operator==(const ProgramVersion &rhs) const;

    /**
     * Compare no-equality between left and right program version.
     *
     * @param[in] rhs right hand side program version.
     * @return true if the left program version is not equal to the right program version.
     */
    bool operator!=(const ProgramVersion &rhs) const;

    /**
     * Compare smaller than between left and right program version.
     *
     * @param[in] rhs right hand side program version.
     * @return true if the left program version is smaller to the right program version.
     */
    bool operator<(const ProgramVersion &rhs) const;

    /**
     * Compare greater than between left and right program version.
     *
     * @param[in] rhs right hand side program version.
     * @return true if the left program version is greater to the right program version.
     */
    bool operator>(const ProgramVersion &rhs) const;

    /**
     * Compare smaller than or equal between left and right program version.
     *
     * @param[in] rhs right hand side program version.
     * @return true if the left program version is smaller or equal to the right program version.
     */
    bool operator<=(const ProgramVersion &rhs) const;

    /**
     * Compare greater than or equal between left and right program version.
     * @param[in] rhs right hand side program version.
     * @return true if the left program version is greater or equal to the right program version.
     */
    bool operator>=(const ProgramVersion &rhs) const;

  private:
    /**
     *
     * @return string of the build date and time.
     */
    static std::string generate_build_date_time_string();

    /**
     * Include standard predefined macros and microsoft specific predefined macros.
     *
     * @return string of the compiler build parameters.
     */
    static std::string generate_compiler_build_parameters_string();

    std::string company_name{"McGill University"};
    std::string file_description{"Monte Carlo BSE."};
    std::string internal_name{"mcbse_console.exe"};
    std::string legal_copyright{"Copyright (C) 2022"};
    std::string original_file_name{"mcbse_console.exe"};
    std::string product_name{"MC-BSE"};
    std::string file_version;
    std::string product_version;

    VersionInfo version;

    std::string build_date_time;
    std::string compiler_build_parameters;
};

/**
 * Constants related to program version.
 */
namespace mcbse::version {

/**
 * Current program version of MonteCarlo-BSE with build information.
 */
inline const ProgramVersion CURRENT_PROGRAM_VERSION{ CURRENT_VERSION };

}// namespace mcbse::version


#endif// MONTECARLO_BSE_PROGRAM_VERSION_H
