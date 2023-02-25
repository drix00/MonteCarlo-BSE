/**
 * @file
 *
 * Template for fuzzing testing.
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
#include <iterator>
#include <utility>
#include <iostream>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
// Project headers
// Project private headers

// Global and constant variables/functions.

/**
 * Sum values.
 *
 * @param[in] data
 * @param[in] size
 * @return the sum value
 */
[[nodiscard]] auto sum_values(const uint8_t *data, size_t size)
{
  constexpr auto scale = 1000;

  int value = 0;
  for (std::size_t offset = 0; offset < size; ++offset) {
    value += static_cast<int>(*std::next(data, static_cast<long>(offset))) * scale;
  }
  return value;
}

/**
 * Fuzzer that attempts to invoke undefined behavior for signed integer overflow.
 *
 * @param[in] data
 * @param[in] size
 * @return 0
 */
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
  std::cout << "Value sum: " << sum_values(data, size) << ", len " << size << "\n";
  return 0;
}
