//
// Created by hendrix on 2020-06-07.
//
#include <vector>
#include <string>

#include "inputs.h"
#include "inputs/Input.h"

using namespace std::string_literals;

std::vector<Data> get_inputs_number_trajectories_repetitions() {
    std::vector<Data> data;

    int number_repetitions{10};
    double initial_energy_eV{10.e3};
    std::vector<int> list_number_trajectories{10, 100, 1000, 10'000, 100'000, 1'000'000};

    for (int number_trajectories: list_number_trajectories){
        for(int repetition_id=1; repetition_id<=number_repetitions; ++repetition_id) {
            Element element = get_cu();
            Input input{ element, initial_energy_eV, number_trajectories, repetition_id};
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_elements_energies() {
    std::vector<Data> data;

    int number_trajectories{1'000'000};
    std::vector<double> energies_keV{1.0, 2.0, 3.0, 4.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 40.0, 50.0, 60.0};
    std::vector<Element> elements{get_c(), get_al(), get_si(), get_fe(), get_cu(), get_ag(), get_au()};

    for (auto element: elements) {
        for (auto energy_keV: energies_keV) {
            auto initial_energy_eV = energy_keV * 1.0e3;
            Input input{ element, initial_energy_eV, number_trajectories };
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_atomic_numbers() {
    std::vector<Data> data;

    double initial_energy_eV{15.e3};
    int number_trajectories{1'000'000};

    for (int atomic_number=1; atomic_number<=96; ++atomic_number){
        Element element{atomic_number, get_atomic_weight_g_mol(atomic_number), get_atomic_mass_density_g_cm3(atomic_number)};
        Input input{ element, initial_energy_eV, number_trajectories };
        data.emplace_back(input, "");
    }

    return data;
}

std::vector<Data> get_inputs_densities() {
    std::vector<Data> data;

    int number_repetitions{10};
    double initial_energy_eV{15.e3};
    int number_trajectories{1'000'000};
    std::vector<double> densities_g_cm3{0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 8.96, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 20.0, 30.0, 40.0, 50.0};

    for (double density_g_cm3: densities_g_cm3){
        for(int repetition_id=1; repetition_id<=number_repetitions; ++repetition_id) {
            Element element = get_cu();
            element.density_g_cm3 = density_g_cm3;
            Input input{ element, initial_energy_eV, number_trajectories, repetition_id };
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_thickness() {
    std::vector<Data> data;

    double initial_energy_eV{15.e3};
    int number_trajectories{1'000'000};
    std::vector<Element> elements{get_c(), get_al(), get_si(), get_fe(), get_cu(), get_ag(), get_au()};
    std::vector<double> thicknesses_nm{5.0, 10.0, 20.0, 30.0, 40.0, 50.0, 100.0, 150.0, 200.0, 250.0, 500.0, 750.0, 1000.0, 1250.0, 1500.0, 1750.0, 2000.0, 2250.0, 2500.0, 3000.0, 4000.0, 5000.0};

    for (auto element: elements) {
        for (double thickness_nm: thicknesses_nm){
            Input input{ element, initial_energy_eV, number_trajectories };
            input.thickness_nm = thickness_nm;
            data.emplace_back(input, "");
        }
    }

    return data;
}

std::vector<Data> get_inputs_profile_serial_simple() {
    std::vector<Data> data;

    int number_repetitions = 10;
    double initial_energy_eV = 10.e3;
    int number_trajectories = 10'000;

    for(int repetition_id=1; repetition_id<=number_repetitions; ++repetition_id) {
        Element element = get_cu();
        Input input{ element, initial_energy_eV, number_trajectories, repetition_id };
        data.emplace_back(input, "");
    }

    return data;
}
