// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#include <ocl/tproc/rope.hpp>
#include <ocl/asio.hpp>
#include <iostream>
#include <memory>
#include <future>

#ifndef STANDALONE
using namespace ocl;
#else
using namespace boost;
#endif

int main()
{
	auto rope		= tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");
	auto new_elem	= std::make_unique<tproc::crope>(", and Jumps again");
	auto new_elem_2 = std::make_unique<tproc::crope>(", and then Jumps down.");

	boost::asio::io_context ioc{1};
	auto					spawn_strand = boost::asio::make_strand(ioc);

	boost::asio::co_spawn(
		spawn_strand, [&new_elem, &new_elem_2, &rope]() -> boost::asio::awaitable<void> {
			rope.concat(new_elem.get());
			new_elem->concat(new_elem_2.get());

			co_return;
		},
		boost::asio::detached);

	ocl::asio::run<[]() { (void)0; }>(ioc);

	std::cout << rope << std::endl;
}
