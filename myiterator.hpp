/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myiterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:41:19 by ybouddou          #+#    #+#             */
/*   Updated: 2022/05/27 10:57:06 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "iteratorTraits.hpp"

namespace ft
{
	//SECTION - ITERATOR
	template <class T>
	class myiterator
	{
		//SECTION - MEMBER TYPES
		public:
			typedef T												iterator_type;
			typedef typename iterator_traits<T>::difference_type  	difference_type;
			typedef typename iterator_traits<T>::value_type  		value_type;
			typedef typename iterator_traits<T>::pointer  			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category  iterator_category;
		private:
			iterator_type	_ptr;
		//SECTION - MEMBER FUNCTIONS
		public:
			myiterator() : _ptr(nullptr) {}
			explicit myiterator(iterator_type ptr) : _ptr(ptr) {}
			template <class Iter>
  			myiterator (const myiterator<Iter>& it) : _ptr(it._ptr) {}

			iterator_type base() const{return _ptr;}
			reference operator*() const{return *_ptr;}
			myiterator operator+ (difference_type n) const{return myiterator(_ptr + n);}
			myiterator& operator++()
			{
				++_ptr;
				return (*this);
			}
			myiterator operator++(int)
			{
				myiterator tmp(*this);
				++_ptr;
				return (tmp);
			}
			myiterator& operator+= (difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			myiterator operator- (difference_type n) const{return myiterator(_ptr - n);}
			myiterator& operator--()
			{
				--_ptr;
				return (*this);
			}
			myiterator operator--(int)
			{
				myiterator tmp(*this);
				--_ptr;
				return (tmp);
			}
			myiterator& operator-= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			pointer operator->() const
			{
				return (&(*_ptr));
			}
			reference operator[] (difference_type n) const {return (_ptr[n]);}
	};
	//SECTION - NON MEMBER FUNCTION OVERLOADS
	template <class Iterator>
	bool operator== (const myiterator<Iterator>& lhs,
					const myiterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!= (const myiterator<Iterator>& lhs,
					const myiterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator< (const myiterator<Iterator>& lhs,
					const myiterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator<= (const myiterator<Iterator>& lhs,
					const myiterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	bool operator> (const myiterator<Iterator>& lhs,
					const myiterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator>= (const myiterator<Iterator>& lhs,
					const myiterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	myiterator<Iterator> operator+ (
				typename myiterator<Iterator>::difference_type n,
				const myiterator<Iterator>& it)
	{
		return (myiterator<Iterator>(it.base() + n));
	}
	template <class Iterator>
	typename myiterator<Iterator>::difference_type operator- (
		const myiterator<Iterator>& lhs,
		const myiterator<Iterator>& rhs)
	{
		return(lhs.base() - rhs.base());
	}
}

#endif