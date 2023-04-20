/**
 * @file
 *
 * @brief Fundamental atomic properties.
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
#include "sample/atom.h"
// Project headers
#include "constants/element.h"
// Project private headers

// Global and constant variables/functions.

unsigned int Atom::get_atomic_number() const
{
    return atomic_number;
}

void Atom::set_atomic_number(const unsigned int new_atomic_number)
{
    atomic_number = new_atomic_number;
}

std::string Atom::get_symbol() const
{
    return mcbse::constants::element::get_symbol(atomic_number);
}

std::string Atom::get_name() const
{
    return mcbse::constants::element::get_name(atomic_number);
}

double Atom::get_atomic_weight_g_mol() const
{
    return mcbse::constants::element::get_atomic_weight_g_mol(atomic_number);
}

double Atom::get_atomic_mass_density_g_cm3() const
{
    return mcbse::constants::element::get_atomic_mass_density_g_cm3(atomic_number);
}

/**
 * \details
 * The atomic density is computed as follow:
 * \f[
 *      n = \frac{N_{A} \cdot \rho}{A}
 * \f]
 * where
 * \li \f$ N_{A} \f$ Avogadro number in \f$ mol \f$
 * \li \f$ \rho \f$ atomic mass density in \f$ g / cm^{3} \f$
 * \li \f$ A \f$ atomic weight in \f$ g / mol \f$
 */
[[nodiscard]] double Atom::get_atomic_density_1_cm3() const
{
    /// @todo Make the Avogadro number variable a global constant.
    const double avogadro_number_mol{ 6.02214076e23 };

    const double atomic_density_1_cm3 = avogadro_number_mol * get_atomic_mass_density_g_cm3() / get_atomic_weight_g_mol();
    return atomic_density_1_cm3;
}
