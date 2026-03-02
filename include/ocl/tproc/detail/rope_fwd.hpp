// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#ifndef OCL_TPROC_ROPE_FWD_HPP
#define OCL_TPROC_ROPE_FWD_HPP

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
		using char_type		  = value_type;
		using allocator_type  = Allocator;
		using size_type		  = std::allocator_traits<Allocator>::size_type;
		using reference		  = CharT&;
		using const_reference = const CharT&;
		using pointer		  = std::allocator_traits<Allocator>::pointer;
		using const_pointer	  = const std::allocator_traits<Allocator>::pointer;
		using rope_ptr		  = basic_rope<CharT>*;

		rope_ptr rbegin();
		rope_ptr rend();

		rope_ptr begin();
		rope_ptr end();

		pointer	 operator*() const;
		rope_ptr operator--();
		rope_ptr operator--(int);
		rope_ptr operator++();
		rope_ptr operator++(int);

		const rope_ptr cbegin() const;
		const rope_ptr cend() const;

		rope_ptr concat(rope_ptr right);

		basic_rope<CharT, Traits, Allocator>& substr(size_type pos, const size_type n = 0);
		size_type							  at(const boost::core::basic_string_view<CharT>& needle);

		bool starts_with(const basic_rope<CharT>&);
		bool ends_with(const basic_rope<CharT>&);

		bool starts_with(const boost::core::basic_string_view<CharT>&);
		bool ends_with(const boost::core::basic_string_view<CharT>&);

		size_type size() const;
		bool	  empty() const;

		rope_ptr insert(size_type pos,
						const boost::core::basic_string_view<CharT>&,
						rope_ptr) const;

		std::basic_string<value_type> to_string();
		std::basic_string<value_type> to_string() const;

	public:
		basic_rope(const boost::core::basic_string_view<CharT>& in = {});
		~basic_rope();

		basic_rope& operator=(const basic_rope& rope) = delete;
		basic_rope(const basic_rope& rope)			  = delete;

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
