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
#include <array>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
#pragma hdrstop
// Project headers
#include "constants/element.h"
// Project private headers

// Global and constant variables/functions.

TEST_CASE("Test if element tests were find", "[test]")
{
   REQUIRE(true);
}

TEST_CASE("Constants element are tested", "[constants]")
{
    REQUIRE(monte_carlo::constants::element::get_symbol(1) == "H");
    REQUIRE(monte_carlo::constants::element::get_symbol(8)== "O");
    REQUIRE(monte_carlo::constants::element::get_symbol(94)== "Pu");

    REQUIRE(monte_carlo::constants::element::get_name(1) == "Hydrogen");
    REQUIRE(monte_carlo::constants::element::get_name(8)== "Oxygen");
    REQUIRE(monte_carlo::constants::element::get_name(94)== "Plutonium");
}

TEST_CASE("Constants element symbols are tested", "[constants]")
{
    const std::array symbols_ref{"H"  , "He" , "Li" , "Be" , "B"  , "C"  , "N"  , "O"  ,
                                            "F"  , "Ne" , "Na" , "Mg" , "Al" , "Si" , "P"  , "S"  ,
                                            "Cl" , "Ar" , "K"  , "Ca" , "Sc" , "Ti" , "V"  , "Cr" ,
                                            "Mn" , "Fe" , "Co" , "Ni" , "Cu" , "Zn" , "Ga" , "Ge" ,
                                            "As" , "Se" , "Br" , "Kr" , "Rb" , "Sr" , "Y"  , "Zr" ,
                                            "Nb" , "Mo" , "Tc" , "Ru" , "Rh" , "Pd" , "Ag" , "Cd" ,
                                            "In" , "Sn" , "Sb" , "Te" , "I"  , "Xe" , "Cs" , "Ba" ,
                                            "La" , "Ce" , "Pr" , "Nd" , "Pm" , "Sm" , "Eu" , "Gd" ,
                                            "Tb" , "Dy" , "Ho" , "Er" , "Tm" , "Yb" , "Lu" , "Hf" ,
                                            "Ta" , "W"  , "Re" , "Os" , "Ir" , "Pt" , "Au" , "Hg" ,
                                            "Tl" , "Pb" , "Bi" , "Po" , "At" , "Rn" , "Fr" , "Ra" ,
                                            "Ac" , "Th" , "Pa" , "U"  , "Np" , "Pu" , "Am" , "Cm" ,
                                            "Bk" , "Cf" , "Es" , "Fm" , "Md" , "No" , "Lr" , "Rf" ,
                                            "Db" , "Sg"
    };

    for (unsigned int i=1; i<=std::size(symbols_ref); ++i) {
        REQUIRE(monte_carlo::constants::element::get_symbol(i) == symbols_ref.at(i-1));
    }
}

TEST_CASE("Constants element names are tested", "[constants]")
{
    const std::array names_ref{"Hydrogen" ,
                                             "Helium" ,
                                             "Lithium" ,
                                             "Beryllium" ,
                                             "Boron" ,
                                             "Carbon" ,
                                             "Nitrogen" ,
                                             "Oxygen" ,
                                             "Fluorine" ,
                                             "Neon" ,
                                             "Sodium" ,
                                             "Magnesium" ,
                                             "Aluminium" ,
                                             "Silicon" ,
                                             "Phosphorus" ,
                                             "Sulfur" ,
                                             "Chlorine" ,
                                             "Argon" ,
                                             "Potassium" ,
                                             "Calcium" ,
                                             "Scandium" ,
                                             "Titanium" ,
                                             "Vanadium" ,
                                             "Chromium" ,
                                             "Manganese" ,
                                             "Iron" ,
                                             "Cobalt" ,
                                             "Nickel" ,
                                             "Copper" ,
                                             "Zinc" ,
                                             "Gallium" ,
                                             "Germanium" ,
                                             "Arsenic" ,
                                             "Selenium" ,
                                             "Bromine" ,
                                             "Krypton" ,
                                             "Rubidium" ,
                                             "Strontium" ,
                                             "Yttrium" ,
                                             "Zirconium" ,
                                             "Niobium" ,
                                             "Molybdenum" ,
                                             "Technetium" ,
                                             "Ruthenium" ,
                                             "Rhodium" ,
                                             "Palladium" ,
                                             "Silver" ,
                                             "Cadmium" ,
                                             "Indium" ,
                                             "Tin" ,
                                             "Antimony" ,
                                             "Tellurium" ,
                                             "Iodine" ,
                                             "Xenon" ,
                                             "Cesium" ,
                                             "Barium" ,
                                             "Lanthanum" ,
                                             "Cerium" ,
                                             "Praseodymium" ,
                                             "Neodymium" ,
                                             "Promethium" ,
                                             "Samarium" ,
                                             "Europium" ,
                                             "Gadolinium" ,
                                             "Terbium" ,
                                             "Dysprosium" ,
                                             "Holmium" ,
                                             "Erbium" ,
                                             "Thulium" ,
                                             "Ytterbium" ,
                                             "Lutetium" ,
                                             "Hafnium" ,
                                             "Tantalum" ,
                                             "Tungsten" ,
                                             "Rhenium" ,
                                             "Osmium" ,
                                             "Iridium" ,
                                             "Platinum" ,
                                             "Gold" ,
                                             "Mercury" ,
                                             "Thallium" ,
                                             "Lead" ,
                                             "Bismuth" ,
                                             "Polonium" ,
                                             "Astatine" ,
                                             "Radon" ,
                                             "Francium" ,
                                             "Radium" ,
                                             "Actinium" ,
                                             "Thorium" ,
                                             "Protactinium" ,
                                             "Uranium" ,
                                             "Neptunium" ,
                                             "Plutonium" ,
                                             "Americium" ,
                                             "Curium" ,
                                             "Berkelium" ,
                                             "Californium" ,
                                             "Einsteinium" ,
                                             "Fermium" ,
                                             "Mendelevium" ,
                                             "Nobelium" ,
                                             "Lawrencium" ,
                                             "Rutherfordium" ,
                                             "Dubnium" ,
                                             "Seaborgium"
    };

    for (unsigned int i=1; i<=std::size(names_ref); ++i) {
        REQUIRE(monte_carlo::constants::element::get_name(i) == names_ref.at(i-1));
    }
}

TEST_CASE("Constants element atomic mass are tested", "[constants]")
{
    const std::array atomic_weight_g_mol{
        1.00794, 4.002602, 6.941, 9.012182, 10.811, 12.0107,
        14.0067, 15.9994, 18.998403, 20.1797, 22.98976928, 24.305,
        26.9815386, 28.0855, 30.973762, 32.065, 35.453, 39.9480,
        39.0983, 40.078, 44.955912, 47.867, 50.9415, 51.9961,
        54.938045, 55.845, 58.933195, 58.6934, 63.546, 65.409,
        69.723, 72.64, 74.92160, 78.960, 79.904, 83.798,
        85.4678, 87.62, 88.90585, 91.224, 92.90638, 95.94,
        97.0, 101.07, 102.90550, 106.42, 107.8682, 112.411,
        114.818, 118.710, 121.760, 127.60, 126.90447, 131.293,
        132.9054519, 137.327, 138.90547, 140.116, 140.90765, 144.242,
        145.0, 150.36, 151.964, 157.25, 158.92535, 162.500,
        164.93032, 167.259, 168.93421, 173.04, 174.967, 178.49,
        180.94788, 183.84, 186.207, 190.23, 192.217, 195.084,
        196.966569, 200.59, 204.3833, 207.2, 208.98040, 209.0,
        210.0, 222.0, 223.0, 226.0, 227.0, 232.03806,
        231.03588, 238.02891, 237.0, 244.0, 243.0, 247.0,
        247.0, 251.0, 252.0, 257.0, 258.0, 259.0,
        266.0, 267.0, 268.0, 269.0
    };

    for (unsigned int i=1; i<=std::size(atomic_weight_g_mol); ++i) {
        INFO("The atomic number is " << i);
        REQUIRE(monte_carlo::constants::element::get_atomic_weight_g_mol(i) == atomic_weight_g_mol.at(i-1));
    }
}

TEST_CASE("Constants element atomic mass density are tested", "[constants]")
{
    const std::array rho_g_cm3{
        0.0899, 0.1787, 0.534, 1.85, 2.34, 2.267, 1.2510, 1.4290,
        1.6960, 0.9010, 0.971, 1.7400, 2.7000, 2.3300, 1.8200, 2.0700,
        3.1700, 1.7840, 0.86, 1.55, 3.0, 4.54, 6.11, 7.15,
        7.44, 7.874, 8.86, 8.912, 8.96, 7.134, 5.907, 5.323,
        5.776, 4.809, 3.122, 3.7400, 1.532, 2.64, 4.469, 6.506,
        8.57, 10.22, 11.5, 12.37, 12.41, 12.02, 10.501, 8.69,
        7.31, 7.287, 6.685, 6.232, 4.93, 5.8900, 1.873, 3.594,
        6.145, 6.77, 6.773, 7.007, 7.26, 7.52, 5.243, 7.895,
        8.229, 8.55, 8.795, 9.066, 9.321, 6.965, 9.84, 13.31,
        16.654, 19.25, 21.02, 22.61, 22.56, 21.46, 19.282, 13.5336,
        11.85, 11.342, 9.807, 9.32, 7.0, 9.91, 1.87, 5.5,
        10.07, 11.72, 15.37, 18.95, 20.45, 19.84, 13.69, 13.51,
        14.79, 15.1, 8.84, 9.7, 10.3, 9.9, 15.6, 23.2, 29.3, 35.0
    };

    for (unsigned int i=1; i<=std::size(rho_g_cm3); ++i) {
        INFO("The atomic number is " << i);
        REQUIRE(monte_carlo::constants::element::get_atomic_mass_density_g_cm3(i) == rho_g_cm3.at(i-1));
    }
}
