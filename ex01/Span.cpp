/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:31:11 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/07 19:16:32 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0), available(0)
{
}

Span::Span(unsigned int n) : n(n), available(n)
{
}

Span::Span(const Span& other) : n(other.n), available(other.available)
{
	*this = other;
}

Span&	Span::operator= (const Span& other)
{
	this->n = other.n;
	this->available = other.available;
	copyStore(other.store, this->store);
	return (*this);
}

Span::~Span()
{
}

void				Span::addNumber(int nbr)
{
	if (available)
	{
		this->store.insert(nbr);
		available--;
	}
	else
		throw (Span::FullStoreException());
}

void				Span::addRange(std::vector<int>::iterator itbegin, std::vector<int>::iterator itend)
{
	while (itbegin != itend)
	{
		if (available)
		{
			this->store.insert(*itbegin);
			available--;
		}
		else
			throw (Span::FullStoreException());
		itbegin++;
	}
}

void				Span::addRange(std::list<int>::iterator itbegin, std::list<int>::iterator itend)
{
	while (itbegin != itend)
	{
		if (available)
		{
			this->store.insert(*itbegin);
			available--;
		}
		else
			throw (Span::FullStoreException());
		itbegin++;
	}
}

void				Span::displayStore(void)
{
	for (std::multiset<int>::iterator it = this->store.begin(); it != this->store.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

unsigned int		Span::shortestSpan(void)
{
	unsigned int	shortest;
	int	one;
	int	next;

	shortest = std::numeric_limits<unsigned int>::max();
	if (this->store.empty())
		throw (Span::NoNumbersStoredException());
	if (this->store.size() == 1)
		throw (Span::OnlyOneNumberStoredException());
	for (std::multiset<int>::iterator it = this->store.begin(); it != this->store.end(); it = it)
	{
		one = absoluteValue(*it);
		it++;
		if (it != this->store.end())
		{
			next = absoluteValue(*it);
			if (absoluteValue(next - one) < shortest)
				shortest = absoluteValue(next - one);
		}
		if (!shortest)
			return (shortest);
	}
	return (shortest);
}

unsigned int		Span::longestSpan(void)
{
	int	first;
	int	last;

	if (this->store.empty())
		throw (Span::NoNumbersStoredException());
	if (this->store.size() == 1)
		throw (Span::OnlyOneNumberStoredException());
	first = absoluteValue(*this->store.begin());
	last = absoluteValue(*(--this->store.end()));
	return (last - first);
}

const char*		Span::FullStoreException::what() const throw()
{
	return ("FullStoreException: the maximum number of elements is already stored");
}

const char*		Span::NoNumbersStoredException::what() const throw()
{
	return ("NoNumbersStoredException: no numbers stored, no span can be found");
}
const char*		Span::OnlyOneNumberStoredException::what() const throw()
{
	return ("OnlyOneNumberStoredException: only one number is stored, no span can be found");
}

void			Span::copyStore(const std::multiset<int>& from, std::multiset<int>& to)
{
	to.clear();
	if (from.empty())
		return ;
	for (std::multiset<int>::const_iterator itFrom = from.begin(); itFrom != from.end(); itFrom++)
		to.insert(*itFrom);
}
unsigned int	Span::absoluteValue(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
