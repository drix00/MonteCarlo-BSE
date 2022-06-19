#ifndef MONTECARLO_BSE_CONSTANTS_ELEMENT_H
#define MONTECARLO_BSE_CONSTANTS_ELEMENT_H

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
// Library headers
// Project headers
// Project private headers

namespace monte_carlo::constants::element {

/**
 * Get the element symbol from an atomic number.
 *
 * From green book: IUPAC-GB3-2012-2ndPrinting-PDFsearchable
 * Wikipedia contributors, "List of chemical elements," Wikipedia, The Free Encyclopedia, https://en.wikipedia.org/w/index.php?title=List_of_chemical_elements&oldid=1033101281 (accessed July 27, 2021).
 *
 * @param[in] atomic_number
 * @return symbol of the element
 */
std::string get_symbol(int atomic_number);
/**
 * Get the element name from an atomic number.
 *
 * From green book: IUPAC-GB3-2012-2ndPrinting-PDFsearchable
 * Wikipedia contributors, "List of chemical elements," Wikipedia, The Free Encyclopedia, https://en.wikipedia.org/w/index.php?title=List_of_chemical_elements&oldid=1033101281 (accessed July 27, 2021).
 *
 * @param[in] atomic_number
 * @return name of the element
 */
std::string get_name(int atomic_number);
/**
 * Get the atomic weight (g/mol) from an atomic number.
 *
 * From green book: IUPAC-GB3-2012-2ndPrinting-PDFsearchable
 * Wikipedia contributors, "List of chemical elements," Wikipedia, The Free Encyclopedia, https://en.wikipedia.org/w/index.php?title=List_of_chemical_elements&oldid=1033101281 (accessed July 27, 2021).
 *
 * @param[in] atomic_number
 * @return atomic weight in g/mol
 */
double get_atomic_weight_g_mol(int atomic_number);
/**
 * Get the mass density (g/cm3) from an atomic number.
 *
 * From green book: IUPAC-GB3-2012-2ndPrinting-PDFsearchable
 * Wikipedia contributors, "List of chemical elements," Wikipedia, The Free Encyclopedia, https://en.wikipedia.org/w/index.php?title=List_of_chemical_elements&oldid=1033101281 (accessed July 27, 2021).
 *
 * @param[in] atomic_number
 * @return mass density in g/cm3
 */
double get_atomic_mass_density_g_cm3(int atomic_number);

}// namespace monte_carlo::constants::element

#endif// MONTECARLO_BSE_CONSTANTS_ELEMENT_H
