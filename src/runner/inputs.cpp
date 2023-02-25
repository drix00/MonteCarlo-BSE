/**
 * @file
 *
 * @brief Input data for simulation runner.
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
#include <vector>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
#include "runner/inputs.h"
// Project headers
#include "constants/element.h"
#include "inputs/Input.h"
#include "inputs/Element.h"
// Project private headers

// Global and constant variables/functions.

using namespace std::string_literals;

std::vector<Data> get_inputs_number_trajectories_repetitions()
{
    std::vector<Data> data;

    const std::vector<int> repetition_ids{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const double initial_energy_eV{ 10.e3 };
    std::vector<int> const list_number_trajectories{ 10, 100, 1000, 10'000, 100'000, 1'000'000 };

    for (const int number_trajectories : list_number_trajectories) {
        for (const int repetition_id : repetition_ids) { // NOLINT
            const Element element = get_cu();
            const Input input{ element, initial_energy_eV, number_trajectories, repetition_id };
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_elements_energies()
{
    std::vector<Data> data;

    const int number_trajectories{ 1'000'000 };
    const std::vector<double> energies_keV{ 1.0, 2.0, 3.0, 4.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 40.0, 50.0, 60.0 };
    const std::vector<Element> elements{ get_c(), get_al(), get_si(), get_fe(), get_cu(), get_ag(), get_au() };

    for (auto element : elements) {
        for (auto energy_keV : energies_keV) { // NOLINT
            const auto initial_energy_eV = energy_keV * 1.0e3;
            const Input input{ element, initial_energy_eV, number_trajectories };
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_atomic_numbers()
{
    std::vector<Data> data;

    const double initial_energy_eV{ 15.e3 };
    const int number_trajectories{ 1'000'000 };
    const unsigned int maximum_atomic_number{96};

    for (unsigned int atomic_number = 1; atomic_number <= maximum_atomic_number; ++atomic_number) { // NOLINT
        const Element element{ atomic_number, mcbse::constants::element::get_atomic_weight_g_mol(atomic_number),
            mcbse::constants::element::get_atomic_mass_density_g_cm3(atomic_number) };
        const Input input{ element, initial_energy_eV, number_trajectories };
        data.emplace_back(input, "");
    }

    return data;
}

std::vector<Data> get_inputs_densities()
{
    std::vector<Data> data;

    const int number_repetitions{ 10 };
    const double initial_energy_eV{ 15.e3 };
    const int number_trajectories{ 1'000'000 };
    const std::vector<double> densities_g_cm3{ 0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 8.96, 9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 20.0, 30.0, 40.0, 50.0 };

    for (const double density_g_cm3 : densities_g_cm3) {
        for (int repetition_id = 1; repetition_id <= number_repetitions; ++repetition_id) { // NOLINT
            Element element = get_cu();
            element.density_g_cm3 = density_g_cm3;
            const Input input{ element, initial_energy_eV, number_trajectories, repetition_id };
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_thickness()
{
    std::vector<Data> data;

    const double initial_energy_eV{ 15.e3 };
    const int number_trajectories{ 1'000'000 };
    const std::vector<Element> elements{ get_c(), get_al(), get_si(), get_fe(), get_cu(), get_ag(), get_au() };
    const std::vector<double> thicknesses_nm{ 5.0, 10.0, 20.0, 30.0, 40.0, 50.0, 100.0, 150.0, 200.0, 250.0, 500.0, 750.0,
        1000.0, 1250.0, 1500.0, 1750.0, 2000.0, 2250.0, 2500.0, 3000.0, 4000.0, 5000.0 };

    for (auto element : elements) {
        for (const double thickness_nm : thicknesses_nm) { // NOLINT
            Input input{ element, initial_energy_eV, number_trajectories };
            input.thickness_nm = thickness_nm;
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_profile_serial_simple()
{
    std::vector<Data> data;

    const int number_repetitions = 10;
    const double initial_energy_eV = 10.e3;
    const int number_trajectories = 10'000;

    for (int repetition_id = 1; repetition_id <= number_repetitions; ++repetition_id) { // NOLINT
        const Element element = get_cu();
        const Input input{ element, initial_energy_eV, number_trajectories, repetition_id };
        data.emplace_back(input, "");
    }

    return data;
}

std::vector<Data> get_inputs_valgrind()
{
    std::vector<Data> data;

    const int repetition_id = 1;
    const double initial_energy_eV = 10.e3;
    const int number_trajectories = 1'000;

    const Element element = get_cu();
    const Input input{ element, initial_energy_eV, number_trajectories, repetition_id };
    data.emplace_back(input, "");

    return data;
}
