/**
 * @file
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2023
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
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "inputs/InputElement.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

// Global and constant variables/functions.

InputElement get_c()
{
    InputElement element{ 6, 12.011, 2.62 };// NOLINT
    return element;
}

InputElement get_al()
{
    InputElement element{ 13, 26.98, 2.7 };// NOLINT
    return element;
}

InputElement get_si()
{
    InputElement element{ 14, 28.09, 2.33 };// NOLINT
    return element;
}

InputElement get_fe()
{
    InputElement element{ 26, 55.85, 7.86 };// NOLINT
    return element;
}

InputElement get_cu()
{
    InputElement element{ 29, 63.55, 8.96 };// NOLINT
    return element;
}

InputElement get_ag()
{
    InputElement element{ 47, 107.87, 10.5 };// NOLINT
    return element;
}

InputElement get_au()
{
    InputElement element{ 79, 196.97, 19.3 };// NOLINT
    return element;
}
