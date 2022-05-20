/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:00:43 by ybouddou          #+#    #+#             */
/*   Updated: 2022/05/18 19:29:26 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

#include <iostream>
#include <queue>
#include <fstream>
#include <iomanip>

template <class T>
class BBST
{
	private:
		struct Node 
		{
			T		data;
			int		balanceFactor;
			int		height;
			Node	*parent;
			Node	*left;
			Node	*right;
			Node(T data) : data(data), balanceFactor(0), height(0), parent(nullptr), left(nullptr), right(nullptr) {}
		};
		Node	*root;
		int		nodecount;
		int		length;
	
	public:
		BBST() : root(nullptr), nodecount(0), length(0) {}
		int		getLenght(int data)
		{
			return (std::to_string(data).length());
		}
		int		getLenght(std::string data)
		{
			return (data.length());
		}
		int		height()
		{
			if (!root)
				return (0);
			return (root->height);
		}
		int		size()
		{
			return (nodecount);
		}
		Node	*&find(T value)
		{
			return find(value, root);
		}
		Node	*find(T value, Node *node)
		{
			if (node)
			{
				if (value == node->data)
					return node;
				else if (value < node->data)
					return find(value, node->left);
				return find(value, node->right);
			}
			return (node);
		}
		void	clear()
		{
			root = clear(root);
			nodecount = 0;
		}
		Node	*clear(Node *node)
		{
			if (node)
			{
				node->left = clear(node->left);
				node->right = clear(node->right);
				delete node;
			}
			return (nullptr);
		}
		bool	insert(T value)
		{
			inserting(value, root);
			nodecount++;
			if (length < getLenght(value))
				length = getLenght(value);
			return true;
		}
		void	inserting(T data, Node *&node, Node *parent = nullptr)
		{
			if (!node)
			{
				node = new Node(data);
				node->parent = parent;
				return ;
			}
			if (node->data == data)
				return ;
			if (data < node->data)
				inserting(data, node->left, node);
			else
				inserting(data, node->right, node);
			update(node);
			balance(node);
		}
		void	update(Node *node)
		{
			if (!node)
				return ;
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
		void	balance(Node *&node)
		{
			if (!node)
				return ;
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
		void	leftRotation(Node *&node)
		{
			Node*	parent =node->parent;
			Node*	root = node->right;
			node->right = root->left;
			node->parent = root;
			root->left = node;
			root->parent = parent;
			node = root;
			update(node->left);
			update(node);
		}
		void	rightRotation(Node *&node)
		{
			Node*	parent = node->parent;
			Node*	root = node->left;
			node->left = root->right;
			node->parent = root;
			root->right = node;
			root->parent = parent;
			node = root;
			update(node->right);
			update(node);
		}
		void	leftLeftCase(Node *&node)
		{
			rightRotation(node);
		}
		void	leftRightCase(Node *&node)
		{
			leftRotation(node->left);
			rightRotation(node);
		}
		void	rightRightCase(Node *&node)
		{
			leftRotation(node);
		}
		void	rightLeftCase(Node *&node)
		{
			rightRotation(node->right);
			leftRotation(node);
		}
		T	findMax(Node *node)
		{
			while (node->right)
				node = node->right;
			return (node->data);
		}
		T	findMin(Node *node)
		{
			while (node->left)
				node = node->left;
			return (node->data);
		}
		bool	remove(T value)
		{
			int oldcount = nodecount;
			removing(root, value);
			return ((oldcount != nodecount) ? true : false);
		}
		void	removingHelper(Node	*&node, Node *parent)
		{
			Node* tmp;
			if (!parent)
			{
				if (node->left)
					tmp = node->left;
				else
					tmp = node->right;
				delete node;
				node = tmp;
				root = node;
				if (root)
					root->parent = nullptr;
			}
			else
			{
				if (node->right)
					tmp = node->right;
				else
					tmp = node->left;
				if (tmp)
					tmp->parent = parent;
				delete node;
				node = tmp;
			}
			nodecount--;
		}
		void	removing(Node *&node, T value)
		{
			if (!node)
				return ;
			if (value == node->data)
			{
				if (!node->left || !node->right)
				{
					removingHelper(node, node->parent);
					return ;
				}
				else
				{
					if (node->left->height > node->right->height)
					{
						node->data = findMax(node->left);
						removing(node->left, node->data);
					}
					else
					{
						node->data = findMin(node->right);
						removing(node->right, node->data);
					}
				}
			}
			else if (value < node->data)
				removing(node->left, value);
			else
				removing(node->right, value);
			update(node);
			balance(node);
		}
		void	print()
		{
			if (!root)
			{
				std::cout << "tree khawya\n";
				return ;
			}
			std::cout << "|number of nodes : " << nodecount << " | tree height: " << root->height << " |\n";
			// printing(root);
			levelOrder(root);
		}
		void	levelOrder(Node *node)
		{
			std::ofstream	outfile("outfile");
			std::queue<Node *> q;
			Node	*empty = new Node(T());
			int	spaces = 0;
			int	currentSpaces = 0;
			int	level = 0;
			int	childs = 0;
			int	repeat;
			int	height = node->height;
			length += 2;

			q.push(root);
			while (height >= 0)
			{
				Node *current = q.front();
				if (current->left)
					q.push(current->left);
				else
					q.push(empty);
				if (current->right)
					q.push(current->right);
				else
					q.push(empty);
				q.pop();
				currentSpaces = (pow(2, height) * length) - length;
				if (level && (childs == (std::pow(2, level) - 1)))
				{
					repeat = pow(2, level);
					spaces = currentSpaces;
					while (spaces--)
						outfile << " ";
					while (--repeat)
					{
						if (repeat % 2)
						{
							spaces = (currentSpaces * 2) + (length * 3) - 2;
							outfile << "+";
							while (spaces--)
								outfile << "-";
							outfile << "+";
						}
						else
						{
							spaces = (currentSpaces * 2) + (length * 1);
							while (spaces--)
								outfile << " ";
						}
					}
					outfile << "\n";
				}
				spaces = currentSpaces;
				while (spaces--)
					outfile << " ";
				outfile << "(";
				repeat = (length - 2) - getLenght(current->data);
				while (repeat--)
					outfile << " ";
				outfile << current->data;
				outfile << ")";
				spaces = currentSpaces + length;
				while (childs && spaces--)
					outfile << " ";
				if (!childs)
				{
					height--;
					level++;
					childs = std::pow(2, level);
					outfile << "\n";
				}
				childs--;
			}
		}
		void	printing(Node *node)
		{
			if (node->left)
				printing(node->left);
			std::cout << node->data << "\n";
			if (node->right)
				printing(node->right);
		}
		
};

#endif