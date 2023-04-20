#ifndef MONTECARLO_BSE_ATOM_H
#define MONTECARLO_BSE_ATOM_H

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

// Forwards declarations
// C system headers
// C++ system header
#include <string>
// Library headers
// Project headers
// Project private headers

/**
 * @brief Fundamental atomic properties.
 *
 * @todo Allow user specified value for atomic weight and atomic mass density.
 * @todo Allow to get value for atomic weight and atomic mass density from an user modified file.
 */
class Atom
{
  public:
    /**
     * Constructor with an atomic number.
     *
     * @param[in] new_atomic_number
     */
    explicit Atom(const unsigned int new_atomic_number) : atomic_number{ new_atomic_number } {};

    /**
     * Default constructor is deleted.
     */
    Atom() : atomic_number{ 0 } {};

    /**
     * Use the default generated copy constructor.
     *
     * @param[in] atom
     */
    Atom(const Atom &atom) = default;

    /**
     * Use the default generated move constructor.
     *
     * @param[in,out] atom
     */
    Atom(Atom &&atom) noexcept = default;

    /**
     * Use the default generated copy assignment.
     *
     * @param[in] atom
     * @return a new Atom object.
     */
    Atom &operator=(const Atom &atom) = default;

    /**
     * Use the default generated move assignment.
     *
     * @param[in,out] atom
     * @return the Atom object.
     */
    Atom &operator=(Atom &&atom) noexcept = default;

    /**
     * Use the default generated destructor.
     */
    virtual ~Atom() = default;

    /**
     * @return the atomic number.
     */
    [[nodiscard]] unsigned int get_atomic_number() const;

    /**
     * @param[in] new_atomic_number
     */
    void set_atomic_number(unsigned int new_atomic_number);

    /**
     * @return the atomic symbol.
     */
    [[nodiscard]] std::string get_symbol() const;

    /**
     * @return the atomic name.
     */
    [[nodiscard]] std::string get_name() const;

    /**
     * @return the atomic weight \f$ A \f$ in \f$ g / mol\f$.
     */
    [[nodiscard]] double get_atomic_weight_g_mol() const;

    /**
     * @return the atomic mass density \f$ \rho \f$  in \f$ g / cm^{3}\f$.
     */
    [[nodiscard]] double get_atomic_mass_density_g_cm3() const;

    /**
     * @brief Compute the atomic density for an atom.
     *
     * @return the atomic density (number of atom per unit of volume) \f$ n \f$ in \f$ 1 / cm^{3}\f$.
     */
    [[nodiscard]] double get_atomic_density_1_cm3() const;

  private:
    unsigned int atomic_number;
};

#endif// MONTECARLO_BSE_ATOM_H
