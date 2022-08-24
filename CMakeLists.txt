cmake_minimum_required(VERSION 3.15)

# Set the project name, version and programming language.
include(cmake/ProjectVersionDetails.cmake)
project(MonteCarlo-BSE LANGUAGES CXX VERSION ${MonteCarlo-BSE_VER})
include(cmake/StandardProjectSettings.cmake)
message("Project version: ${PROJECT_VERSION}")
message("CMake project version: ${CMAKE_PROJECT_VERSION}")
message("Monte Carlo BSE version${MonteCarlo-BSE_VERSION}")

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if (ENABLE_BUILD_WITH_TIME_TRACE)
    add_compile_definitions(project_options INTERFACE -ftime-trace)
  endif()
endif()
 
# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)
option(ENABLE_FUZZING "Enable Fuzz Test Builds" OFF)

# Very basic PCH example
option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if (ENABLE_PCH)
  # This sets a global PCH parameter, each project will build its own PCH, which
  # is a good idea if any #define's change
  # 
  # consider breaking this out per project as necessary 
  target_precompile_headers(project_options INTERFACE <vector> <string> <map> <utility>)
endif()


# Set up some extra Conan dependencies based on our needs
# before loading Conan
# Add conan to the path
LIST(APPEND CMAKE_PROGRAM_PATH  "venv/Scripts" ...)
set(CONAN_EXTRA_REQUIRES "")
set(CONAN_EXTRA_OPTIONS "")

include(cmake/Conan.cmake)
run_conan()

find_package(Threads)

#find_package(catch2 REQUIRED)
#find_package(spdlog)
#find_package(cli11)
include_directories(${CLI11_DIR}/include)

if(CMAKE_CXX_SIMULATE_ID STREQUAL "MSVC" AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_definitions(project_options  INTERFACE _CRT_SECURE_NO_WARNINGS)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_link_libraries(project_options INTERFACE tbb)
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_definitions(project_options  INTERFACE _CRT_SECURE_NO_WARNINGS)
endif()
if(MSVC)
  if(CPU_INSTRUCTION_SET MATCHES "arm64" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # Exceptions are not enabled by default for ARM targets and clang-cl, enable them
    target_compile_options(project_options INTERFACE /EHsc)
  endif()
endif()

# Add source folder before test folder.
add_subdirectory(src)

if(ENABLE_TESTING)
  enable_testing()
  message(
    "Building Tests. Be sure to check out test/constexpr_tests for constexpr testing"
  )
  add_subdirectory(test)
endif()

if(ENABLE_FUZZING)
  message(
    "Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html"
  )
  add_subdirectory(fuzz_test)
endif()
