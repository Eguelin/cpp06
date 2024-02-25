/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:28:39 by eguelin           #+#    #+#             */
/*   Updated: 2024/02/13 17:46:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <sys/time.h>

Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

#endif
