//
// Created by hendrix on 2020-05-25.
//

#include <string>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <iostream>

#include "inputs/Element.h"
#include "inputs/Input.h"
#include "models/RandomSeed.h"
#include "simulation/Simulation.h"

void profile_serial_simple(std::string suffix)
{
    int number_repetitions = 1;
    double initial_energy_eV = 10.e3;
    int number_trajectories = 100'000;

    std::string file_name = "profile_serial_simple" + suffix + ".csv";
    std::ofstream output_file(file_name);

    output_file << "atomic number" << ",";
    output_file << "initial energy eV" << ",";
    output_file << "number trajectories" << ",";
    output_file << "repetition id" << ",";
    output_file << "bse" << ",";
    output_file << "bse variance" << ",";
    output_file << "bse std" << ",";
    output_file << "te" << ",";
    output_file << "te variance" << ",";
    output_file << "te std" << ",";
    output_file << "elapse time s" << '\n';

    for(int repetition_id=1; repetition_id<=number_repetitions; ++repetition_id) {
        Element element = get_cu();
        Input input{ element, initial_energy_eV, number_trajectories };
        RandomSeed rand_seed;
        Simulation simulation{ input, rand_seed() };

        simulation.do_simulation();

        output_file << element.atomic_number << ",";
        output_file << initial_energy_eV << ",";
        output_file << number_trajectories << ",";
        output_file << repetition_id << ",";
        output_file << simulation.bse.mean() << ",";
        output_file << simulation.bse.variance() << ",";
        output_file << simulation.bse.standard_deviation() << ",";
        output_file << simulation.te.mean() << ",";
        output_file << simulation.te.variance() << ",";
        output_file << simulation.te.standard_deviation() << ",";
        output_file << simulation.elapse_time_s() << std::endl;
    }
}

int main(int , const char **)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&t_c), "_%Y%m%d_%H%M%S");
    std::string suffix{ss.str()};

    std::chrono::steady_clock::time_point start_time{ std::chrono::steady_clock::now() };
    profile_serial_simple(suffix);
    std::chrono::steady_clock::time_point end_time{ std::chrono::steady_clock::now() };
    std::chrono::duration elapse_time = end_time - start_time;
    auto elapse_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapse_time);
    auto elapse_time_s = std::chrono::duration_cast<std::chrono::seconds>(elapse_time_ns).count();
    double fraction = static_cast<double>(elapse_time_ns.count()) - static_cast<double>(elapse_time_s) * 1.0e9;
    double time_s = static_cast<double>(elapse_time_s) + fraction * 1.0e-9;
    std::cout << "Elapse time: " << time_s << " s\n";
}