#include <iostream>
#include <vector>
#include <cmath>
#include "vector.hpp"
#include <map>
// #include "tree.hpp"
#include "BST.hpp"

int main()
{
	BBST<std::string> mytree;

	mytree.insert("fjdskf");
	mytree.insert("fsakdfs");
	mytree.insert("reqwf");
	mytree.insert("cvas");
	mytree.insert("aafew");
	mytree.insert("vasfd");
	mytree.insert("ewr");
	// mytree.insert(5);
	// mytree.insert(6);
	// mytree.insert(2);
	// mytree.insert(4);
	// mytree.insert(9);
	// mytree.insert(7);
	// mytree.insert(80);
	// mytree.insert(10);
	// mytree.insert(11);
	// mytree.insert(12);
	// mytree.insert(15);
	// mytree.insert(20);
	// mytree.insert(40);
	// mytree.insert(29);
	// mytree.insert(1);
	// mytree.insert(3);
	// mytree.insert(111);
	// std::cout << mytree.find(12) << std::endl;
	mytree.print();
}