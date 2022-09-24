# Set the runner source files
set(runner_source_files)
foreach(item IN LISTS mcbse_source_files)
    set(runner_source_files ${runner_source_files} "../${item}")
endforeach()

list(LENGTH runner_source_files len)
message("Runner source files length = ${len}")

# Function to create each runner program
function(runner_program program_name)
    add_executable(${program_name} ${program_name}.cpp ${runner_source_files})
    target_include_directories(${program_name} PRIVATE ../../src)
    target_link_libraries(${program_name} PRIVATE project_options project_warnings Threads::Threads CONAN_PKG::spdlog CONAN_PKG::cli11
            MonteCarlo-BSE_version)
endfunction()

# Runner program
runner_program(run_serial_simple)
runner_program(run_async_simple)
runner_program(run_for_each_simple)
runner_program(run_valgrind)
runner_program(profile_serial_simple)
