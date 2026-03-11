// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#ifndef OCL_TPROC_ROPE_INL
#define OCL_TPROC_ROPE_INL

namespace ocl::tproc::rope
{

	template <typename It, class Pred>
	Pred find(It begin, It end, Pred pred)
	{
		for (auto it = begin; it != end; ++it)
		{
			if (*it == pred)
			{
				return *it;
			}
		}

		return end;
	}

	template <typename It, class Pred>
	Pred find_if(It begin, It end, Pred pred)
	{
		for (auto it = begin; it != end; ++it)
		{
			if (pred(it))
			{
				return *it;
			}
		}

		return end;
	}

	template <typename It, class Pred>
	typename Pred::size_type erase(It begin, It end, Pred pred)
	{
		typename Pred::size_type count{};

		for (auto it = begin; it != end;)
		{
			if (*it == pred)
			{
				it = begin.erase(it);
				++count;
			}
			else
			{
				++it;
			}
		}

		return count;
	}

	template <typename It, class Pred>
	typename Pred::size_type erase_if(It begin, It end, Pred)
	{
		typename Pred::size_type count{};

		for (auto it = begin; it != end;)
		{
			if (pred(it))
			{
				it = begin.erase(it);
				++count;
			}
			else
			{
				++it;
			}
		}

		return count;
	}

} // namespace ocl::tproc::rope

#endif
