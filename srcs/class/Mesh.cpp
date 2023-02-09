/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:35:33 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 14:53:07 by dracken24        ###   ########.fr       */
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

Mesh::Mesh(std::vector<GLfloat> vertices, std::vector<GLuint> indices,
	size_t vecSize, size_t indicesSize) :
_vertices(vertices),
_indices(indices),
_vertLen(vecSize),
_indicesLen(indicesSize)
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
		this->_vertLen = rhs._vertLen;
		this->_indicesLen = rhs._indicesLen;
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

GLuint	Mesh::getVertLen(void) const
{
	return this->_vertLen;
}

GLuint	Mesh::getIndicesLen(void) const
{
	return this->_indicesLen;
}

Vector3	Mesh::getCenterAxis(void) const
{
	return this->_centerAxis;
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

void	Mesh::setCenterAxis(void)
{
	float	x = 0.0f;
	float	y = 0.0f;
	float	z = 0.0f;
	GLuint	i = 0;

	while (i < _vertLen)
	{
		x += _vertices.at(i);
		y += _vertices.at(i + 1);
		z += _vertices.at(i + 2);
		i += 3;
	}
	x /= (_vertLen / 3);
	y /= (_vertLen / 3);
	z /= (_vertLen / 3);
	i = 0;
	while (i < _vertLen)
	{
		_vertices.at(i) -= x;
		_vertices.at(i + 1) -= y;
		_vertices.at(i + 2) -= z;
		i += 3;
	}
}

void	Mesh::setCenterVertices()
{
	GLuint	i;
	float	tx;
	float	theta;

	i = 0;
	theta = 90 * (M_PI / 180);
	while (i < _vertLen)
	{
		tx = _vertices.at(i);
		_vertices.at(i) = _vertices.at(i) * cos(theta) - _vertices.at(i + 2) * sin(theta);
		_vertices.at(i + 2) = tx * sin(theta) + _vertices.at(i + 2) * cos(theta);
		i += 3;
	}
	
	_centerAxis = Vector3({0.0f, 0.0f, 0.0f});
}
