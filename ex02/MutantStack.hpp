/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:48:17 by TheTerror         #+#    #+#             */
/*   Updated: 2024/03/12 18:00:10 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
# define	MUTANTSTACK_HPP

# include <cstddef>
# include <iostream>
# include <algorithm>
# include <stack>
# include <iterator>


template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack<T>();
		MutantStack<T>(const MutantStack& other);
		MutantStack&	operator= (const MutantStack& other);
		~MutantStack<T>();

		class iterator : public std::iterator<
										std::random_access_iterator_tag,
										T,
										std::ptrdiff_t,
										T*,
										T>
		{
			public :

				iterator();
				iterator(T* ptr);
				iterator(const iterator& other);
				iterator&	operator= (const iterator& other);
				~iterator();

			
				
				T&					operator* () const;
				T&					operator[] (std::ptrdiff_t n) const;
				
				iterator&			operator++ ();
				iterator&			operator-- ();
				iterator			operator++ (int);
				iterator			operator-- (int);

				std::ptrdiff_t		operator- (const iterator& rhs) const;
				iterator&			operator-= (std::ptrdiff_t n);
				iterator&			operator+= (std::ptrdiff_t n);

				iterator			operator+ (std::ptrdiff_t n);
				iterator			operator- (std::ptrdiff_t n);
				bool				operator== (const iterator& rhs);
				bool				operator!= (const iterator& rhs);
				bool				operator< (const iterator& rhs);
				bool				operator> (const iterator& rhs);
				bool				operator<= (const iterator& rhs);
				bool				operator>= (const iterator& rhs);
				
			private :

				T*	ptr;
				
		};

		iterator	begin(void);
		iterator	end(void);
		
	
	private:

		T*	getBottom(void);

};

# include "MutantStack.tpp"

#endif