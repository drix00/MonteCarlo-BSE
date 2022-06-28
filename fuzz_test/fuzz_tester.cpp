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
#include <iterator>
#include <utility>
#include <iostream>
// Library headers
// Precompiled header
// Current declaration header file of this implementation file.
// Project headers
// Project private headers

// Global and constant variables/functions.

[[nodiscard]] auto sum_values(const uint8_t *Data, size_t Size)
{
  constexpr auto scale = 1000;

  int value = 0;
  for (std::size_t offset = 0; offset < Size; ++offset) {
    value += static_cast<int>(*std::next(Data, static_cast<long>(offset))) * scale;
  }
  return value;
}

// Fuzzer that attempts to invoke undefined behavior for signed integer overflow
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
  std::cout << "Value sum: " << sum_values(Data, Size) << ", len " << Size << "\n";
  return 0;
}
