/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:10:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/02 14:12:47 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span():size(0) {}

Span::Span(const unsigned int& size):size(size) {}

Span::Span(const Span& src):size(src.size), arr(src.arr)
{
}

Span::~Span() {}

Span&	Span::operator=(const Span& src)
{
	if (this == &src)
		return (*this);
	static_cast<void>(src);
	return (*this);
}

void	Span::addNumber(int a)
{
	if (size == arr.size())
		throw Span::OutOfRange();
	arr.push_back(a);
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>	diff;

	if (arr.empty() || arr.size() == 1)
		throw Span::ImpossbleSpan();
	std::sort(arr.begin(), arr.end());
	for (std::vector<int>::iterator it = arr.begin(); it != arr.end() - 1; it++)
		diff.push_back(*(it + 1) - *it);
	std::sort(diff.begin(), diff.end());
	return (diff[0]);
}

unsigned int	Span::longestSpan()
{
	if (arr.empty() || arr.size() == 1)
		throw Span::ImpossbleSpan();
	std::sort(arr.begin(), arr.end());
	return (*(arr.end() - 1) - *(arr.begin()));
}

const char*	Span::OutOfRange::what() const _NOEXCEPT
{
	return ("Span exception: out of range");
}

const char*	Span::ImpossbleSpan::what() const _NOEXCEPT
{
	return ("Span exception: not enough value to span");
}
