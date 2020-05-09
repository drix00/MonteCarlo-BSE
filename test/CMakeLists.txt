# automatically enable catch2 to generate ctest targets
if (CONAN_CATCH2_ROOT_DEBUG)
    include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else ()
    include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif ()


add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)
target_link_libraries(catch_main PRIVATE project_options)

set(source_files ../src/inputs/Input.cpp ../src/inputs/Element.cpp ../src/inputs/Element.h ../src/models/Rutherford.cpp ../src/models/Rutherford.h ../src/models/EnergyLoss.cpp ../src/models/EnergyLoss.h ../src/models/MeanFreePath.cpp ../src/models/MeanFreePath.h ../src/models/DirectionCosine.cpp ../src/models/DirectionCosine.h)
set(test_source_files inputs/Input_test.cpp inputs/Element_test.cpp models/Rutherford_test.cpp models/EnergyLoss_test.cpp models/MeanFreePath_test.cpp models/DirectionCosine_test.cpp)

add_executable(tests tests.cpp ${test_source_files} ${source_files})
target_link_libraries(tests PRIVATE project_warnings project_options catch_main)
target_include_directories(tests PRIVATE ../src)


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
target_link_libraries(constexpr_tests PRIVATE project_options project_warnings
        catch_main)

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
target_link_libraries(
        relaxed_constexpr_tests PRIVATE project_options project_warnings
        catch_main)
target_compile_definitions(
        relaxed_constexpr_tests PRIVATE
        -DCATCH_CONFIG_RUNTIME_STATIC_REQUIRE)


catch_discover_tests(
        relaxed_constexpr_tests
        TEST_PREFIX
        "relaxed_constexpr."
        EXTRA_ARGS
        -s
        --reporter=xml
        --out=relaxed_constexpr.xml)