/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:29:51 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 14:41:48 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_HPP
# define MESH_HPP

#include "../utils.hpp"

class Mesh
{
	public:
		/* Constructors */
		Mesh(std::vector<GLfloat> vertices, std::vector<GLuint> indices, size_t vecSize, size_t indicesSize);
		Mesh(const Mesh &src);
		~Mesh(void);

		/* Operators */
		Mesh	&operator=(const Mesh &rhs);

		/* Getters */
		std::vector<GLfloat>	getVertices(void) const;
		std::vector<Vector3>	getNormals(void) const;
		std::vector<Vector2>	getUvs(void) const;
		std::vector<GLuint>		getIndices(void) const;
		GLuint					getVertLen(void) const;
		GLuint					getIndicesLen(void) const;
		Vector3					getCenterAxis(void) const;

		/* Setters */
		void	setVertices(std::vector<GLfloat> vertices);
		void	setNormals(std::vector<Vector3> normals);
		void	setUvs(std::vector<Vector2> uvs);
		void	setIndices(std::vector<GLuint> indices);
		void	setCenterAxis(void);
		void	setCenterVertices(void);

	private:
		Mesh(void);

		std::string             _name;
		std::string             _path;

		GLuint					_vertLen;
		GLuint					_indicesLen;

		Vector3					_centerAxis;

		std::vector<GLfloat>	_vertices;
		std::vector<Vector3>	_normals;
		std::vector<Vector2>	_uvs;
		std::vector<GLuint>		_indices;
		// std::vector<GLfloat>	_vertices;
		
};

#endif
