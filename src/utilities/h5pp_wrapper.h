#ifndef MONTECARLO_BSE_H5PP_WRAPPER_H
#define MONTECARLO_BSE_H5PP_WRAPPER_H

/**
 * @file
 *
 * @brief Wrapper to suppress warning in h5pp code when using MSVC.
 *
 * @note h5pp/h5pp.h should not directly included in the source code, but utilities/h5pp_wrapper.h included
 * when h5pp is needed.
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
// Library headers
#ifdef _MSC_VER
    #pragma warning( push )
    #pragma warning(suppress : 4244)
    #pragma warning(suppress : 4267)
    #pragma warning(suppress : 4702)
    #include <h5pp/h5pp.h>
    #pragma warning( pop )
#else
    #include <h5pp/h5pp.h>
#endif
// Project headers
// Project private headers

#endif// MONTECARLO_BSE_H5PP_WRAPPER_H
