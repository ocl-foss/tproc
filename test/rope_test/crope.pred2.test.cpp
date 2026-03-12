// SPDX-License-Identifier: BSL-1.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#include <ocl/tproc/rope.hpp>
#include <memory>
#include <iostream>

#define BOOST_TEST_MODULE crope_pred2
#include <boost/test/included/unit_test.hpp>

#ifndef STANDALONE
using namespace ocl;
#else
using namespace boost;
#endif

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_concat)
{
	auto rope	   = tproc::crope("Exact");
	auto next_rope = std::make_unique<tproc::crope>(" Sentence");
	auto rope_2	   = rope.concat(next_rope.get());

	std::cout << "Result: " << rope << std::endl;

	BOOST_TEST(rope.to_string() == "Exact Sentence");
}
