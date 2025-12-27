/*
 * File: crope.pred.test.cpp
 * Purpose: Char rope test.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include <ocl/tproc/rope.hpp>

#define BOOST_TEST_MODULE crope_pred
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_empty_pred)
{
	auto rope = ocl::tproc::crope("");
	auto it	  = ocl::tproc::rope::exact_pred{"foo"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it == rope.cend());
}

BOOST_AUTO_TEST_CASE(rope_should_not_succeed_in_empty_pred)
{
	auto rope = ocl::tproc::crope("foobar");
	// find the leaf with the exact value 'foo'
	auto it = ocl::tproc::rope::starts_with_pred{"foo"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it != rope.cend());
}
