/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:54:16 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 14:15:11 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
	public:

		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );

	private:

		Serializer( void );
		Serializer( const Serializer &src );
		~Serializer( void );

		Serializer	&operator=( const Serializer &src );
};

#endif
