/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:49:34 by ybouddou          #+#    #+#             */
/*   Updated: 2022/03/20 15:26:01 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myiterator.hpp"
#include <iostream>
#include <vector>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			//NOTE - MEMBER TYPES
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer 			pointer;
			typedef	typename allocator_type::const_pointer 		const_pointer;
			typedef	ft::myiterator<pointer>						iterator;
			typedef	ft::myiterator<const_pointer>				const_iterator;
			typedef	typename allocator_type::difference_type 	difference_type;
			typedef	typename allocator_type::size_type 			size_type;

			//NOTE - MEMBER FUNCTIONS
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_capacity = 0;
				_size = 0;
				_arr = 0;
			}
			explicit vector (int n, const value_type& val = value_type(),
                			const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_capacity = n;
				_size = n;
				_arr = _alloc.allocate(_capacity);
				while (--n >= 0)
				{
					_arr[n] = val;
					if (!n)
						break ;
				}
				while (n < _size)
					std::cout << " * " << _arr[n++];
				std::cout << "\n";
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				size_type	i = -1;
				difference_type	size = last - first;
				_arr = _alloc.allocate(size);
				while (++i < size)
				{
					_arr[i] = *first;
					first++;
				}
				i = -1;
				while (++i < size)
					std::cout << " - " << _arr[i];
				std::cout << "\n";
			}
			vector (const vector& x)
			{
				size_type	i = -1;
				_alloc = x._alloc;
				_capacity = x._capacity;
				_size = x._size;
				_arr = _alloc.allocate(_capacity);
				while (++i < _capacity)
					_arr[i] = x._arr[i];
				i = -1;
				while (++i < _capacity)
					std::cout << " + " << _arr[i];
			}
			iterator begin()
			{
				return (_arr);
			}
			iterator end()
			{
				return (_arr + _size);
			}
		
		//NOTE - DATA MEMBERS
		private:
			pointer			_arr;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	};
}