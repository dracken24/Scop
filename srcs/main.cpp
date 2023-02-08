/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:13:00 by nadesjar          #+#    #+#             */
/*   Updated: 2023/02/08 04:48:08 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include <GLFW/glfw3.h>

#include "Scop.hpp"

Scop	scop;

// void    mainLoop()
// {
// 	while (app._quit == true && glfwWindowShouldClose(app.window) != true)
// 	{
// 		glfwPollEvents();

// 		events(app.window); // Events //
// 		onKeyPress();       // Key gestion //

// 		threadChooseTexture(); // Thread to choose texture //

// 		app.drawFrame(); // Draw on screen //

// 		app.useFPS(); // FPS gestion //
// 	}
// }

// Callback //
static void framebufferResizeCallback(GLFWwindow *window, int width, int height)
{
	auto app = reinterpret_cast<Scop *>(glfwGetWindowUserPointer(window));
	scop.framebufferResized = true;
}

int     main(void)
{
	

	try
	{
		// app.initVariables(argc, argv);
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		scop.window = glfwCreateWindow(WIDTH, HEIGHT, "BANKAI", nullptr, nullptr);

		glfwSetWindowUserPointer(scop.window, nullptr);
		glfwSetFramebufferSizeCallback(scop.window, framebufferResizeCallback);

		// mainLoop();

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
