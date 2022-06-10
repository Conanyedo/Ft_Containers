/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:02:54 by ybouddou          #+#    #+#             */
/*   Updated: 2022/06/10 09:59:37 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "iteratorTraits.hpp"

namespace ft
{
	//SECTION - REVERSE ITERATOR
	template <class Iterator>
	class reverseiterator
	{
		//SECTION - MEMBER TYPES
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type  	difference_type;
			typedef typename iterator_traits<Iterator>::value_type  		value_type;
			typedef typename iterator_traits<Iterator>::pointer  			pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category  iterator_category;
		private:
			iterator_type	_ptr;
			
		//SECTION - MEMBER FUNCTIONS
		public:
			reverseiterator() : _ptr(nullptr) {}
			explicit reverseiterator(iterator_type ptr) : _ptr(ptr) {}
			template <class Iter>
  			reverseiterator (const reverseiterator<Iter>& it) : _ptr(it._ptr) {}
			  
			iterator_type base() const{return _ptr;}
			reference operator*() const{return *(--base());}
			reverseiterator operator+ (difference_type n) const{return reverseiterator(_ptr - n);}
			reverseiterator& operator++()
			{
				--_ptr;
				return (*this);
			}
			reverseiterator operator++(int)
			{
				reverseiterator tmp(*this);
				--(_ptr);
				return (tmp);
			}
			reverseiterator& operator+= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			reverseiterator operator- (difference_type n) const{return reverseiterator(_ptr + n);}
			reverseiterator& operator--()
			{
				++_ptr;
				return (*this);
			}
			reverseiterator operator--(int)
			{
				reverseiterator tmp(*this);
				++(_ptr);
				return (tmp);
			}
			reverseiterator& operator-= (difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			pointer operator->() const
			{
				return (&(*(--base())));
			}
			reference operator[] (difference_type n) const {return (*(--base() - n));}
	};
	//SECTION - NON MEMBER FUNCTION OVERLOADS
	template <class Iterator>
	bool operator== (const reverseiterator<Iterator>& lhs,
					const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!= (const reverseiterator<Iterator>& lhs,
					const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator< (const reverseiterator<Iterator>& lhs,
					const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator<= (const reverseiterator<Iterator>& lhs,
					const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	bool operator> (const reverseiterator<Iterator>& lhs,
					const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator>= (const reverseiterator<Iterator>& lhs,
					const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	reverseiterator<Iterator> operator+ (
				typename reverseiterator<Iterator>::difference_type n,
				const reverseiterator<Iterator>& it)
	{
		return (reverseiterator<Iterator>(it.base() - n));
	}
	template <class Iterator>
	typename reverseiterator<Iterator>::difference_type operator- (
		const reverseiterator<Iterator>& lhs,
		const reverseiterator<Iterator>& rhs)
	{
		return(rhs.base() - lhs.base());
	}
}

#endif