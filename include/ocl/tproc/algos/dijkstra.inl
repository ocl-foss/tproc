// SPDX-License-Identifier: BSL-1.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/open-cpp-libraries/tproc

namespace ocl::tproc
{

	template <>
	inline void dijkstra(double&) = delete;

	template <>
	inline void dijkstra(void*&) = delete;

	template <>
	inline void dijkstra(char*&) = delete;

	template <>
	inline void dijkstra(int&) = delete;

} // namespace ocl::tproc