
# Generic test that uses conan libs
add_executable(intro main.cpp)
target_link_libraries(intro PRIVATE project_options project_warnings CONAN_PKG::spdlog)

# Simulate serial an simple code.
set(serial_simple_source_files ../src/inputs/Input.cpp ../src/inputs/Element.cpp ../src/inputs/Element.h ../src/models/Rutherford.cpp ../src/models/Rutherford.h ../src/models/EnergyLoss.cpp ../src/models/EnergyLoss.h ../src/models/MeanFreePath.cpp ../src/models/MeanFreePath.h ../src/models/DirectionCosine.cpp ../src/models/DirectionCosine.h ../src/simulation/Simulation.cpp ../src/simulation/Simulation.h ../src/models/RandomNumber.cpp ../src/models/RandomNumber.h ../src/results/Statistic.cpp ../src/results/Statistic.h ../src/models/RandomSeed.cpp ../src/models/RandomSeed.h results/Counter.cpp results/Counter.h)

add_executable(run_serial_simple run_serial_simple.cpp ${serial_simple_source_files})
target_link_libraries(run_serial_simple PRIVATE project_options project_warnings)
target_include_directories(run_serial_simple PRIVATE ../src)
target_compile_definitions(run_serial_simple  PRIVATE _CRT_SECURE_NO_WARNINGS)

add_executable(profile_serial_simple profile_serial_simple.cpp ${serial_simple_source_files})
target_link_libraries(profile_serial_simple PRIVATE project_options project_warnings)
target_include_directories(profile_serial_simple PRIVATE ../src)
target_compile_definitions(profile_serial_simple  PRIVATE _CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
#set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -DNDEBUG -mavx")
message(${CMAKE_CXX_FLAGS_RELEASE})
