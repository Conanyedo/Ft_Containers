/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:32:01 by ybouddou          #+#    #+#             */
/*   Updated: 2022/04/18 02:00:47 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include <map>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
			typedef	Key												key_type;
			typedef T												mapped_type;
			typedef	pair<const key_type, mapped_type>				value_type;
			typedef Compare											key_compare;
			
			//NOTE - Nested function class to compare elements
			class value_compare : public binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c) : comp(c) {}
				public:
					bool operator()(const value_type& lhs, const value_type& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}
			};
			
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef	typename allocator_type::difference_type 		difference_type;
			typedef	typename allocator_type::size_type 				size_type;
			
		private:
			allocator_type _alloc;
	};
}

#endif