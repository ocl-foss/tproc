/*
 * File: crope.pred.test.cpp
 * Purpose: Char rope test.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include <ocl/tproc/rope.hpp>

#define BOOST_TEST_MODULE crope_pred
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_find_pred)
{
	auto rope = ocl::tproc::crope("foo");
	auto it	  = ocl::tproc::rope::exact_pred<ocl::tproc::crope>{"foo"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it != rope.cend());

	ocl::io::println(it->data());
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_starts_with)
{
	auto rope = ocl::tproc::crope("foobar");

	// find the leaf with the starting value 'foo'
	auto it = ocl::tproc::rope::starts_with_pred<ocl::tproc::crope>{"foo"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it != rope.cend());

	ocl::io::println(it->data());
}
