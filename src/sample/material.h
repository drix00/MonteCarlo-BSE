#ifndef MONTECARLO_BSE_MATERIAL_H
#define MONTECARLO_BSE_MATERIAL_H

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

// Forwards declarations
// C system headers
// C++ system header
#include <vector>
// Library headers
// Project headers
#include "sample/element.h"
// Project private headers

/**
 * @brief A material contains one or more atoms with a composition.
 */
class Material
{
  public:
    /**
     * Use the default generated default constructor.
     */
    Material() = default;

    /**
     * Use the default generated copy constructor.
     *
     * @param[in] material
     */
    Material(const Material &material) = default;

    /**
     * Use the default generated move constructor.
     *
     * @param[in,out] material
     */
    Material(Material &&material) noexcept = default;

    /**
     * Use the default generated copy assignment.
     *
     * @param[in] material
     * @return a new Material object.
     */
    Material &operator=(const Material &material) = default;

    /**
     * Use the default generated move assignment.
     *
     * @param[in,out] material
     * @return the Material object.
     */
    Material &operator=(Material &&material) noexcept = default;

    /**
     * Use the default generated destructor.
     */
    virtual ~Material() = default;

    /**
     *
     * @return the number of elements in the material.
     */
    [[nodiscard]] unsigned int number_elements() const;

    /**
     *
     * @param[in] atomic_number
     * @param[in] weight_fraction
     */
    void add_atomic_number_with_weight_fraction(unsigned int atomic_number, double weight_fraction = 1.0);

    /**
     *
     * @param[in] atomic_number
     * @param[in] atomic_fraction
     */
    void add_atomic_number_with_atomic_fraction(unsigned int atomic_number, double atomic_fraction = 1.0);

    /**
     * Verify if the total weight fraction is equal to 1.0.
     *
     * @return True if the total weight fraction is equal to 1.0.
     */
    [[nodiscard]] bool is_total_weight_fraction_valid() const;

    /**
     * Verify if the total atomic fraction is equal to 1.0.
     *
     * @return True if the total atomic fraction is equal to 1.0.
     */
    [[nodiscard]] bool is_total_atomic_fraction_valid() const;

    /**
     * Compute the atomic fraction from the weight fraction of the material.
     */
    void compute_atomic_fraction();

    /**
     * Compute the weight fraction from the atomic fraction of the material.
     */
    void compute_weight_fraction();

    /**
     * Compute the mass density of the material.
     *
     * @return the mass density of the material in \f$ g / cm^{3}\f$.
     */
    [[nodiscard]] double mass_density_g_cm3() const;

  private:
    std::vector<Element> elements;
};

#endif// MONTECARLO_BSE_MATERIAL_H
