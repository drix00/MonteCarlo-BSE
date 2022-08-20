# automatically enable catch2 to generate ctest targets
if (CONAN_CATCH2_ROOT_DEBUG)
    include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else ()
    include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif ()

add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)
target_link_libraries(catch_main PRIVATE project_options CONAN_PKG::spdlog MonteCarlo-BSE_version)

set(test_source_files constants/element_test.cpp       )
set(test_source_files ${test_source_files} inputs/Element_test.cpp)
set(test_source_files ${test_source_files} inputs/Input_test.cpp)
set(test_source_files ${test_source_files} models/DirectionCosine_test.cpp)
set(test_source_files ${test_source_files} models/EnergyLoss_test.cpp)
set(test_source_files ${test_source_files} models/MeanFreePath_test.cpp)
set(test_source_files ${test_source_files} models/RandomNumber_test.cpp)
set(test_source_files ${test_source_files} models/RandomSeed_test.cpp)
set(test_source_files ${test_source_files} models/Rutherford_test.cpp)
set(test_source_files ${test_source_files} results/Counter_test.cpp)
set(test_source_files ${test_source_files} results/Statistic_test.cpp)
set(test_source_files ${test_source_files} simulation/Simulation_test.cpp)
set(test_source_files ${test_source_files} utilities/logger_test.cpp)
set(test_source_files ${test_source_files} utilities/ProgramVersion_test.cpp)
set(test_source_files ${test_source_files} utilities/Timer_test.cpp)
set(test_source_files ${test_source_files} utilities/version_test.cpp)
set(test_source_files ${test_source_files} utilities/VersionInfo_test.cpp)
set(test_source_files ${test_source_files} constexpr_tests.cpp)
set(test_source_files ${test_source_files} runner/Data_test.cpp)
set(test_source_files ${test_source_files} runner/inputs_test.cpp)
set(test_source_files ${test_source_files} mcbse_console_test.cpp)
set(test_source_files ${test_source_files} runner/simulate_test.cpp)

list(LENGTH test_source_files len)
message("MCBSE test source files length = ${len}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fprofile-arcs -ftest-coverage)
    add_link_options(-lgcov --coverage)
endif()

add_executable(tests ${test_source_files} ${mcbse_source_files})
target_include_directories(tests PRIVATE ../src)
target_link_libraries(tests PRIVATE project_options project_warnings catch_main CONAN_PKG::spdlog)

# automatically discover tests that are defined in catch based test files you
# can modify the unittests. TEST_PREFIX to whatever you want, or use different
# for different binaries
catch_discover_tests(
        tests
        TEST_PREFIX
        "unittests."
        EXTRA_ARGS
        -s
        --reporter=xml
        --out=tests.xml)

# Add a file containing a set of constexpr tests
add_executable(constexpr_tests constexpr_tests.cpp)
target_link_libraries(constexpr_tests PRIVATE project_options project_warnings catch_main)

catch_discover_tests(
        constexpr_tests
        TEST_PREFIX
        "constexpr."
        EXTRA_ARGS
        -s
        --reporter=xml
        --out=constexpr.xml)

# Disable the constexpr portion of the test, and build again this allows us to
# have an executable that we can debug when things go wrong with the constexpr
# testing
add_executable(relaxed_constexpr_tests constexpr_tests.cpp)
target_link_libraries(relaxed_constexpr_tests PRIVATE project_options project_warnings catch_main)
target_compile_definitions(relaxed_constexpr_tests PRIVATE -DCATCH_CONFIG_RUNTIME_STATIC_REQUIRE)

catch_discover_tests(
        relaxed_constexpr_tests
        TEST_PREFIX
        "relaxed_constexpr."
        EXTRA_ARGS
        -s
        --reporter=xml
        --out=relaxed_constexpr.xml)
