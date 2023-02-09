/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:04:37 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 20:44:24 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/class/Scop.hpp"

extern Scop	scop;

//******************************************************************************************************//
//											Static Functions								    		//
//******************************************************************************************************//

// Callback //
static void framebufferResizeCallback(GLFWwindow *window, int width, int height)
{
	auto app = reinterpret_cast<Scop *>(glfwGetWindowUserPointer(window));
	scop.framebufferResized = true;
}

//******************************************************************************************************//
//										Constructor - Destructor							    		//
//******************************************************************************************************//

Scop::Scop()
{
	
}

Scop::Scop(std::string name)
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	_window = glfwCreateWindow(WIDTH, HEIGHT, name.c_str(), nullptr, nullptr);

	glfwSetWindowUserPointer(scop._window, nullptr);
	glfwSetFramebufferSizeCallback(scop._window, framebufferResizeCallback);
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

//******************************************************************************************************//
//												Getters										    		//
//******************************************************************************************************//

std::vector<GLfloat>	Scop::getVertices() const
{
	return (_vertices);
}

std::vector<Mesh>		Scop::getMesh() const
{
	return (_mesh);
}

Texture				Scop::getTexture(int i) const
{
	return (_textures.at(i));
}


//******************************************************************************************************//
//											Public Functions								    		//
//******************************************************************************************************//

// Init variables //
void	Scop::init(void)
{
	
}

// Open mesh file .obj //
void	Scop::loadMesh(std::string const &path)
{
	std::ifstream	infile(path);
	std::string		line;
	
	// std::getline(infile, line);
	// std::istringstream	s(line);
	// std::string			type;
	
	for (; std::getline(infile, line);)
	{
		// std::cout << line << std::endl;
		std::istringstream	s(line);
		std::string			type;
		s >> type;
		if (type == "v")
		{
			Vector3glf v;
			s >> v.x;
			s >> v.y;
			s >> v.z;
			_vertices.push_back(v.x);
			_vertices.push_back(v.y);
			_vertices.push_back(v.z);
		}
		else if (type == "f")
		{
			unsigned int a, b, c;
			s >> a;
			s >> b;
			s >> c;
			_indices.push_back(a - 1);
			_indices.push_back(b - 1);
			_indices.push_back(c - 1);
		}
	}
	GLuint	verLen = scop._vertices.size();
	
	_mesh.push_back(Mesh(scop._vertices, _indices, _vertices.size(), _indices.size()));
	_mesh.at(0).setCenterAxis();
	_mesh.at(0).setCenterVertices();
	
	_vertices.clear();
	_indices.clear();
}

void	Scop::loadTexture(std::string const &path, int i)
{
	std::cout << "0" << std::endl;
	
	Texture *tmp = new Texture(path);
	_textures.push_back(*tmp);

	_textures.at(i).setTexture(path.c_str());
}

//******************************************************************************************************//
//											Private Functions								    		//
//******************************************************************************************************//

// Save mesh file .obj in std::vector<Mesh> //
// GLfloat	*Scop::saveMesh(GLfloat *array, char *line)
// {
// 	// GLfloat	*tmp = 5.0f;
// 	// int		i;

// 	return (array);
// }

