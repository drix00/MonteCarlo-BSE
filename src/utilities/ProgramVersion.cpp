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
#include <sstream>
#include <fstream>
#include <utility>
// Library headers
#include "spdlog/spdlog.h"
// Precompiled header
// Current declaration header file of this implementation file.
#include "utilities/ProgramVersion.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

ProgramVersion::ProgramVersion(VersionInfo new_version) noexcept
    : version(std::move(new_version))
{
    set_default();
    build_date_time = generate_build_date_time_string();
    compiler_build_parameters = generate_compiler_build_parameters_string();
}

void ProgramVersion::set_default()
{
    company_name = "McGill University";
    file_description = "Monte Carlo X-Ray simulation.";
    file_version = version.to_string();
    internal_name = "MCBSE.exe";
    legal_copyright = "Copyright (C) 2022";
    original_file_name = "MCBSE.exe";
    product_name = "MCBSE";
    product_version = version.to_string();
}

std::string ProgramVersion::get_company_name() const
{
    return company_name;
}

std::string ProgramVersion::get_file_description() const
{
    return file_description;
}

std::string ProgramVersion::get_file_version() const
{
    return file_version;
}

std::string ProgramVersion::get_internal_name() const
{
    return internal_name;
}

std::string ProgramVersion::get_legal_copyright() const
{
    return legal_copyright;
}

std::string ProgramVersion::get_original_file_name() const
{
    return original_file_name;
}

std::string ProgramVersion::get_product_name() const
{
    return product_name;
}

std::string ProgramVersion::get_product_version() const
{
    return product_version;
}

VersionInfo ProgramVersion::get_version() const
{
    return version;
}

std::string ProgramVersion::get_build_date_time_string() const
{
    return build_date_time;
}

std::string ProgramVersion::generate_build_date_time_string()
{
    const std::string seperator = "_";

    const std::string find_string = " ";
    const std::string replace_string = "-";
    std::string date = __DATE__;
    std::string::size_type pos = date.find(find_string);
    while (pos != std::string::npos) {
        date.replace(pos, find_string.size(), replace_string);
        pos = date.find(find_string, pos + find_string.size());
    }

    std::ostringstream outputString;
    outputString << date << seperator;
    outputString << __TIME__;

    const std::string newBuildString = outputString.str();

    return newBuildString;
}

std::string ProgramVersion::get_compiler_build_parameters_string() const
{
    return compiler_build_parameters;
}

std::string ProgramVersion::generate_compiler_build_parameters_string()
{
    const std::string seperator = "\t";
    const std::string seperator_key_value = ":";

    std::ostringstream output_string;

#ifdef _ATL_VER
    output_string << "Active_Template_Library" << seperator_key_value;
    output_string << _ATL_VER << seperator;
#endif

#ifdef __CLR_VER
    output_string << "Common_Language_Runtime" << seperator_key_value;
    output_string << __CLR_VER << seperator;
#endif

#ifdef __cplusplus_cli
    output_string << "C++_cli" << seperator;
    output_string << __cplusplus_cli << seperator;
#endif

#ifdef __cplusplus
    output_string << "C++" << seperator_key_value;
    output_string << __cplusplus << seperator;
#endif

#ifdef _CPPRTTI
    output_string << "Run-Time_Type_Information" << seperator_key_value;
    output_string << _CPPRTTI << seperator;
#endif

#ifdef _CPPUNWIND
    output_string << "Exception_Handling" << seperator_key_value;
    output_string << _CPPUNWIND << seperator;
#endif

#ifdef _DEBUG
    output_string << "Debug" << seperator;
#else
    output_string << "Release" << seperator;
#endif

#ifdef _DLL
    output_string << "DLL" << seperator_key_value;
    output_string << _DLL << seperator;
#endif

#ifdef _INTEGRAL_MAX_BITS
    output_string << "Integral_Max_Bits" << seperator_key_value;
    output_string << _INTEGRAL_MAX_BITS << seperator;
#endif

#ifdef _M_AMD64
    output_string << "amd64" << seperator_key_value;
    output_string << _M_AMD64 << seperator;
#endif

#ifdef _M_IX86
    output_string << "x86" << seperator_key_value;
    output_string << _M_IX86 << seperator;
#endif

#ifdef _M_IA64
    output_string << "ia64" << seperator_key_value;
#endif

#if _M_IX86_FP == 0
    output_string << "noSSE" << seperator;
#elif _M_IX86_FP == 1
    output_string << "SSE" << seperator;
#elif _M_IX86_FP == 2
    output_string << "SSE2" << seperator;
#else
    output_string << _M_IX86_FP << seperator;
#endif

#ifdef _M_X64
    output_string << "x64" << seperator_key_value;
    output_string << _M_X64 << seperator;
#endif

#ifdef _MFC_VER
    output_string << "MFC" << seperator_key_value;
    output_string << _MFC_VER << seperator;
#endif

#ifdef _MSC_EXTENSIONS
    output_string << "Microsoft_Extensions" << seperator_key_value;
    output_string << _MSC_EXTENSIONS << seperator;
#endif

#ifdef __MSVC_RUNTIME_CHECKS
    output_string << "Run-Time_Error_Checks" << seperator_key_value;
    output_string << __MSVC_RUNTIME_CHECKS << seperator;
#endif

#ifdef _MT
    output_string << "Multithread" << seperator;
#endif

#ifdef _MSC_FULL_VER
    output_string << "Visual_C++_Compiler" << seperator_key_value;
    output_string << _MSC_FULL_VER << seperator;
#endif

#ifdef _MSC_BUILD
    output_string << "Visual_C++_Compiler_Build_Number" << seperator_key_value;
    output_string << _MSC_BUILD << seperator;
#endif

#ifdef _WIN32
    output_string << "win32" << seperator;
#endif

#ifdef _WIN64
    output_string << "win64" << seperator;
#endif

    std::string new_compiler_build_string = output_string.str();

    return new_compiler_build_string;
}

bool ProgramVersion::operator==(const ProgramVersion &rhs) const
{
    return company_name == rhs.company_name && file_description == rhs.file_description &&
           file_version == rhs.file_version && internal_name == rhs.internal_name &&
           legal_copyright == rhs.legal_copyright && original_file_name == rhs.original_file_name &&
           product_name == rhs.product_name && product_version == rhs.product_version && version == rhs.version &&
           build_date_time == rhs.build_date_time && compiler_build_parameters == rhs.compiler_build_parameters;
}

bool ProgramVersion::operator!=(const ProgramVersion &rhs) const
{
    return !(rhs == *this);
}

bool ProgramVersion::operator<(const ProgramVersion &rhs) const
{
    if (company_name < rhs.company_name) {
        return true;
    }
    if (rhs.company_name < company_name) {
        return false;
    }
    if (file_description < rhs.file_description) {
        return true;
    }
    if (rhs.file_description < file_description) {
        return false;
    }
    if (file_version < rhs.file_version) {
        return true;
    }
    if (rhs.file_version < file_version) {
        return false;
    }
    if (internal_name < rhs.internal_name) {
        return true;
    }
    if (rhs.internal_name < internal_name) {
        return false;
    }
    if (legal_copyright < rhs.legal_copyright) {
        return true;
    }
    if (rhs.legal_copyright < legal_copyright) {
        return false;
    }
    if (original_file_name < rhs.original_file_name) {
        return true;
    }
    if (rhs.original_file_name < original_file_name) {
        return false;
    }
    if (product_name < rhs.product_name) {
        return true;
    }
    if (rhs.product_name < product_name) {
        return false;
    }
    if (product_version < rhs.product_version) {
        return true;
    }
    if (rhs.product_version < product_version) {
        return false;
    }
    if (version < rhs.version) {
        return true;
    }
    if (rhs.version < version) {
        return false;
    }
    if (build_date_time < rhs.build_date_time) {
        return true;
    }
    if (rhs.build_date_time < build_date_time) {
        return false;
    }
    return compiler_build_parameters < rhs.compiler_build_parameters;
}

bool ProgramVersion::operator>(const ProgramVersion &rhs) const
{
    return rhs < *this;
}

bool ProgramVersion::operator<=(const ProgramVersion &rhs) const
{
    return !(rhs < *this);
}

bool ProgramVersion::operator>=(const ProgramVersion &rhs) const
{
    return !(*this < rhs);
}
