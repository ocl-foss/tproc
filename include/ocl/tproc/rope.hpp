// Copyright 2025, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-org/tproc

#ifndef __OCL_TPROC_ROPE_HPP
#define __OCL_TPROC_ROPE_HPP

#include <ocl/tproc/detail/rope_fwd.hpp>
#include <string>

namespace ocl::tproc::rope
{

	/// \brief rbegin exact pred type.
	class reverse_pred final
	{
		std::string cond_;

	public:
		reverse_pred(const boost::core::string_view& cond)
			: cond_(cond)
		{
		}

		template <typename It>
		It operator()(It rbegin, It rend)
		{ 
			for (auto rbeg{rbegin}; rbegin != rend; ++rbeg)
			{
				if (*rbeg == cond_)
					return rbeg;
			}

			return rend;
		}
	};

	class uppercase_pred final
	{
		std::string cond_;

	public:
		uppercase_pred(const boost::core::string_view& cond)
			: cond_(cond)
		{
		}

		template <typename It>
		It operator()(It begin, It end)
		{
			auto cmp = std::transform(cond_.begin(), cond_.end(), [](std::string::char_type& ch) {
				return std::toupper(ch);
			});

			for (auto beg{begin}; begin != end; ++beg)
			{
				if (*beg == cond_)
					return beg;
			}

			return end;
		}
	};

	class lowercase_pred final
	{
		std::string cond_;

	public:
		lowercase_pred(const boost::core::string_view& cond)
			: cond_(cond)
		{
		}

		template <typename It>
		It operator()(It begin, It end)
		{
			auto cmp = std::transform(cond_.begin(), cond_.end(), [](std::string::char_type& ch) {
				return std::tolower(ch);
			});

			for (auto beg{begin}; begin != end; ++beg)
			{
				if (*beg == cond_)
					return beg;
			}

			return end;
		}
	};

	class exact_pred final
	{
		std::string cond_;

	public:
		exact_pred(const boost::core::string_view& cond)
			: cond_(cond)
		{
		}

		template <typename It>
		It operator()(It begin, It end)
		{ 
			for (auto beg{begin}; begin != end; ++beg)
			{
				if (*beg == cond_)
					return beg;
			}

			return end;
		}
	};

	class starts_with_pred final
	{
		std::string cond_;

	public:
		starts_with_pred(const boost::core::string_view& cond)
			: cond_(cond)
		{
		}

		template <typename It>
		It operator()(It begin, It end) { return end; }
	};

} // namespace ocl::tproc::rope

namespace ocl::tproc
{

	template <typename It, class Pred>
	Pred find(It begin, It end, Pred);

	template <typename It, class Pred>
	Pred find_if(It begin, It end, Pred);

	template <typename It, class Pred>
	It::typename size_type erase(It begin, It end, Pred);

	template <typename It, class Pred>
	It::typename size_type erase_if(It begin, It end, Pred);

} // namespace ocl::tproc

#endif // __OCL_TPROC_ROPE_HPP
