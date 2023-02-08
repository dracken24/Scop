/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:35:33 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 10:46:24 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/class/Mesh.hpp"

//******************************************************************************************************//
//										Constructor - Destructor							    		//
//******************************************************************************************************//
	
Mesh::Mesh()
{
	// std::cout << "Default Mesh constructor called" << std::endl;
}

Mesh::Mesh(std::vector<GLfloat> vertices, std::vector<Vector3> normals, std::vector<Vector2> uvs, std::vector<GLuint> indices) :
_vertices(vertices),
_normals(normals),
_uvs(uvs),
_indices(indices)
{
	// std::cout << "Mesh constructor called" << std::endl;
}

Mesh::Mesh(const Mesh &src)
{
	*this = src;
}

Mesh::~Mesh()
{
	// std::cout << "Mesh destructor called" << std::endl;
}

Mesh &Mesh::operator=(Mesh const &rhs)
{
	if (this != &rhs)
	{
		this->_indices = rhs._indices;
		this->_vertices = rhs._vertices;
		this->_normals = rhs._normals;
		this->_uvs = rhs._uvs;
	}
	return *this;
}

//******************************************************************************************************//
//												Setters										    		//
//******************************************************************************************************//

std::vector<GLfloat>	Mesh::getVertices(void) const
{
	return this->_vertices;
}

std::vector<Vector3>	Mesh::getNormals(void) const
{
	return this->_normals;
}

std::vector<Vector2>	Mesh::getUvs(void) const
{
	return this->_uvs;
}

std::vector<GLuint>		Mesh::getIndices(void) const
{
	return this->_indices;
}

//******************************************************************************************************//
//												Setters										    		//
//******************************************************************************************************//

void	Mesh::setVertices(std::vector<GLfloat> vertices)
{
	this->_vertices = vertices;
}

void	Mesh::setNormals(std::vector<Vector3> normals)
{
	this->_normals = normals;
}

void	Mesh::setUvs(std::vector<Vector2> uvs)
{
	this->_uvs = uvs;
}

void	Mesh::setIndices(std::vector<GLuint> indices)
{
	this->_indices = indices;
}
