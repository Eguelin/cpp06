/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:32:04 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/10 14:31:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.hpp"

static Base	*generateA( void );
static Base	*generateB( void );
static Base	*generateC( void );

/* ************************************************************************** */
/*                                 Functions                                  */
/* ************************************************************************** */

Base	*generate( void )
{
	Base	*(*generate[3])(void) = {generateA, generateB, generateC};
	timeval	currentTime;

	gettimeofday(&currentTime, NULL);
	std::srand(static_cast<unsigned int>(currentTime.tv_usec));

	return (generate[std::rand() % 3]());
}

void	identify( Base *p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify (Base &p )
{
	try
	{
		static_cast<void>(dynamic_cast<A &>(p));

		std::cout << "A" << std::endl;

		return;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		static_cast<void>(dynamic_cast<B &>(p));

		std::cout << "B" << std::endl;

		return;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		static_cast<void>(dynamic_cast<C &>(p));

		std::cout << "C" << std::endl;

		return;
	}
	catch(const std::exception& e)
	{
	}
}

/* ************************************************************************** */
/*                                Static functions                            */
/* ************************************************************************** */

static Base	*generateA( void )
{
	return (new A());
}

static Base	*generateB( void )
{
	return (new B());
}

static Base	*generateC( void )
{
	return (new C());
}

