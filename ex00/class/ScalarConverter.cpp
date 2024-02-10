/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:29:58 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/10 14:54:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	trim( std::string &str );

/* ************************************************************************** */
/*                       Static public member function                        */
/* ************************************************************************** */

int	ScalarConverter::convert( std::string str )
{
	double	d;
	char	*ptr;

	if (str.size() > 1)
		trim(str);

	if (str.empty())
	{
		std::cout << "Error: Invalid argument" << std::endl;

		return (1);
	}

	if (str.size() == 1 && !std::isdigit(str[0]))
		_convertChar(str);
	else
	{
		d = std::strtod(str.c_str(), &ptr);

		if ((*ptr != 'f' && *ptr != '\0') || (*ptr == 'f' && ptr[1] != '\0'))
		{
			std::cout << "Error: Invalid argument" << std::endl;

			return (1);
		}

		if (str.find('f') != std::string::npos)
			ScalarConverter::_convertFloat(str);
		else if (str.find('.') == std::string::npos && \
				str.find('e') == std::string::npos && \
				d < std::numeric_limits<int>::max() && \
				d > std::numeric_limits<int>::min())
			ScalarConverter::_convertInt(str);
		else
			ScalarConverter::_convertDouble(str);
	}

	ScalarConverter::_printChar();
	ScalarConverter::_printInt();
	ScalarConverter::_printFloat();
	ScalarConverter::_printDouble();

	return (0);
}

/* ************************************************************************** */
/*                      Private Constructor & Destructor                      */
/* ************************************************************************** */

ScalarConverter::ScalarConverter( void )
{
}

ScalarConverter::ScalarConverter( const ScalarConverter &scalarConverter )
{
	*this = scalarConverter;
}

ScalarConverter::~ScalarConverter( void )
{
}

/* ************************************************************************** */
/*                          Private operator overload                         */
/* ************************************************************************** */

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &scalarConverter )
{
	static_cast<void>(scalarConverter);

	return (*this);
}

/* ************************************************************************** */
/*                            Private member function                         */
/* ************************************************************************** */

void	ScalarConverter::_convertChar( const std::string &str )
{
	ScalarConverter::_char = str[0];
	ScalarConverter::_int = static_cast<int>(ScalarConverter::_char);
	ScalarConverter::_float = static_cast<float>(ScalarConverter::_char);
	ScalarConverter::_double = static_cast<double>(ScalarConverter::_char);
}

void	ScalarConverter::_convertInt( const std::string &str )
{
	ScalarConverter::_int = std::atoi(str.c_str());
	ScalarConverter::_char = static_cast<char>(ScalarConverter::_int);
	ScalarConverter::_float = static_cast<float>(ScalarConverter::_int);
	ScalarConverter::_double = static_cast<double>(ScalarConverter::_int);
}

void	ScalarConverter::_convertFloat( const std::string &str )
{
	ScalarConverter::_float = std::strtof(str.c_str(), NULL);
	ScalarConverter::_char = static_cast<char>(ScalarConverter::_float);
	ScalarConverter::_int = static_cast<int>(ScalarConverter::_float);
	ScalarConverter::_double = static_cast<double>(ScalarConverter::_float);
}

void	ScalarConverter::_convertDouble( const std::string &str )
{
	ScalarConverter::_double = std::strtod(str.c_str(), NULL);
	ScalarConverter::_char = static_cast<char>(ScalarConverter::_double);
	ScalarConverter::_int = static_cast<int>(ScalarConverter::_double);
	ScalarConverter::_float = static_cast<float>(ScalarConverter::_double);
}

void	ScalarConverter::_printChar( void )
{
	std::cout << "char: ";
	if (std::isnan(ScalarConverter::_double) || \
		ScalarConverter::_double < std::numeric_limits<char>::min() || \
		ScalarConverter::_double > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;

		return ;
	}

	if (std::isprint(ScalarConverter::_char))
		std::cout << "'" << ScalarConverter::_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::_printInt( void )
{
	std::cout << "int: ";
	if (std::isnan(ScalarConverter::_double) || \
		ScalarConverter::_double < std::numeric_limits<int>::min() || \
		ScalarConverter::_double > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;

		return ;
	}

	std::cout << ScalarConverter::_int << std::endl;
}

void	ScalarConverter::_printFloat( void )
{
	std::ostringstream sFloat;

	std::cout << "float: ";

	sFloat << ScalarConverter::_float;
	if (sFloat.str().find('.') == std::string::npos && \
		sFloat.str().find('e') == std::string::npos)
		sFloat << ".0f";
	else
		sFloat << "f";

	std::cout << sFloat.str() << std::endl;
}

void	ScalarConverter::_printDouble( void )
{
	std::ostringstream sDouble;

	std::cout << "double: ";

	sDouble << ScalarConverter::_double;
	if (sDouble.str().find('.') == std::string::npos && \
		sDouble.str().find('e') == std::string::npos)
		sDouble << ".0";

	std::cout << sDouble.str() << std::endl;
}

/* ************************************************************************** */
/*                              Static function                               */
/* ************************************************************************** */

static void trim(std::string &str)
{
	std::string::iterator start = str.begin();
	std::string::iterator end = str.end() - 1;

	while (start != str.end() && isspace(*start))
		++start;

	if (start == str.end())
	{
		str.clear();
		return ;
	}

	while (end != start && isspace(*end))
		--end;

	str = std::string(start, end + 1);
}

/* ************************************************************************** */
/*                       Static private member variable                       */
/* ************************************************************************** */

char	ScalarConverter::_char;
int		ScalarConverter::_int;
float	ScalarConverter::_float;
double	ScalarConverter::_double;
