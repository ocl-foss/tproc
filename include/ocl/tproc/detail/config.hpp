// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/open-cpp-libraries/tproc

#ifndef OCL_TPROC_CONFIG
#define OCL_TPROC_CONFIG

#include <boost/assert/source_location.hpp>
#include <ocl/detail/config.hpp>
#include <boost/core/detail/string_view.hpp>

namespace ocl::tproc
{

	namespace detail
	{

		inline void throw_invalid_range(const auto sc = BOOST_CURRENT_LOCATION)
		{
			throw std::out_of_range(sc.to_string());
		}

		inline void throw_bad_alloc()
		{
			throw std::bad_alloc();
		}

	} // namespace detail

} // namespace ocl::tproc

#endif // ifndef OCL_TPROC_CONFIG
