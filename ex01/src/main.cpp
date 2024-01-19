/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:48:04 by eguelin           #+#    #+#             */
/*   Updated: 2024/01/16 15:25:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	uintptr_t	raw;
	Data		*dataPtr = new Data;

	dataPtr->str = "Hello World!";

	std::cout << "dataPtr: " << dataPtr << std::endl;

	raw = Serializer::serialize( dataPtr );
	dataPtr = NULL;

	std::cout << "    raw: " << raw << std::endl;

	dataPtr = Serializer::deserialize( raw );

	std::cout << "dataPtr: " << dataPtr << std::endl;
	std::cout << "dataPtr->str: " << dataPtr->str << std::endl;

	delete dataPtr;

	return (0);
}
