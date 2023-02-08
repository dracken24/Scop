/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:04:37 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 05:05:53 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scop.hpp"

Scop::Scop()
{
	// initWindow();
	// initVulkan();
}

Scop::Scop(Scop const &src)
{
	*this = src;
}

Scop::~Scop()
{
	// cleanup();
}

Scop &Scop::operator=(Scop const &rhs)
{
	if (this != &rhs)
	{
		// this-> = rhs.;
	}
	return *this;
}

