/*
 * File: example.cpp
 * Purpose: Rope example.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include <ocl/tproc/rope.hpp>

int main()
{
	auto rope = ocl::tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");

	auto new_elem = new ocl::tproc::crope(", and Jumps again.");
	auto res = rope.concat(new_elem);

	ocl::io::println((++rope)->data());
	ocl::io::println(rope.data());

	delete new_elem;
	delete res;
}
