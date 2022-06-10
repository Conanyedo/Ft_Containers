/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 02:38:59 by conanyedo         #+#    #+#             */
/*   Updated: 2022/06/10 09:57:58 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

namespace ft
{
	//SECTION - BST DATA STRUCTURE
	template <class T>
	struct Node 
	{
		T		data;
		Node	*parent;
		Node	*left;
		Node	*right;
		int		balanceFactor;
		int		height;
		
		Node() : parent(nullptr), left(nullptr), right(nullptr) {}
		Node(const T& data) : data(data){}
		Node(const T& data, const int height) : data(data), parent(nullptr), left(nullptr), right(nullptr), balanceFactor(0), height(height) {}
	};

	//SECTION - BALANCED BINARY SEARCH TREE
	template <class T, class Compare, class Alloc>
	class AVLTree
	{
		public:
			typedef T																value_type;
			typedef Compare															key_compare;
			typedef Node<T>*														nodePtr;
			typedef typename Alloc::template rebind<Node<T> >::other				allocator_type;
			typedef	typename allocator_type::size_type 								size_type;
			
		private:
			nodePtr			_root;
			nodePtr			_end;
			allocator_type	_alloc;
			key_compare		_cmp;
			size_type		_size;
		
		public:
			AVLTree(const allocator_type& alloc = allocator_type(), const key_compare& cmp = key_compare()) : _root(nullptr), _end(nullptr), _alloc(alloc), _cmp(cmp), _size(0)
			{
				_end = _alloc.allocate(1);
				_alloc.construct(_end);
			}
			~AVLTree()
			{
				clear();
				_alloc.deallocate(_end, 1);
				_end = nullptr;
			}
			size_type size() const {return _size;}
			size_type max_size() const {return _alloc.max_size();}
			allocator_type get_allocator() const {return (this->_alloc);}
			nodePtr	getEnd() const {return (this->_end);}
			nodePtr	getMin(nodePtr node = nullptr) const
			{
				if (!node)
					node = _root;
				while (node && node->left)
					node = node->left;
				return node;
			}
			nodePtr	getMax(nodePtr node = nullptr)
			{
				if (!node)
					node = _root;
				while (node && node->right)
					node = node->right;
				return node;
			}
			nodePtr	lowerBound(const value_type& data)
			{
				nodePtr node = getMin();
                while (node != _end)
                {
                    if (!_cmp(node->data.first, data.first))
                        return (node);
                    node = successor(node);
                }
                return (_end);
			}
			nodePtr	upperBound(const value_type& data)
			{
				nodePtr node = getMin();
                while (node != _end)
                {
                    if (_cmp(data.first, node->data.first))
                        return (node);
                    node = successor(node);
                }
                return (_end);
			}
			void	swap(AVLTree& tree)
			{
				nodePtr			root = _root;
				nodePtr			end = _end;
				allocator_type	alloc = _alloc;
				key_compare		cmp = _cmp;
				size_type		size = _size;

				_root = tree._root;
				_end = tree._end;
				_alloc = tree._alloc;
				_cmp = tree._cmp;
				_size = tree._size;
				
				tree._root = root;
				tree._end = end;
				tree._alloc = alloc;
				tree._cmp = cmp;
				tree._size = size;
			}
			void	clear()
			{
				clear(_root);
				_size = 0;
			}
			nodePtr	find(const value_type& data)
			{
				return find(data, _root);
			}
			void	insert(const value_type data)
			{
				insert(data, _root, _end);
				_end->left = _root;
				_root->parent = _end;
			}
			void	erase(const value_type& data)
			{
				erase(_root, data);
				_end->left = _root;
				if (_root)
					_root->parent = _end;
			}
		private:
			void	eraseHelper(nodePtr &node, nodePtr& parent)
			{
				nodePtr tmp;
				if (node->right)
					tmp = node->right;
				else
					tmp = node->left;
				if (tmp)
					tmp->parent = parent;
				_alloc.deallocate(node, 1);
				node = tmp;
				_size--;
			}
			void	erase (nodePtr &node, const value_type& data)
			{
				if (!node)
					return ;
				if (node->data.first == data.first)
				{
					if (!node->left || !node->right)
					{
						eraseHelper(node, node->parent);
						return ;
					}
					else
					{
						if (node->left->height > node->right->height)
						{
							value_type value(getMax(node->left)->data);
							_alloc.construct(node, value);
							erase(node->left, value);
						}
						else
						{
							value_type value(getMin(node->right)->data);
							_alloc.construct(node, value);
							erase(node->right, value);
						}
					}
				}
				else if (_cmp(data.first, node->data.first))
					erase(node->left, data);
				else
					erase(node->right, data);
				update(node);
				balance(node);
			}
			void	insert(const value_type& data, nodePtr &node, nodePtr& parent)
			{
				if (!node)
				{
					node = _alloc.allocate(1);
					_alloc.construct(node, data, 0);
					node->parent = parent;
					_size++;
					return ;
				}
				if (_cmp(data.first, node->data.first))
					insert(data, node->left, node);
				else
					insert(data, node->right, node);
				update(node);
				balance(node);
			}
			nodePtr	find(const value_type& data, nodePtr& node)
			{
				if (!node || node == _end)
					return (_end);
				if (data.first == node->data.first)
					return (node);
				if (_cmp(data.first, node->data.first))
					return (find(data, node->left));
				return (find(data, node->right));
			}
			nodePtr	successor(nodePtr node)
			{
				nodePtr	parent = node->parent;
				nodePtr	tmp = node;
				if (tmp->right)
				{
					tmp = tmp->right;
					while (tmp->left)
						tmp = tmp->left;
					return tmp;
				}
				else
				{
					while (parent && tmp == parent->right)
					{
						tmp = parent;
						parent = tmp->parent;
					}
					return (parent);
				}
			}
			void	clear(nodePtr &node)
			{
				if (node)
				{
					clear(node->left);
					clear(node->right);
					_alloc.deallocate(node, 1);
					node = nullptr;
				}
			}
			void	update(nodePtr node)
			{
				int	leftNodeHeight = -1;
				int	rightNodeHeight = -1;
				
				if (node->left)
					leftNodeHeight = node->left->height;
				if (node->right)
					rightNodeHeight = node->right->height;

				int diff = ((leftNodeHeight > rightNodeHeight) ? leftNodeHeight : rightNodeHeight);
				node->height = 1 + diff;
				node->balanceFactor = rightNodeHeight - leftNodeHeight;
			}
			void	balance(nodePtr &node)
			{
				if (node->balanceFactor < -1)
				{
					if (node->left->balanceFactor <= 0)
						leftLeftCase(node);
					else
						leftRightCase(node);
				}
				else if (node->balanceFactor > 1)
				{
					if (node->right->balanceFactor >= 0)
						rightRightCase(node);
					else
						rightLeftCase(node);
				}
			}
			void	leftRotation(nodePtr &node)
			{
				nodePtr	parent = node->parent;
				nodePtr	root = node->right;
				node->right = root->left;
				if (node->right)
					node->right->parent = node;
				node->parent = root;
				root->left = node;
				root->parent = parent;
				node = root;
				update(node->left);
				update(node);
			}		
			void	rightRotation(nodePtr &node)
			{
				nodePtr	parent = node->parent;
				nodePtr	root = node->left;
				node->left = root->right;
				if (node->left)
					node->left->parent = node;
				node->parent = root;
				root->right = node;
				root->parent = parent;
				node = root;
				update(node->right);
				update(node);
			}		
			void	leftLeftCase(nodePtr &node)
			{
				rightRotation(node);
			}
			void	leftRightCase(nodePtr &node)
			{
				leftRotation(node->left);
				rightRotation(node);
			}
			void	rightRightCase(nodePtr &node)
			{
				leftRotation(node);
				
			}
			void	rightLeftCase(nodePtr &node)
			{
				rightRotation(node->right);
				leftRotation(node);
			}
	};
}



#endif