/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:35:16 by nadesjar          #+#    #+#             */
/*   Updated: 2023/02/08 05:06:04 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_HPP
# define SCOP_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <GLFW/glfw3.h>

#define WIDTH 1500
#define HEIGHT 920

class Scop
{
	public:
		Scop();
		Scop(Scop const &src);
		~Scop();
		Scop	&operator=(Scop const &rhs);

		// void    mainLoop();
		// static void    framebufferResizeCallback(GLFWwindow *window, int width, int height);
		// int     main(void);

	public:
		GLFWwindow	*window;
		bool framebufferResized = false; //- Stock framebuffer resized -//

	private:
		
};

#endif
