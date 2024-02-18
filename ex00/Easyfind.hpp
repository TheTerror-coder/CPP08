/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:52:46 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/07 12:54:01 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EASYFIND_HPP
# define	EASYFIND_HPP

# include <iterator>

template <typename T>
typename T::iterator	easyfind(T& intContainer, int n)
{
	for (typename T::iterator it = intContainer.begin(); it != intContainer.end(); it++)
	{
		if (*it == n)
			return (it);
	}
	return (intContainer.end());
}

#endif