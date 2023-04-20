#ifndef MONTECARLO_BSE_SAMPLE_ELEMENT_H
#define MONTECARLO_BSE_SAMPLE_ELEMENT_H

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

// Forwards declarations
// C system headers
// C++ system header
// Library headers
// Project headers
#include "sample/atom.h"
// Project private headers

/**
 * @brief Element is an atom with a composition.
 */
class Element : public Atom
{
  public:
    /**
     * Constructor with an atomic number and a weight fraction.
     *
     * @param[in] new_atomic_number
     * @param[in] new_weight_fraction
     */
    Element(const unsigned int new_atomic_number, const double new_weight_fraction)
        : Atom{ new_atomic_number },
          weight_fraction{ new_weight_fraction },
          atomic_fraction{ 0.0 } {};

    /**
     * Default constructor is deleted.
     */
    Element() = delete;

    /**
     * Use the default generated copy constructor.
     *
     * @param[in] element
     */
    Element(const Element &element) = default;

    /**
     * Use the default generated move constructor.
     *
     * @param[in,out] element
     */
    Element(Element &&element) noexcept = default;

    /**
     * Use the default generated copy assignment.
     *
     * @param[in] element
     * @return a new Element object.
     */
    Element &operator=(const Element &element) = default;

    /**
     * Use the default generated move assignment.
     *
     * @param[in,out] element
     * @return the Element object.
     */
    Element &operator=(Element &&element) noexcept = default;

    /**
     * Use the default generated destructor.
     */
    ~Element() override = default;

    /**
     *
     * @return the weight fraction of the element.
     */
    [[nodiscard]] double get_weight_fraction() const;

    /**
     *
     * @param[in] new_weight_fraction
     */
    void set_weight_fraction(double new_weight_fraction);

    /**
     *
     * @return the atomic fraction of the element.
     */
    [[nodiscard]] double get_atomic_fraction() const;

    /**
     *
     * @param[in] new_atomic_fraction
     */
    void set_atomic_fraction(double new_atomic_fraction);

  private:
    double weight_fraction;
    double atomic_fraction;
};

#endif// MONTECARLO_BSE_SAMPLE_ELEMENT_H
