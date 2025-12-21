// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef OCL_TPROC_ROPE_FWD_HPP
#define OCL_TPROC_ROPE_FWD_HPP

#include <memory>
#include <string>

/// \file rope_fwd.hpp
/// \brief Basic forward definitions of the `rope` type.

namespace ocl {
/// \brief This class implements a rope type for any **CharT** type.
/// \note Specializations are available as `crope` and `wrope`.
/// \author Amlal El Mahrouss
template <class CharT, class Traits = std::char_traits<CharT>,
          class Allocator = std::allocator<CharT>>
class basic_rope {
public:
  using traits_type = Traits;
  using value_type = CharT;
  using allocator_type = Allocator;
  using size_type = std::allocator_traits<Allocator>::size_type;
  using reference = CharT &;
  using const_reference = const CharT &;
  using pointer = std::allocator_traits<Allocator>::pointer;
  using const_pointer = std::allocator_traits<Allocator>::pointer;

  [[nodiscard]]
  CharT *begin() {
    return nullptr;
  }

  [[nodiscard]]
  CharT *end() {
    return nullptr;
  }

  [[nodiscard]]
  size_type size() {
    return 0UL;
  }

  basic_rope() = default;
  virtual ~basic_rope() = default;
};

#if __cplusplus >= 201811L
#ifdef __cpp_char8_t
using u8rope = basic_rope<char8_t>;
#endif
#endif

using crope = basic_rope<char>;
using wrope = basic_rope<wchar_t>;
} // namespace ocl

#endif