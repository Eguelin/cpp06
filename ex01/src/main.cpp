/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 14:28:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	uintptr_t	raw;
	Data		*dataPtr = new Data("Hello word");

	std::cout << "dataPtr: " << dataPtr << std::endl;

	raw = Serializer::serialize( dataPtr );
	dataPtr = NULL;

	std::cout << "    raw: " << raw << std::endl;

	dataPtr = Serializer::deserialize( raw );

	std::cout << "dataPtr: " << dataPtr << std::endl;
	std::cout << "dataPtr->getBase(): " << dataPtr->getBase() << std::endl;

	delete dataPtr;

	return (0);
}
