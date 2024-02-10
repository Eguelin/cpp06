/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:29:58 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/10 14:50:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <sstream>
# include <string>
# include <cmath>

class  ScalarConverter
{
	public:

		static int	convert( std::string str );

	private:

		static char		_char;
		static int		_int;
		static float	_float;
		static double	_double;

		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &scalarConverter );
		~ScalarConverter( void );

		static void	_convertChar( const std::string &str );
		static void	_convertInt( const std::string &str );
		static void	_convertFloat( const std::string &str );
		static void	_convertDouble( const std::string &str );

		static void	_printChar( void );
		static void	_printInt( void );
		static void	_printFloat( void );
		static void	_printDouble( void );

		ScalarConverter	&operator=( const ScalarConverter &scalarConverter );
};

#endif
