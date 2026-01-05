/*
 * File: config.hpp
 * Purpose: Configuration header of the `tproc` library.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#ifndef __OCL_TPROC_CONFIG
#define __OCL_TPROC_CONFIG

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

#endif // ifndef __OCL_TPROC_CONFIG
