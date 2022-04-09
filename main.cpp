#include <iostream>
#include <vector>
#include <cmath>
#include "vector.hpp"

int main()
{
	std::cout << "is_integral:" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "char:  " << ft::is_integral<char>::value << std::endl;
	std::cout << "int:   " << ft::is_integral<int>::value << std::endl;
	std::cout << "float: " << ft::is_integral<float>::value << std::endl;

	ft::vector<int> v1(3, 2);
	ft::vector<int> v2(v1.begin(), v1.end() - 1);

	size_t	i = 0;
	while (i < v1.size())
	{
		std::cout << " " << v1[i];
		i++;
	}
	std::cout << std::endl;
	i = 0;
	while (i < v2.size())
	{
		std::cout << " " << v1[i];
		i++;
	}
	std::cout << std::endl;
	return 0;
}