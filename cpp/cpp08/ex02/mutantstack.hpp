/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:07:45 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/02 01:31:18 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>
# include <iterator>

template <typename T>
class MutantStack:public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack& src): std::stack<T>(src) {};
		~MutantStack() {};
		MutantStack&	operator=(const MutantStack& src)
		{
			if (this == &src)
				return (*this);
			std::stack<T>::operator=(src);
			return (*this);
		};
		typedef	typename std::stack<T>::container_type::iterator iterator;
		typedef	typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef	typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator	begin()
		{
			return (std::stack<T>::c.begin());
		};
		iterator	end()
		{
			return (std::stack<T>::c.end());
		};

		const_iterator	cbegin()
		{
			return (std::stack<T>::c.cbegin());
		}
		const_iterator	cend()
		{
			return (std::stack<T>::c.cend());
		}

		reverse_iterator	rbegin()
		{
			return (std::stack<T>::c.rbegin());
		}
		reverse_iterator	rend()
		{
			return (std::stack<T>::c.rbegin());
		}
};

#endif
