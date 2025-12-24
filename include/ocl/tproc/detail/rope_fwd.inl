// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef OCL_TPROC_ROPE_FWD_INL
#define OCL_TPROC_ROPE_FWD_INL

namespace ocl {

template <class CharT, class Traits, class Allocator>
struct basic_rope<CharT, Traits, Allocator>::tree_impl {};

template <class CharT, class Traits, class Allocator>
basic_rope<CharT, Traits, Allocator>::~basic_rope() = default;

template <class CharT, class Traits, class Allocator>
basic_rope<CharT, Traits, Allocator>::basic_rope(
    const boost::basic_string_view<CharT> &in) {}

} // namespace ocl

#endif