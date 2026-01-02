// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef OCL_TPROC_ROPE_FWD_INL
#define OCL_TPROC_ROPE_FWD_INL

#include <boost/system/error_code.hpp>

namespace ocl::tproc
{

	template <class CharT, class Traits, class Allocator>
	struct basic_rope<CharT, Traits, Allocator>::tree_impl
	{
		using char_type = CharT;

	private:
		std::allocator_traits<Allocator>::size_type size_;
		basic_rope<CharT, Traits, Allocator> *									head_, *tail_{};
		boost::system::error_code					ec_{};
        CharT* blob_{};

	public:
		std::allocator_traits<Allocator>::size_type size()
		{
			return size_;
		}

		basic_rope<CharT, Traits, Allocator> * begin()
		{
			return head_;
		}

		basic_rope<CharT, Traits, Allocator> * end()
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
		impl_ = std::exchange(other.impl_, nullptr);
		return *this;
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::basic_rope(
		basic_rope<CharT, Traits, Allocator>&& other)
	{
		impl_ = std::exchange(other.impl_, nullptr);
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>&
	basic_rope<CharT, Traits, Allocator>::operator=(const basic_rope& other)
	{
		impl_ = std::exchange(other.impl_, nullptr);
		return *this;
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::basic_rope(const basic_rope& other)
	{
		impl_ = std::exchange(other.impl_, nullptr);
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::basic_rope(
		const boost::core::basic_string_view<CharT>& in)
		: impl_(new tree_impl())
	{
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::iterator_type basic_rope<CharT, Traits, Allocator>::begin()
	{
		return impl_->begin();
	}

	template <class CharT, class Traits, class Allocator>
	basic_rope<CharT, Traits, Allocator>::iterator_type basic_rope<CharT, Traits, Allocator>::end()
	{
		return impl_->end();
	}

	template <class CharT, class Traits, class Allocator>
	const basic_rope<CharT, Traits, Allocator>::iterator_type basic_rope<CharT, Traits, Allocator>::cbegin()
	{
		return impl_->begin();
	}

	template <class CharT, class Traits, class Allocator>
	const basic_rope<CharT, Traits, Allocator>::iterator_type basic_rope<CharT, Traits, Allocator>::cend()
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
		return impl_->size() < 1UL;
	}

} // namespace ocl::tproc

#endif