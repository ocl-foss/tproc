# OCL.TProc

[![License: BSL](https://img.shields.io/badge/license-BSL-blue.svg)](LICENSE)
![GitHub Repo stars](https://img.shields.io/github/stars/ocl-foss-org/tproc)

Text Processing set of containers from the OCL.

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
	auto new_elem = std::make_unique<tproc::crope>(", and Jumps again.");

	rope.concat(new_elem.get());

	std::cout << *++rope << std::endl;
}
```

The library is header-only as well, so no compilation step is needed, and is written in modern C++ (C++17 or later).

## Freestanding Status

The Freestanding Status is a concept where a module is evaluated on whether it has or is fully freestanding or not.

- Unverified

##### (c) 2025-2026 Amlal El Mahrouss and OCL Authors, licensed under the Boost Software License.
