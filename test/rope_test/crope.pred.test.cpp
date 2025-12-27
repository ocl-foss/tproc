/*
 * File: crope.pred.test.cpp
 * Purpose: Char rope test.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include <ocl/tproc/rope.hpp>

#define BOOST_TEST_MODULE crope_pred
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(allocator_should_succeed_in_empty_pred)
{
	auto rope = ocl::tproc::crope("");
	auto it = ocl::tproc::rope::find(rope.cbegin(), rope.cend(), ocl::tproc::rope::exact_pred("foo"));

	BOOST_TEST(it == rope.cend());
}

BOOST_AUTO_TEST_CASE(allocator_should_not_succeed_in_empty_pred)
{
	auto rope = ocl::tproc::crope("foobar");

	auto it = ocl::tproc::rope::find(rope.cbegin(), rope.cend(), ocl::tproc::rope::stars_with_pred("foo"));

	BOOST_TEST(it != rope.cend());
}
