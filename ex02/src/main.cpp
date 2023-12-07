/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 16:19:19 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.hpp"

int main( void )
{
	Base	*rand;
	size_t	count = 20;

	for (size_t i = 0; i < count; i++)
	{
		rand = generate();

		std::cout << "identify( Base *p ): ";
		identify(rand);
		std::cout << "identify( Base &p ): ";
		identify(*rand);
		if (count - 1 != i)
			std::cout << std::endl;

		delete rand;
	}

	return (0);
}
