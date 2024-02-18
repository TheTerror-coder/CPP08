/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:53 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/18 20:44:58 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stack>

void	myTests(MutantStack<int>* container);
void	myTests(std::list<int>* container);

int	main(void)
{
	MutantStack<int>		_stack;
	std::list<int>			_list;

	_stack.push(100);
	_stack.push(200);
	_stack.push(300);
	_stack.push(400);
	_stack.push(500);

	_list.push_back(100);
	_list.push_back(200);
	_list.push_back(300);
	_list.push_back(400);
	_list.push_back(500);

	myTests(&_stack);
	myTests(&_list);

	return (0);
}

void	myTests(MutantStack<int>* container)
{
	std::cout << "\n**********************Displaying the containerck**********************" << std::endl;
	{
		MutantStack<int>::iterator	it = container->begin();
		for (size_t len = container->size(); len; len--)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the containerck from begin() to end() with an iterator**********************" << std::endl;
	{
		for (MutantStack<int>::iterator	it = container->begin(); it != container->end(); it++)
			std::cout << *it << " ";
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the containerck from begin() to end() with offset operator [] **********************" << std::endl;
	{
		MutantStack<int>::iterator	it = container->begin();
	
		for (size_t index = 0; index < container->size(); index++)
			std::cout << it[index] << " ";
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************testing Inc/Dec operators -- ++**********************" << std::endl;
	{
		MutantStack<int>::iterator	it1 = container->begin();
		MutantStack<int>::iterator	it2 = container->end();

		std::cout << "value: " << *it1 << std::endl;
		std::cout << "value: " << *(it1++) << std::endl;
		std::cout << "value: " << *it1 << std::endl;
		std::cout << "value: " << *(++it1) << std::endl;
		std::cout << "value: " << *it2 << std::endl;
		std::cout << "value: " << *(--it2) << std::endl;
		std::cout << "value: " << *(it2--) << std::endl;
		std::cout << "value: " << *it2 << std::endl;
	}

	std::cout << "\n**********************testing arithmetic operators - + -= += **********************" << std::endl;
	{
		MutantStack<int>::iterator	it = container->begin();
	
		std::cout << "size(): " << container->size() << std::endl;
		std::cout << "end() - begin(): " << container->end() - container->begin() << std::endl;

		std::cout << "value: " << *(it = it + 3) << std::endl;
		std::cout << "value: " << *(it - 3) << std::endl;
		std::cout << "value: " << *(it + 1) << std::endl;
		std::cout << "value: " << *(it -= 3) << std::endl;
		std::cout << "value: " << *it << std::endl;
		std::cout << "value: " << *(it += 1) << std::endl;
	}
	
	std::cout << "\n**********************testing comparison operators **********************" << std::endl;
	{
		MutantStack<int>::iterator	it1 = container->begin();
		MutantStack<int>::iterator	it2 = container->begin();

		if (it1 == it2)
			std::cout << "it1 is equal to it2" << std::endl;
		if (it1 >= it2)
			std::cout << "it1 is equal to it2" << std::endl;
		if (it1 <= it2)
			std::cout << "it1 is equal to it2" << std::endl;
		
		it2 = container->end();
		if (it1 != it2)
			std::cout << "it1 is different from it2" << std::endl;
		if (it1 < it2)
			std::cout << "it1 is inferior to it2" << std::endl;
		if (container->end() > container->begin())
			std::cout << "end() is superior to begin()" << std::endl;
		if (it1 <= it2)
			std::cout << "it1 is inferior to it2" << std::endl;
		if (container->end() >= container->begin())
			std::cout << "end() is superior to begin()" << std::endl;
	}
}

void	myTests(std::list<int>* container)
{
	std::cout << "\n**********************Displaying the containerck**********************" << std::endl;
	{
		std::list<int>::iterator	it = container->begin();
		for (size_t len = container->size(); len; len--)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the containerck from begin() to end() with an iterator**********************" << std::endl;
	{
		for (std::list<int>::iterator	it = container->begin(); it != container->end(); it++)
			std::cout << *it << " ";
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the containerck from begin() to end() with offset operator [] **********************" << std::endl;
	{
		// std::list<int>::iterator	it = container->begin();
	
		// for (size_t index = 0; index < container->size(); index++)
		// 	std::cout << it[index] << " ";
		// std::cout  << std::endl;
	}
	
	std::cout << "\n**********************testing Inc/Dec operators -- ++**********************" << std::endl;
	{
		std::list<int>::iterator	it1 = container->begin();
		std::list<int>::iterator	it2 = container->end();

		std::cout << "value: " << *it1 << std::endl;
		std::cout << "value: " << *(it1++) << std::endl;
		std::cout << "value: " << *it1 << std::endl;
		std::cout << "value: " << *(++it1) << std::endl;
		std::cout << "value: " << *it2 << std::endl;
		std::cout << "value: " << *(--it2) << std::endl;
		std::cout << "value: " << *(it2--) << std::endl;
		std::cout << "value: " << *it2 << std::endl;
	}

	std::cout << "\n**********************testing arithmetic operators - + -= += **********************" << std::endl;
	// {
	// 	std::list<int>::iterator	it = container->begin();
	
	// 	std::cout << "size(): " << container->size() << std::endl;
	// 	std::cout << "end() - begin(): " << container->end() - container->begin() << std::endl;

	// 	std::cout << "value: " << *(it = it + 3) << std::endl;
	// 	std::cout << "value: " << *(it - 3) << std::endl;
	// 	std::cout << "value: " << *(it + 1) << std::endl;
	// 	std::cout << "value: " << *(it -= 3) << std::endl;
	// 	std::cout << "value: " << *it << std::endl;
	// 	std::cout << "value: " << *(it += 1) << std::endl;
	// }
	
	std::cout << "\n**********************testing comparison operators **********************" << std::endl;
	{
		std::list<int>::iterator	it1 = container->begin();
		std::list<int>::iterator	it2 = container->begin();

		if (it1 == it2)
			std::cout << "it1 is equal to it2" << std::endl;
		// if (it1 >= it2)
		// 	std::cout << "it1 is equal to it2" << std::endl;
		// if (it1 <= it2)
		// 	std::cout << "it1 is equal to it2" << std::endl;
		
		// it2 = container->end();
		// if (it1 != it2)
		// 	std::cout << "it1 is different from it2" << std::endl;
		// if (it1 < it2)
		// 	std::cout << "it1 is inferior to it2" << std::endl;
		// if (container->end() > container->begin())
		// 	std::cout << "end() is superior to begin()" << std::endl;
		// if (it1 <= it2)
		// 	std::cout << "it1 is inferior to it2" << std::endl;
		// if (container->end() >= container->begin())
		// 	std::cout << "end() is superior to begin()" << std::endl;
	}
}

