/**
* @file
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
// Library headers
#include <catch2/catch.hpp>
// Precompiled header
// Project headers
#include "utilities/VersionInfo.h"
// Project private headers

// Global and constant variables/functions.
using namespace mcbse::version;

TEST_CASE("Test if VersionInfo tests were find", "[version]")
{
   REQUIRE(true);
}

TEST_CASE( "test VersionInfo constructor and getter methods", "[version]")
{
    VersionInfo version{1U, 2U, 3U, 4U};

    REQUIRE(1U == version.get_version_major());
    REQUIRE(2U == version.get_version_minor());
    REQUIRE(3U == version.get_version_patch());
    REQUIRE(4U == version.get_version_tweak());
}

TEST_CASE( "test VersionInfo to and from string", "[version]")
{
    VersionInfo version{1U, 2U, 3U, 4U};

    REQUIRE("1.2.3.4" == version.to_string());

    version.from_string("5.6.7");
    REQUIRE(version == VersionInfo{5, 6, 7, 4});

    version.from_string("5.6.7.8");
    REQUIRE(version == VersionInfo{5, 6, 7, 8});
}

TEST_CASE( "test to_string", "[version]" )
{
    VersionInfo version{1U, 2U, 3U, 4U};
    const std::string version_str_ref = "1.2.3.4";
    REQUIRE(version_str_ref == version.to_string());
}

TEST_CASE( "test from_string", "[version]" )
{
    VersionInfo version{1U, 2U, 3U, 4U};
    const std::string version_str_ref = "5.6.7.8";
    version.from_string(version_str_ref);
    REQUIRE(version_str_ref == version.to_string());

    REQUIRE(5U == version.get_version_major());
    REQUIRE(6U == version.get_version_minor());
    REQUIRE(7U == version.get_version_patch());
    REQUIRE(8U == version.get_version_tweak());
}

TEST_CASE("test current version", "[version]")
{
    REQUIRE(CURRENT_VERSION != VERSION_0_1_0);
    REQUIRE(CURRENT_VERSION != VERSION_0_2_0);
    REQUIRE(CURRENT_VERSION != VERSION_0_2_1);
    REQUIRE(CURRENT_VERSION == VERSION_0_3_0_1);

    VersionInfo version{0U, 3U, 0U, 1U};
    REQUIRE(CURRENT_VERSION == version);
    REQUIRE(CURRENT_VERSION.get_version_major() == version.get_version_major());
    REQUIRE(CURRENT_VERSION.get_version_minor() == version.get_version_minor());
    REQUIRE(CURRENT_VERSION.get_version_patch() == version.get_version_patch());

    version = VERSION_0_3_0_1;
    REQUIRE(CURRENT_VERSION == version);
    REQUIRE(CURRENT_VERSION.get_version_major() == version.get_version_major());
    REQUIRE(CURRENT_VERSION.get_version_minor() == version.get_version_minor());
    REQUIRE(CURRENT_VERSION.get_version_patch() == version.get_version_patch());
}

TEST_CASE( "test assignment", "[version]" )
{
    VersionInfo version_ref{1U, 2U, 3U, 4U};
    VersionInfo version_ref2{5U, 6U, 7U, 8U};

    VersionInfo version(version_ref);

    REQUIRE(version_ref == version);
    REQUIRE(version_ref2 != version);

    REQUIRE(1U == version.get_version_major());
    REQUIRE(2U == version.get_version_minor());
    REQUIRE(3U == version.get_version_patch());
    REQUIRE(4U == version.get_version_tweak());

    version = version_ref2;

    REQUIRE(version_ref != version);
    REQUIRE(version_ref2 == version);

    REQUIRE(5U == version.get_version_major());
    REQUIRE(6U == version.get_version_minor());
    REQUIRE(7U == version.get_version_patch());
    REQUIRE(8U == version.get_version_tweak());
}

TEST_CASE( "test comparisons", "[version]" )
{
    REQUIRE(true == (VERSION_0_3_0_1 == VERSION_0_3_0_1));
    REQUIRE(false == (VERSION_0_3_0_1 != VERSION_0_3_0_1));
    REQUIRE(false == (VERSION_0_3_0_1 > VERSION_0_3_0_1));
    REQUIRE(false == (VERSION_0_3_0_1 < VERSION_0_3_0_1));
    REQUIRE(true == (VERSION_0_3_0_1 >= VERSION_0_3_0_1));
    REQUIRE(true == (VERSION_0_3_0_1 <= VERSION_0_3_0_1));
}


TEST_CASE("Test VersionInfo comparison operators", "[version]")
{
    const VersionInfo version1{1U, 2U, 3U, 4U};

    const VersionInfo version2{1U, 2U, 3U, 4U};
    const VersionInfo version3{5U, 2U, 3U, 4U};
    const VersionInfo version4{1U, 5U, 3U, 4U};
    const VersionInfo version5{1U, 2U, 6U, 4U};
    const VersionInfo version6{1U, 2U, 3U, 7U};

    REQUIRE(version1 == version2);
    REQUIRE(version1 != version3);
    REQUIRE(version1 != version4);
    REQUIRE(version1 != version5);
    REQUIRE(version1 != version6);

    REQUIRE((version1 < version2) == false);
    REQUIRE((version1 < version3) == true);
    REQUIRE((version1 < version4) == true);
    REQUIRE((version1 < version5) == true);
    REQUIRE((version1 < version6) == true);

    REQUIRE((version1 > version2) == false);
    REQUIRE((version1 > version3) == false);
    REQUIRE((version1 > version4) == false);
    REQUIRE((version1 > version5) == false);
    REQUIRE((version1 > version6) == false);

    REQUIRE((version1 <= version2) == true);
    REQUIRE((version1 <= version3) == true);
    REQUIRE((version1 <= version4) == true);
    REQUIRE((version1 <= version5) == true);
    REQUIRE((version1 <= version6) == true);

    REQUIRE((version1 >= version2) == true);
    REQUIRE((version1 >= version3) == false);
    REQUIRE((version1 >= version4) == false);
    REQUIRE((version1 >= version5) == false);
    REQUIRE((version1 >= version6) == false);
}

TEST_CASE( "test version constants", "[version]" )
{
    VersionInfo version{0U, 3U, 0U, 1U};
    REQUIRE(version == VERSION_0_3_0_1);

    const std::string versionStrRef = "0.3.0.1";
    REQUIRE(versionStrRef == VERSION_0_3_0_1.to_string());

    REQUIRE(0U == VERSION_0_3_0_1.get_version_major());
    REQUIRE(3U == VERSION_0_3_0_1.get_version_minor());
    REQUIRE(0U == VERSION_0_3_0_1.get_version_patch());
    REQUIRE(1U == VERSION_0_3_0_1.get_version_tweak());
}

TEST_CASE("test current version 2", "[version]")
{
    REQUIRE(CURRENT_VERSION == VERSION_0_3_0_1);

    VersionInfo version{0U, 3U, 0U, 1U};

    REQUIRE(CURRENT_VERSION == version);
    REQUIRE(CURRENT_VERSION.get_version_major() == version.get_version_major());
    REQUIRE(CURRENT_VERSION.get_version_minor() == version.get_version_minor());
    REQUIRE(CURRENT_VERSION.get_version_patch() == version.get_version_patch());
    REQUIRE(CURRENT_VERSION.get_version_tweak() == version.get_version_tweak());

    version = VERSION_0_3_0_1;
    REQUIRE(CURRENT_VERSION == version);
    REQUIRE(CURRENT_VERSION.get_version_major() == version.get_version_major());
    REQUIRE(CURRENT_VERSION.get_version_minor() == version.get_version_minor());
    REQUIRE(CURRENT_VERSION.get_version_patch() == version.get_version_patch());
    REQUIRE(CURRENT_VERSION.get_version_tweak() == version.get_version_tweak());
}

TEST_CASE( "test has_feature", "[version]" )
{
    VersionInfo version{VERSION_0_3_0_1};

    REQUIRE(true == version.has_feature("bse"));
    REQUIRE(false == version.has_feature(""));
    REQUIRE(false == version.has_feature("se"));
    REQUIRE(false == version.has_feature("no feature"));

    version = VersionInfo{0U, 0U, 0U};
    REQUIRE(false == version.has_feature("bse"));
}


TEST_CASE( "test is_at_least", "[version]" )
{
    VersionInfo version{2 ,2 ,2 ,2};

    REQUIRE(true == version.is_at_least(VersionInfo{2, 2, 2, 2}));

    REQUIRE(true == version.is_at_least(VersionInfo{1, 2, 2, 2}));
    REQUIRE(true == version.is_at_least(VersionInfo{1, 3, 2, 2}));
    REQUIRE(true == version.is_at_least(VersionInfo{1, 2, 3, 2}));
    REQUIRE(true == version.is_at_least(VersionInfo{1, 2, 2, 3}));

    REQUIRE(false == version.is_at_least(VersionInfo{3, 2, 2, 2}));
    REQUIRE(false == version.is_at_least(VersionInfo{3, 1, 2, 2}));
    REQUIRE(false == version.is_at_least(VersionInfo{3, 2, 1, 2}));
    REQUIRE(false == version.is_at_least(VersionInfo{3, 2, 2, 1}));

    REQUIRE(true == version.is_at_least(VersionInfo{2, 1, 2, 2}));
    REQUIRE(true == version.is_at_least(VersionInfo{2, 1, 3, 2}));
    REQUIRE(true == version.is_at_least(VersionInfo{2, 1, 2, 3}));

    REQUIRE(false == version.is_at_least(VersionInfo{2, 3, 2, 2}));
    REQUIRE(false == version.is_at_least(VersionInfo{2, 3, 1, 2}));
    REQUIRE(false == version.is_at_least(VersionInfo{2, 3, 2, 1}));

    REQUIRE(true == version.is_at_least(VersionInfo{2, 2, 1, 2}));
    REQUIRE(true == version.is_at_least(VersionInfo{2, 2, 1, 3}));

    REQUIRE(false == version.is_at_least(VersionInfo{2, 2, 3, 2}));
    REQUIRE(false == version.is_at_least(VersionInfo{2, 2, 3, 1}));

    REQUIRE(true == version.is_at_least(VersionInfo{2, 2, 2, 1}));
    REQUIRE(false == version.is_at_least(VersionInfo{2, 2, 2, 3}));

    REQUIRE(true == version.is_at_least(2, 2, 2));

    REQUIRE(true == version.is_at_least(1, 2, 2));
    REQUIRE(true == version.is_at_least(1, 3, 2));
    REQUIRE(true == version.is_at_least(1, 2, 3));
    REQUIRE(true == version.is_at_least(1, 2, 2));

    REQUIRE(false == version.is_at_least(3, 2, 2));
    REQUIRE(false == version.is_at_least(3, 1, 2));
    REQUIRE(false == version.is_at_least(3, 2, 1));
    REQUIRE(false == version.is_at_least(3, 2, 2));

    REQUIRE(true == version.is_at_least(2, 1, 2));
    REQUIRE(true == version.is_at_least(2, 1, 3));
    REQUIRE(true == version.is_at_least(2, 1, 2));

    REQUIRE(false == version.is_at_least(2, 3, 2));
    REQUIRE(false == version.is_at_least(2, 3, 1));
    REQUIRE(false == version.is_at_least(2, 3, 2));

    REQUIRE(true == version.is_at_least(2, 2, 1));
    REQUIRE(true == version.is_at_least(2, 2, 1));

    REQUIRE(false == version.is_at_least(2, 2, 3));
    REQUIRE(false == version.is_at_least(2, 2, 3));

    REQUIRE(true == version.is_at_least(2, 2, 2));
    REQUIRE(true == version.is_at_least(2, 2, 2));
}
