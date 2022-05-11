/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conanyedo <conanyedo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 02:38:59 by conanyedo         #+#    #+#             */
/*   Updated: 2022/04/27 03:17:23 by conanyedo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

#include <iostream>

namespace ft
{
	//!SECTION - BST DATA STRUCTURE
	template <class T>
	struct Node 
	{
		T		data;
		Node	*left;
		Node	*right;
		int		balanceFactor;
		int		height;
		
		Node(const T& data) : data(data), balanceFactor(0), height(0), left(NULL), right(NULL) {}
	};

	//!SECTION - BINARY SEARCH TREE
	template <class T, class Compare, class Alloc>
	class BST
	{
		public:
			typedef T																value_type;
			typedef Node<T>*														node;
			typedef Compare															key_compare;
			typedef typename Alloc::template rebind<node<value_type> >::other		allocator_type;
			typedef	typename allocator_type::size_type 								size_type;
			
		private:
			node			_root;
			allocator_type	_alloc;
			key_compare		_cmp;
			size_type		_size;
		
		public:
			BST(const allocator_type& alloc = allocator_type(), const key_compare& cmp = key_compare()) : _root(nullptr), _alloc(alloc), _cmp(cmp) {}
			size_type size() const {return _size;}
			size_type max_size() const {return _alloc.max_size();}
			allocator_type get_allocator() const {return (this->_alloc);}
			
	};
}



#endif