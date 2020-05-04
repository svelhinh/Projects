/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 19:00:25 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/05 19:54:54 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4 || !av[2][0] || !av[3][0])
		return 0;
	std::string		filename = av[1], s1 = av[2], s2 = av[3], buf;
	std::ifstream	ifs(filename);
	std::ofstream	ofs(filename + ".replace");
	std::ostringstream ss;

	ss << ifs.rdbuf();
	buf = ss.str();

	if(!buf.empty())
	{
        for(size_t pos = 0; (pos = buf.find(s1, pos)) != std::string::npos; pos += s2.size())
            buf.replace(pos, s1.size(), s2);
	}
	ofs << buf;
	return 0;
}
