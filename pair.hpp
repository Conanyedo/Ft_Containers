/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:58:32 by ybouddou          #+#    #+#             */
/*   Updated: 2022/04/17 23:25:18 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		//SECTION - MEMBER TYPES
		typedef	T1		first_type;
		typedef	T2		second_type;
		
		first_type		first;
		second_type		second;
		
		//SECTION - MEMBER FUNCTIONS
		pair() : first(), second() {}
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}
		pair& operator= (const pair& pr)
		{
			if (this == &pr)
				return (*this);
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};
	//SECTION - NON MEMBER FUNCTION OVERLOADS
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ 
		return (lhs.first == rhs.first) && (lhs.second == rhs.second); 
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ 
		return !(lhs == rhs); 
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ 
		return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second); 
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ 
		return !(rhs < lhs); 
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ 
		return rhs < lhs; 
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ 
		return !(lhs < rhs); 
	}
	
	//SECTION - MAKE PAIR
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

# endif