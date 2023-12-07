/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:32:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 16:16:42 by eguelin          ###   ########lyon.fr   */
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
	timeval currentTime;

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
}

void	identify (Base &p )
{
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
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

