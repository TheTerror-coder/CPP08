/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:40:56 by TheTerror         #+#    #+#             */
/*   Updated: 2024/03/12 16:26:21 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "MutantStack.hpp"


template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
	*this = other;
}

template <typename T>
MutantStack<T>&		MutantStack<T>::operator= (const MutantStack& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::iterator::iterator() : ptr(NULL)
{
}

template <typename T>
MutantStack<T>::iterator::iterator(T* ptr) : ptr(ptr)
{
}

template <typename T>
MutantStack<T>::iterator::iterator(const iterator& other) : ptr(other.ptr)
{
	*this = other;
}

template <typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator= (const iterator& other)
{
	if (this == &other)
		return (*this);
	this->ptr = other.ptr;
	return (*this);
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{
}



template <typename T>
T&										MutantStack<T>::iterator::operator* () const
{
	return (*(this->ptr));
}

template <typename T>
T&										MutantStack<T>::iterator::operator[] (std::ptrdiff_t n) const
{
	return (*(this->ptr + n));
}

template <typename T>
typename MutantStack<T>::iterator&		MutantStack<T>::iterator::operator++ ()
{
	this->ptr++;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator&		MutantStack<T>::iterator::operator-- ()
{
	this->ptr--;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::iterator::operator++ (int)
{
	iterator	tmp = *this;

	this->ptr++;
	return (tmp);
}

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::iterator::operator-- (int)
{
	iterator	tmp = *this;

	this->ptr--;
	return (tmp);
}

template <typename T>
typename MutantStack<T>::iterator&		MutantStack<T>::iterator::operator-= (std::ptrdiff_t n)
{
	this->ptr -= n;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator&		MutantStack<T>::iterator::operator+= (std::ptrdiff_t n)
{
	this->ptr += n;
	return (*this);
}

template <typename T>
std::ptrdiff_t							MutantStack<T>::iterator::operator- (const iterator& rhs) const
{
	return (this->ptr - rhs.ptr);
}


template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::iterator::operator+ (std::ptrdiff_t n)
{
	return (this->ptr + n);
}

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::iterator::operator- (std::ptrdiff_t n)
{
	return (this->ptr - n);
}

template <typename T>
bool									MutantStack<T>::iterator::operator== (const typename MutantStack<T>::iterator& rhs)
{
	return (this->ptr == rhs.ptr);
}

template <typename T>
bool									MutantStack<T>::iterator::operator!= (const typename MutantStack<T>::iterator& rhs)
{
	return (this->ptr != rhs.ptr);
}

template <typename T>
bool									MutantStack<T>::iterator::operator< (const typename MutantStack<T>::iterator& rhs)
{
	return (this->ptr < rhs.ptr);
}

template <typename T>
bool									MutantStack<T>::iterator::operator> (const typename MutantStack<T>::iterator& rhs)
{
	return (this->ptr > rhs.ptr);
}

template <typename T>
bool									MutantStack<T>::iterator::operator<= (const typename MutantStack<T>::iterator& rhs)
{
	return (this->ptr <= rhs.ptr);
}

template <typename T>
bool									MutantStack<T>::iterator::operator>= (const typename MutantStack<T>::iterator& rhs)
{
	return (this->ptr >= rhs.ptr);
}

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::begin()
{
	return (iterator(this->getBottom()));
}

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end()
{
	T*	__end;

	__end = &this->top();
	return (iterator(++__end));
}

template <typename T>
T*										MutantStack<T>::getBottom()
{
	iterator it = this->end();
	
	for (size_t len = this->size(); len; len--)
		it--;
	return (&(*it));
}
