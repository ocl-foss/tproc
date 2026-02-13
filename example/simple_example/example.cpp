/*
 * File: example.cpp
 * Purpose: Rope example.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025-2026, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include <ocl/tproc/rope.hpp>
#include <iostream>
#include <memory>

#ifndef STANDALONE
using namespace ocl;
#else
using namespace boost;
#endif

int main()
{
	auto rope = tproc::crope("The Quick Brown Fox Jumps Over The Lazy Dog");
	auto new_elem = std::make_unique<tproc::crope>(", and Jumps again.");
	
	rope.concat(new_elem.get());

	std::cout << *++rope << std::endl;
}
