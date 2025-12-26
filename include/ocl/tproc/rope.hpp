// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef __OCL_TPROC_ROPE_HPP
#define __OCL_TPROC_ROPE_HPP

#include <ocl/tproc/detail/rope_fwd.hpp>

namespace ocl::tproc::rope
{
    struct reverse_pred;
    struct fast_pred;
    struct lowercase_pred;
    struct exact_pred;
    struct stars_with_pred;

	template <typename It, class Pred>
	It find(It begin, It end, Pred);

	template <typename It, class Callable>
	It find_if(It begin, It end, Callable);

	template <typename It, class Pred>
	size_t erase(It begin, It end, Pred);

	template <typename It, class Callable>
	size_t erase_if(It begin, It end, Callable);

} // namespace ocl::tproc

#endif // __OCL_TPROC_ROPE_HPP