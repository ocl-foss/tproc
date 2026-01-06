/*
 * File: crope.pred.test.cpp
 * Purpose: Char rope test.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include <ocl/tproc/rope.hpp>
#include <memory>

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
	auto it	  = tproc::rope::exact_pred<tproc::crope>{"Exact Sentence"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it != rope.cend());

	ocl::io::println(it->data());
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_at)
{
	auto rope = tproc::crope("Exact Sentence");
	auto it	  = std::move(rope.substr(rope.at("Exact"), rope.size()));

	ocl::io::println(it.data());
}

BOOST_AUTO_TEST_CASE(rope_should_succeed_in_starts_with)
{
	auto rope = tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");
	
	// find the leaf with the starting value 'foo'
	auto it = tproc::rope::starts_with_pred<tproc::crope>{"The Quick"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it != rope.cend());

	auto it_end = tproc::rope::ends_with_pred<tproc::crope>{"Lazy Dog"}(rope.cbegin(), rope.cend());

	BOOST_TEST(it_end != rope.cend());

	io::println(it_end->data());
	io::println(it->data());

	std::unique_ptr<tproc::crope> new_elem(new tproc::crope(", and Jumps again."));
	std::unique_ptr<tproc::crope> ret_elem(rope.concat(new_elem.get()));

	io::println(ret_elem->data());
}
