/**
 * @file
 *
 * Tests for VersionInfo.
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

/**
 * Test if VersionInfo tests were find.
 */
TEST_CASE("Test if VersionInfo tests were find", "[version]")
{
    REQUIRE(true);
}

/**
 * Test VersionInfo constructor and getter methods.
 */
TEST_CASE("test VersionInfo constructor and getter methods", "[version]")
{
    const VersionInfo version{ 1U, 2U, 3U, 4U };

    REQUIRE(1U == version.get_version_major());
    REQUIRE(2U == version.get_version_minor());
    REQUIRE(3U == version.get_version_patch());
    REQUIRE(4U == version.get_version_tweak());
}

/**
 * Test VersionInfo to and from string.
 */
TEST_CASE("test VersionInfo to and from string", "[version]")
{
    VersionInfo version{ 1U, 2U, 3U, 4U };

    REQUIRE("1.2.3.4" == version.to_string());

    version.from_string("5.6.7");
    REQUIRE(version == VersionInfo{ 5, 6, 7, 4 });

    version.from_string("5.6.7.8");
    REQUIRE(version == VersionInfo{ 5, 6, 7, 8 });
}

/**
 * Test to_string.
 */
TEST_CASE("test to_string", "[version]")
{
    const VersionInfo version{ 1U, 2U, 3U, 4U };
    const std::string version_str_ref = "1.2.3.4";
    REQUIRE(version_str_ref == version.to_string());
}

/**
 * Test from_string.
 */
TEST_CASE("test from_string", "[version]")
{
    VersionInfo version{ 1U, 2U, 3U, 4U };
    const std::string version_str_ref = "5.6.7.8";
    version.from_string(version_str_ref);
    REQUIRE(version_str_ref == version.to_string());

    REQUIRE(5U == version.get_version_major());
    REQUIRE(6U == version.get_version_minor());
    REQUIRE(7U == version.get_version_patch());
    REQUIRE(8U == version.get_version_tweak());
}

/**
 * Test assignment.
 */
TEST_CASE("test assignment", "[version]")
{
    const VersionInfo version_ref{ 1U, 2U, 3U, 4U };
    const VersionInfo version_ref2{ 5U, 6U, 7U, 8U };

    VersionInfo version(version_ref);

    REQUIRE(version_ref == version); // NOLINT
    REQUIRE(version_ref2 != version); // NOLINT

    REQUIRE(1U == version.get_version_major()); // NOLINT
    REQUIRE(2U == version.get_version_minor()); // NOLINT
    REQUIRE(3U == version.get_version_patch()); // NOLINT
    REQUIRE(4U == version.get_version_tweak()); // NOLINT

    version = version_ref2;

    REQUIRE(version_ref != version); // NOLINT
    REQUIRE(version_ref2 == version); // NOLINT

    REQUIRE(5U == version.get_version_major()); // NOLINT
    REQUIRE(6U == version.get_version_minor()); // NOLINT
    REQUIRE(7U == version.get_version_patch()); // NOLINT
    REQUIRE(8U == version.get_version_tweak());
}

/**
 * Test comparisons.
 */
TEST_CASE("test comparisons", "[version]")
{
    REQUIRE(true == (VERSION_0_3_0_1 == VERSION_0_3_0_1));
    REQUIRE(false == (VERSION_0_3_0_1 != VERSION_0_3_0_1));
    REQUIRE(false == (VERSION_0_3_0_1 > VERSION_0_3_0_1));
    REQUIRE(false == (VERSION_0_3_0_1 < VERSION_0_3_0_1));
    REQUIRE(true == (VERSION_0_3_0_1 >= VERSION_0_3_0_1));
    REQUIRE(true == (VERSION_0_3_0_1 <= VERSION_0_3_0_1));
}

/**
 * Test VersionInfo comparison operators.
 */
TEST_CASE("Test VersionInfo comparison operators", "[version]")
{
    const VersionInfo version1{ 1U, 2U, 3U, 4U };

    const VersionInfo version2{ 1U, 2U, 3U, 4U };
    const VersionInfo version3{ 5U, 2U, 3U, 4U };
    const VersionInfo version4{ 1U, 5U, 3U, 4U };
    const VersionInfo version5{ 1U, 2U, 6U, 4U };
    const VersionInfo version6{ 1U, 2U, 3U, 7U };

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

/**
 * Test has_feature.
 */
TEST_CASE("test has_feature", "[version]")
{
    VersionInfo version{ VERSION_0_3_0_1 };

    REQUIRE(true == version.has_feature("bse")); // NOLINT
    REQUIRE(false == version.has_feature("")); // NOLINT
    REQUIRE(false == version.has_feature("se")); // NOLINT
    REQUIRE(false == version.has_feature("no feature")); // NOLINT

    version = VersionInfo{ 0U, 0U, 0U };
    REQUIRE(false == version.has_feature("bse"));

    REQUIRE(true == CURRENT_VERSION.has_feature("bse")); // NOLINT
}

/**
 * Test has_feature geometry box.
 */
TEST_CASE("test has_feature geometry box", "[version]")
{
    VersionInfo version{ VERSION_0_3_0_1 };

    REQUIRE(true == version.has_feature("box")); // NOLINT
    REQUIRE(false == version.has_feature("")); // NOLINT
    REQUIRE(false == version.has_feature("se")); // NOLINT
    REQUIRE(false == version.has_feature("no feature")); // NOLINT

    version = VersionInfo{ 0U, 0U, 0U };
    REQUIRE(false == version.has_feature("box"));

    REQUIRE(true == CURRENT_VERSION.has_feature("box")); // NOLINT
}

/**
 * Test is_at_least.
 */
TEST_CASE("test is_at_least", "[version]")
{
    const VersionInfo version{ 2, 2, 2, 2 };

    REQUIRE(true == version.is_at_least(VersionInfo{ 2, 2, 2, 2 }));

    REQUIRE(true == version.is_at_least(VersionInfo{ 1, 2, 2, 2 }));
    REQUIRE(true == version.is_at_least(VersionInfo{ 1, 3, 2, 2 }));
    REQUIRE(true == version.is_at_least(VersionInfo{ 1, 2, 3, 2 }));
    REQUIRE(true == version.is_at_least(VersionInfo{ 1, 2, 2, 3 }));

    REQUIRE(false == version.is_at_least(VersionInfo{ 3, 2, 2, 2 }));
    REQUIRE(false == version.is_at_least(VersionInfo{ 3, 1, 2, 2 }));
    REQUIRE(false == version.is_at_least(VersionInfo{ 3, 2, 1, 2 }));
    REQUIRE(false == version.is_at_least(VersionInfo{ 3, 2, 2, 1 }));

    REQUIRE(true == version.is_at_least(VersionInfo{ 2, 1, 2, 2 }));
    REQUIRE(true == version.is_at_least(VersionInfo{ 2, 1, 3, 2 }));
    REQUIRE(true == version.is_at_least(VersionInfo{ 2, 1, 2, 3 }));

    REQUIRE(false == version.is_at_least(VersionInfo{ 2, 3, 2, 2 }));
    REQUIRE(false == version.is_at_least(VersionInfo{ 2, 3, 1, 2 }));
    REQUIRE(false == version.is_at_least(VersionInfo{ 2, 3, 2, 1 }));

    REQUIRE(true == version.is_at_least(VersionInfo{ 2, 2, 1, 2 }));
    REQUIRE(true == version.is_at_least(VersionInfo{ 2, 2, 1, 3 }));

    REQUIRE(false == version.is_at_least(VersionInfo{ 2, 2, 3, 2 }));
    REQUIRE(false == version.is_at_least(VersionInfo{ 2, 2, 3, 1 }));

    REQUIRE(true == version.is_at_least(VersionInfo{ 2, 2, 2, 1 }));
    REQUIRE(false == version.is_at_least(VersionInfo{ 2, 2, 2, 3 }));

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

/**
 * Test current version.
 *
 * \note This test need to be updated when the current version is changed.
 */
TEST_CASE("Test current version", "[version]")
{
    REQUIRE(CURRENT_VERSION != VERSION_0_1_0);
    REQUIRE(CURRENT_VERSION != VERSION_0_2_0);
    REQUIRE(CURRENT_VERSION != VERSION_0_2_1);
    REQUIRE(CURRENT_VERSION != VERSION_0_3_0_0);
    REQUIRE(CURRENT_VERSION == VERSION_0_3_0_1);

    VersionInfo version{ 0U, 3U, 0U, 1U };
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

/**
 * Test VERSION_0_1_0 constant.
 */
TEST_CASE("test VERSION_0_1_0 constant", "[version]")
{
    const VersionInfo version{ 0U, 1U, 0U, 0U };
    REQUIRE(version == VERSION_0_1_0);

    const std::string versionStrRef = "0.1.0.0";
    REQUIRE(versionStrRef == VERSION_0_1_0.to_string());

    REQUIRE(0U == VERSION_0_1_0.get_version_major());
    REQUIRE(1U == VERSION_0_1_0.get_version_minor());
    REQUIRE(0U == VERSION_0_1_0.get_version_patch());
    REQUIRE(0U == VERSION_0_1_0.get_version_tweak());
}

/**
 * Test VERSION_0_2_0 constant.
 */
TEST_CASE("test VERSION_0_2_0 constant", "[version]")
{
    const VersionInfo version{ 0U, 2U, 0U, 0U };
    REQUIRE(version == VERSION_0_2_0);

    const std::string versionStrRef = "0.2.0.0";
    REQUIRE(versionStrRef == VERSION_0_2_0.to_string());

    REQUIRE(0U == VERSION_0_2_0.get_version_major());
    REQUIRE(2U == VERSION_0_2_0.get_version_minor());
    REQUIRE(0U == VERSION_0_2_0.get_version_patch());
    REQUIRE(0U == VERSION_0_2_0.get_version_tweak());
}

/**
 * Test VERSION_0_2_1 constant.
 */
TEST_CASE("test VERSION_0_2_1 constant", "[version]")
{
    const VersionInfo version{ 0U, 2U, 1U, 0U };
    REQUIRE(version == VERSION_0_2_1);

    const std::string versionStrRef = "0.2.1.0";
    REQUIRE(versionStrRef == VERSION_0_2_1.to_string());

    REQUIRE(0U == VERSION_0_2_1.get_version_major());
    REQUIRE(2U == VERSION_0_2_1.get_version_minor());
    REQUIRE(1U == VERSION_0_2_1.get_version_patch());
    REQUIRE(0U == VERSION_0_2_1.get_version_tweak());
}

/**
 * Test VERSION_0_3_0_0 constant.
 */
TEST_CASE("test VERSION_0_3_0_0 constant", "[version]")
{
    const VersionInfo version{ 0U, 3U, 0U, 0U };
    REQUIRE(version == VERSION_0_3_0_0);

    const std::string versionStrRef = "0.3.0.0";
    REQUIRE(versionStrRef == VERSION_0_3_0_0.to_string());

    REQUIRE(0U == VERSION_0_3_0_0.get_version_major());
    REQUIRE(3U == VERSION_0_3_0_0.get_version_minor());
    REQUIRE(0U == VERSION_0_3_0_0.get_version_patch());
    REQUIRE(0U == VERSION_0_3_0_0.get_version_tweak());
}

/**
 * Test VERSION_0_3_0_1 constant.
 */
TEST_CASE("test VERSION_0_3_0_1 constant", "[version]")
{
    const VersionInfo version{ 0U, 3U, 0U, 1U };
    REQUIRE(version == VERSION_0_3_0_1);

    const std::string versionStrRef = "0.3.0.1";
    REQUIRE(versionStrRef == VERSION_0_3_0_1.to_string());

    REQUIRE(0U == VERSION_0_3_0_1.get_version_major());
    REQUIRE(3U == VERSION_0_3_0_1.get_version_minor());
    REQUIRE(0U == VERSION_0_3_0_1.get_version_patch());
    REQUIRE(1U == VERSION_0_3_0_1.get_version_tweak());
}
