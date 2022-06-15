# MonteCarlo-BSE
Monte Carlo simulation of backscattered electron (BSE) in a SEM.

## Badges

AppVeyor (Windows): [![Build status](https://ci.appveyor.com/api/projects/status/95ald9y73323fgr7?svg=true)](https://ci.appveyor.com/project/drix00/montecarlo-bse)

Travis CI (Linux): [![Build Status](https://travis-ci.com/drix00/MonteCarlo-BSE.svg?branch=master)](https://travis-ci.com/drix00/MonteCarlo-BSE)

## Changelog

### Version 0.3

* Add for_each simulation run.
* Refactor run simulation code.
* Add run valgrind.
* Add profiling run.

### Version 0.2.1

* Add Python script to analyse simulations results.
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
3. .\venv\Scripts\activate.ps1
4. python -m pip install conan


### Clion


### Visual Studio 2019 (Windows)

The best way to use the CMake project with Visual Studio 2019 is to use "File > Open > Folder" to open the project folder with the main CMakeLists.txt.
Use the CMakeSettings.json to add target to the project.
