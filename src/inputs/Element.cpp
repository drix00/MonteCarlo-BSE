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
#include <unordered_map>
// Precompiled header
#pragma hdrstop
// Current declaration header file of this implementation file.
#include "Element.h"
// Project headers
// Project private headers

// Global and constant variables/functions.

// Global and constant variables/functions.

/**
 *
 * @return element C
 */
Element get_c()
{
    Element element{ 6, 12.011, 2.62 };
    return element;
}

/**
 *
 * @return element Al
 */
Element get_al()
{
    Element element{ 13, 26.98, 2.7 };
    return element;
}

/**
 *
 * @return element Si
 */
Element get_si()
{
    Element element{ 14, 28.09, 2.33 };
    return element;
}

/**
 *
 * @return element Fe
 */
Element get_fe()
{
    Element element{ 26, 55.85, 7.86 };
    return element;
}

/**
 *
 * @return element Cu
 */
Element get_cu()
{
    Element element{ 29, 63.55, 8.96 };
    return element;
}

/**
 *
 * @return element Ag
 */
Element get_ag()
{
    Element element{ 47, 107.87, 10.5 };
    return element;
}

/**
 *
 * @return element Au
 */
Element get_au()
{
    Element element{ 79, 196.97, 19.3 };
    return element;
}

/**
 * Atomic weight in g/mol.
 *
 * @note Using a map, the first element is the atomic number and the second element the atomic weight.
 */
const std::unordered_map<int, double> atomic_weights_g_mol{
                {1, 1.008},
                {2, 4.003},
                {3, 6.940},
                {4, 9.010},
                {5, 10.81},
                {6, 12.01},
                {7, 14.01},
                {8, 16.00},
                {9, 19.00},
                {10, 20.18},
                {11, 22.99},
                {12, 24.31},
                {13, 26.98},
                {14, 28.09},
                {15, 30.97},
                {16, 32.06},
                {17, 35.45},
                {18, 39.95},
                {19, 39.10},
                {20, 40.08},
                {21, 44.96},
                {22, 47.90},
                {23, 50.94},
                {24, 52.00},
                {25, 54.94},
                {26, 55.85},
                {27, 58.93},
                {28, 58.71},
                {29, 63.55},
                {30, 65.37},
                {31, 69.72},
                {32, 72.59},
                {33, 74.92},
                {34, 78.96},
                {35, 79.90},
                {36, 83.80},
                {37, 85.47},
                {38, 87.62},
                {39, 88.91},
                {40, 91.22},
                {41, 92.91},
                {42, 95.94},
                {43, 98.91},
                {44, 101.07},
                {45, 102.91},
                {46, 106.4},
                {47, 107.87},
                {48, 112.40},
                {49, 114.82},
                {50, 118.69},
                {51, 121.75},
                {52, 127.60},
                {53, 126.90},
                {54, 131.30},
                {55, 132.90},
                {56, 137.34},
                {57, 138.91},
                {58, 140.12},
                {59, 140.91},
                {60, 144.24},
                {61, 145.0},
                {62, 150.35},
                {63, 151.96},
                {64, 157.25},
                {65, 158.92},
                {66, 162.50},
                {67, 164.93},
                {68, 167.26},
                {69, 168.93},
                {70, 173.04},
                {71, 174.97},
                {72, 178.49},
                {73, 180.95},
                {74, 183.95},
                {75, 186.20},
                {76, 190.20},
                {77, 192.20},
                {78, 195.09},
                {79, 196.97},
                {80, 200.59},
                {81, 204.37},
                {82, 207.19},
                {83, 208.98},
                {84, 209.0},
                {85, 210.0},
                {86, 222.0},
                {87, 223.0},
                {88, 226.0},
                {89, 227.0},
                {90, 232.0},
                {91, 231.0},
                {92, 238.0},
                {93, 237.0},
                {94, 244.0},
                {95, 243.0},
                {96, 247.0}
        };
/**
 * Density in g/cm3.
 *
 * @note Using a map, the first element is the atomic number and the second element the mass density.
 */
const std::unordered_map<int, double> atomic_mass_density_g_cm3{
                {1, 0.071},
                {2, 0.126},
                {3, 0.53},
                {4, 1.85},
                {5, 2.34},
                {6, 2.26},
                {7, 0.81},
                {8, 1.14},
                {9, 1.505},
                {10, 1.2},
                {11, 0.97},
                {12, 1.74},
                {13, 2.7},
                {14, 2.33},
                {15, 1.82},
                {16, 2.07},
                {17, 1.56},
                {18, 1.4},
                {19, 0.86},
                {20, 1.55},
                {21, 3.0},
                {22, 4.51},
                {23, 6.1},
                {24, 7.19},
                {25, 7.43},
                {26, 7.86},
                {27, 8.9},
                {28, 8.9},
                {29, 8.96},
                {30, 7.14},
                {31, 5.91},
                {32, 5.32},
                {33, 5.72},
                {34, 4.79},
                {35, 3.12},
                {36, 2.6},
                {37, 1.53},
                {38, 2.6},
                {39, 4.47},
                {40, 6.49},
                {41, 8.4},
                {42, 10.2},
                {43, 11.5},
                {44, 12.2},
                {45, 12.4},
                {46, 12.0},
                {47, 10.5},
                {48, 8.65},
                {49, 7.31},
                {50, 7.3},
                {51, 6.62},
                {52, 6.24},
                {53, 4.94},
                {54, 3.06},
                {55, 1.9},
                {56, 3.5},
                {57, 6.17},
                {58, 6.67},
                {59, 6.77},
                {60, 7.0},
                {61, 7.26},
                {62, 7.54},
                {63, 5.26},
                {64, 7.89},
                {65, 8.27},
                {66, 8.54},
                {67, 8.8},
                {68, 9.05},
                {69, 9.33},
                {70, 6.98},
                {71, 9.84},
                {72, 13.1},
                {73, 16.6},
                {74, 19.3},
                {75, 21.0},
                {76, 22.6},
                {77, 22.5},
                {78, 21.4},
                {79, 19.3},
                {80, 13.6},
                {81, 11.85},
                {82, 11.4},
                {83, 9.8},
                {84, 9.2},
                {85, 7.0},
                {86, 9.91},
                {87, 2.44},
                {88, 5.0},
                {89, 10.07},
                {90, 11.7},
                {91, 15.4},
                {92, 18.9},
                {93, 20.4},
                {94, 19.8},
                {95, 13.6},
                {96, 13.511}
        };


/**
 * Get the atomic weight (g/mol) from atomic number.
 *
 * @param[in] atomic_number
 * @return atomic weight in g/mol
 * @retval 0.0 the atomic number was invalid
 */
double get_atomic_weight_g_mol(const int atomic_number)
{
    return atomic_weights_g_mol.at(atomic_number);
}

/**
 * Get the mass density from atomic number.
 *
 * @param[in] atomic_number
 * @return mass density in g/cm3
 * @retval 0.0 the atomic number was invalid
 */
double get_atomic_mass_density_g_cm3(const int atomic_number)
{
    return atomic_mass_density_g_cm3.at(atomic_number);
}
