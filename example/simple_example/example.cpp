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
	ocl::io::println(rope.data());
}
