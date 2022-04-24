/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:00:43 by ybouddou          #+#    #+#             */
/*   Updated: 2022/04/24 22:15:30 by ybouddou         ###   ########.fr       */
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
			Node	*left;
			Node	*right;
			Node(T data) : data(data), balanceFactor(0), height(0), left(NULL), right(NULL) {}
			bool	find(T value)
			{
				if (value == data)
					return true;
				else if (value < data && left)
					return left->find(value);
				else if (value > data && right)
					return right->find(value);
				return false;
			}
		};
		int		nodecount;
		Node	*root;
		int		length;
	
	public:
		BBST() : root(NULL), nodecount(0), length(0) {}
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
		bool	find(T value)
		{
			if (!root)
				return false;
			return root->find(value);
		}
		bool	insert(T value)
		{
			if (!root)
				length = 0;
			if (!find(value))
			{
				root = inserting(root, value);
				nodecount++;
				if (length < getLenght(value))
					length = getLenght(value);
				return true;
			}
			return false;
		}
		Node	*inserting(Node *node, T value)
		{
			if (!node)
				return (new Node(value));
			if (value <= node->data)
				node->left = inserting(node->left, value);
			else
				node->right = inserting(node->right, value);
			update(node);
			return balance(node);
		}
		void	update(Node *node)
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
		Node	*balance(Node *node)
		{
			if (node->balanceFactor < -1)
			{
				if (node->left->balanceFactor <= 0)
					return leftLeftCase(node);
				return leftRightCase(node);	
			}
			else if (node->balanceFactor > 1)
			{
				if (node->right->balanceFactor >= 0)
					return rightRightCase(node);
				return rightLeftCase(node);
			}
			return (node);
		}
		Node	*leftRotation(Node *node)
		{
			Node	*parent = node->right;
			node->right = parent->left;
			parent->left = node;
			update(node);
			update(parent);
			return (parent);
		}		
		Node	*rightRotation(Node *node)
		{
			Node	*parent = node->left;
			node->left = parent->right;
			parent->right = node;
			update(node);
			update(parent);
			return (parent);
		}		
		Node	*leftLeftCase(Node *node)
		{
			return rightRotation(node);
		}
		Node	*leftRightCase(Node *node)
		{
			node->left = leftRotation(node->left);
			return rightRotation(node);
		}
		Node	*rightRightCase(Node *node)
		{
			return leftRotation(node);
		}
		Node	*rightLeftCase(Node *node)
		{
			node->right = rightRotation(node->right);
			return leftRotation(node);
		}
		bool	remove(T value)
		{
			if (find(value))
			{
				root = removing(root, value);
				nodecount--;
				return (true);
			}
			return (false);
		}
		T	findMax(Node *node)
		{
			while (!node->right)
				node = node->right;
			return (node->data);
		}
		T	findMin(Node *node)
		{
			while (!node->left)
				node = node->left;
			return (node->data);
		}
		Node	*removing(Node *node,T value)
		{
			if (!node)
				return (NULL);
			if (value < node->data)
				node->left = removing(node->left, value);
			else if (value > node->data)
				node->right = removing(node->right, value);
			else
			{
				if (!node->left)
					return (node->right);
				else if (!node->right)
					return (node->left);
				else
				{
					if (node->left->height > node->right->height)
					{
						node->data = findMax(node->left);
						node->left = removing(node->left, node->data);
					}
					else
					{
						node->data = findMin(node->right);
						node->right = removing(node->right, node->data);
					}
				}
			}
			update(node);
			return (balance(node));
		}
		void	print()
		{
			if (!root)
				return ;
			std::cout << "| number of nodes : " << nodecount << " | tree height: " << root->height << " |\n";
			std::cout << "lenght : " << length << " |\n";
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
		/*
		void	levelOrder(Node *node)
		{
			std::ofstream	outfile("outfile");
			std::queue<Node *> q;
			Node	*empty = new Node(T());
			int	spaces = 0;
			int	oldSpaces = 0;
			int	currentSpaces = 0;
			int	level = 0;
			int	childs = 0;
			int	first = 1;
			int	repeat;

			q.push(root);
			while (level <= root->height)
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
				if (first)
				{
					spaces = pow(2, ((node->height + length) - level));
					currentSpaces = spaces;
					if (!level)
						std::cout << "spaces : " << spaces << " | height : " << node->height << " |\n";
					// if (current && (current->data >= 10))
					// 	spaces--;
					while (spaces--)
						outfile << " ";
					if (level)
					{
						spaces = oldSpaces + 1;
						repeat = pow(2, level);
						while (--repeat)
						{
							if (repeat % 2)
							{
								spaces = oldSpaces + 1 - 2;
								outfile << "+";
								while (spaces--)
									outfile << "-";
								outfile << "+";
								
							}
							else
							{
								spaces = oldSpaces - 1;
								while (spaces--)
									outfile << " ";
								
							}
						}
						outfile << "\n";
						spaces = currentSpaces - 1;
						while (spaces--)
							outfile << " ";
					}
					outfile << "(" << current->data  << ")";
				}
				else
				{
					spaces = oldSpaces - 1;
					// if (current && (current->data >= 10))
					// 	spaces--;
					spaces -= 2;
					while (spaces--)
						outfile << " ";
					outfile << "(" << current->data << ")";
				}
				first = 0;
				if (!childs)
				{
					level++;
					first = 1;
					oldSpaces = currentSpaces;
					childs = std::pow(2, level);
					outfile << "\n";
				}
				childs--;
			}
		}
		*/
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