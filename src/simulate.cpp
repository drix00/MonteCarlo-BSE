//
// Created by hendrix on 2020-06-07.
//
#include "simulate.h"

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <execution>

#include "models/RandomSeed.h"
#include "simulation/Simulation.h"
#include "Data.h"

void run_simulation(Data& datum, RandomSeed rand_seed) {

    Simulation simulation{ datum.input, rand_seed() };

    simulation.do_simulation();

    std::ostringstream output_file{""};
    output_file << datum.input.element.atomic_number << ",";
    output_file << datum.input.element.density_g_cm3 << ",";
    output_file << datum.input.thickness_nm << ",";
    output_file << datum.input.initial_energy_eV << ",";
    output_file << datum.input.number_trajectories << ",";
    output_file << datum.input.repetition_id << ",";
    output_file << simulation.bse.mean() << ",";
    output_file << simulation.bse.variance() << ",";
    output_file << simulation.bse.standard_deviation() << ",";
    output_file << simulation.te.mean() << ",";
    output_file << simulation.te.variance() << ",";
    output_file << simulation.te.standard_deviation() << ",";
    output_file << simulation.elapse_time_s() << std::endl;
    datum.line = output_file.str();
}

void write_results_file(std::string name, std::string suffix, std::vector<Data> data) {
    std::string file_name = name + suffix + ".csv";
    std::ofstream output_file(file_name);

    output_file << "atomic number" << ",";
    output_file << "density (g/cm3)" << ",";
    output_file << "thickness (nm)" << ",";
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

    for(auto datum: data) {
        output_file << datum.line << std::endl;
    }

}

void run_simulations_serial_simple(std::string name, std::string suffix, std::vector<Data> data) {
    for (auto& datum: data) {
        RandomSeed rand_seed;

        run_simulation(datum, rand_seed);
    }

    write_results_file(name, suffix, data);
}

void run_simulations_async_simple(std::string name, std::string suffix, std::vector<Data> data) {
    for (auto& datum: data) {
        RandomSeed rand_seed;

        run_simulation(datum, rand_seed);
    }

    write_results_file(name, suffix, data);
}

void run_simulations_for_each_simple(std::string name, std::string suffix, std::vector<Data> data) {
//    for_each (std::execution::par, data.begin(), data.end(), [] (auto& datum) {RandomSeed rand_seed; run_simulation(datum, rand_seed);});
    for_each (data.begin(), data.end(), [] (auto& datum) {RandomSeed rand_seed; run_simulation(datum, rand_seed);});

    write_results_file(name, suffix, data);
}

void run_simulations_for_each_seq_simple(std::string name, std::string suffix, std::vector<Data> data) {
    for_each (std::execution::seq, data.begin(), data.end(), [] (auto& datum) {RandomSeed rand_seed; run_simulation(datum, rand_seed);});

    write_results_file(name, suffix, data);
}

void run_simulations_for_each_unseq_simple(std::string name, std::string suffix, std::vector<Data> data) {
    for_each (std::execution::unseq, data.begin(), data.end(), [] (auto& datum) {RandomSeed rand_seed; run_simulation(datum, rand_seed);});

    write_results_file(name, suffix, data);
}

void run_simulations_for_each_par_simple(std::string name, std::string suffix, std::vector<Data> data) {
    for_each (std::execution::par, data.begin(), data.end(), [] (auto& datum) {RandomSeed rand_seed; run_simulation(datum, rand_seed);});

    write_results_file(name, suffix, data);
}

void run_simulations_for_each_par_unseq_simple(std::string name, std::string suffix, std::vector<Data> data) {
    for_each (std::execution::par_unseq, data.begin(), data.end(), [] (auto& datum) {RandomSeed rand_seed; run_simulation(datum, rand_seed);});

    write_results_file(name, suffix, data);
}

std::string get_suffix(){
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&t_c), "_%Y%m%d_%H%M%S");
    std::string suffix{ss.str()};
    return suffix;
}
