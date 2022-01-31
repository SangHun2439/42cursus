/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:35:11 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/31 21:31:08 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

void	replace(std::string &str, char *s1, char *s2)
{
	std::string::size_type	start;
	std::string::size_type	end;
	int						s1_len;
	std::string				tmp;

	s1_len = strlen(s1);
	start = 0;
	while ((end = str.find(s1, start)) != std::string::npos)
	{
		tmp += str.substr(start, end - start);
		tmp += s2;
		start = end + s1_len;
	}
	str = tmp + str.substr(start);
}

int	rrw(char *filename, char *s1, char *s2)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		str;

	str = filename;
	ifs.open(filename);
	str += ".replace";
	ofs.open(str);
	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "file open fail" << std::endl;
		return (0);
	}
	while (std::getline(ifs, str))
	{
		replace(str, s1, s2);
		ofs << str;
		if (!ifs.eof())
			ofs << std::endl;
		else
			ofs << std::flush;
	}
	ifs.close();
	ofs.close();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong arguments" << std::endl;
		return (0);
	}
	if (!*(argv[2]) || !*(argv[3]))
	{
		std::cout << "cannot handle empty string" << std::endl;
		return (0);
	}
	return (rrw(argv[1], argv[2], argv[3]));
}
