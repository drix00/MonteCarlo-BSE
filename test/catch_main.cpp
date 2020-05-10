//#define CATCH_CONFIG_MAIN // This tells the catch header to generate a main
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"

int main(int argc, char *argv[])
{
    // global setup...

    auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.log");
    spdlog::set_default_logger(file_logger);

    int result = Catch::Session().run(argc, argv);

    // global clean-up...

    return result;
}