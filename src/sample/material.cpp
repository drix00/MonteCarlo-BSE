/**
 * @file
 *
 * @brief A material contains one or more atoms with a composition.
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
#include <cmath>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "sample/material.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

[[nodiscard]] unsigned int Material::number_elements() const
{
    const size_t number_elements = elements.size();
    return static_cast<unsigned int>(number_elements);
}

/**
 * \note
 * If the total weight fraction is equal to 1, the atomic fraction is computed for all elements.
 */
void Material::add_atomic_number_with_weight_fraction(const unsigned int atomic_number, const double weight_fraction)
{
    const Element new_element{ atomic_number, weight_fraction };
    elements.push_back(new_element);

    if(is_total_weight_fraction_valid()) {
        compute_atomic_fraction();
    }
}

/**
 * \note
 * If the total atomic fraction is equal to 1, the weight fraction is computed for all elements.
 */
void Material::add_atomic_number_with_atomic_fraction(const unsigned int atomic_number, const double atomic_fraction) {
    Element new_element{ atomic_number, 0.0};
    new_element.set_atomic_fraction(atomic_fraction);
    elements.push_back(new_element);

    if(is_total_atomic_fraction_valid()) {
        compute_weight_fraction();
    }
}

bool Material::is_total_weight_fraction_valid() const
{
    const int maximum_precision{ 1000000 };
    double total_weight_fraction = 0.0;

    for (const auto &element : elements) {// NOLINT
        total_weight_fraction += element.get_weight_fraction();
    }

    return std::round(total_weight_fraction * maximum_precision) == maximum_precision;
}

bool Material::is_total_atomic_fraction_valid() const
{
    const int maximum_precision{ 1000000 };
    double total_atomic_fraction = 0.0;

    for (const auto &element : elements) {// NOLINT
        total_atomic_fraction += element.get_atomic_fraction();
    }

    return std::round(total_atomic_fraction * maximum_precision) == maximum_precision;
}

/**
 * \details
 * The atomic fraction for all elements is computed as follow:
 *
 * \f[
 *      f_{i}^{A} = \frac{f_{i}^{W} / A_{i}}{\sum_{j} f_{j}^{W} / A_{j}}
 * \f]
 *
 * where
 *
 * \li \f$ f_{i}^{A} \f$ is the atomic fraction of element \f$i\f$
 * \li \f$ f_{i}^{W} \f$ is the weight fraction of element \f$i\f$
 * \li \f$ A_{i} \f$ is the atomic weight of element \f$i\f$ in \f$ g / mol\f$
 */
void Material::compute_atomic_fraction()
{
    if (!is_total_weight_fraction_valid()) {
        return;
    }

    double total_weight_fraction = 0.0;

    for (const auto &element : elements) {// NOLINT
        total_weight_fraction += element.get_weight_fraction() / element.get_atomic_weight_g_mol();
    }

    for (auto &element : elements) {// NOLINT
        const double atomic_fraction = element.get_weight_fraction() / element.get_atomic_weight_g_mol() / total_weight_fraction;
        element.set_atomic_fraction(atomic_fraction);
    }
}

/**
 * \details
 * The weight fraction for all elements is computed as follow:
 *
 * \f[
 *      f_{i}^{W} = \frac{f_{i}^{A} \cdot A_{i}}{\sum_{j} f_{j}^{A} \cdot A_{j}}
 * \f]
 *
 * where
 *
 * \li \f$ f_{i}^{W} \f$ is the weight fraction of element \f$i\f$
 * \li \f$ f_{i}^{A} \f$ is the atomic fraction of element \f$i\f$
 * \li \f$ A_{i} \f$ is the atomic weight of element \f$i\f$ in \f$ g / mol\f$
 */
void Material::compute_weight_fraction()
{
    if (!is_total_atomic_fraction_valid()) {
        return;
    }

    double total_atomic_fraction = 0.0;

    for (const auto &element : elements) {// NOLINT
        total_atomic_fraction += element.get_atomic_fraction() * element.get_atomic_weight_g_mol();
    }

    for (auto &element : elements) {// NOLINT
        const double weight_fraction = element.get_atomic_fraction() * element.get_atomic_weight_g_mol() / total_atomic_fraction;
        element.set_weight_fraction(weight_fraction);
    }
}

/**
 * \details
 * The mass density of the material is computed as follow:
 *
 * \f[
 *      \rho_{R} = \frac{ 1 }{\sum_{i} \frac{f_{i}^{M}}{\rho_{i}} }
 * \f]
 *
 * where
 *
 * \li \f$ \rho_{R} \f$ is the mass density of the material or also called total mass density
 * \li \f$ f_{i}^{W} \f$ is the weight fraction of element \f$i\f$
 * \li \f$ \rho_{i} \f$ is the mass density of element \f$i\f$
 *
 * @todo Find reference for this calculation.
 */
[[nodiscard]] double Material::mass_density_g_cm3() const
{
    if (!is_total_weight_fraction_valid()) {
        return 0.0;
    }

    double denominator{ 0.0 };

    for (const auto &element : elements) {// NOLINT
        denominator += element.get_weight_fraction() / element.get_atomic_mass_density_g_cm3();
    }

    return 1.0 / denominator;
}
