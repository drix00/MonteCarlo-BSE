#ifndef MONTECARLO_BSE_VERSIONINFO_H
#define MONTECARLO_BSE_VERSIONINFO_H

/**
 * @file
 *
 * @brief Information about the version of the program.
 *
 * Useful for versioning input and output files for the program.
 *
 * The version numbers of the project (program) is defined in the file cmake/ProjectVersionDetails.cmake.
 *
 * Here are the steps to change the version numbers:
 *  -# Change the numbers in the file cmake/ProjectVersionDetails.cmake.
 *  -# Add a new variable in namespace mcbse::version in the file utilities/VersionInfo.h
 *      \code{.cpp}
 *          inline const VersionInfo VERSION_X_Y_Z_T{ X, Y, Z, T };
 *      \endcode
 *      -# List new and changed features in the documentation block of the new variable.
 *      -# If appropriate add new features in the @ref features_group list and modified VersionInfo::has_feature method.
 *      -# Change the variable mcbse::version::CURRENT_VERSION with the new variable.
 *      -# Update and add tests for this new version in tests/utilities/VersionInfo_test.cpp
 *          and tests/utilities/version_test.cpp.
 *      -# You may need to update and add the code and tests for input/output file related methods.
 *  -# Update the Changelog section in the README.md file.
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

/**
 * @brief Utility to define and manage the program version.
 *
 * Use semantic versioning: major, minor, patch and tweak.
 *
 * For example, you can get the current version number as a string using VersionInfo::to_string,
 * or you can get the separate major, minor, and patch integer values
 * by calling VersionInfo::get_version_major, VersionInfo::get_version_minor,
 * or VersionInfo::get_version_patch, respectively.
 *
 * This class also provides some basic version comparison functionality (comparison operators
 * and VersionInfo::is_at_least) and lets you determine if certain named features are present in your current build
 * by calling VersionInfo::has_feature.
 */
class VersionInfo
{
  public:
    /**
     * @brief Constructor with version numbers.
     *
     * @param[in] major
     * @param[in] minor
     * @param[in] patch
     * @param[in] tweak
     */
    VersionInfo(unsigned int major, unsigned int minor, unsigned int patch,
        unsigned int tweak = 0) noexcept;

    /**
     * @brief Empty constructor is deleted.
     */
    VersionInfo() = delete;

    /**
     * @brief Use the default generated copy constructor.
     *
     * @param[in] version_info input VersionInfo object
     */
    VersionInfo(const VersionInfo & version_info) noexcept = default;

    /**
     * @brief Use the default generated move constructor.
     *
     * @param[in,out] version_info input VersionInfo object
     */
    VersionInfo(VersionInfo && version_info) noexcept = default;

    /**
     * @brief Use the default generated copy assignment.
     *
     * @param[in] version_info input VersionInfo object
     * @return a new VersionInfo object.
     */
    VersionInfo &operator=(const VersionInfo & version_info) = default;

    /**
     * @brief Use the default generated move assignment.
     *
     * @param[in,out] version_info input VersionInfo object
     * @return a new VersionInfo object.
     */
    VersionInfo &operator=(VersionInfo && version_info) noexcept = default;

    /**
     * @brief Use the default generated destructor.
     */
    virtual ~VersionInfo() = default;

    /**
     * @name Version Numbers
     * @{
     */
    /**
     * @brief Convert version numbers to a string.
     *
     * @return string representation of the version numbers.
     */
    [[nodiscard]] std::string to_string() const;

    /**
     * @brief Extract version numbers from a string.
     *
     * @param[in] version_string string with the format "1.2.3.4"
     */
    void from_string(const std::string & version_string);

    /**
     * @brief Return the major version number.
     *
     * @return major version number.
     */
    [[nodiscard]] unsigned int get_version_major() const;

    /**
     * @brief Return the minor version number.
     *
     * @return minor version number.
     */
    [[nodiscard]] unsigned int get_version_minor() const;

    /**
     * @brief Return the patch version number.
     *
     * @return patch version number.
     */
    [[nodiscard]] unsigned int get_version_patch() const;

    /**
     * @brief Return the tweak version number.
     *
     * @return tweak version number.
     */
    [[nodiscard]] unsigned int get_version_tweak() const;

    /** @} */

    /**
     * @name Version Number Math
     * @{
     */
    /**
     * @brief Version comparison to check the current version is at least equal to or greater than a specific version.
     *
     * This method lets you check to see if the current version is greater than or equal to the specified version.
     * This may be useful to perform operations that require a minimum version number.
     *
     * @param[in] major version value to compare against
     * @param[in] minor version value to compare against
     * @param[in] patch version value to compare against
     * @return true if current version is greater or equal.
     */
    [[nodiscard]] bool is_at_least(unsigned int major, unsigned int minor=0, unsigned int patch=0) const;

    /**
     * @brief Version comparison to check the current version is at least equal or greater than a specific version.
     *
     * This method lets you check to see if the current version is greater than or equal to the specified version.
     * This may be useful to perform operations that require a minimum version number.
     *
     * @param version version values to compare against
     * @return true if version is greater or equal.
     */
    [[nodiscard]] bool is_at_least(const VersionInfo &version) const;

    /**
     * @brief Compare equality between left and right version numbers.
     *
     * @param[in] rhs right hand side version.
     * @return true if the left version numbers is equal to the right version numbers.
     */
    bool operator==(const VersionInfo &rhs) const;

    /**
     * @brief Compare no-equality between left and right version numbers.
     *
     * @param[in] rhs right hand side version.
     * @return true if the left version numbers is not equal to the right version numbers.
     */
    bool operator!=(const VersionInfo &rhs) const;

    /**
     * @brief Compare smaller than between left and right version numbers.
     *
     * @param[in] rhs right hand side version.
     * @return true if the left version numbers is smaller to the right version numbers.
     */
    bool operator<(const VersionInfo &rhs) const;

    /**
     * @brief Compare greater than between left and right version numbers.
     *
     * @param[in] rhs right hand side version.
     * @return true if the left version numbers is greater to the right version numbers.
     */
    bool operator>(const VersionInfo &rhs) const;

    /**
     * @brief Compare smaller than or equal between left and right version numbers.
     *
     * @param[in] rhs right hand side version.
     * @return true if the left version numbers is smaller or equal to the right version numbers.
     */
    bool operator<=(const VersionInfo &rhs) const;

    /**
     * @brief Compare greater than or equal between left and right version numbers.
     *
     * @param[in] rhs right hand side version.
     * @return true if the left version numbers is greater or equal to the right version numbers.
     */
    bool operator>=(const VersionInfo &rhs) const;
    /** @} */

    /**
     * @name Feature Tags
     * @{
     */
    /**
     * @brief Query if this version has this feature.
     *
     * New features that change the implementation of API methods are specified as @ref features_group tags.
     * This method lets you query the API to find out if a given feature is available.
     *
     * @param[in] name feature to check, e.g., "bse"
     * @return true if version has this feature.
     */
    [[nodiscard]] bool has_feature(const std::string &name) const;
    /** @} */

  private:
    unsigned int major;
    unsigned int minor;
    unsigned int patch;
    unsigned int tweak;
};

/**
 * @brief Namespace for the different versions of the project (program).
 *
 * @todo Should we move this namespace into a new file in constants folder?
 */
namespace mcbse::version {

/**
 * @brief Version 0.1.0 of MonteCarlo-BSE.
 *
 * Initial version with serial and simple Monte Carlo code to compute BSE coefficient.
 * Build 2020-05-11, see commit 38682f48529305fc85824fccd8fb98402920ef19.
 */
inline const VersionInfo VERSION_0_1_0{ 0, 1, 0 };

/**
 * @brief Version 0.2.0 of MonteCarlo-BSE.
 *
 * Correct compilation problems with gcc/Linux and failing tests.
 * Build 2020-05-12, see commit 5280894ab01d4e18f9b6bc47c5c161ba7bf4faf8.
 */
inline const VersionInfo VERSION_0_2_0{ 0, 2, 0 };

/**
 * @brief Version 0.2.1 of MonteCarlo-BSE.
 *
 * Add a Python script to analyse simulations results.
 * Remove space in csv result files.
 */
inline const VersionInfo VERSION_0_2_1{ 0, 2, 1 };

/**
 * @brief Version 0.3.0.0 of MonteCarlo-BSE.
 *
 * Add for_each simulation run.
 * Refactor run simulation code.
 * Add run valgrind.
 * Add profiling run.
 */
inline const VersionInfo VERSION_0_3_0_0{ 0, 3, 0, 0 };

/**
 * @brief Version 0.3.0.1 of MonteCarlo-BSE.
 *
 * Add MC-BSE console program.
 * Implement program and file version feature.
 * Add logging with spdlog.
 * Add command line feature.
 *
 */
inline const VersionInfo VERSION_0_3_0_1{ 0, 3, 0, 1 };

/**
 * @brief Current version of MonteCarlo-BSE.
 *
 * @note Don't forget to change the version in cmake/ProjectVersionDetails.cmake and
 * the test test current version and test current version 2 in tests/utilities/VersionInfo_test.cpp.
 */
inline const VersionInfo CURRENT_VERSION{ VERSION_0_3_0_1 };

}// namespace mcbse::version

#endif// MONTECARLO_BSE_VERSIONINFO_H
