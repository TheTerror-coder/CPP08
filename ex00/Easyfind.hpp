/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:52:46 by TheTerror         #+#    #+#             */
/*   Updated: 2024/03/11 19:36:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EASYFIND_HPP
# define	EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& intContainer, int n)
{
	return (std::find(intContainer.begin(), intContainer.end(), n));
}

#endif