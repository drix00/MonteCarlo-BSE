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
    file_version = version.to_string();
    product_version = version.to_string();

    build_date_time = generate_build_date_time_string();
    compiler_build_parameters = generate_compiler_build_parameters_string();
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

void ProgramVersion::set_company_name(const std::string new_value)
{
    company_name = new_value;
}

void ProgramVersion::set_file_description(const std::string new_value)
{
    file_description = new_value;
}

void ProgramVersion::set_file_version(const std::string new_value)
{
    file_version = new_value;
}

void ProgramVersion::set_internal_name(const std::string new_value)
{
    internal_name = new_value;
}

void ProgramVersion::set_legal_copyright(const std::string new_value)
{
    legal_copyright = new_value;
}

void ProgramVersion::set_original_file_name(const std::string new_value)
{
    original_file_name = new_value;
}

void ProgramVersion::set_product_name(const std::string new_value)
{
    product_name = new_value;
}

void ProgramVersion::set_product_version(const std::string new_value)
{
    product_version = new_value;
}

void ProgramVersion::set_version(const VersionInfo new_value)
{
    version = new_value;
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

    std::ostringstream output_string;
    output_string << date << seperator;
    output_string << __TIME__;

    const std::string basic_string = output_string.str();

    return basic_string;
}

std::string ProgramVersion::get_compiler_build_parameters_string() const
{
    return compiler_build_parameters;
}

/**
 * @todo Add G++ specific predefined macros.
 * @todo Add Clang-specific predefined macros.
 */
std::string ProgramVersion::generate_compiler_build_parameters_string()
{
    const std::string seperator = " ; ";
    const std::string seperator_key_value = ": ";

    std::ostringstream output_string;

// Standard predefined macros.
#ifdef __cplusplus
    output_string << "C++" << seperator_key_value;
    output_string << __cplusplus << seperator;
#endif

#ifdef __STDC__
    output_string << "__STDC__" << seperator_key_value;
    output_string << __STDC__ << seperator;
#endif

#ifdef __STDC_HOSTED__
    output_string << "__STDC_HOSTED__ " << seperator_key_value;
    output_string << __STDC_HOSTED__ << seperator;
#endif

#ifdef __STDC_NO_ATOMICS__
    output_string << "__STDC_NO_ATOMICS__ " << seperator_key_value;
    output_string << __STDC_NO_ATOMICS__ << seperator;
#endif

#ifdef __STDC_NO_COMPLEX__
    output_string << "__STDC_NO_COMPLEX__ " << seperator_key_value;
    output_string << __STDC_NO_COMPLEX__ << seperator;
#endif

#ifdef __STDC_NO_THREADS__
    output_string << "__STDC_NO_THREADS__ " << seperator_key_value;
    output_string << __STDC_NO_THREADS__ << seperator;
#endif

#ifdef __STDC_NO_VLA__
    output_string << "__STDC_NO_VLA__ " << seperator_key_value;
    output_string << __STDC_NO_VLA__ << seperator;
#endif

#ifdef __STDC_VERSION__
    output_string << "__STDC_VERSION__ " << seperator_key_value;
    output_string << __STDC_VERSION__ << seperator;
#endif

#ifdef __STDCPP_DEFAULT_NEW_ALIGNMENT__
    output_string << "__STDCPP_DEFAULT_NEW_ALIGNMENT__ " << seperator_key_value;
    output_string << __STDCPP_DEFAULT_NEW_ALIGNMENT__ << seperator;
#endif

#ifdef __STDCPP_THREADS__
    output_string << "__STDCPP_THREADS__ " << seperator_key_value;
    output_string << __STDCPP_THREADS__ << seperator;
#endif

// Microsoft-specific predefined macros.
#ifdef __ATOM__
    output_string << "__ATOM__" << seperator_key_value;
    output_string << __ATOM__ << seperator;
#endif

#ifdef __AVX__
    output_string << "__AVX__" << seperator_key_value;
    output_string << __AVX__ << seperator;
#endif

#ifdef __AVX2__
    output_string << "__AVX2__" << seperator_key_value;
    output_string << __AVX2__ << seperator;
#endif

#ifdef __AVX512BW__
    output_string << "__AVX512BW__" << seperator_key_value;
    output_string << __AVX512BW__ << seperator;
#endif

#ifdef __AVX512CD__
    output_string << "__AVX512CD__" << seperator_key_value;
    output_string << __AVX512CD__ << seperator;
#endif

#ifdef __AVX512DQ__
    output_string << "__AVX512DQ__" << seperator_key_value;
    output_string << __AVX512DQ__ << seperator;
#endif

#ifdef __AVX512F__
    output_string << "__AVX512F__" << seperator_key_value;
    output_string << __AVX512F__ << seperator;
#endif

#ifdef __AVX512VL__
    output_string << "__AVX512VL__" << seperator_key_value;
    output_string << __AVX512VL__ << seperator;
#endif

#ifdef _CHAR_UNSIGNED
    output_string << "_CHAR_UNSIGNED" << seperator_key_value;
    output_string << _CHAR_UNSIGNED << seperator;
#endif

#ifdef __CLR_VER
    output_string << "__CLR_VER" << seperator_key_value;
    output_string << __CLR_VER << seperator;
#endif

#ifdef _CONTROL_FLOW_GUARD
    output_string << "_CONTROL_FLOW_GUARD " << seperator_key_value;
    output_string << _CONTROL_FLOW_GUARD  << seperator;
#endif

// ATL or MFC library version
#ifdef _ATL_VER
    output_string << "Active_Template_Library" << seperator_key_value;
    output_string << _ATL_VER << seperator;
#endif

#ifdef _MFC_VER
    output_string << "MFC" << seperator_key_value;
    output_string << _MFC_VER << seperator;
#endif

#ifdef __cplusplus_cli
    output_string << "C++_cli" << seperator;
    output_string << __cplusplus_cli << seperator;
#endif

#ifdef __cplusplus_winrt
    output_string << "__cplusplus_winrt" << seperator;
    output_string << __cplusplus_winrt << seperator;
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

#ifdef __INTELLISENSE__
    output_string << "__INTELLISENSE__" << seperator_key_value;
    output_string << __INTELLISENSE__ << seperator;
#endif

#ifdef _ISO_VOLATILE
    output_string << "_ISO_VOLATILE" << seperator_key_value;
    output_string << _ISO_VOLATILE << seperator;
#endif

#ifdef _KERNEL_MODE
    output_string << "_KERNEL_MODE" << seperator_key_value;
    output_string << _KERNEL_MODE << seperator;
#endif

#ifdef _M_AMD64
    output_string << "amd64" << seperator_key_value;
    output_string << _M_AMD64 << seperator;
#endif

#ifdef _M_ARM
    output_string << "_M_ARM" << seperator_key_value;
    output_string << _M_ARM << seperator;
#endif

#ifdef _M_ARM_ARMV7VE
    output_string << "_M_ARM_ARMV7VE" << seperator_key_value;
    output_string << _M_ARM_ARMV7VE << seperator;
#endif

#ifdef _M_ARM_FP
    output_string << "_M_ARM_FP" << seperator_key_value;
    output_string << _M_ARM_FP << seperator;
#endif

#ifdef _M_ARM64
    output_string << "_M_ARM64" << seperator_key_value;
    output_string << _M_ARM64 << seperator;
#endif

#ifdef _M_ARM64EC
    output_string << "_M_ARM64EC" << seperator_key_value;
    output_string << _M_ARM64EC << seperator;
#endif

#ifdef _M_CEE
    output_string << "_M_CEE" << seperator_key_value;
    output_string << _M_CEE << seperator;
#endif

#ifdef _M_CEE_PURE
    output_string << "_M_CEE_PURE" << seperator_key_value;
    output_string << _M_CEE_PURE << seperator;
#endif

#ifdef _M_CEE_SAFE
    output_string << "_M_CEE_SAFE" << seperator_key_value;
    output_string << _M_CEE_SAFE << seperator;
#endif

#ifdef _M_FP_CONTRACT
    output_string << "_M_FP_CONTRACT" << seperator_key_value;
    output_string << _M_FP_CONTRACT << seperator;
#endif

#ifdef _M_FP_EXCEPT
    output_string << "_M_FP_EXCEPT" << seperator_key_value;
    output_string << _M_FP_EXCEPT << seperator;
#endif

#ifdef _M_FP_FAST
    output_string << "_M_FP_FAST" << seperator_key_value;
    output_string << _M_FP_FAST << seperator;
#endif

#ifdef _M_FP_PRECISE
    output_string << "_M_FP_PRECISE" << seperator_key_value;
    output_string << _M_FP_PRECISE << seperator;
#endif

#ifdef _M_FP_STRICT
    output_string << "_M_FP_STRICT" << seperator_key_value;
    output_string << _M_FP_STRICT << seperator;
#endif

#ifdef _M_IX86
    output_string << "x86" << seperator_key_value;
    output_string << _M_IX86 << seperator;
#endif

#ifdef _M_IX86_FP
    output_string << "_M_IX86_FP" << seperator_key_value;
    output_string << _M_IX86_FP << seperator;
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

#ifdef _M_IA64
    output_string << "ia64" << seperator_key_value;
#endif

#ifdef _M_X64
    output_string << "x64" << seperator_key_value;
    output_string << _M_X64 << seperator;
#endif

#ifdef _MANAGED
    output_string << "_MANAGED" << seperator_key_value;
    output_string << _MANAGED << seperator;
#endif

#ifdef _MSC_BUILD
    output_string << "_MSC_BUILD" << seperator_key_value;
    output_string << _MSC_BUILD << seperator;
#endif

#ifdef _MSC_EXTENSIONS
    output_string << "Microsoft_Extensions" << seperator_key_value;
    output_string << _MSC_EXTENSIONS << seperator;
#endif

#ifdef _MSC_FULL_VER
    output_string << "_MSC_FULL_VER" << seperator_key_value;
    output_string << _MSC_FULL_VER << seperator;
#endif

#ifdef _MSC_VER
    output_string << "_MSC_VER" << seperator_key_value;
    output_string << _MSC_VER << seperator;
#endif

#ifdef _MSVC_LANG
    output_string << "_MSVC_LANG" << seperator_key_value;
    output_string << _MSVC_LANG << seperator;
#endif

#ifdef __MSVC_RUNTIME_CHECKS
    output_string << "__MSVC_RUNTIME_CHECKS" << seperator_key_value;
    output_string << __MSVC_RUNTIME_CHECKS << seperator;
#endif

#ifdef _MSVC_TRADITIONAL
    output_string << "_MSVC_TRADITIONAL" << seperator_key_value;
    output_string << _MSVC_TRADITIONAL << seperator;
#endif

#ifdef _MT
    output_string << "Multithread" << seperator;
#endif

#ifdef _NATIVE_WCHAR_T_DEFINED
    output_string << "_NATIVE_WCHAR_T_DEFINED" << seperator;
#endif

#ifdef _OPENMP
    output_string << "_OPENMP" << seperator_key_value;
    output_string << _OPENMP << seperator;
#endif

#ifdef _PREFAST_
    output_string << "_PREFAST_" << seperator_key_value;
    output_string << _PREFAST_ << seperator;
#endif

#ifdef __SANITIZE_ADDRESS__
    output_string << "__SANITIZE_ADDRESS__" << seperator_key_value;
    output_string << __SANITIZE_ADDRESS__ << seperator;
#endif

#ifdef _VC_NODEFAULTLIB
    output_string << "_VC_NODEFAULTLIB" << seperator_key_value;
    output_string << _VC_NODEFAULTLIB << seperator;
#endif

#ifdef _WCHAR_T_DEFINED
    output_string << "_WCHAR_T_DEFINED" << seperator;
//    output_string << "_WCHAR_T_DEFINED" << seperator_key_value;
//    output_string << _WCHAR_T_DEFINED << seperator;
#endif

#ifdef _WIN32
    output_string << "win32" << seperator;
#endif

#ifdef _WIN64
    output_string << "win64" << seperator;
#endif

#ifdef _WINRT_DLL
    output_string << "_WINRT_DLL " << seperator;
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
