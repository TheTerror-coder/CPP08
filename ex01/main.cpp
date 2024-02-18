/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:53 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/07 19:28:47 by TheTerror        ###   ########lyon.fr   */
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
		std::vector<int>	range;

		// srand(std::time(NULL));
		for (size_t i = 0; i < 100000; i++)
			range.push_back(rand());
		try
		{
			sp.addRange(range.begin(), range.end());
			// sp.addNumber(10);
			// sp.addNumber(10);
			// sp.displayStore();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "--------------------------------------------------------------" << std::endl;
	}
	return (0);
}