/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:10:06 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 14:15:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	public:

		Data( void );
		Data( const Data &src );
		Data( const std::string &str );
		~Data( void );

		Data	&operator=( const Data &src );

		const std::string	&getBase( void ) const;

	private:

		std::string _base;
};

#endif
