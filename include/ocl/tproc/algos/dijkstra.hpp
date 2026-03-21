// SPDX-License-Identifier: BSL-1.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#ifndef OCL_TPROC_DIJKSTRA_HPP
#define OCL_TPROC_DIJKSTRA_HPP

#include <ocl/tproc/detail/config.hpp>

namespace ocl::tproc
{

	/// @brief Implementation of dijkstra's algorithm.
	/// @note Complies with the SourcePair requirement.
	template <class SourcePair>
	inline void dijkstra(SourcePair& pair)
	{
		for (auto& v : pair.source.vertices())
		{
			pair.dist[v] = SourcePair::infinity;
			pair.prev[v] = SourcePair::undefined;
			pair.q += v;
			pair.source[v] = {};
		}

		while (pair.q)
		{
			auto u = pair.q.vertex;
			pair.q.remove(u);

			for (auto& v : pair.graph)
			{
				auto& alt = pair.dist[v.u] + pair.graph.distance(v.u, v.v);

				if (alt < pair.dist[v.u])
				{
					pair.dist[v.v] = alt;
					pair.prev[v.v] = u;
				}
			}
		}
	}

} // namespace ocl::tproc

#endif // OCL_TPROC_DIJKSTRA_HPP
