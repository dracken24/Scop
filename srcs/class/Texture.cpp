/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:48:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 10:51:09 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/class/Texture.hpp"

//******************************************************************************************************//
//										Constructor - Destructor							    		//
//******************************************************************************************************//

Texture::Texture()
{
	// std::cout << "Default Texture constructor called" << std::endl;
}

Texture::Texture(std::string path) :
_path(path)
{
	// std::cout << "Texture constructor called" << std::endl;
}

Texture::Texture(const Texture &src)
{
	*this = src;
}

Texture::~Texture()
{
	// std::cout << "Texture destructor called" << std::endl;
}

Texture &Texture::operator=(Texture const &rhs)
{
	if (this != &rhs)
	{
		this->_path = rhs._path;
	}
	return *this;
}

//******************************************************************************************************//
//												Setters										    		//
//******************************************************************************************************//

void	Texture::setId(GLuint id)
{
	this->_id = id;
}

void	Texture::setPath(std::string path)
{
	this->_path = path;
}

//******************************************************************************************************//
//												Getters										    		//
//******************************************************************************************************//

GLuint	Texture::getId(void) const
{
	return this->_id;
}

std::string	Texture::getPath(void) const
{
	return this->_path;
}
