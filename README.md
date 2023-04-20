# MonteCarlo-BSE                {#mainpage}  
Monte Carlo simulation of backscattered electron (BSE) in a SEM.

## Badges

AppVeyor (Windows): [![Build status](https://ci.appveyor.com/api/projects/status/95ald9y73323fgr7?svg=true)](https://ci.appveyor.com/project/drix00/montecarlo-bse)

AppVeyor (Windows) master branch: [![Build status](https://ci.appveyor.com/api/projects/status/95ald9y73323fgr7/branch/master?svg=true)](https://ci.appveyor.com/project/drix00/montecarlo-bse/branch/master)

Travis CI (Linux): [![Build Status](https://app.travis-ci.com/drix00/MonteCarlo-BSE.svg?branch=master)](https://app.travis-ci.com/github/drix00/MonteCarlo-BSE)

GitHub Action build (linux): ![Build Status](https://github.com/drix00/MonteCarlo-BSE/actions/workflows/build_cmake.yml/badge.svg)

## Changelog

### Version 0.3

* Add for_each simulation run.
* Refactor run simulation code.
* Add run valgrind.
* Add profiling run.

### Version 0.2.1

* Add a Python script to analyse simulations results.
* Remove space in csv result files.

### Version 0.2

* Correct compilation problems with gcc/Linux and failing tests.
* Build 2020-05-12, see commit 5280894ab01d4e18f9b6bc47c5c161ba7bf4faf8.

### Version 0.1

* Initial version with serial and simple Monte Carlo code to compute BSE coefficient.
* Build 2020-05-11, see commit 38682f48529305fc85824fccd8fb98402920ef19.

## Development

Need to install:

1. Install Python
2. Setup venv in the project folder
3. ".\venv\Scripts\activate.ps1"
4. python -m pip install conan

### Clion

1. Setup venv in the project setting
2. Add conan package in setting
3. Add toolchain
4. Add CMake profile

### Visual Studio 2019 (Windows)

The best way to use the CMake project with Visual Studio 2019 is to use "File > Open > Folder" to open the project folder with the main CMakeLists.txt.
Use the CMakeSettings.json to add target to the project.

## Ideas to implement

* Make Continuous build on github to work.
  * Continuous integration via GitHub Actions
* Code formatting enforced by clang-format and cmake-format via Format.cmake
* Installable target with automatic versioning information and header generation via PackageProject.cmake
* Compile on these compiler.
  * GCC
  * Clang
  * cl (Visual Studio)
  * clang-cl
* Generated and publish documentation with doxygen.
  * Automatic documentation and deployment with Doxygen and GitHub Pages
* Generate test coverage
  * coveralls
  * codecov
* Do static analysis
  * at least -Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror and -W4 on Windows
  * gcc -fanalyzer
  * cl.exe /analyze
  * cppcheck
  * clang-tidy
  * pvs studio https://pvs-studio.com/en/
  * sonar's tools https://www.sonarsource.com/
* Runtime analysis during testing 
  * address sanitizer (https://clang.llvm.org/docs/index.html)
  * undefined behavior sanitizer
  * thread sanitizer
  * valgrind (if you can tolerate it)
  * debug checked iterators https://gcc.gnu.org/onlinedocs/libstdc++/manual/debug_mode_using.html#debug_mode.using.mode https://learn.microsoft.com/en-us/cpp/standard-library/checked-iterators?view=msvc-170
  * drmemory
* Fuzz Testing
* Ship with hardening enabled
  * Control Flow Guard - https://learn.microsoft.com/en-us/cpp/build/reference/guard-enable-control-flow-guard?view=msvc-170
  * _FORITFY_SOURCE - https://developers.redhat.com/articles/2022/09/17/gccs-new-fortification-level
  * Stack Protector - https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html
  * UBSan "Minimal runtime" mode - https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html#minimal-runtime
* Continuous slowing down energy loss models comparison.
* Electron inelastic cross section models comparison. 
* Electron elastic cross section models comparison.
* Fix geometry
  * bulk
  * film on substrate
  * thin film
  * sphere on a substrate
  * cube on a substrate
  * sphere in a substrate
  * vertical interface
  * pyramid with a square base on a substrate
  * pyramid with a triangle base on a substrate
  * cylinder on its side
  * cylinder on end
  * hemispherical cap
  * buried layer in substrate
  * buried box in substrate
* Constructive solid geometry (CSG)
  * sphere
  * ellipsoid
  * plane
  * cube (cuboid) and prism
  * cylinder
  * cone
  * tetrahedron
  * polyhedron
  * truncated pyramid
  * rounded box
* Triangle meshes (surface representation modeling)
  * Bounding volume hierarchies
* Line scan
* Map or image scan
* Beam shape models comparison
* Secondary electrons
* Fast secondary electrons
* Material (spatial zone)
  * homogeneous composition
  * continuous change of composition
  * interface crossing models comparison
* Parallelization
  * single scanning point
  * line scan and map scanning point
* Simulation input file
* Simulation results file
* Results
  * BSE
  * trajectories
  * exit electrons
  * energy loss
  * detector geometry and efficiency
* X-ray
  * characteristic cross section models comparison
  * bremsstrahlung cross section models comparison
  * absorption models comparison
  * detector models
* Simulate magnetic field.
* Simulate electric field.
* Plural scattering model.
* Charge collection microscopy
  * EBIC
  * Cathodoluminescence
