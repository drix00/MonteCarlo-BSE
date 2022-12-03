#ifndef MONTECARLO_BSE_LOGGER_H
#define MONTECARLO_BSE_LOGGER_H

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
#include <map>
// Library headers
#include "spdlog/common.h"
// Project headers
// Project private headers

namespace monte_carlo::constants::logger {

const std::map<std::string, spdlog::level::level_enum> map_levels{
    { "off", spdlog::level::off },
    { "critical", spdlog::level::critical },
    { "error", spdlog::level::err },
    { "warning", spdlog::level::warn },
    { "info", spdlog::level::info },
    { "debug", spdlog::level::debug },
    { "trace", spdlog::level::trace }
};

}// namespace monte_carlo::constants::logger

#endif// MONTECARLO_BSE_LOGGER_H
