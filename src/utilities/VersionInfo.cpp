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
#include <sstream>
#include <fstream>
// Library headers
#include "spdlog/spdlog.h"
// Precompiled header
// Current declaration header file of this implementation file.
#include "utilities/VersionInfo.h"
// Project headers
// Project private headers

// Global and constant variables/functions.
const std::string FEATURE_BSE{"bse"};

unsigned int VersionInfo::get_version_major() const {
    return major;
}

unsigned int VersionInfo::get_version_minor() const {
    return minor;
}

unsigned int VersionInfo::get_version_patch() const {
    return patch;
}

unsigned int VersionInfo::get_version_tweak() const {
    return tweak;
}

bool VersionInfo::is_at_least(const unsigned int other_major, const unsigned int other_minor,
    const unsigned int other_patch) const {
    return *this >= VersionInfo{other_major, other_minor, other_patch};
}

bool VersionInfo::is_at_least(const VersionInfo& version) const {
    return *this >= version;
}

bool VersionInfo::has_feature(const std::string &name) const {
    using namespace mcbse::version;

    if (name == FEATURE_BSE && *this >= VERSION_0_1_0) {
        return true;
    }

    return false;
}

VersionInfo::VersionInfo(const unsigned int new_major, const unsigned int new_minor, const unsigned int new_patch,
    const unsigned int new_tweak) noexcept
    : major(new_major), minor(new_minor), patch(new_patch), tweak(new_tweak)
{
}

std::string VersionInfo::to_string() const
{
    std::ostringstream outputString;
    outputString << major << ".";
    outputString << minor << ".";
    outputString << patch << ".";
    outputString << tweak;

    std::string versionString = outputString.str();

    return (versionString);
}

void VersionInfo::from_string(const std::string& version_string)
{
    if (version_string != "")
    {
        char dummy{};
        std::istringstream inputString(version_string);
        inputString >> major >> dummy;
        inputString >> minor >> dummy;
        inputString >> patch >> dummy;
        inputString >> tweak;
    }
}

bool VersionInfo::operator==(const VersionInfo &rhs) const
{
    return major == rhs.major && minor == rhs.minor && patch == rhs.patch && tweak == rhs.tweak;
}

bool VersionInfo::operator!=(const VersionInfo &rhs) const
{
    return !(rhs == *this);
}

bool VersionInfo::operator<(const VersionInfo &rhs) const
{
    if (major < rhs.major)
        return true;
    if (rhs.major < major)
        return false;
    if (minor < rhs.minor)
        return true;
    if (rhs.minor < minor)
        return false;
    if (patch < rhs.patch)
        return true;
    if (rhs.patch < patch)
        return false;
    return tweak < rhs.tweak;
}

bool VersionInfo::operator>(const VersionInfo &rhs) const
{
    return rhs < *this;
}

bool VersionInfo::operator<=(const VersionInfo &rhs) const
{
    return !(rhs < *this);
}

bool VersionInfo::operator>=(const VersionInfo &rhs) const
{
    return !(*this < rhs);
}
