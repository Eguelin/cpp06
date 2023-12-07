/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:29:58 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/07 14:36:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	trim( std::string &str );
static void	printChar( double d , bool isNan);
static void	printInt( double d, bool isNan);
static void	printFloat( double d );
static void	printDouble( double d );

/* ************************************************************************** */
/*                       Static public member function                        */
/* ************************************************************************** */

int	ScalarConverter::convert( std::string str )
{
	double	d;
	char	*ptr;

	trim(str);

	if (str.empty())
	{
		std::cerr << "Error: Empty string" << std::endl;

		return (1);
	}

	d = strtod(str.c_str(), &ptr);

	if ((str.size() == 1 && std::isdigit(str[0])) || (*ptr != 'f' && *ptr != '\0') || *(ptr + 1) != '\0')
	{
		std::cerr << "Error: Invalid argument" << std::endl;

		return (1);
	}

	printChar(d, str == "nan" || str == "nanf");
	printInt(d, str == "nan" || str == "nanf");
	printFloat(d);
	printDouble(d);

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
/*                              Static function                               */
/* ************************************************************************** */

static void	trim( std::string &str )
{
	std::string::iterator	it = str.begin();

	if (str.empty())
		return ;

	while (it != str.end() && std::isspace(*it))
		it++;
	str.erase(str.begin(), it);

	if (str.empty())
		return ;

	it = str.end();
	while (it != str.begin() && std::isspace(*(it - 1)))
		it--;
	str.erase(it, str.end());
}


static void	printChar( double d, bool isNan )
{
	char	c;

	std::cout << "char: ";
	if (isNan || d < CHAR_MIN || d > CHAR_MAX)
	{
		std::cout << "impossible" << std::endl;

		return ;
	}

	c = static_cast<char>(d);

	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

static void	printInt( double d, bool isNan )
{
	std::cout << "int: ";
	if (isNan || d < INT_MIN || d > INT_MAX)
	{
		std::cout << "impossible" << std::endl;

		return ;
	}

	std::cout << static_cast<int>(d) << std::endl;
}

static void	printFloat( double d )
{
	float	f = static_cast<float>(d);

	std::cout << "float: ";
	if (f < MAX_NB_PRINTABLE && f > MIN_NB_PRINTABLE && f == static_cast<int>(f))
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

static void	printDouble( double d )
{
	std::cout << "double: ";
	if (d < MAX_NB_PRINTABLE && d > MIN_NB_PRINTABLE && d == static_cast<int>(d))
		std::cout << d << ".0" << std::endl;
	else
		std::cout << d << std::endl;
}
