//
// Created by Hendrix Demers on 2020-05-10.
//
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

#include "inputs/Element.h"
#include "inputs/Input.h"
#include "models/RandomSeed.h"
#include "simulation/Simulation.h"

void simulate_number_trajectories_repetitions(std::string suffix)
{
    int number_repetitions = 10;
    double initial_energy_eV = 10.e3;
    std::vector<int> list_number_trajectories{10, 100, 1000, 10'000, 100'000, 1'000'000};

    std::string file_name = "simulate_number_trajectories_repetitions" + suffix + ".csv";
    std::ofstream output_file(file_name);

    output_file << "atomic number" << ", ";
    output_file << "initial energy eV" << ", ";
    output_file << "number trajectories" << ", ";
    output_file << "repetition id" << ", ";
    output_file << "bse" << ", ";
    output_file << "bse variance" << ", ";
    output_file << "bse std" << ", ";
    output_file << "te" << ", ";
    output_file << "te variance" << ", ";
    output_file << "te std" << ", ";
    output_file << "elapse time s" << '\n';

    for (int number_trajectories: list_number_trajectories){
        for(int repetition_id=1; repetition_id<=number_repetitions; ++repetition_id) {
            Element element = get_cu();
            Input input{ element, initial_energy_eV, number_trajectories };
            RandomSeed rand_seed;
            Simulation simulation{ input, rand_seed() };

            simulation.do_simulation();

            output_file << element.atomic_number << ", ";
            output_file << initial_energy_eV << ", ";
            output_file << number_trajectories << ", ";
            output_file << repetition_id << ", ";
            output_file << simulation.bse.mean() << ", ";
            output_file << simulation.bse.variance() << ", ";
            output_file << simulation.bse.standard_deviation() << ", ";
            output_file << simulation.te.mean() << ", ";
            output_file << simulation.te.variance() << ", ";
            output_file << simulation.te.standard_deviation() << ", ";
            output_file << simulation.elapse_time_s() << std::endl;
        }
    }
}

void simulate_elements_energies(std::string suffix)
{
    int repetition_id = 1;
    int number_trajectories = 1'000'000;
    std::vector<double> energies_keV{1.0, 2.0, 3.0, 4.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 40.0, 50.0, 60.0};
    std::vector<Element> elements{get_c(), get_al(), get_si(), get_fe(), get_cu(), get_ag(), get_au()};

    std::string file_name = "simulate_elements_energies" + suffix + ".csv";
    std::ofstream output_file(file_name);

    output_file << "atomic number" << ", ";
    output_file << "initial energy eV" << ", ";
    output_file << "number trajectories" << ", ";
    output_file << "repetition id" << ", ";
    output_file << "bse" << ", ";
    output_file << "bse variance" << ", ";
    output_file << "bse std" << ", ";
    output_file << "te" << ", ";
    output_file << "te variance" << ", ";
    output_file << "te std" << ", ";
    output_file << "elapse time s" << '\n';

    for (auto element: elements) {
        for (auto energy_keV: energies_keV) {
            auto initial_energy_eV = energy_keV * 1.0e3;
            Input input{ element, initial_energy_eV, number_trajectories };
            RandomSeed rand_seed;
            Simulation simulation{ input, rand_seed() };

            simulation.do_simulation();

            output_file << element.atomic_number << ", ";
            output_file << initial_energy_eV << ", ";
            output_file << number_trajectories << ", ";
            output_file << repetition_id << ", ";
            output_file << simulation.bse.mean() << ", ";
            output_file << simulation.bse.variance() << ", ";
            output_file << simulation.bse.standard_deviation() << ", ";
            output_file << simulation.te.mean() << ", ";
            output_file << simulation.te.variance() << ", ";
            output_file << simulation.te.standard_deviation() << ", ";
            output_file << simulation.elapse_time_s() << std::endl;
        }
    }
}

void simulate_atomic_numbers(std::string suffix)
{
    int repetition_id = 1;
    double initial_energy_eV = 15.e3;
    int number_trajectories = 1'000'000;

    std::string file_name = "simulate_atomic_numbers" + suffix + ".csv";
    std::ofstream output_file(file_name);

    output_file << "atomic number" << ", ";
    output_file << "initial energy eV" << ", ";
    output_file << "number trajectories" << ", ";
    output_file << "repetition id" << ", ";
    output_file << "bse" << ", ";
    output_file << "bse variance" << ", ";
    output_file << "bse std" << ", ";
    output_file << "te" << ", ";
    output_file << "te variance" << ", ";
    output_file << "te std" << ", ";
    output_file << "elapse time s" << '\n';

    for (int atomic_number=1; atomic_number<=96; ++atomic_number){
        Element element{atomic_number, get_atomic_weight_g_mol(atomic_number), get_atomic_mass_density_g_cm3(atomic_number)};
        Input input{ element, initial_energy_eV, number_trajectories };
        RandomSeed rand_seed;
        Simulation simulation{ input, rand_seed() };

        simulation.do_simulation();

        output_file << element.atomic_number << ", ";
        output_file << initial_energy_eV << ", ";
        output_file << number_trajectories << ", ";
        output_file << repetition_id << ", ";
        output_file << simulation.bse.mean() << ", ";
        output_file << simulation.bse.variance() << ", ";
        output_file << simulation.bse.standard_deviation() << ", ";
        output_file << simulation.te.mean() << ", ";
        output_file << simulation.te.variance() << ", ";
        output_file << simulation.te.standard_deviation() << ", ";
        output_file << simulation.elapse_time_s() << std::endl;
    }
}

void simulate_densities(std::string suffix)
{
    int number_repetitions = 10;
    double initial_energy_eV = 15.e3;
    int number_trajectories = 1'000'000;
    std::vector<double> densities_g_cm3{0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 8.96, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 20.0, 30.0, 40.0, 50.0};

    std::string file_name = "simulate_densities" + suffix + ".csv";
    std::ofstream output_file(file_name);

    output_file << "atomic number" << ", ";
    output_file << "density (g/cm3)" << ", ";
    output_file << "initial energy eV" << ", ";
    output_file << "number trajectories" << ", ";
    output_file << "repetition id" << ", ";
    output_file << "bse" << ", ";
    output_file << "bse variance" << ", ";
    output_file << "bse std" << ", ";
    output_file << "te" << ", ";
    output_file << "te variance" << ", ";
    output_file << "te std" << ", ";
    output_file << "elapse time s" << '\n';

    for (double density_g_cm3: densities_g_cm3){
        for(int repetition_id=1; repetition_id<=number_repetitions; ++repetition_id) {
            Element element = get_cu();
            element.density_g_cm3 = density_g_cm3;
            Input input{ element, initial_energy_eV, number_trajectories };
            RandomSeed rand_seed;
            Simulation simulation{ input, rand_seed() };

            simulation.do_simulation();

            output_file << element.atomic_number << ", ";
            output_file << element.density_g_cm3 << ", ";
            output_file << initial_energy_eV << ", ";
            output_file << number_trajectories << ", ";
            output_file << repetition_id << ", ";
            output_file << simulation.bse.mean() << ", ";
            output_file << simulation.bse.variance() << ", ";
            output_file << simulation.bse.standard_deviation() << ", ";
            output_file << simulation.te.mean() << ", ";
            output_file << simulation.te.variance() << ", ";
            output_file << simulation.te.standard_deviation() << ", ";
            output_file << simulation.elapse_time_s() << std::endl;
        }
    }
}

void simulate_thickness(std::string suffix)
{
    int repetition_id = 1;
    double initial_energy_eV = 15.e3;
    int number_trajectories = 1'000'000;
    std::vector<Element> elements{get_c(), get_al(), get_si(), get_fe(), get_cu(), get_ag(), get_au()};
    std::vector<double> thicknesses_nm{5.0, 10.0, 20.0, 30.0, 40.0, 50.0, 100.0, 150.0, 200.0, 250.0, 500.0, 750.0, 1000.0, 1250.0, 1500.0, 1750.0, 2000.0, 2250.0, 2500.0, 3000.0, 4000.0, 5000.0};

    std::string file_name = "simulate_thickness" + suffix + ".csv";
    std::ofstream output_file(file_name);

    output_file << "atomic number" << ", ";
    output_file << "thickness (nm)" << ", ";
    output_file << "initial energy eV" << ", ";
    output_file << "number trajectories" << ", ";
    output_file << "repetition id" << ", ";
    output_file << "bse" << ", ";
    output_file << "bse variance" << ", ";
    output_file << "bse std" << ", ";
    output_file << "te" << ", ";
    output_file << "te variance" << ", ";
    output_file << "te std" << ", ";
    output_file << "elapse time s" << '\n';

    for (auto element: elements) {
        for (double thickness_nm: thicknesses_nm){
            Input input{ element, initial_energy_eV, number_trajectories };
            input.thickness_nm = thickness_nm;
            RandomSeed rand_seed;
            Simulation simulation{ input, rand_seed() };

            simulation.do_simulation();

            output_file << element.atomic_number << ", ";
            output_file << input.thickness_nm << ", ";
            output_file << initial_energy_eV << ", ";
            output_file << number_trajectories << ", ";
            output_file << repetition_id << ", ";
            output_file << simulation.bse.mean() << ", ";
            output_file << simulation.bse.variance() << ", ";
            output_file << simulation.bse.standard_deviation() << ", ";
            output_file << simulation.te.mean() << ", ";
            output_file << simulation.te.variance() << ", ";
            output_file << simulation.te.standard_deviation() << ", ";
            output_file << simulation.elapse_time_s() << std::endl;
        }
    }
}


int main(int , const char **)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&t_c), "_%Y%m%d_%H%M%S");
    std::string suffix{ss.str()};

    simulate_number_trajectories_repetitions(suffix);
    simulate_elements_energies(suffix);
    simulate_atomic_numbers(suffix);
    simulate_densities(suffix);
    simulate_thickness(suffix);
}