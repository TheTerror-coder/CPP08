/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:53 by TheTerror         #+#    #+#             */
/*   Updated: 2024/03/12 18:03:00 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	myTests(MutantStack<int>* container);
void	myTests(std::list<int>* container);

int	main(void)
{

// GIVEN MAIN

	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		{
			std::stack<int> s(mstack);
		}
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n" << std::endl;

	{
		std::list<int> mlst;
		
		mlst.push_back(5);
		mlst.push_back(17);
		std::cout << mlst.back() << std::endl;
		mlst.pop_back();
		std::cout << mlst.size() << std::endl;
		mlst.push_back(3);
		mlst.push_back(5);
		mlst.push_back(737);
		//[...]
		mlst.push_back(0);
		std::list<int>::iterator it = mlst.begin();
		std::list<int>::iterator ite = mlst.end();
		++it;
		--it;
		{
			std::list<int> s(mlst);
		}
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

// MY TESTS

	// MutantStack<int>		_stack;
	// std::list<int>			_list;

	// _stack.push(100);
	// _stack.push(200);
	// _stack.push(300);
	// _stack.push(400);
	// _stack.push(500);

	// _list.push_back(100);
	// _list.push_back(200);
	// _list.push_back(300);
	// _list.push_back(400);
	// _list.push_back(500);

	// myTests(&_stack);
	// std::cout << "\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n" << std::endl;
	// myTests(&_list);

	return (0);
}

void	myTests(MutantStack<int>* container)
{
	std::cout << "\n**********************Displaying the container**********************" << std::endl;
	{
		MutantStack<int>::iterator	it = container->begin();
		for (size_t len = container->size(); len; len--)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the container from begin() to end() with an iterator**********************" << std::endl;
	{
		for (MutantStack<int>::iterator	it = container->begin(); it != container->end(); it++)
			std::cout << *it << " ";
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the container from begin() to end() with offset operator [] **********************" << std::endl;
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
	std::cout << "\n**********************Displaying the container**********************" << std::endl;
	{
		std::list<int>::iterator	it = container->begin();
		for (size_t len = container->size(); len; len--)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the container from begin() to end() with an iterator**********************" << std::endl;
	{
		for (std::list<int>::iterator	it = container->begin(); it != container->end(); it++)
			std::cout << *it << " ";
		std::cout  << std::endl;
	}
	
	std::cout << "\n**********************Displaying the container from begin() to end() with offset operator [] **********************" << std::endl;
	{
	
		for (size_t index = 0; index < container->size(); index++)
		{
			std::list<int>::iterator	it = container->begin();
			std::advance(it, index);
			std::cout << *it << " ";
		}
		std::cout  << std::endl;
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
	{
		std::list<int>::iterator	it = container->begin();
		std::list<int>::iterator	it_tmp;
	
		std::cout << "size(): " << container->size() << std::endl;
		std::cout << "end() - begin(): " << std::distance(container->begin(), container->end()) << std::endl;

		std::advance(it, 3);
		std::cout << "value: " << *it << std::endl;
		it_tmp = it;
		std::advance(it_tmp, -3);
		std::cout << "value: " << *it_tmp << std::endl;
		it_tmp = it;
		std::advance(it_tmp, 1);
		std::cout << "value: " << *it_tmp << std::endl;
		std::advance(it, -3);
		std::cout << "value: " << *it << std::endl;
		std::cout << "value: " << *it << std::endl;
		std::advance(it, 1);
		std::cout << "value: " << *it << std::endl;
	}
	
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

