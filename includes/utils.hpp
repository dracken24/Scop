/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:33:18 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 13:40:11 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <vector>
# include <string>
# include <iostream>
# include <ostream>
# include <fstream>
# include <sstream>
# include <GL/glew.h>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <glm/gtc/type_ptr.hpp>
# include <stdexcept>
# include <GLFW/glfw3.h>


# define RESET "\033[0m"
# define BOLD "\033[1m"
# define DIM "\033[2m"
# define ITALIC "\033[3m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define INVERT "\033[6m"
# define REVERSE "\033[7m"
# define CONCEALED "\033[8m"

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef struct Vector3glf
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}   Vector3glf;

typedef struct Vector3
{
	float x;
	float y;
	float z;
}   Vector3;

typedef struct Vector2
{
	float x;
	float y;
}   Vector2;

typedef struct Transform
{
	Vector3		translate;
	Vector3		rotate;
	Vector3		scale;

	Vector2		mouse;
}	Transform;

typedef struct KeyCount
{
	bool		KEY_W;
	bool		KEY_A;
	bool		KEY_S;
	bool		KEY_D;
	bool		KEY_Q;
	bool		KEY_E;

	bool		KEY_UP;
	bool		KEY_DOWN;
	bool		KEY_LEFT;
	bool		KEY_RIGHT;

	bool		MOUSE_LEFT;
	bool		MOUSE_RIGHT;
	bool		MOUSE_MIDDLE;
}	KeyCount;

typedef struct Modifier
{
	float		zoom;
}	Modifier;

#endif
