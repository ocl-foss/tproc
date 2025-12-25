// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef OCL_TPROC_ROPE_FWD_INL
#define OCL_TPROC_ROPE_FWD_INL

namespace ocl
{

	template <class CharT, class Traits, class Allocator>
	struct basic_rope<CharT, Traits, Allocator>::tree_impl
	{
	};

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::~basic_rope()
	{
		delete impl_;
		impl_ = nullptr;
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>&
	basic_rope<CharT, Traits, Allocator>::operator=(
		basic_rope<CharT, Traits, Allocator>&& rope)
	{
		impl_ = std::exchange(other.impl_);
		return *this;
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::basic_rope(
		basic_rope<CharT, Traits, Allocator>&& rope)
	{
		impl_	   = std::exchange(other.impl_);
		rope.impl_ = nullptr;
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::basic_rope(
		const boost::core::basic_string_view<CharT>& in)
		: impl_(new tree_impl())
	{
	}

	template <class CharT, class Traits, class Allocator>
	CharT* basic_rope<CharT, Traits, Allocator>::begin()
	{
		return nullptr;
	}

	template <class CharT, class Traits, class Allocator>
	CharT* basic_rope<CharT, Traits, Allocator>::end()
	{
		return nullptr;
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::size_type
	basic_rope<CharT, Traits, Allocator>::size()
	{
		return 0UL;
	}

	template <class CharT, class Traits, class Allocator>
	bool basic_rope<CharT, Traits, Allocator>::empty() const
	{
		return true;
	}

} // namespace ocl

#endif