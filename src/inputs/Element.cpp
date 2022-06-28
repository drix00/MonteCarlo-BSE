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

// C system headers
// C++ system header
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "Element.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

// Global and constant variables/functions.

/**
 * Generate element properties for C.
 *
 * @return Element C
 */
Element get_c()
{
    Element element{ 6, 12.011, 2.62 };
    return element;
}

/**
 * Generate element properties for Al.
 *
 * @return Element Al
 */
Element get_al()
{
    Element element{ 13, 26.98, 2.7 };
    return element;
}

/**
 * Generate element properties for Si.
 *
 * @return Element Si
 */
Element get_si()
{
    Element element{ 14, 28.09, 2.33 };
    return element;
}

/**
 * Generate element properties for Fe.
 *
 * @return Element Fe
 */
Element get_fe()
{
    Element element{ 26, 55.85, 7.86 };
    return element;
}

/**
 * Generate element properties for Cu.
 *
 * @return Element Cu
 */
Element get_cu()
{
    Element element{ 29, 63.55, 8.96 };
    return element;
}

/**
 * Generate element properties for Ag.
 *
 * @return Element Ag
 */
Element get_ag()
{
    Element element{ 47, 107.87, 10.5 };
    return element;
}

/**
 * Generate element properties for Au.
 *
 * @return Element Au
 */
Element get_au()
{
    Element element{ 79, 196.97, 19.3 };
    return element;
}
