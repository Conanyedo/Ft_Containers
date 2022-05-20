// #include <iostream>
// #include <vector>
// #include <cmath>
// #include "vector.hpp"
// #include <map>
// #include "map.hpp"
// #include "BST.hpp"

// int main()
// {
// 	BBST<int> mytree;

// 	mytree.insert(6);
// 	mytree.insert(4);
// 	mytree.insert(2);
// 	mytree.insert(5);
// 	mytree.insert(0);
// 	mytree.insert(-1);
// 	mytree.insert(-2);
// 	mytree.remove(4);
// 	// mytree.remove(2);
// 	// mytree.remove(4);
// 	// mytree.remove(5);
// 	// mytree.remove(6);
// 	mytree.print();

// }


#include "map.hpp"
#include <iostream>
#include <map>

int main ()
{
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	// ft::map<char,int>::reverse_iterator it = mymap.rbegin();
	// ft::map<char,int>::reverse_iterator ti = mymap.rend();
	// while (it != ti)
	// {
	// 	std::cout << "| " << it->first << " = " << (*it).second << " |\n";
	// 	it++;
	// }
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	return 0;
}