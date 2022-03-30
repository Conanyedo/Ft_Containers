/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:49:34 by ybouddou          #+#    #+#             */
/*   Updated: 2022/03/30 23:07:39 by ybouddou         ###   ########.fr       */
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
				// i = -1;
				// while (++i < _capacity)
				// 	std::cout << " + " << _arr[i];
				return (*this);
			}
			~vector()
			{
				_alloc.deallocate(_arr, _capacity);
			}
			
			//SECTION - MEMBER FUCTIONS
			iterator begin()
			{
				return (iterator(_arr));
			}
			const_iterator begin() const
			{
				return (const_iterator(_arr));
			}
			iterator end()
			{
				return (iterator(_arr + _size));
			}
			const_iterator end() const
			{
				return (const_iterator(_arr + _size));
			}
			size_type size() const {return _size;}
			size_type max_size() const 
			{
				size_type ret = std::pow(2,64)/sizeof(T);
				return (ret - 1);
			}
			size_type capacity() const {return _capacity;}
			reference operator[] (size_type n) {return (_arr[n]);}
			const_reference operator[] (size_type n) const {return (_arr[n]);}
			bool empty() const
			{
				if (!_size)
					return (true);
				return (false);
			}
			void resize (size_type n, value_type val = value_type()) 
			{
				pointer			tmp;
				size_type		i = -1;
				size_type		cap;
				
				if (n <= _size)
					_size = n;
				else if (n <= _capacity)
				{
					while (_size < n)
						_arr[_size++] = val;
				}
				else if (n > _capacity)
				{
					tmp = _arr;
					cap = _capacity;
					_capacity = (n <= (_capacity * 2)) ? (_capacity * 2) : n;
					_arr = _alloc.allocate(_capacity);
					while(++i < _size)
						_arr[i] = tmp[i];
					_alloc.deallocate(tmp, cap);
					while (_size < n)
						_arr[_size++] = val;
				}
			}
			void reserve (size_type n)
			{
				pointer			tmp;
				size_type	i = -1;

				if (n > _capacity)
				{
					tmp = _arr;
					_arr = _alloc.allocate(n);
					while(++i < _size)
						_arr[i] = tmp[i];
					_alloc.deallocate(tmp, _capacity);
					_capacity = n;
				}
			}
			// void shrink_to_fit()
			// {
			// 	pointer			tmp;
			// 	size_type	i = -1;
				
			// 	if (_capacity > _size)
			// 	{
			// 		tmp = _arr;
			// 		_arr = _alloc.allocate(_size);
			// 		while(++i < _size)
			// 			_arr[i] = tmp[i];
			// 		_alloc.deallocate(tmp, _capacity);
			// 		_capacity = _size;
			// 	}
			// }
			reference at (size_type n)
			{
				if (n < _size)
					return (_arr[n]);
				throw(std::out_of_range("vector"));
			}
			const_reference at (size_type n) const
			{
				if (n < _size)
					return (_arr[n]);
				throw(std::out_of_range("vector"));
			}
			reference front() {return (*_arr);}
			const_reference front() const {return (*_arr);}
			reference back() {return (_arr[_size - 1]);}
			const_reference back() const {return (_arr[_size - 1]);}
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				size_type	i = -1;
				
				_size = last - first;
				if (_size <= _capacity)
				{
					while (++i < _size)
						_arr[i] = *(first++);
				}
				else
				{
					_alloc.dealloacte(_arr, _capacity);
					_capacity = _size;
					_arr = _alloc.allocate(_capacity);
					while (++i < _size)
						_arr[i] = *(first++);
				}
			}
			void assign (size_type n, const value_type& val)
			{
				size_type	i = -1;
				
				_size = n;
				if (_size <= _capacity)
				{
					while (++i < _size)
						_arr[i] = val;
				}
				else
				{
					_alloc.dealloacte(_arr, _capacity);
					_capacity = _size;
					_arr = _alloc.allocate(_capacity);
					while (++i < _size)
						_arr[i] = val;
				}
			}
			void push_back (const value_type& val)
			{
				pointer			tmp;
				size_type	i = -1;

				if (!_capacity)
					_arr = _alloc.allocate(++_capacity);
				else if (_size == _capacity)
				{
					tmp = _arr;
					_arr = _alloc.allocate(_capacity * 2);
					while(++i < _size)
						_arr[i] = tmp[i];
					_alloc.deallocate(tmp, _capacity);
					_capacity *= 2;
				}
				_arr[_size] = val;
				++_size;
			}
			void pop_back()
			{
				if (_size)
					_size--;
			}
			iterator insert (iterator position, const value_type& val)
			{
				pointer		tmp;
				size_type	i = -1;
				size_type	cap = _capacity;
				size_type	pos = position - this->begin();
				size_type	newSize = (pos >= _size) ? pos: _size;
				
				newSize++;
				if (newSize > _capacity)
				{
					tmp = _arr;
					// _capacity = ((_capacity * 2) >= newSize) ? (_capacity * 2) : newSize;
					_capacity = _capacity * 2;
					_arr = _alloc.allocate(_capacity);
					while(++i < _size)
						_arr[i] = tmp[i];
					_alloc.deallocate(tmp, cap);
				}
				_size = newSize;
				while (--newSize > pos)
					_arr[newSize] = _arr[newSize - 1];
				_arr[pos] = val;
				return (this->begin() + pos);
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				pointer		tmp;
				size_type	cap = _capacity;
				size_type	shift = -1;
				size_type	pos = position - this->begin();
				size_type	newSize = ((pos + n) >= (_size + n)) ? (pos + n): (_size + n);
				
				if (newSize > _capacity)
				{
					tmp = _arr;
					// _capacity = ((_capacity * 2) >= newSize) ? (_capacity * 2) : newSize;
					_capacity = ((_capacity * 2) >= (_size + n)) ? (_capacity * 2) : (_size + n);
					// _capacity = _capacity * 2;
					_arr = _alloc.allocate(_capacity);
					while(++shift < _size)
						_arr[shift] = tmp[shift];
					_alloc.deallocate(tmp, cap);
				}
				shift = _size - pos;
				_size = newSize;
				while ((int)shift-- > 0 && newSize--)
					_arr[newSize] = _arr[newSize - n];
				while (n--)
					_arr[pos++] = val;
			}
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{
				pointer		tmp;
				size_type	cap = _capacity;
				size_type	shift = -1;
				size_type	n = last - first;
				size_type	pos = position - this->begin();
				size_type	newSize = ((pos + n - 1) >= (_size + n - 1)) ? (pos + n - 1): (_size + n - 1);
				
				newSize++;
				if (newSize > _capacity)
				{
					tmp = _arr;
					// _capacity = ((_capacity * 2) >= newSize) ? (_capacity * 2) : newSize;
					_capacity = ((_capacity * 2) >= (_size + n)) ? (_capacity * 2) : (_size + n);
					// _capacity = _capacity * 2;
					_arr = _alloc.allocate(_capacity);
					while(++shift < _size)
						_arr[shift] = tmp[shift];
					_alloc.deallocate(tmp, cap);
				}
				shift = _size - pos;
				_size = newSize;
				while ((int)shift-- > 0 && newSize--)
					_arr[newSize] = _arr[newSize - n];
				while (n--)
					_arr[pos++] = *(first++);
			}
			iterator erase (iterator position)
			{
				size_type	pos = position - this->begin();
				
				while (pos < _size - 1)
				{
					_arr[pos] = _arr[pos + 1];
					pos++;
				}
				_size--;
				return (this->begin() + pos);
			}
			iterator erase (iterator first, iterator last)
			{
				size_type	pos = last - first;
				
			}
			void swap (vector& x)
			{
				size_type	size = x._size;
				size_type	cap = x._capacity;
				pointer		arr = x._arr;

				x._size = this->_size;
				x._capacity = this->_capacity;
				x._arr = this->_arr;
				this->_size = size;
				this->_capacity = cap;
				this->_arr = arr;
			}
			void clear()
			{
				size_type	size = -1;
				while (--size < _size)
					_arr[size] = 0;
				_size = 0;
			}
			allocator_type get_allocator() const {return (this->_alloc);}
		
		//SECTION - DATA MEMBERS
		private:
			pointer			_arr;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	};
}