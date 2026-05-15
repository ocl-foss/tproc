// SPDX-License-Identifier: BSL-1.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss/tproc

#ifndef OCL_TPROC_BFS_HPP
#define OCL_TPROC_BFS_HPP

#include <ocl/tproc/detail/config.hpp>

namespace ocl::tproc::bfs
{
	template <typename T>
	struct source_iterator;

	/// \brief This data structure contains information about an iterator.
	template <typename T>
	struct source_iterator final
	{
        using type = T;
		using pointer = T*;
		using PredT	  = pointer (*)(pointer);
		/// \brief the end iterator

		[[maybe_unused]] static pointer end()
		{
			return nullptr;
		}
	};

	/// \requires source_iterator
	/// \return SrcIt::T
	template <typename SrcIt>
	inline typename SrcIt::type find(typename SrcIt::pointer beg, typename SrcIt::PredT pred)
	{
		if (beg == SrcIt::end())
			return beg;

		[[maybe_unused]] auto beg_		= beg;
		[[maybe_unused]] auto prev_beg_ = beg_;

		do
		{
			if (!prev_beg_)
				return SrcIt::end();

			if (!beg_)
			{
				beg_ = prev_beg_->root;
				if (!beg_)
					return SrcIt::end();

				continue;
			}

			if (pred(beg_))
				return beg_;

			prev_beg_ = beg_;

			if (beg_->left)
				beg_ = beg_->left;
			else if (beg->right)
				beg_ = beg_->right;

		} while (beg_ && prev_beg_);

		return SrcIt::end();
	}

} // namespace ocl::tproc::bfs

#include "bfs.inl"

#endif // OCL_TPROC_BFS_HPP
