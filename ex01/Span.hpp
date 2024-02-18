/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:14:32 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/07 19:16:27 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
# define	SPAN_HPP

# include <iostream>
# include <set>
# include <vector>
# include <list>
# include <exception>
# include <limits>

class Span
{
	public:
	
		Span(unsigned int n);
		Span(const Span& other);
		Span&	operator= (const Span& other);
		~Span();

		void				addNumber(int nbr);
		void				addRange(std::vector<int>::iterator itbegin, std::vector<int>::iterator itend);
		void				addRange(std::list<int>::iterator itbegin, std::list<int>::iterator itend);
		void				displayStore(void);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);

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
		unsigned int		absoluteValue(int nbr);
};




#endif