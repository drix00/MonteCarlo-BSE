macro(run_conan)
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
          "${CMAKE_BINARY_DIR}/conan.cmake"
          TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

# conan_add_remote(NAME bincrafters URL https://api.bintray.com/conan/bincrafters/public-conan)

set(CONAN_DISABLE_CHECK_COMPILER TRUE)

#conan_cmake_configure(REQUIRES
#        catch2/2.13.9
#        fmt/8.1.1
#        spdlog/1.10.0
##        cli11/2.2.0
#        GENERATORS cmake_find_package)
#
#conan_cmake_autodetect(settings)
#
#conan_cmake_install(PATH_OR_REFERENCE .
#        BUILD missing
#        REMOTE conancenter
#        SETTINGS ${settings})

conan_cmake_run(
  REQUIRES
  ${CONAN_EXTRA_REQUIRES}
  catch2/2.13.9
  spdlog/1.10.0
  cli11/2.1.2
  OPTIONS
  ${CONAN_EXTRA_OPTIONS}
  BASIC_SETUP
  CMAKE_TARGETS # individual targets to link to
  BUILD
  missing)
endmacro()
