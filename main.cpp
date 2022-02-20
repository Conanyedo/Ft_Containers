#include <iostream>
#include <vector>

template <class Iterator>
class iterator_traits
{
	public:
	typedef typename Iterator::difference_type  	difference_type;
	typedef typename Iterator::value_type  		value_type;
	typedef typename Iterator::pointer  			pointer;
	typedef typename Iterator::reference  reference;
	typedef typename Iterator::iterator_category  iterator_category;
};

template <class T> 
class iterator_traits<T*>
{
	public:
	typedef 	ptrdiff_t	difference_type;
	typedef		T			value_type;
	typedef		T*			pointer;
	typedef		T&			reference;
	typedef		std::random_access_iterator_tag			iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
	public:
	typedef 	ptrdiff_t	difference_type;
	typedef		T			value_type;
	typedef		const T*	pointer;
	typedef		const T&	reference;
	typedef		std::random_access_iterator_tag			iterator_category;
};

template <class iter>
void	some(iter f) // int *
{
	typedef typename iterator_traits<iter>::value_type value_type;
	value_type a = *f; //value_type = int
	std::cout << a << std::endl;
}

int main()
{
	// std::vector<int> v(3, 1337);
	// some(v.begin());
	int arr[] = {1337, 42, 19};
	some(arr);
}