/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:41:19 by ybouddou          #+#    #+#             */
/*   Updated: 2021/12/20 18:51:48 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
#include <cstddef>
#include <vector>

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T> 
	class iterator_traits<T*>
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		T*									pointer;
			typedef		T&									reference;
			typedef		std::random_access_iterator_tag		iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		const T*							pointer;
			typedef		const T&							reference;
			typedef		std::random_access_iterator_tag		iterator_category;
	};
	
	template <class T>
	class myiterator
	{
		public:
			typedef typename iterator_traits<T>::difference_type  	difference_type;
			typedef typename iterator_traits<T>::value_type  		value_type;
			typedef typename iterator_traits<T>::pointer  			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category  iterator_category;
		private:
			value_type ptr;
		public:
			
	};
}

#endif