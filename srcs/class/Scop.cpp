/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:04:37 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 11:26:49 by dracken24        ###   ########.fr       */
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

	scop._window = glfwCreateWindow(WIDTH, HEIGHT, name.c_str(), nullptr, nullptr);

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
//											Public Functions								    		//
//******************************************************************************************************//

void	Scop::loadMesh(std::string const &path)
{
	
}

//******************************************************************************************************//
//											Private Functions								    		//
//******************************************************************************************************//

GLfloat	*Scop::saveMesh(GLfloat *array, char *line)
{
	// GLfloat	*tmp = 5.0f;
	// int		i;

	return (array);
}

