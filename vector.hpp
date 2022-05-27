/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:49:34 by ybouddou          #+#    #+#             */
/*   Updated: 2022/05/27 16:47:20 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "myiterator.hpp"
#include "reverseIterator.hpp"
#include "enable_if.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		//SECTION - MEMBER TYPES
		public:
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer 			pointer;
			typedef	typename allocator_type::const_pointer 		const_pointer;
			typedef	ft::myiterator<pointer>						iterator;
			typedef	ft::myiterator<const_pointer>				const_iterator;
			typedef	ft::reverseiterator<iterator>				reverse_iterator;
			typedef	ft::reverseiterator<const_iterator>			const_reverse_iterator;
			typedef	typename allocator_type::difference_type 	difference_type;
			typedef	typename allocator_type::size_type 			size_type;

		//SECTION - PRIVATE DATA MEMBERS
		private:
			pointer			_arr;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
		
		//SECTION - MEMBER FUNCTIONS
		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _arr(nullptr)
			{
			}
			explicit vector (size_type n, const value_type& val = value_type(),
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
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename enable_if<!is_integral <InputIterator>::value, InputIterator>::type * = nullptr)
					//ANCHOR - SFINAE
			{
				size_type	i = -1;
				_alloc = alloc;
				_capacity = last - first;
				_size = _capacity;
				_arr = _alloc.allocate(_capacity);
				while (++i < _capacity)
				{
					_arr[i] = *first;
					first++;
				}
			}
			vector (const vector& x) : _capacity(0), _size(0), _arr(nullptr)
			{
				*this = x;
			}
			vector& operator= (const vector& x)
			{
				size_type	i = -1;
				
				if (this == &x)
					return (*this);
				_alloc = x._alloc;
				if (_capacity)
					_alloc.deallocate(_arr, _capacity);
				_capacity = x._capacity;
				_size = x._size;
				_arr = _alloc.allocate(_capacity);
				while (++i < _capacity)
					_arr[i] = x._arr[i];
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
			//NOTE - REVERSE ITERATOR BEGIN AND END
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
			
			size_type size() const {return _size;}
			size_type max_size() const 
			{
				// size_type ret = std::pow(2,64)/sizeof(T) - 1;
				size_type ret = _alloc.max_size();
				return (ret);
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
			void assign (InputIterator first, InputIterator last,
						typename enable_if<!is_integral <InputIterator>::value, InputIterator>::type * = nullptr)
						//ANCHOR - SFINAE
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
					_alloc.deallocate(_arr, _capacity);
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
					_alloc.deallocate(_arr, _capacity);
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
    		void insert (iterator position, InputIterator first, InputIterator last,
						typename enable_if<!is_integral <InputIterator>::value, InputIterator>::type * = nullptr)
						//ANCHOR - SFINAE)
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
				pos = position - this->begin();
				if (pos < _size)
					_size--;
				return (this->begin() + pos);
			}
			iterator erase (iterator first, iterator last)
			{
				size_type	fpos = first - this->begin();
				size_type	lpos = last - this->begin();
				size_type	pos = last - first;
				size_type	size = _size;
				
				if (lpos >= size)
					_size = fpos;
				else
					_size -= pos;
				while (lpos < size)
				{
					_arr[fpos] = _arr[lpos];
					fpos++;
					lpos++;
				}
				return (this->begin() + lpos);
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
		
	};
	//SECTION - NON MEMBER FUNCTION OVERLOADS
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {x.swap(y);}
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if ((first2 == last2) || (*first1 > *first2)) 
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size()));
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif