// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/open-cpp-libraries/tproc

#ifndef OCL_TPROC_HPP
#define OCL_TPROC_HPP

#include <ocl/tproc/detail/config.hpp>
#include <ocl/tproc/rope.hpp>

#ifdef OCL_TPROC_REGEX
// #include <ocl/tproc/linter.hpp>
#endif

#ifdef OCL_TPROC_ALGOS
#include <ocl/tproc/algos/bfs.hpp>
#include <ocl/tproc/algos/dijkstra.hpp>
#endif

#endif // OCL_TPROC_HPP
