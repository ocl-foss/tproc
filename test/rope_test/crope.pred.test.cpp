// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#include <ocl/tproc/rope.hpp>
#include <memory>
#include <iostream>

#define BOOST_TEST_MODULE crope_pred
#include <boost/test/included/unit_test.hpp>

#ifndef STANDALONE
using namespace ocl;
#else
using namespace boost;
#endif

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_find_pred)
{
	auto rope = tproc::crope("Exact Sentence");
	auto it	  = tproc::rope::exact_pred<tproc::crope>{"Exact Sentence"}(rope.begin(), rope.end());

	BOOST_TEST(it != rope.cend());

	std::cout << "Result: " << rope << std::endl;
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_at)
{
	auto rope = tproc::crope("Exact Sentence");
	BOOST_ASSERT(rope.to_string() == "Exact Sentence");
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_concat)
{
	auto						  rope	   = tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");
	std::unique_ptr<tproc::crope> new_elem = std::make_unique<tproc::crope>(", and Jumps again.");
	rope.concat(new_elem.get());

	BOOST_TEST((rope.to_string() == "The Quick Brown Fox Jumps Over The Lazy Dog, and Jumps again."));
	BOOST_TEST((new_elem->to_string() == ", and Jumps again."));
	std::cout << "Result: " << rope << std::endl;
}
