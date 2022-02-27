/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:44:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 20:47:37 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base() {};
};

class A:public Base {};

class B:public Base {};

class C:public Base {};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
