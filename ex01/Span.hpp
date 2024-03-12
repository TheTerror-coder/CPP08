/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:14:32 by TheTerror         #+#    #+#             */
/*   Updated: 2024/03/12 15:58:34 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
# define	SPAN_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <set>
# include <vector>
# include <list>
# include <exception>
# include <limits>

class Span
{
	public:
	
		Span(const unsigned& n);
		Span(const Span& other);
		Span&	operator= (const Span& other);
		~Span();

		void				addNumber(int nbr);
		void				displayStore(void);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
		template <class T_iterator>
		void				addRange(T_iterator itbegin, T_iterator itend);

		class	FullStoreException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	NoNumbersStoredException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	OnlyOneNumberStoredException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
	
	private:

		Span();

		unsigned int		n;
		unsigned int		available;
		std::multiset<int>	store;

		void				copyStore(const std::multiset<int>& from, std::multiset<int>& to);
};

template <typename T_iterator>
void				Span::addRange(T_iterator itbegin, T_iterator itend)
{
	while (itbegin != itend)
	{
		if (this->available > 0 && this->available <= this->n)
		{
			this->store.insert(*itbegin);
			available--;
		}
		else
			throw (Span::FullStoreException());
		itbegin++;
	}
}

#endif