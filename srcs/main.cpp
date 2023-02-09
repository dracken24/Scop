/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:13:00 by nadesjar          #+#    #+#             */
/*   Updated: 2023/02/08 20:45:39 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include <GLFW/glfw3.h>

#include "../includes/class/Scop.hpp"
#include "../includes/class/Mesh.hpp"

Scop	scop("BANKAI");

int		events(void)
{
	glfwSetKeyCallback(scop._window, key_callback);	                // Key Hook //
	glfwSetMouseButtonCallback(scop._window, mouse_button_callback);	// Mouse Hook //;
	glfwSetScrollCallback(scop._window, scroll_callback);	            // Scroll Hook //;
	glfwSetCursorPosCallback(scop._window, cursor_position_callback);	// Cursor Hook //;
	// glfwSetDropCallback(app.window, drop_callback);				// Drop files into window //
	
	return (0);
}

void    mainLoop()
{
	while (glfwWindowShouldClose(scop._window) != true && scop._quit == true )
	{
		glfwPollEvents();

		events();
		
		// drawFrame();
		
		// useFPS();	// Wait for 16.666 ms to have 60 fps //

		// std::cout << "FPS: " << i << std::endl;
		// i++;
	}
}

int     main(int argc, char **argv)
{
	try
	{
		scop.init();
		scop.loadMesh(argv[1]);
		scop.loadTexture(argv[2], 0);
		std::cout << "Texture Path: " << scop.getTexture(0).getPath() << std::endl;
		std::cout << "Texture Name: " << scop.getTexture(0).getName() << std::endl;
		
		std::cout << "Img: " << scop.getTexture(0).getTexture()->img << std::endl;

		mainLoop();

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// else
	// {
	// 	std::cout << RED << "Usage: ./scop [file.obj] [texture file.png or .jpg or ...]" << RESET << std::endl;
	// 	return EXIT_FAILURE;
	// }

	return EXIT_SUCCESS;
}
