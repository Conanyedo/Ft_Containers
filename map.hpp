/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:32:01 by ybouddou          #+#    #+#             */
/*   Updated: 2022/05/20 20:08:45 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "binarySearchTree.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		//SECTION - MEMBER TYPES
		public:
			typedef	Key												key_type;
			typedef T												mapped_type;
			typedef	pair<const key_type, mapped_type>				value_type;
			typedef Compare											key_compare;
			
			//NOTE - Nested function class to compare elements
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c) : comp(c) {}
				public:
					bool operator()(const value_type& lhs, const value_type& rhs) const //NOTE - Fuction object
					{
						return comp(lhs.first, rhs.first);
					}
			};
			
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef BBST<value_type, key_compare, allocator_type>	tree;
			typedef typename tree::nodePtr							nodePtr;
			typedef	ft::mapiterator<pointer, nodePtr>				iterator;
			typedef	ft::mapiterator<const_pointer, nodePtr>			const_iterator;
			typedef	ft::mapreverseiterator<pointer, nodePtr>		reverse_iterator;
			typedef	ft::mapreverseiterator<const_pointer, nodePtr>	const_reverse_iterator;
			typedef	typename allocator_type::difference_type 		difference_type;
			typedef	typename allocator_type::size_type 				size_type;
		
		//SECTION - PRIVATE DATA MEMBERS
		private:
			allocator_type	_alloc;
			key_compare		_cmp;
			tree			_tree;
		
		//SECTION - MEMBER FUNCTIONS
		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _cmp(comp), _alloc(alloc) {}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _tree(), _cmp(comp), _alloc(alloc)
			{
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}
			map (const map& x) : _cmp(x.comp), _alloc(x.alloc)
			{
				*this = x;
			}
			map& operator= (const map& x)
			{
				if (this == &x)
					return *this;
				_tree.clear();
				if (x.size())
					insert(x.begin(), x.end());
				return *this;
			}
			~map()
			{
				_tree.clear();
			}

			//SECTION - MEMBER FUCTIONS
			iterator begin()
			{
				return (iterator(_tree.getMin()));
			}
			const_iterator begin() const
			{
				return (const_iterator(_tree.getMin()));
			}
			iterator end()
			{
				nodePtr	node = _tree.getMax();
				iterator it = iterator(node);
				++it;
				return (it);
			}
			const_iterator end() const
			{
				nodePtr	node = _tree.getMax();
				const_iterator cit = const_iterator(node);
				++cit;
				return (cit);
			}
			//NOTE - REVERSE ITERATOR BEGIN AND END
			reverse_iterator rbegin()
			{
				return (reverse_iterator(_tree.getMax()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_tree.getMax()));
			}
			reverse_iterator rend()
			{
				nodePtr	node = _tree.getMin();
				reverse_iterator rit = reverse_iterator(node);
				++rit;
				return (rit);
			}
			const_reverse_iterator rend() const
			{
				nodePtr	node = _tree.getMin();
				const_reverse_iterator crit = reverse_iterator(node);
				++crit;
				return (crit);
			}

			allocator_type get_allocator() const {return (this->_alloc);}
			size_type	size() const {return (_tree.size());}
			bool empty() const {return (size() == 0);}
			size_type	max_size() const {return (_tree.max_size());}
			void clear() {_tree.clear();}
			
			mapped_type& operator[] (const key_type& k)
			{
				nodePtr	node = _tree.find(ft::make_pair(k, mapped_type()));
				if (!node)
				{
					_tree.insert(make_pair(k, mapped_type()));
					node = _tree.find(make_pair(k, mapped_type()));
				}
				return (node->data.second);
			}
			pair<iterator,bool> insert (const value_type& val)
			{
				nodePtr	node = _tree.find(val);
				bool	notInserted = false;
				if (!node)
				{
					_tree.insert(val);
					node = _tree.find(val);
					notInserted = true;
				}
				return (make_pair(iterator(node), notInserted));
			}
			iterator insert (iterator position, const value_type& val)
			{
				static_cast<void>(position);
				nodePtr	node = _tree.find(val);
				if (!node)
				{
					_tree.insert(val);
					node = _tree.find(val);
				}
				return (iterator(node));
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}
			void erase (iterator position)
			{
				nodePtr node = position.base();
				if (node)
					_tree.erase(node);
			}
			size_type erase (const key_type& k)
			{
				nodePtr node = _tree.find(make_pair(k, mapped_type()));
				if (!node)
					return (0);
				_tree.erase(node);
				return (1);
			}
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
			}
			void swap (map& x)
			{
				allocator_type	alloc = x.get_allocator();
				key_compare		cmp = x._cmp;
				tree			tree = x._tree;
				x._alloc = this->get_allocator();
				x._cmp = this->_cmp;
				x._tree = this->_tree;
				this->_alloc = alloc;
				this->_cmp = cmp;
				this->_tree = tree;
			}
			iterator find (const key_type& k)
			{
				nodePtr	node = _tree.find(make_pair(k, mapped_type()));
				return (iterator(node));
			}
			const_iterator find (const key_type& k) const
			{
				nodePtr	node = _tree.find(make_pair(k, mapped_type()));
				return (const_iterator(node));
			}
			size_type count (const key_type& k) const
			{
				nodePtr&	node = _tree.find(make_pair(k, mapped_type()));
				
				if (!node)
					return (0);
				return (1);
			}
			key_compare key_comp() const
			{
				return (this->_cmp);
			}
			value_compare value_comp() const
			{
				return (value_comp());
			}
			iterator lower_bound (const key_type& k)
			{
				iterator it = find(k);
				return (it);
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator cit = find(k);
				return (cit);
			}
			iterator upper_bound (const key_type& k)
			{
				iterator it = find(k);
				return (++it);
			}
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator cit = find(k);
				return (++cit);
			}
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (make_pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (make_pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
			}
	};
}

#endif