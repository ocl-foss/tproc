/*
 * File: crope.test.cpp
 * Purpose: Char rope test.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include <ocl/tproc/rope.hpp>

#define BOOST_TEST_MODULE crope
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( allocator_should_succeed )
{
    auto rope = ocl::crope("foo");
    BOOST_TEST( rope.empty() == false  );
}
