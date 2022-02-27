/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:29:12 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 20:35:39 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <iostream>

int main()
{
	Data*	data_origin;
	Data*	data_deserialize;
	uintptr_t	uint_ptr_val;

	data_origin = new Data;
	data_origin->c = 'a';
	data_origin->i = -1234;
	data_origin->str = static_cast<std::string>("hello");

	uint_ptr_val = serialize(data_origin);
	data_deserialize = deserialize(uint_ptr_val);

	std::cout << "Data origin ptr value : " << data_origin << '\n';
	std::cout << "Data serialize uintptr_t value : " <<uint_ptr_val << '\n';
	std::cout << "Data deserialize ptr value : " << data_deserialize << std::endl;
	delete data_origin;
	return (0);
}
