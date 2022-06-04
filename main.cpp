/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:57:33 by ybouddou          #+#    #+#             */
/*   Updated: 2022/06/04 19:12:51 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <deque>
#include <stdlib.h>

#ifndef NS
#define NS std
#endif

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public NS::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename NS::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	NS::vector<std::string> vector_str;
// 	NS::vector<int> vector_int;
// 	NS::stack<int> stack_int;
// 	NS::vector<Buffer> vector_buffer;
// 	NS::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	NS::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	NS::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(NS::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		NS::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }


int main()
{
	
    std::cout << "*************************************************************************" << std::endl;
    std::cout << "\t\t\t\tVector" << std::endl;
    std::cout << "*************************************************************************" << std::endl;

    //NOTE - Constructor
    {
        std::cout << "------------- Library FT (Constructor) -------------" << std::endl;
        NS::vector<int> first1;
        NS::vector<int> second(4, 100);
        NS::vector<int> third(second.begin(), second.end());
        NS::vector<int> fourth(third);
        int myints[] = {16, 2, 77, 29};
        NS::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
        std::cout << "The contents of fifth are:";
        for (NS::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    //NOTE - Assign content (operator=)
    {
        std::cout << "------------- Library FT (operator=)-------------" << std::endl;
        NS::vector<int> foo1(3, 0);
        NS::vector<int> bar1(5, 0);
        bar1 = foo1;
        foo1 = NS::vector<int>();
        std::cout << "Size of foo: " << int(foo1.size()) << '\n';
        std::cout << "Size of bar: " << int(bar1.size()) << '\n';
    }

    //NOTE - Return iterator to beginning
    {
        std::cout << "------------- Library FT (iterator to beginning)-------------" << std::endl;
        NS::vector<int> myvector1;
        for (int i = 1; i <= 5; i++)
            myvector1.push_back(i);
        std::cout << "myvector contains:";
        for (NS::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    //NOTE - Return iterator to end
    {
        std::cout << "------------- Library FT (iterator to end)-------------" << std::endl;
        NS::vector<int> myvector1;
        for (int i = 1; i <= 5; i++)
            myvector1.push_back(i);
        std::cout << "myvector contains:";
        for (NS::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    // NOTE - Return reverse iterator to reverse beginning
    {
        std::cout << "------------- Library FT (reverse iterator to reverse beginning)-------------" << std::endl;
        NS::vector<int> myvector1(5); // 5 default-constructed ints
        int i1 = 0;
        NS::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
        for (; rit1 != myvector1.rend(); ++rit1)
            *rit1 = ++i1;
        std::cout << "myvector contains:";
        for (NS::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); ++it1)
            std::cout << ' ' << *it1;
        std::cout << '\n';
    }

    // NOTE - Return reverse iterator to reverse end
    {
        std::cout << "------------- Library FT (reverse iterator to reverse end)-------------" << std::endl;
        NS::vector<int> myvector1(5);
        NS::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
        int i1 = 0;
        for (rit1 = myvector1.rbegin(); rit1 != myvector1.rend(); ++rit1)
            *rit1 = ++i1;
        std::cout << "myvector contains:";
        for (NS::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); ++it1)
            std::cout << ' ' << *it1;
        std::cout << '\n';
    }

    // NOTE - Return size
    {
        std::cout << "------------- Library FT (size)-------------" << std::endl;
        NS::vector<int> myints1;
        std::cout << "0. size: " << myints1.size() << '\n';
        for (int i = 0; i < 10; i++)
            myints1.push_back(i);
        std::cout << "1. size: " << myints1.size() << '\n';
        myints1.insert(myints1.end(), 10, 100);
        std::cout << "2. size: " << myints1.size() << '\n';
        myints1.pop_back();
        std::cout << "3. size: " << myints1.size() << '\n';
    }

    // NOTE - Return maximum size
    {
        std::cout << "------------- Library FT (maximum size)-------------" << std::endl;
        NS::vector<int> myvector1;
        for (int i = 0; i < 100; i++)
            myvector1.push_back(i);
        std::cout << "size: " << myvector1.size() << "\n";
        std::cout << "capacity: " << myvector1.capacity() << "\n";
        std::cout << "max_size: " << myvector1.max_size() << "\n";
    }

    // NOTE - Change size
    {
        std::cout << "------------- Library FT (resize)-------------" << std::endl;
        NS::vector<int> myvector1;
        for (int i = 1; i < 10; i++)
            myvector1.push_back(i);
        myvector1.resize(5);
        myvector1.resize(8, 100);
        myvector1.resize(12);
        std::cout << "myvector contains:";
        for (size_t i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
    }

    // NOTE - Return size of allocated storage capacity
    {
        std::cout << "------------- Library FT (Return size of allocated storage capacity)-------------" << std::endl;
        NS::vector<int> myvector1;
        for (int i = 0; i < 100; i++)
            myvector1.push_back(i);
        std::cout << "size: " << (int)myvector1.size() << '\n';
        std::cout << "capacity: " << (int)myvector1.capacity() << '\n';
        std::cout << "max_size: " << (int)myvector1.max_size() << '\n';
    }

    // NOTE - Test whether vector is empty
    {
        std::cout << "------------- Library FT (Test whether vector is empty)-------------" << std::endl;
        NS::vector<int> myvector1;
        int sum1(0);
        for (int i = 1; i <= 10; i++)
            myvector1.push_back(i);
        while (!myvector1.empty())
        {
            sum1 += myvector1.back();
            myvector1.pop_back();
        }
        std::cout << "total: " << sum1 << '\n';
    }

    // NOTE - Request a change in capacity
    {
        std::cout << "------------- Library FT (Request a change in capacity)-------------" << std::endl;
        NS::vector<int>::size_type sz1;
        NS::vector<int> foo1;
        sz1 = foo1.capacity();
        std::cout << "making foo grow:\n";
        for (int i = 0; i < 100; ++i)
        {
            foo1.push_back(i);
            if (sz1 != foo1.capacity())
            {
                sz1 = foo1.capacity();
                std::cout << "capacity changed: " << sz1 << '\n';
            }
        }
        NS::vector<int> bar1;
        sz1 = bar1.capacity();
        bar1.reserve(100); // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i = 0; i < 100; ++i)
        {
            bar1.push_back(i);
            if (sz1 != bar1.capacity())
            {
                sz1 = bar1.capacity();
                std::cout << "capacity changed: " << sz1 << '\n';
            }
        }
    }

    // NOTE - Access element
    {
        std::cout << "------------- Library FT (Access element)-------------" << std::endl;
        NS::vector<int> myvector1(10);
        NS::vector<int>::size_type sz1 = myvector1.size();
        for (unsigned i = 0; i < sz1; i++)
            myvector1[i] = i;
        for (unsigned i = 0; i < sz1 / 2; i++)
        {
            int temp1;
            temp1 = myvector1[sz1 - 1 - i];
            myvector1[sz1 - 1 - i] = myvector1[i];
            myvector1[i] = temp1;
        }
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < sz1; i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
    }

    // NOTE - Access element
    {
        std::cout << "------------- Library FT (Access element)-------------" << std::endl;
        NS::vector<int> myvector1(10);
        for (unsigned i = 0; i < myvector1.size(); i++)
            myvector1.at(i) = i;
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1.at(i);
        std::cout << '\n';
    }

    // NOTE - Access first element
    {
        std::cout << "------------- Library FT (Access first element)-------------" << std::endl;
        NS::vector<int> myvector1;
        myvector1.push_back(78);
        myvector1.push_back(16);
        myvector1.front() -= myvector1.back();
        std::cout << "myvector.front() is now " << myvector1.front() << '\n';
    }
    // NOTE - Access last element
    {
        std::cout << "------------- Library FT (Access last element)-------------" << std::endl;
        NS::vector<int> myvector1;
        myvector1.push_back(10);
        while (myvector1.back() != 0)
        {
            myvector1.push_back(myvector1.back() - 1);
        }
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
    }

    // NOTE - Assign vector content
    {
        std::cout << "------------- Library FT (Assign vector content)-------------" << std::endl;
        NS::vector<int> first1;
        NS::vector<int> second1;
        NS::vector<int> third1;
        first1.assign(7, 100);
        NS::vector<int>::iterator it1;
        it1 = first1.begin() + 1;
        second1.assign(it1, first1.end() - 1);
        int myints1[] = {1776, 7, 4};
        third1.assign(myints1, myints1 + 3);
        std::cout << "Size of first: " << int(first1.size()) << '\n';
        std::cout << "Size of second: " << int(second1.size()) << '\n';
        std::cout << "Size of third: " << int(third1.size()) << '\n';
    }

    // NOTE - Add element at the end
    {
        std::cout << "------------- Library FT (Add element at the end)-------------" << std::endl;
        NS::vector<int> myvector1;
        int myint1;
        std::cout << "Please enter some integers (enter 0 to end):\n";
        do
        {
            std::cin >> myint1;
            myvector1.push_back(myint1);
        } while (myint1);
        std::cout << "myvector stores " << int(myvector1.size()) << " numbers.\n";
    }

    // NOTE - Delete last element
    {
        std::cout << "------------- Library FT (Delete last element)-------------" << std::endl;
        NS::vector<int> myvector1;
        int sum1(0);
        myvector1.push_back(100);
        myvector1.push_back(200);
        myvector1.push_back(300);
        while (!myvector1.empty())
        {
            sum1 += myvector1.back();
            myvector1.pop_back();
        }
        std::cout << "The elements of myvector add up to " << sum1 << '\n';
    }
    // NOTE - Clear content
    {
        std::cout << "------------- Library FT (Clear content)-------------" << std::endl;
        NS::vector<int> myvector1;
        myvector1.push_back(100);
        myvector1.push_back(200);
        myvector1.push_back(300);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.clear();
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.push_back(1101);
        myvector1.push_back(2202);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
    }

    // NOTE - Insert elements
    {
        std::cout << "------------- Library FT (Insert elements)-------------" << std::endl;
        NS::vector<int> myvector1(3, 100);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        NS::vector<int>::iterator it1;
        it1 = myvector1.begin();
        it1 = myvector1.insert(it1, 200);
        myvector1.insert(it1, 2, 300);
        it1 = myvector1.begin();
        NS::vector<int> anothervector1(2, 400);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.insert(it1 + 2, anothervector1.begin(), anothervector1.end());
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        int myarray1[] = {501, 502, 503};
        myvector1.insert(myvector1.begin(), myarray1, myarray1 + 3);
        std::cout << "myvector contains:";
        for (it1 = myvector1.begin(); it1 < myvector1.end(); it1++)
            std::cout << ' ' << *it1;
        std::cout << '\n';
    }
    {
        NS::vector<int> vec1;
        vec1.push_back(10);
        vec1.push_back(20);
        vec1.push_back(30);
        vec1.push_back(40);
        NS::vector<int>::iterator it1 = vec1.insert(vec1.begin(), 3);
        vec1.insert(it1, 2);
        int i1 = 2;
        it1 = vec1.insert(vec1.begin() + i1, 7);
        std::cout << "The vector elements are: ";
        for (NS::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
            std::cout << *it1 << " ";
        std::cout << std::endl;
    }

    // NOTE - Erase elements
    {
        std::cout << "------------- Library FT (Erase elements)-------------" << std::endl;
        NS::vector<int> myvector;
        // set some values (from 1 to 10)
        for (int i = 1; i <= 10; i++)
            myvector.push_back(i);
        // erase the 6th element
        myvector.erase(myvector.begin() + 5);
        // erase the first 3 elements:
        myvector.erase(myvector.begin(), myvector.begin() + 3);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }

    // NOTE - Swap content
    {
        std::cout << "------------- Library FT (Swap content)-------------" << std::endl;
        NS::vector<int> foo1(3, 100); // three ints with a value of 100
        NS::vector<int> bar1(5, 200); // five ints with a value of 200
        std::cout << "Size foo1 before " << foo1.size() << std::endl;
        std::cout << "Capa foo1 before " << foo1.capacity() << std::endl;
        std::cout << "Size bar1 before " << bar1.size() << std::endl;
        std::cout << "Capa bar1 before " << bar1.capacity() << std::endl;
        foo1.swap(bar1);
        std::cout << "Size foo1 after " << foo1.size() << std::endl;
        std::cout << "Capa foo1 after " << foo1.capacity() << std::endl;
        std::cout << "Size bar1 after " << bar1.size() << std::endl;
        std::cout << "Capa bar1 after " << bar1.capacity() << std::endl;
        std::cout << "foo contains:";
        for (unsigned i = 0; i < foo1.size(); i++)
            std::cout << ' ' << foo1[i];
        std::cout << '\n';
        std::cout << "bar contains:";
        for (unsigned i = 0; i < bar1.size(); i++)
            std::cout << ' ' << bar1[i];
        std::cout << '\n';
    }

    // // NOTE - Get allocator
    {
        std::cout << "------------- Library FT (Get allocator)-------------" << std::endl;
        NS::vector<int> myvector;
        int *p;
        unsigned int i;
        p = myvector.get_allocator().allocate(5);
        for (i = 0; i < 5; i++)
            myvector.get_allocator().construct(&p[i], i);
        std::cout << "The allocated array contains:";
        for (i = 0; i < 5; i++)
            std::cout << ' ' << p[i];
        std::cout << '\n';
        for (i = 0; i < 5; i++)
            myvector.get_allocator().destroy(&p[i]);
        myvector.get_allocator().deallocate(p, 5);
    }
	
    // // NOTE - Relational operators for vector
    {
        std::cout << "------------- Library FT (Relational operators for vector)-------------" << std::endl;
        NS::vector<int> foo(2, 200);
        NS::vector<int> bar;
        bar.push_back(200);
        bar.push_back(200);
        bar.push_back(300);
        bar.push_back(400);
        if (foo == bar)
            std::cout << "foo and bar are equal\n";
        if (foo != bar)
            std::cout << "foo and bar are not equal\n";
        if (foo < bar)
            std::cout << "foo is less than bar\n";
        if (foo > bar)
            std::cout << "foo is greater than bar\n";
        if (foo <= bar)
            std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar)
            std::cout << "foo is greater than or equal to bar\n";
    }
	
    // // NOTE - Exchange contents of vectors
    {
        std::cout << "------------- Library FT (Exchange contents of vectors)-------------" << std::endl;
        NS::vector<int> foo(3, 100); // three ints with a value of 100
        NS::vector<int> bar(5, 200); // five ints with a value of 200
        NS::swap(foo, bar);
        std::cout << "foo contains:";
        for (NS::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "bar contains:";
        for (NS::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    std::cout << "*************************************************************************" << std::endl;
    std::cout << "\t\t\t\tStack" << std::endl;
    std::cout << "*************************************************************************" << std::endl;

    // NOTE - NS::stack::stack
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::vector<int> myvector (2,200);        // vector with 2 elements
        NS::stack<int> first;                    // empty stack
        NS::stack<int,NS::vector<int> > third;  // empty stack using vector
        NS::stack<int,NS::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }
    // // NOTE - NS::stack::empty
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int> mystack;
        int sum(0);
        for (int i = 1; i <= 10; i++)
            mystack.push(i);
        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }
        std::cout << "total: " << sum << '\n';
    }

    // // NOTE - NS::stack::size
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';
        for (int i = 0; i < 5; i++)
            myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';
        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }

    // // NOTE - NS::stack::top
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int> mystack;
        mystack.push(10);
        mystack.push(20);
        mystack.top() -= 5;
        std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }

    // // NOTE - NS::stack::push
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int> mystack;
        for (int i = 0; i < 5; ++i)
            mystack.push(i);
        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }

    // // NOTE - NS::stack::pop
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int> mystack;
        for (int i = 0; i < 5; ++i)
            mystack.push(i);
        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }

    // // NOTE - operator==
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int, NS::vector<int> > s1, s2, s3;
        s1.push(1);
        s2.push(2);
        s3.push(1);

        if (s1 == s2)
            std::cout << "The stacks s1 and s2 are equal." << std::endl;
        else
            std::cout << "The stacks s1 and s2 are not equal." << std::endl;

        if (s1 == s3)
            std::cout << "The stacks s1 and s3 are equal." << std::endl;
        else
            std::cout << "The stacks s1 and s3 are not equal." << std::endl;
    }

    // // NOTE - operator!=
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int, NS::vector<int> > s1, s2, s3;
        s1.push(1);
        s2.push(2);
        s3.push(1);
        if (s1 != s2)
            std::cout << "The stacks s1 and s2 are not equal." << std::endl;
        else
            std::cout << "The stacks s1 and s2 are equal." << std::endl;
        if (s1 != s3)
            std::cout << "The stacks s1 and s3 are not equal." << std::endl;
        else
            std::cout << "The stacks s1 and s3 are equal." << std::endl;
    }

    // // NOTE - operator<
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int, NS::vector<int> > s1, s2, s3;
        s1.push(2);
        s1.push(4);
        s1.push(6);
        s1.push(8);
        s2.push(5);
        s2.push(10);
        s3.push(2);
        s3.push(4);
        s3.push(6);
        s3.push(8);
        if (s1 < s2)
            std::cout << "The stack s1 is less than "
                      << "the stack s2." << std::endl;
        else
            std::cout << "The stack s1 is greater than or equal to "
                      << "the stack s2." << std::endl;

        if (s1 < s3)
            std::cout << "The stack s1 is less than "
                      << "the stack s3." << std::endl;
        else
            std::cout << "The stack s1 is greater than to "
                      << "the stack s3." << std::endl;
        NS::stack<int>::size_type i_size_s1 = s1.size();
        std::cout << "The stack s1 from the top down is: ( ";
        unsigned int i;
        for (i = 1; i <= i_size_s1; i++)
        {
            std::cout << s1.top() << " ";
            s1.pop();
        }
        std::cout << ")." << std::endl;
    }

    // // NOTE - operator<=
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int> s1, s2, s3;
        s1.push(5);
        s1.push(10);
        s2.push(1);
        s2.push(2);
        s3.push(5);
        s3.push(10);
        if (s1 <= s2)
            std::cout << "The stack s1 is less than or equal to "
                      << "the stack s2." << std::endl;
        else
            std::cout << "The stack s1 is greater than "
                      << "the stack s2." << std::endl;

        if (s1 <= s3)
            std::cout << "The stack s1 is less than or equal to "
                      << "the stack s3." << std::endl;
        else
            std::cout << "The stack s1 is greater than "
                      << "the stack s3." << std::endl;
    }

    // // NOTE - operator>
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int, NS::vector<int> > s1, s2, s3;
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s2.push(5);
        s2.push(10);
        s3.push(1);
        s3.push(2);
        if (s1 > s2)
            std::cout << "The stack s1 is greater than "
                      << "the stack s2." << std::endl;
        else
            std::cout << "The stack s1 is not greater than "
                      << "the stack s2." << std::endl;

        if (s1 > s3)
            std::cout << "The stack s1 is greater than "
                      << "the stack s3." << std::endl;
        else
            std::cout << "The stack s1 is not greater than "
                      << "the stack s3." << std::endl;
    }

    // // NOTE - operator>=
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::stack<int, NS::vector<int> > s1, s2, s3;
        s1.push(1);
        s1.push(2);
        s2.push(5);
        s2.push(10);
        s3.push(1);
        s3.push(2);
        if (s1 >= s2)
            std::cout << "The stack s1 is greater than or equal to "
                      << "the stack s2." << std::endl;
        else
            std::cout << "The stack s1 is less than "
                      << "the stack s2." << std::endl;

        if (s1 >= s3)
            std::cout << "The stack s1 is greater than or equal to "
                      << "the stack s3." << std::endl;
        else
            std::cout << "The stack s1 is less than "
                      << "the stack s3." << std::endl;
    }

    std::cout << "*************************************************************************" << std::endl;
    std::cout << "\t\t\t\tMap" << std::endl;
    std::cout << "*************************************************************************" << std::endl;

    // NOTE - Construct pair
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::pair<std::string, double> product1;
        NS::pair<std::string, double> product2("tomatoes", 2.30);
        NS::pair<std::string, double> product3(product2);
        product1 = NS::make_pair(std::string("lightbulbs"), 0.99); // using make_pair (move)
        product2.first = "shoes";
        product2.second = 39.90;
        std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
        std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
        std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    }

    // NOTE - pair::operator= example
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::pair<std::string, int> planet("Earth", 6371), homeplanet;
        planet = NS::make_pair("Earth", 6371);
        homeplanet = planet;
        std::cout << "Home planet: " << homeplanet.first << '\n';
        std::cout << "Planet size: " << homeplanet.second << '\n';
    }

    // NOTE - make_pair example
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::pair<int, int> foo;
        NS::pair<int, int> bar;
        foo = NS::make_pair(10, 20);
        bar = NS::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>
        std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
        std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    }

    // NOTE - Relational operators for pair
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::pair<int, char> foo(10, 'z');
        NS::pair<int, char> bar(90, 'a');
        if (foo == bar)
            std::cout << "foo and bar are equal\n";
        if (foo != bar)
            std::cout << "foo and bar are not equal\n";
        if (foo < bar)
            std::cout << "foo is less than bar\n";
        if (foo > bar)
            std::cout << "foo is greater than bar\n";
        if (foo <= bar)
            std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar)
            std::cout << "foo is greater than or equal to bar\n";
    }

    // NOTE - Construct map
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> first;
        first['a'] = 10;
        first['b'] = 30;
        first['c'] = 50;
        first['d'] = 70;
        NS::map<char, int> second(first.begin(), first.end());
        for (NS::map<char, int>::iterator i = second.begin(); i != second.end(); i++)
        {
            std::cout << i->first << "\t" << i->second << std::endl;
        }
    }

    // NOTE - Access element
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, std::string> mymap;
        mymap['a'] = "an element";
        mymap['b'] = "another element";
        mymap['c'] = mymap['b'];
        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';
        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }

    // NOTE - Test whether container is empty
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }

    // NOTE - Return maximum size
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        int i;
        NS::map<int, int> mymap;
        if (mymap.max_size() > 1000)
        {
            for (i = 0; i < 1000; i++)
                mymap[i] = i;
            std::cout << "The map contains 1000 elements.\n";
        }
        std::cout << mymap.max_size() << std::endl;
    }

    // NOTE - Insert elements
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        // first insert function version (single parameter):
        NS::map<char, int> mymap;
        mymap.insert(NS::pair<char, int>('a', 100));
        mymap.insert(NS::pair<char, int>('z', 200));
        NS::pair<NS::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(NS::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }
        std::cout << mymap.size() << std::endl;
        // second insert function version (with hint position):
        NS::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, NS::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, NS::pair<char, int>('c', 400));
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        // third insert function version (range insertion):
        NS::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.end());
        for (NS::map<char, int>::iterator i = anothermap.begin(); i != anothermap.end(); i++)
        {
            std::cout << i->first << "\t" << i->second << std::endl;
        }
    }

    // NOTE - Clear content
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> mymap;
        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;
        std::cout << "mymap contains:\n";
        for (NS::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;
        std::cout << "mymap contains:\n";
        for (NS::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    // NOTE - Assignement Operator (new_map = old_map)
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> first;
        NS::map<char, int> second;
        first['x'] = 8;
        first['y'] = 16;
        first['z'] = 32;
        second = first;               // second now contains 3 ints
        first = NS::map<char, int>(); // and first is now empty
        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }

    // NOTE - Erase elements
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> mymap;
        // insert some values:
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;
        NS::map<char, int>::iterator it = mymap.begin();
        it = mymap.find('b');
        mymap.erase(it);  // erasing by iterator
        mymap.erase('c'); // erasing by key
        it = mymap.find('e');
        mymap.erase(it, mymap.end()); // erasing by range
        // show content:
        for (it = mymap.begin(); it != mymap.end(); ++it)
        {
            std::cout << it->first << " => " << it->second << '\n';
        }
    }

    // NOTE - Swap content
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> foo, bar;
        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;
        foo.swap(bar);
        std::cout << "foo contains:\n";
        for (NS::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
        {
            std::cout << it->first << " => " << it->second << '\n';
        }
        std::cout << "bar contains:\n";
        for (NS::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    // NOTE - Return key comparison object
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> mymap;
        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300;
        std::cout << "mymap contains:\n";
        char highest = mymap.rbegin()->first; // key value of last element
        NS::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.key_comp()((*it++).first, highest));
        std::cout << '\n';
    }
	
    // NOTE - Return value comparison object
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int, std::greater<char> > mymap;
        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;
        std::cout << "mymap contains:\n";
        NS::pair<char, int> highest = *mymap.rbegin(); // last element
        NS::map<char, int, std::greater<char> >::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }
	
    // NOTE - Get iterator to element
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> mymap;
        NS::map<char, int>::iterator it;
        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;
        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);
        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }

    // NOTE - Count elements with a specific key
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        char c;
        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;
        for (c = 'a'; c < 'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }

    // NOTE - Return iterator to lower bound
    // NOTE - Return iterator to upper bound
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> mymap;
        NS::map<char, int>::iterator itlow, itup;
        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;
        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)
        mymap.erase(itlow, itup);       // erases [itlow,itup)
        // print content:
        for (NS::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    // NOTE - Get range of equal elements
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        NS::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        NS::pair<NS::map<char, int>::iterator, NS::map<char, int>::iterator> ret;
        ret = mymap.equal_range('b');
        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';
        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }

    // NOTE - Get allocator
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        int psize;
        NS::map<char, int> mymap;
        NS::pair<const char, int> *p;
        // allocate an array of 5 elements using mymap's allocator:
        p = mymap.get_allocator().allocate(5);
        // assign some values to array
        psize = sizeof(NS::map<char, int>::value_type) * 5;
        std::cout << "The allocated array has a size of " << psize << " bytes.\n";
        mymap.get_allocator().deallocate(p, 5);

        NS::map<int, std::string> m;
        m.insert(NS::make_pair(1, "younes"));
        m.insert(NS::make_pair(2, "choaib"));
        m.insert(NS::make_pair(3, "abdelah"));
        NS::map<int, std::string>::iterator it = m.begin();
        m[3] = "hatim";
        for (; it != m.end(); it++)
        {
            std::cout << it->first << "\t" << it->second << std::endl;
        }
    }
}
