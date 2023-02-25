/**
 * @file
 *
 * Tests to learn how to use the h5pp library for using HDF5 file.
 *
 * @author Hendrix Demers <hendrix.demers@mail.mcgill.ca>
 * @copyright 2022
 */

//   Copyright 2022 Hendrix Demers
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

// C system headers
// C++ system header
#include <filesystem>
#include <string>
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "utilities/h5pp_wrapper.h"
// Project private headers

// Global and constant variables/functions.
namespace fs = std::filesystem;

TEST_CASE("Test if h5pp tests were find", "[h5pp_test]")
{
    REQUIRE(true);
}

TEST_CASE("Test write /read a vector", "[h5pp_test]")
{
    const fs::path file_path = fs::temp_directory_path() / "vector.h5";
    if (fs::is_regular_file(file_path))
    {
        fs::remove(file_path);
    }
    REQUIRE(fs::is_regular_file(file_path) == false);

    const std::vector<double> vector_ref = { 1.0, 2.0, 3.0 };

    h5pp::File write_file(file_path);
    write_file.writeDataset(vector_ref, "std_vector");

    REQUIRE(fs::is_regular_file(file_path)); // NOLINT

    const h5pp::File file(file_path, h5pp::FileAccess::READWRITE);
    auto vector_values = file.readDataset<std::vector<double>>("std_vector");

    REQUIRE(vector_values == vector_ref);
}

TEST_CASE("Test write /read a int", "[h5pp_test]")
{
    const fs::path file_path = fs::temp_directory_path() / "int.h5";

    const int write_int{42};

    h5pp::File write_file(file_path, h5pp::FileAccess::REPLACE);
    write_file.writeDataset(write_int, "integer_data");

    REQUIRE(fs::is_regular_file(file_path)); // NOLINT

    const h5pp::File file(file_path, h5pp::FileAccess::READWRITE);

    auto read_int = file.readDataset<int>("integer_data");
    REQUIRE(read_int == write_int);

    int read_int_alt{0};
    file.readDataset(read_int_alt, "integer_data");
    REQUIRE(read_int_alt == write_int);
}

TEST_CASE("Test write /read a string", "[h5pp_test]")
{
    const fs::path file_path = fs::temp_directory_path() / "string.h5";

    const std::string write_str{"Hello world"};

    h5pp::File write_file(file_path, h5pp::FileAccess::REPLACE);
    write_file.writeDataset(write_str, "string_data");

    REQUIRE(fs::is_regular_file(file_path)); // NOLINT

    const h5pp::File file(file_path, h5pp::FileAccess::READWRITE);

    auto read_str = file.readDataset<std::string>("string_data");
    REQUIRE(read_str == write_str);

    std::string read_str_alt;
    file.readDataset(read_str_alt, "string_data");
    REQUIRE(read_str_alt == write_str);
}

TEST_CASE("Test write /read an attribute", "[h5pp_test]")
{
    const fs::path file_path = fs::temp_directory_path() / "attribute.h5";

    const int write_int{42};

    h5pp::File write_file(file_path, h5pp::FileAccess::REPLACE);
    write_file.writeDataset(write_int, "int_group/my_int");

    write_file.writeAttribute("this is some info about my int", "int_group/my_int", "myInt_stringAttribute");
    write_file.writeAttribute(3.14, "int_group/my_int", "myInt_doubleAttribute"); // NOLINT

    REQUIRE(fs::is_regular_file(file_path)); // NOLINT

    const h5pp::File file(file_path, h5pp::FileAccess::READWRITE);
    h5pp::print("{}\n", file.getAttributeNames("int_group/my_int"));

    auto stringAttribute = file.readAttribute<std::string>("int_group/my_int", "myInt_stringAttribute");
    auto doubleAttribute = file.readAttribute<double>("int_group/my_int", "myInt_doubleAttribute");

    REQUIRE(stringAttribute == "this is some info about my int"); // NOLINT
    REQUIRE(doubleAttribute == 3.14); // NOLINT
}
