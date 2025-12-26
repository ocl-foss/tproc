// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef OCL_TPROC_ROPE_FWD_INL
#define OCL_TPROC_ROPE_FWD_INL

namespace ocl::tproc
{

	template <class CharT, class Traits, class Allocator>
	struct basic_rope<CharT, Traits, Allocator>::tree_impl
	{
		size_t size_;
		CharT *head_, tail_;

		size_t size()
		{
			return size_;
		}
		CharT* begin()
		{
			return head_;
		}
		CharT* end()
		{
			return tail_;
		}
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
		basic_rope<CharT, Traits, Allocator>&& other)
	{
		impl_ = std::exchange(other.impl_);
		return *this;
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::basic_rope(
		basic_rope<CharT, Traits, Allocator>&& other)
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
		return impl_->begin();
	}

	template <class CharT, class Traits, class Allocator>
	CharT* basic_rope<CharT, Traits, Allocator>::end()
	{
		return impl_->end();
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::size_type
	basic_rope<CharT, Traits, Allocator>::size()
	{
		return impl_->size();
	}

	template <class CharT, class Traits, class Allocator>
	bool basic_rope<CharT, Traits, Allocator>::empty() const
	{
		return impl_->size() < 1;
	}

} // namespace ocl::tproc

#endif