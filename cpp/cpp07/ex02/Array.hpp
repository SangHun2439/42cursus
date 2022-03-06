/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:05:12 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/06 19:28:49 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		T*				arr;
		unsigned int	len;
	public:
		Array():arr(new T[0]), len(0) {};
		Array(unsigned int n):arr(new T[n]), len(n) {};
		Array(const Array& src):arr(new T[src.len]), len(src.len)
		{
			for (unsigned int i = 0; i < len; i++)
				arr[i] = src[i];
		};
		~Array() {delete[] arr;};
		Array&	operator=(const Array& src)
		{
			len = src.size();
			delete[] arr;
			arr = new T[len];
			for (unsigned int i = 0; i < len; i++)
				arr[i] = src[i];
		};
		T&		operator[](unsigned int idx) const
		{
			if (idx >= this->len)
				throw OutOfRange();
			return (arr[idx]);
		};
		unsigned int	size() const
		{
			return (len);
		};

		class OutOfRange: public std::exception
		{
			public:
				const char*	what() const _NOEXCEPT;
		};
};

template <typename T>
const char*	Array<T>::OutOfRange::what( void ) const _NOEXCEPT
{
	return ("Out of range Exception");
}


#endif
