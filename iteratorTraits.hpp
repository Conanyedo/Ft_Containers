/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:11:13 by ybouddou          #+#    #+#             */
/*   Updated: 2022/05/21 22:17:59 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

#include <iostream>

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
}

#endif