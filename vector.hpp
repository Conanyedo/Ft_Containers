/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:49:34 by ybouddou          #+#    #+#             */
/*   Updated: 2022/03/21 19:33:43 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myiterator.hpp"
#include <iostream>
#include <vector>
#include <cmath>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			//SECTION - MEMBER TYPES
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

			//SECTION - CONSTRUCTORS - DESTRUCTOR
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
				// while (n < _size)
				// 	std::cout << " * " << _arr[n++];
				// std::cout << "\n";
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			{
				size_type	i = -1;
				_alloc = alloc;
				_capacity = last - first;
				_size = last - first;
				_arr = _alloc.allocate(_capacity);
				while (++i < _capacity)
				{
					_arr[i] = *first;
					first++;
				}
				// i = -1;
				// while (++i < _capacity)
				// 	std::cout << " - " << _arr[i];
				// std::cout << "\n";
			}
			vector (const vector& x)
			{
				*this = x;
			}
			vector& operator= (const vector& x)
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
				return (*this);
			}
			~vector()
			{
				_alloc.deallocate(_arr, _capacity);
			}
			
			//SECTION - MEMBER FUCTIONS
			iterator begin()
			{
				return (_arr);
			}
			iterator end()
			{
				return (_arr + _size);
			}
			size_type size() const {return _size;}
			size_type max_size() const 
			{
				size_type ret = std::pow(2,64)/sizeof(T);
				return (ret - 1);
			}
			size_type capacity() const {return _capacity;}
			reference operator[] (size_type n) {return (_arr[n]);}
			void resize (size_type n, value_type val = value_type()) 
			{
				pointer			tmp;
				size_type	i = -1;
				
				if (n <= _size)
					_size = n;
				else if (n > _size && n <= _capacity)
				{
					while (_size < n)
						_arr[_size++] = val;
				}
				else if (n > _capacity)
				{
					tmp = _arr;
					_capacity = (n <= (_capacity * 2)) ? (_capacity * 2) : n;
					_arr = _alloc.allocate(_capacity);
					while(++i < _size)
						_arr[i] = tmp[i];
					while (_size < n)
						_arr[_size++] = val;
					_alloc.deallocate(tmp, _capacity / 2);
				}
			}
		
		//SECTION - DATA MEMBERS
		private:
			pointer			_arr;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	};
}