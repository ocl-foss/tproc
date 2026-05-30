# OCL.TProc

[![License: BSL](https://img.shields.io/badge/license-BSL-blue.svg)](LICENSE)
![GitHub Repo Stars](https://img.shields.io/github/stars/open-cpp-libraries/tproc)

Like the project? Star us!

Text Processing containers and algorithms from the OCL.

## Requirements:

The OCL requires the following:

- [Boost](https://www.boost.org/)
- [Clang](https://clang.llvm.org/)
- [CMake](https://cmake.org/)
- [Git](https://git-scm.com/)
- OCL.Core

## Using TProc:

Taken from the example, you can see:

```cpp
int main()
{
	auto rope	  = tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");
	auto next_elem = std::make_unique<tproc::crope>(", and Jumps again.");

	rope.concat(next_elem.get());

	std::cout << *++rope << std::endl; // returns 'next_elem'
}
```

The library is header-only as well, so no compilation step is needed, and is written in modern C++ (C++17 or later).

## Freestanding Status

The Freestanding Status is a concept where a module is evaluated on whether it has or is fully freestanding or not.

- Unverified

##### (c) 2025-2026 Amlal El Mahrouss and OCL Authors, licensed under the Boost Software License.
