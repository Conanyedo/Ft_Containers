/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:29:19 by ybouddou          #+#    #+#             */
/*   Updated: 2022/04/17 23:21:15 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	template <bool Cond, class T = void> //NOTE - Main template struct
	struct enable_if
	{
	};

	template <class T> //NOTE - Specialized template struct
	struct enable_if<true, T> //ANCHOR - in case of true
	{
		typedef T type;
	};

	template <class T> //NOTE - Main template struct
	struct is_integral
	{
		static const bool value = false;
	};
	template <> //NOTE - Specialized template struct for int type
	struct is_integral<int>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct for bool type
	struct is_integral<bool>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct for char type
	struct is_integral<char>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<char16_t>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<char32_t>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<short>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<long>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<long long>
	{
		static const bool value = true;
	};
}

#endif