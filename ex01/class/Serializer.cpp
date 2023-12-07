/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:54:16 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 14:06:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                       Static public member function                        */
/* ************************************************************************** */

uintptr_t	Serializer::serialize( Data* ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>(raw));
}

/* ************************************************************************** */
/*                      Private Constructor & Destructor                      */
/* ************************************************************************** */

Serializer::Serializer( void )
{
}

Serializer::Serializer( const Serializer &src )
{
	*this = src;
}

Serializer::~Serializer( void )
{
}

/* ************************************************************************** */
/*                          Private operator overload                         */
/* ************************************************************************** */

Serializer	&Serializer::operator=( const Serializer &src )
{
	static_cast<void>(src);

	return (*this);
}
