// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#include <ocl/tproc/rope.hpp>

#define BOOST_TEST_MODULE crope
#include <boost/test/included/unit_test.hpp>

#ifndef STANDALONE
using namespace ocl;
#else
using namespace boost;
#endif

BOOST_AUTO_TEST_CASE(allocator_should_succeed_in_empty)
{
	auto rope = tproc::crope("");
	BOOST_TEST(rope.empty() == true);
}

BOOST_AUTO_TEST_CASE(allocator_should_not_succeed_in_empty)
{
	auto rope = tproc::crope("foobar");
	BOOST_TEST(rope.empty() == false);
}
