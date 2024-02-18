/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:53 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/07 13:12:56 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "Easyfind.hpp"

int	main(void)
{
	{
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::vector<int>			v;
		std::vector<int>::iterator	it;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(2147483647);
		it = v.begin();
		*it = 88;
		v.insert(it, 199);
		for (std::vector<int>::iterator __it = v.begin(); __it != v.end(); __it++)
			std::cout << *__it << std::endl;
		it = easyfind(v, 5);
		if (it != v.end())
			std::cout << "value: " << *it << std::endl;
		it = easyfind(v, 56);
		if (it != v.end())
			std::cout << "value: " << *it << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
	}
	{
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::list<int>				lst;
		std::list<int>::iterator	it;

		lst.push_back(2147483647);
		lst.push_back(2147483648);
		lst.push_back(2147483649);
		lst.push_back(2147483650);
		lst.push_back(2147483651);
		lst.push_back(2147483652);
		lst.push_back(2147483653);
		for (std::list<int>::iterator __it = lst.begin(); __it != lst.end(); __it++)
			std::cout << *__it << std::endl;
		it = easyfind(lst, -2147483647);
		if (it != lst.end())
			std::cout << "value: " << *it << std::endl;
		it = easyfind(lst, 2147483655);
		if (it != lst.end())
			std::cout << "value: " << *it << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
	}
	return (0);
}