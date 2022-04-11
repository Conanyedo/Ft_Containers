#include <iostream>
#include <vector>
#include <cmath>
#include "vector.hpp"

int main()
{
	std::vector<int> vec;
	ft::vector<int> v;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::vector<int>::iterator rit = vec.begin();
	std::vector<int>::iterator myrit = vec.begin() + 2;
	std::vector<int>::iterator::difference_type myrit2 = myrit - rit;
	// ft::vector<int>::iterator rit = v.begin();
	// ft::vector<int>::iterator myrit = v.begin() + 2;
	// ft::vector<int>::iterator::difference_type myrit2 = myrit - rit;
	// ft::vector<int>::reverse_iterator myrit2 = rit + 1;

	// std::cout << *rit << "\n";
	// std::cout << *myrit << "\n";
	std::cout << myrit2 << "\n";
	// std::cout << *rit << "\n";

}