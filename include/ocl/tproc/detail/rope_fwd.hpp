// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef __OCL_TPROC_ROPE_FWD_HPP
#define __OCL_TPROC_ROPE_FWD_HPP

#include <ocl/tproc/detail/config.hpp>

/// \file rope_fwd.hpp
/// \brief Basic forward definitions of the `rope` type.

namespace ocl::tproc
{

	/// \brief This class implements a rope type for any **CharT** type.
	/// \note Specializations are available as `crope` and `wrope`.
	/// \author Amlal El Mahrouss
	template <class CharT, class Traits = std::char_traits<CharT>, class Allocator = std::allocator<CharT>>
	class basic_rope final
	{
	public:
		using traits_type	  = Traits;
		using value_type	  = CharT;
		using allocator_type  = Allocator;
		using size_type		  = std::allocator_traits<Allocator>::size_type;
		using reference		  = CharT&;
		using const_reference = const CharT&;
		using pointer		  = std::allocator_traits<Allocator>::pointer;
		using const_pointer	  = std::allocator_traits<Allocator>::pointer;
		using iterator_type	  = basic_rope<CharT, Traits, Allocator>*;

		iterator_type rbegin();
		iterator_type rend();

		iterator_type begin();
		iterator_type end();

		/// \todo do we need const_iterator_type now?
		const iterator_type cbegin();
		const iterator_type cend();

		/// \brief Extarcts a needle from a position of n length.
		basic_rope<CharT, Traits, Allocator>& substr(size_type pos, const size_type n = 0);

		/// \brief Rope's version of the find method.
		size_type at(const boost::core::basic_string_view<CharT>& needle);

		bool starts_with(const basic_rope<CharT>&);
		bool ends_with(const basic_rope<CharT>&);

		bool starts_with(const boost::core::basic_string_view<CharT>&);
		bool ends_with(const boost::core::basic_string_view<CharT>&);

		size_type size();
		bool	  empty() const;

	public:
		~basic_rope();
		basic_rope(const boost::core::basic_string_view<CharT>& in = {});

		basic_rope& operator=(const basic_rope& rope);
		basic_rope(const basic_rope& rope);

		basic_rope& operator=(basic_rope&& rope);
		basic_rope(basic_rope&& rope);

	    bool operator!=(const basic_rope& rope);
		bool operator==(const basic_rope& rope);

		bool operator!=(const boost::core::basic_string_view<CharT>&);
		bool operator==(const boost::core::basic_string_view<CharT>&);

	public:
		static constexpr size_type npos = (size_type)(-1);

	private:
		struct tree_impl;
		tree_impl* impl_{};
	};

#if __cplusplus >= 201811L
	using u8rope  = basic_rope<char8_t>;
	using u16rope = basic_rope<char16_t>;
#endif

	using crope = basic_rope<char>;
	using wrope = basic_rope<wchar_t>;

} // namespace ocl::tproc

#include "rope_fwd.inl"

#endif
