/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:29:58 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 14:31:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <climits>
# include <limits>
# include <sstream>

# define MAX_NB_PRINTABLE 1000000
# define MIN_NB_PRINTABLE -1000000

class  ScalarConverter
{
	public:

		static int	convert( std::string str );

	private:

		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &scalarConverter );
		~ScalarConverter( void );

		ScalarConverter	&operator=( const ScalarConverter &scalarConverter );
};

#endif
