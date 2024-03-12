/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:53 by TheTerror         #+#    #+#             */
/*   Updated: 2024/03/12 16:07:27 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <experimental/random>
#include "Span.hpp"

int	main(void)
{
	{
		std::cout << "--------------------------------------------------------------" << std::endl;
		Span sp = Span(5);
		Span void_span = Span(1);
		
		try
		{
			void_span.addNumber(263);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(95);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		// sp.displayStore();
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << void_span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "--------------------------------------------------------------" << std::endl;
	}
	{
		std::cout << "--------------------------------------------------------------" << std::endl;
		Span 				sp = Span(200000);
		std::set<int>	range;

		srand(std::time(NULL));
		for (size_t i = 0; i < 300; i++)
			range.insert(rand());
		try
		{
			sp.addRange(range.begin(), range.end());
			sp.addNumber(2147483647);
			sp.addNumber(-2147483648);
			// sp.displayStore();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
	}
	return (0);
}