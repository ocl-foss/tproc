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
	auto rope = ocl::tproc::crope("Exact Sentence");
	auto it	  = ocl::tproc::rope::exact_pred<ocl::tproc::crope>{"Exact Sentence"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it != rope.cend());

	ocl::io::println(it->data());
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_starts_with)
{
	auto rope = ocl::tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");
	// find the leaf with the starting value 'foo'
	auto it = ocl::tproc::rope::starts_with_pred<ocl::tproc::crope>{"The Quick"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it != rope.cend());

	auto it_end = ocl::tproc::rope::ends_with_pred<ocl::tproc::crope>{"Lazy Dog"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it_end != rope.cend());

	ocl::io::println(it_end->data());
	ocl::io::println(it->data());

	auto new_elem = new ocl::tproc::crope(", and Jumps again.");
	auto ret_elem = rope.concat(new_elem);

	ocl::io::println(ret_elem->data());

	delete new_elem;
}
