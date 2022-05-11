/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conanyedo <conanyedo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 03:18:48 by conanyedo         #+#    #+#             */
/*   Updated: 2022/04/27 03:57:39 by conanyedo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <iostream>
#include "myiterator.hpp"

namespace ft
{
	template <class T>
	class mapiterator
	{
		typedef typename iterator_traits<T>::difference_type  	difference_type;
		typedef typename iterator_traits<T>::value_type  		value_type;
		typedef typename iterator_traits<T>::pointer  			pointer;
		typedef typename iterator_traits<T>::reference			reference;
		typedef std::bidirectional_iterator_tag					iterator_category;
	};
}

#endif