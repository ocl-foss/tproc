// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#include <ocl/tproc/rope.hpp>
#include <iostream>
#include <memory>

#ifndef STANDALONE
using namespace ocl;
#else
using namespace boost;
#endif

int main()
{
	auto rope	  = tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");
	auto new_elem = std::make_unique<tproc::crope>(", and Jumps again.");

	rope.concat(new_elem.get());

	std::cout << *++rope << std::endl;
}
