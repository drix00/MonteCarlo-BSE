//
// Created by hendrix on 2020-06-07.
//

#include "Timer.h"

double Timer::get_elapse_time_s() {
    double time_s = compute_elapse_time_s(last, std::chrono::steady_clock::now());
    last = std::chrono::steady_clock::now();
    return time_s;
}
double Timer::get_total_elapse_time_s() {
    double time_s = compute_elapse_time_s(start_time, std::chrono::steady_clock::now());
    return time_s;
}

double Timer::compute_elapse_time_s(std::chrono::steady_clock::time_point start_time_, std::chrono::steady_clock::time_point end_time) {
    std::chrono::duration elapse_time = end_time - start_time_;
    auto elapse_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapse_time);
    auto elapse_time_s = std::chrono::duration_cast<std::chrono::seconds>(elapse_time_ns).count();
    double fraction = static_cast<double>(elapse_time_ns.count()) - static_cast<double>(elapse_time_s) * 1.0e9;
    double time_s = static_cast<double>(elapse_time_s) + fraction * 1.0e-9;

    return time_s;
}
