/*
 * File: crope.pred.test.cpp
 * Purpose: Char rope test.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025-2026, Amlal El Mahrouss, licensed under the Boost Software License.
 */

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

	std::cout << rope << std::endl;
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_at)
{
	auto rope = tproc::crope("Exact Sentence");
	auto it	  = std::move(rope.substr(rope.at("Exact"), rope.size()));

	BOOST_ASSERT(it == "Exact Sentence");
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_starts_with)
{
	auto rope = tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");

	// find the leaf with the starting value 'foo'
	auto it = tproc::rope::starts_with_pred<tproc::crope>{"The Quick"}(rope.begin(), rope.end());

	BOOST_TEST(it != rope.cend());

	auto it_end = tproc::rope::ends_with_pred<tproc::crope>{"Lazy Dog"}(rope.begin(), rope.end());

	BOOST_TEST(it_end != rope.cend());

	std::unique_ptr<tproc::crope> new_elem = std::make_unique<tproc::crope>(", and Jumps again.");
	std::unique_ptr<tproc::crope> ret_elem(rope.concat(new_elem.get()));

	BOOST_TEST((*ret_elem == "The Quick Brown Fox Jumps Over The Lazy Dog, and Jumps again."));

	std::cout << *ret_elem;
}
