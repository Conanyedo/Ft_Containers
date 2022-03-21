#include <iostream>
#include <vector>
#include <cmath>
#include "vector.hpp"

int main()
{
	ft::vector<int>::iterator it;
	ft::vector<int> vec(5, 1337);
	it = vec.begin();
	std::vector<char> vec_c(5, 'a');
	std::vector<int> tvector(5, 42);
	std::cout << "| " << tvector.max_size() << " | " << sizeof(tvector.max_size()) << " | " << sizeof(size_t) << " |\n";
	std::cout << "| " << vec.max_size() << " | " << sizeof(vec.max_size()) << " | " << sizeof(size_t) << " |\n";
	std::cout << "| " << *it << " |\n";
	size_t i;

	
	std::cout << "\n| " << vec.size() << " | " << vec.capacity() << " == > ";
	for (i=0;i< vec.size();i++)
		std::cout << ' ' << vec[i];
	std::cout << "\n| " << tvector.size() << " | " << tvector.capacity() << " == > ";
	for (i=0;i< tvector.size();i++)
		std::cout << ' ' << tvector[i];

	vec.resize(6);
	tvector.resize(6);

	std::cout << "\n| " << vec.size() << " | " << vec.capacity() << " == > ";
	for (i=0;i< vec.size();i++)
		std::cout << ' ' << vec[i];
	std::cout << "\n| " << tvector.size() << " | " << tvector.capacity() << " == > ";
	for (i=0;i< tvector.size();i++)
		std::cout << ' ' << tvector[i];
}