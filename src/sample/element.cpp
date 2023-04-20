/**
 * @file
 *
 * @brief Element is an atom with a composition.
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2023
 */

//   Copyright 2023 Hendrix Demers
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
#include "sample/element.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

double Element::get_weight_fraction() const
{
    return weight_fraction;
}

void Element::set_weight_fraction(const double new_weight_fraction)
{
    weight_fraction = new_weight_fraction;
}

double Element::get_atomic_fraction() const
{
    return atomic_fraction;
}

void Element::set_atomic_fraction(const double new_atomic_fraction)
{
    atomic_fraction = new_atomic_fraction;
}
