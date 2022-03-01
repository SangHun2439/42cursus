/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:58:29 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/01 23:02:56 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private:
		const unsigned int	size;
		std::vector<int>	arr;
	public:
		Span();
		Span(const unsigned int& size);
		Span(const Span& src);
		~Span();
		Span&	operator=(const Span& src);

		void			addNumber(int a);
		template <typename T>
		void			addNumber(T f, T e)
		{
			unsigned int		i;

			i = 0;
			arr.clear();
			while (f != e)
			{
				arr.push_back(*f);
				if (i == size)
					throw Span::OutOfRange();
				f++;
				i++;
			}
		}
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class OutOfRange:public std::exception
		{
			const char*	what() const _NOEXCEPT;
		};
		class ImpossbleSpan:public std::exception
		{
			const char*	what() const _NOEXCEPT;
		};
};


#endif
