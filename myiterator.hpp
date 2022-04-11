/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myiterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:41:19 by ybouddou          #+#    #+#             */
/*   Updated: 2022/04/11 02:28:43 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

namespace ft
{
	//SECTION - ITERATOR TRAITS
	template <class Iterator> //NOTE - Main template class
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T> //NOTE - Specialized template class
	class iterator_traits<T*> //ANCHOR - Specialized for T pointer
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		T*									pointer;
			typedef		T&									reference;
			typedef		std::random_access_iterator_tag		iterator_category;
	};

	template <class T> //NOTE - Specialized template class
	class iterator_traits<const T*> //ANCHOR - Specialized for T const pointer
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		const T*							pointer;
			typedef		const T&							reference;
			typedef		std::random_access_iterator_tag		iterator_category;
	};
	
	//SECTION - ITERATOR
	template <class T>
	class myiterator
	{
		public:
			typedef T												iterator_type;
			typedef typename iterator_traits<T>::difference_type  	difference_type;
			typedef typename iterator_traits<T>::value_type  		value_type;
			typedef typename iterator_traits<T>::pointer  			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category  iterator_category;
		private:
			iterator_type	_ptr;
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
				++(*this);
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
				--(*this);
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
	
	//SECTION - REVERSE ITERATOR
	template <class T>
	class myreverseiterator
	{
		public:
			typedef T												iterator_type;
			typedef typename iterator_traits<T>::difference_type  	difference_type;
			typedef typename iterator_traits<T>::value_type  		value_type;
			typedef typename iterator_traits<T>::pointer  			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category  iterator_category;
		private:
			iterator_type	_ptr;
		public:
			myreverseiterator() : _ptr(nullptr) {}
			explicit myreverseiterator(iterator_type ptr) : _ptr(ptr) {}
			template <class Iter>
  			myreverseiterator (const myreverseiterator<Iter>& it) : _ptr(it._ptr) {}
			  
			iterator_type base() const{return _ptr;}
			reference operator*() const{return *(_ptr - 1);}
			myreverseiterator operator+ (difference_type n) const{return myreverseiterator(_ptr - n);}
			myreverseiterator& operator++()
			{
				--_ptr;
				return (*this);
			}
			myreverseiterator operator++(int)
			{
				myreverseiterator tmp(*this);
				--(*this);
				return (tmp);
			}
			myreverseiterator& operator+= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			myreverseiterator operator- (difference_type n) const{return myreverseiterator(_ptr + n);}
			myreverseiterator& operator--()
			{
				++_ptr;
				return (*this);
			}
			myreverseiterator operator--(int)
			{
				myreverseiterator tmp(*this);
				++(*this);
				return (tmp);
			}
			myreverseiterator& operator-= (difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			pointer operator->() const
			{
				return (&(*_ptr));
			}
			reference operator[] (difference_type n) const {return (*(_ptr - n - 1));}
	};
	template <class Iterator>
	bool operator== (const myreverseiterator<Iterator>& lhs,
					const myreverseiterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!= (const myreverseiterator<Iterator>& lhs,
					const myreverseiterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator< (const myreverseiterator<Iterator>& lhs,
					const myreverseiterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator<= (const myreverseiterator<Iterator>& lhs,
					const myreverseiterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	bool operator> (const myreverseiterator<Iterator>& lhs,
					const myreverseiterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator>= (const myreverseiterator<Iterator>& lhs,
					const myreverseiterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	myreverseiterator<Iterator> operator+ (
				typename myreverseiterator<Iterator>::difference_type n,
				const myreverseiterator<Iterator>& it)
	{
		return (myreverseiterator<Iterator>(it.base() - n));
	}
	template <class Iterator>
	typename myreverseiterator<Iterator>::difference_type operator- (
		const myreverseiterator<Iterator>& lhs,
		const myreverseiterator<Iterator>& rhs)
	{
		return(rhs.base() - lhs.base());
	}
}

#endif