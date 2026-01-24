# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**tproc** is a C++20 header-only library that is part of the Open C++ Libraries (OCL) project. It provides text processing utilities, currently focused on implementing a rope data structure for efficient string manipulation.

- **License**: Boost Software License 1.0
- **Repository**: https://github.com/ocl-org/tproc
- **Standard**: C++20 (required, no extensions)

## Dependencies

This library depends on other OCL components and Boost:

- **OCL core libraries**: `ocl/detail/config.hpp`, `ocl/equiv.hpp`, `ocl/option.hpp`, `ocl/smart_ptr.hpp`
- **Boost libraries**: `boost/core/detail/string_view.hpp`, Boost.Test (for testing)
- The library expects Boost headers to be available (see `compile_flags.txt` for include paths)

## Build System

The project uses **two build systems**:

### CMake (for installation)

```bash
# Configure and build
cmake -B build -DINSTALL_OCL=ON
cmake --build build

# Install headers only (header-only library)
sudo cmake --install build
```

- Minimum CMake version: 3.30
- The CMake build is primarily for installing headers to the system
- Use `-DINSTALL_OCL=ON` to enable installation

### Boost.Build (for testing)

Tests are built using Boost.Build (b2/bjam):

```bash
# Navigate to test directory
cd test/rope_test

# Build and run tests
b2

# Run specific test
./bin/crope.test.o
```

- Test configuration is in `test/rope_test/Jamfile.v2`
- Tests use Boost.Test with the header-only variant (`#include <boost/test/included/unit_test.hpp>`)

## Code Formatting

The project uses **clang-format** with a custom Microsoft-based style:

```bash
# Format all source files
./format.sh
```

**Key formatting rules** (`.clang-format`):
- **Tabs for indentation** (`UseTab: Always`)
- No column limit (`ColumnLimit: 0`)
- Pointer alignment left (`int* ptr`)
- Namespace indentation included (`NamespaceIndentation: All`)
- Aligned consecutive macros, assignments, and declarations
- File extensions formatted: `.cpp`, `.c`, `.hpp`, `.inl`

Always run `./format.sh` before committing code changes.

## Architecture

### Header Organization

```
include/ocl/tproc.hpp              # Main umbrella header
include/ocl/tproc/
  ├── rope.hpp                     # Public rope API (find, find_if algorithms)
  └── detail/
      ├── config.hpp               # Library configuration and common includes
      ├── rope_fwd.hpp             # basic_rope class declaration
      └── rope_fwd.inl             # basic_rope template implementations
```

### The Rope Data Structure

The `basic_rope` class template is the core component:

- **Template parameters**: `CharT` (character type), `Traits` (char_traits), `Allocator`
- **Type aliases**: `crope` (char), `wrope` (wchar_t), `u8rope` (char8_t, C++20), `u16rope` (char16_t, C++20)
- **Implementation pattern**:
  - Declaration in `rope_fwd.hpp`
  - Implementation in `rope_fwd.inl` (inline file)
  - Private `tree_impl` struct for internal tree representation
- **Current state**: Basic scaffold with move semantics, but tree implementation is incomplete (stub methods return null/zero)

### Design Patterns

1. **Header/inline separation**: `.hpp` files contain declarations, `.inl` files contain template implementations
2. **Forward declaration pattern**: `rope_fwd.hpp` contains the class, included by `rope.hpp` which provides algorithms
3. **PIMPL-like pattern**: `tree_impl` private struct hides implementation details
4. **Move-only semantics**: Supports move construction and move assignment, tree ownership transfer

## Development Workflow

### Adding New Tests

1. Create or modify test files in `test/rope_test/`
2. Update `test/rope_test/Jamfile.v2` if adding new test executables
3. Build with `b2` in the test directory
4. Tests use Boost.Test macros: `BOOST_AUTO_TEST_CASE`, `BOOST_TEST`

### Modifying Headers

1. **Read before editing**: All header changes require understanding the template structure
2. **Maintain declaration/implementation split**: Keep declarations in `.hpp`, implementations in `.inl`
3. **Format after changes**: Run `./format.sh` before committing
4. **Template syntax**: All template parameters must be explicitly specified (see `rope_fwd.inl` for examples)

### Code Style Notes

- Use tabs for indentation (enforced by clang-format)
- All source files include Boost Software License headers
- Include guards use `OCL_TPROC_*` pattern for main headers, `OCL_TPROC_*` for detail headers
- Namespace: All public API is in `ocl` or `ocl::tproc` namespace
